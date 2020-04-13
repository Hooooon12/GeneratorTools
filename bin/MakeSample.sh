#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" ]
then
  echo "usage: $0 Sherpa|MG PROCESSNAME NEVENT [NCORE]"
  echo "example: $0 Sherpa ttH 2000 24"
  exit 1
elif [ ! -f $GENERATORTOOLS_BASE/x509up_u`id -u` ]
then
  echo "do voms-proxy-init --voms cms -valid 240:00; cp /tmp/x509up_u`id -u` $GENERATORTOOLS_BASE; before run this"
  exit 1
fi

test -z "$GENERATORTOOLS_BASE" && { echo "Please source setup.sh";exit 1; }
source $GENERATORTOOLS_BASE/bin/functions.sh
CheckCMSSW

GENERATOR=$1
PROCESSNAME=$2
NEVENT=$3
NCORE=${4:-1}

echo "GENERATOR=$GENERATOR"
echo "PROCESSNAME=$PROCESSNAME"
echo "NEVENT=$NEVENT"
echo "NCORE=$NCORE"

echo $NEVENT|grep -q "[^0-9]" && { echo "NEVENT=$NEVENT is not integer... Exiting...";exit 1; }
echo $NCORE|grep -q "[^0-9]" && { echo "NCORE=$NCORE is not integer... Exiting...";exit 1; }
    
if [ "$GENERATOR" = "MG" ]
then
  [ -f $CMSSW_BASE/src/MY/mg/python/${PROCESSNAME}.pyc ] || { echo "No MG python config for $PROCESSNAME... Exiting...";exit 1; }

  echo -n "Submitting GS jobs"
  WORKING_DIR=$GENERATORTOOLS_BASE/MG/Sample/$PROCESSNAME
  mkdir -p $WORKING_DIR
  cd $WORKING_DIR
  echo "#!/bin/bash" > run_GS.sh
  echo "cmsDriver.py MY/mg/python/${PROCESSNAME}.py --fileout file:${PROCESSNAME}_GS.root --mc --eventcontent RAWSIM,LHE --datatier GEN-SIM,LHE --conditions 102X_upgrade2018_realistic_v20 --beamspot Realistic25ns13TeVEarly2018Collision --step LHE,GEN,SIM --nThreads 8 --geometry DB:Extended --era Run2_2018 --python_filename ${PROCESSNAME}_GS_cfg.py -n $NEVENT" >> run_GS.sh #following RunIIFall18wmLHEGS campaign
  chmod +x run_GS.sh
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_GS <<EOF >/dev/null
executable = run_GS.sh
output = run_GS.out
error = run_GS.err
log = run_GS.log
getenv = true
request_memory = 8000
request_cpus = $NCORE
accounting_group = group_cms
queue
EOF
  else
    ./run_GS.sh 1>run_GS.out 2>run_GS.err &
  fi
  echo -n '.'
  echo ""
  
  echo -n "Waiting GS"
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_wait ${WORKING_DIR}/run_GS.log > /dev/null
  else
    wait $!
  fi
  echo -n '.'
  echo ""

  echo -n "Submitting step1 jobs"
  echo "#!/bin/bash" > run_step1.sh
  echo "echo \"Copying grid certificate...\"" >> run_step1.sh
  echo "cp \"$GENERATORTOOLS_BASE/x509up_u\"* \"/tmp/x509up_u\"`id -u`" >> run_step1.sh
  echo "ls -hlt /tmp/" >> run_step1.sh
  echo "echo \"Making config file...\"" >> run_step1.sh
  echo "time bash -c \"cmsDriver.py step1 --mc --eventcontent PREMIXRAW --datatier GEN-SIM-RAW --conditions 102X_upgrade2018_realistic_v20 --step DIGI,DATAMIX,L1,DIGI2RAW,HLT:@relval2018 --procModifiers premix_stage2 --nThreads 8 --geometry DB:Extended --datamix PreMix --era Run2_2018 --filein file:${PROCESSNAME}_GS.root --fileout file:${PROCESSNAME}_step1.root --pileup_input \"dbs:/Neutrino_E-10_gun/RunIISummer17PrePremix-PUAutumn18_102X_upgrade2018_realistic_v15-v1/GEN-SIM-DIGI-RAW\" --python_filename ${PROCESSNAME}_step1_cfg.py -n $NEVENT --no_exec\"" >> run_step1.sh #following RunIIAutumn18DRPremix campaign
  echo "sed -i \"s/\/store/root:\/\/eoscms.cern.ch\/\/eos\/cms\/store/g\" ${PROCESSNAME}_step1_cfg.py" >> run_step1.sh
  echo "echo \"Now cmsRun...\"" >> run_step1.sh
  echo "cmsRun ${PROCESSNAME}_step1_cfg.py" >> run_step1.sh
  chmod +x run_step1.sh
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]                                           
  then
    condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_step1 <<EOF >/dev/null
executable = run_step1.sh
output = run_step1.out
error = run_step1.err
log = run_step1.log
getenv = true
request_memory = 10000
request_cpus = $NCORE
accounting_group = group_cms
queue
EOF
  else
    ./run_step1.sh 1>run_step1.out 2>run_step1.err &
  fi
  echo -n '.'
  echo ""

  echo -n "Waiting step1"
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_wait ${WORKING_DIR}/run_step1.log > /dev/null
  else
    wait $!
  fi
  echo -n '.'
  echo ""

  echo -n "Submitting step2 jobs"
  echo "#!/bin/bash" > run_step2.sh
  echo "cmsDriver.py step2 --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 102X_upgrade2018_realistic_v20 --step RAW2DIGI,L1Reco,RECO,RECOSIM,EI --procModifiers premix_stage2 --nThreads 8 --era Run2_2018 --filein file:${PROCESSNAME}_step1.root --fileout file:${PROCESSNAME}_step2.root --python_filename ${PROCESSNAME}_step2_cfg.py -n $NEVENT" >> run_step2.sh #following RunIIAutumn18DRPremix campaign
  chmod +x run_step2.sh
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_step2 <<EOF >/dev/null
executable = run_step2.sh
output = run_step2.out
error = run_step2.err
log = run_step2.log
getenv = true
request_memory = 8000
request_cpus = $NCORE
accounting_group = group_cms
queue
EOF
  else
    ./run_step2.sh 1>run_step2.out 2>run_step2.err &
  fi
  echo -n '.'
  echo ""
 
  echo -n "Waiting step2"
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_wait ${WORKING_DIR}/run_step2.log > /dev/null
  else
    wait $!
  fi
  echo -n '.'
  echo ""

  echo -n "Submitting MiniAOD jobs"
  echo "#!/bin/bash" > run_MiniAOD.sh
  echo "cmsDriver.py step1 --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 102X_upgrade2018_realistic_v20 --step PAT --nThreads 8 --geometry DB:Extended --era Run2_2018 --filein file:${PROCESSNAME}_step2.root --fileout file:${PROCESSNAME}_MiniAOD.root --python_filename ${PROCESSNAME}_MiniAOD_cfg.py -n $NEVENT" >> run_MiniAOD.sh #following RunIIAutumn18MiniAOD campaign
  chmod +x run_MiniAOD.sh
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_MiniAOD <<EOF >/dev/null
executable = run_MiniAOD.sh
output = run_MiniAOD.out
error = run_MiniAOD.err
log = run_MiniAOD.log
getenv = true
request_memory = 8000
request_cpus = $NCORE
accounting_group = group_cms
queue
EOF
  else
    ./run_step2.sh 1>run_step2.out 2>run_step2.err &
  fi
  echo -n '.'
  echo ""

  echo -n "Waiting MiniAOD"
  if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
  then
    condor_wait ${WORKING_DIR}/run_MiniAOD.log > /dev/null
  else
    wait $!
  fi
  echo -n '.'
  echo ""


else
    echo "Improper GENERATOR=$GENERATOR"
    exit 1
fi
