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

  WORKING_DIR=$GENERATORTOOLS_BASE/MG/Sample/$PROCESSNAME
  mkdir -p $WORKING_DIR
  cd $WORKING_DIR

  echo -n "Submitting GS jobs"
  WAITLIST_GS=()
  for i in $(seq 1 $NCORE) 
  do   
    mkdir -p $WORKING_DIR/run_${i} 
    cd $WORKING_DIR/run_${i}

    echo "#!/bin/bash" > run_GS_${i}.sh
    echo "cmsDriver.py MY/mg/python/${PROCESSNAME}.py --fileout file:${PROCESSNAME}_GS_${i}.root --mc --eventcontent RAWSIM,LHE --datatier GEN-SIM,LHE --conditions 102X_upgrade2018_realistic_v20 --beamspot Realistic25ns13TeVEarly2018Collision --step LHE,GEN,SIM --nThreads 8 --geometry DB:Extended --era Run2_2018 --python_filename ${PROCESSNAME}_GS_cfg_${i}.py -n $NEVENT" >> run_GS_${i}.sh #following RunIIFall18wmLHEGS campaign
    chmod +x run_GS_${i}.sh
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_GS <<EOF >/dev/null
executable = run_GS_${i}.sh
output = run_GS_${i}.out
error = run_GS_${i}.err
log = run_GS_${i}.log
getenv = true
request_memory = 8000
accounting_group = group_cms
queue
EOF
      WAITLIST_GS+=(${WORKING_DIR}/run_${i}/run_GS_${i}.log)
    else
      ./run_GS_${i}.sh 1>run_GS_${i}.out 2>run_GS_${i}.err &
      WAITLIST_GS+=($!)
    fi
    echo -n '.'
  done
  echo ""
  
  echo -n "Waiting GS"
  for WAITTARGET in "${WAITLIST_GS[@]}"
  do
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_wait $WAITTARGET > /dev/null
    else
      echo $WAITTARGET
      echo ${WAITLIST_GS[@]}
      wait $WAITTARGET
    fi
    echo -n '.'
  done
  echo ""

  echo -n "Submitting step1 jobs"
  WAITLIST_step1=()
  for i in $(seq 1 $NCORE)
  do
    cd $WORKING_DIR/run_${i}

    echo "#!/bin/bash" > run_step1_${i}.sh
    echo "echo \"Copying grid certificate...\"" >> run_step1_${i}.sh
    echo "cp \"$GENERATORTOOLS_BASE/x509up_u\"* \"/tmp/x509up_u\"`id -u`" >> run_step1_${i}.sh
    echo "ls -hlt /tmp/" >> run_step1_${i}.sh
    echo "echo \"Making config file...\"" >> run_step1_${i}.sh
    echo "time bash -c \"cmsDriver.py step1 --mc --eventcontent PREMIXRAW --datatier GEN-SIM-RAW --conditions 102X_upgrade2018_realistic_v20 --step DIGI,DATAMIX,L1,DIGI2RAW,HLT:@relval2018 --procModifiers premix_stage2 --nThreads 8 --geometry DB:Extended --datamix PreMix --era Run2_2018 --filein file:${PROCESSNAME}_GS_${i}.root --fileout file:${PROCESSNAME}_step1_${i}.root --pileup_input \"dbs:/Neutrino_E-10_gun/RunIISummer17PrePremix-PUAutumn18_102X_upgrade2018_realistic_v15-v1/GEN-SIM-DIGI-RAW\" --python_filename ${PROCESSNAME}_step1_cfg_${i}.py -n $NEVENT --no_exec\"" >> run_step1_${i}.sh #following RunIIAutumn18DRPremix campaign
    echo "sed -i \"s/\/store/root:\/\/eoscms.cern.ch\/\/eos\/cms\/store/g\" ${PROCESSNAME}_step1_cfg_${i}.py" >> run_step1_${i}.sh
    echo "echo \"Now cmsRun...\"" >> run_step1_${i}.sh
    echo "cmsRun ${PROCESSNAME}_step1_cfg_${i}.py" >> run_step1_${i}.sh
    chmod +x run_step1_${i}.sh
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]    
    then
      condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_step1 <<EOF >/dev/null
executable = run_step1_${i}.sh
output = run_step1_${i}.out
error = run_step1_${i}.err
log = run_step1_${i}.log
getenv = true
request_memory = 10000
accounting_group = group_cms
queue
EOF
      WAITLIST_step1+=(${WORKING_DIR}/run_${i}/run_step1_${i}.log)
    else
      ./run_step1_${i}.sh 1>run_step1_${i}.out 2>run_step1_${i}.err &
      WAITLIST_step1+=($!)
    fi
    echo -n '.'
  done
  echo ""

  echo -n "Waiting step1"
  for WAITTARGET in "${WAITLIST_step1[@]}"
  do
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_wait $WAITTARGET > /dev/null
    else
      wait $WAITTARGET
    fi
    echo -n '.'
  done
  echo ""

  echo -n "Submitting step2 jobs"
  WAITLIST_step2=()
  for i in $(seq 1 $NCORE)
  do
    cd $WORKING_DIR/run_${i}

    echo "#!/bin/bash" > run_step2_${i}.sh
    echo "cmsDriver.py step2 --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 102X_upgrade2018_realistic_v20 --step RAW2DIGI,L1Reco,RECO,RECOSIM,EI --procModifiers premix_stage2 --nThreads 8 --era Run2_2018 --filein file:${PROCESSNAME}_step1_${i}.root --fileout file:${PROCESSNAME}_step2_${i}.root --python_filename ${PROCESSNAME}_step2_cfg_${i}.py -n $NEVENT" >> run_step2_${i}.sh #following RunIIAutumn18DRPremix campaign
    chmod +x run_step2_${i}.sh
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_step2 <<EOF >/dev/null
executable = run_step2_${i}.sh
output = run_step2_${i}.out
error = run_step2_${i}.err
log = run_step2_${i}.log
getenv = true
request_memory = 8000
accounting_group = group_cms
queue
EOF
      WAITLIST_step2+=(${WORKING_DIR}/run_${i}/run_step2_${i}.log)
    else
      ./run_step2_${i}.sh 1>run_step2_${i}.out 2>run_step2_${i}.err &
      WAITLIST_step2+=($!)
    fi
    echo -n '.'
  done
  echo ""
 
  echo -n "Waiting step2"
  for WAITTARGET in "${WAITLIST_step2[@]}"
  do
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_wait $WAITTARGET > /dev/null
    else
      wait $WAITTARGET
    fi
    echo -n '.'
  done
  echo ""

  echo -n "Submitting MiniAOD jobs"
  WAITLIST_MiniAOD=()
  for i in $(seq 1 $NCORE)
  do
    cd $WORKING_DIR/run_${i}

    echo "#!/bin/bash" > run_MiniAOD_${i}.sh
    echo "cmsDriver.py step1 --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 102X_upgrade2018_realistic_v20 --step PAT --nThreads 8 --geometry DB:Extended --era Run2_2018 --filein file:${PROCESSNAME}_step2_${i}.root --fileout file:${PROCESSNAME}_MiniAOD_${i}.root --python_filename ${PROCESSNAME}_MiniAOD_cfg_${i}.py -n $NEVENT" >> run_MiniAOD_${i}.sh #following RunIIAutumn18MiniAOD campaign
    chmod +x run_MiniAOD_${i}.sh
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_submit -batch-name MG_MakeSample_${PROCESSNAME}_MiniAOD <<EOF >/dev/null
executable = run_MiniAOD_${i}.sh
output = run_MiniAOD_${i}.out
error = run_MiniAOD_${i}.err
log = run_MiniAOD_${i}.log
getenv = true
request_memory = 8000
accounting_group = group_cms
queue
EOF
      WAITLIST_MiniAOD+=(${WORKING_DIR}/run_${i}/run_MiniAOD_${i}.log)
    else
      ./run_MiniAOD_${i}.sh 1>run_MiniAOD_${i}.out 2>run_MiniAOD_${i}.err &
      WAITLIST_MiniAOD+=($!)
    fi
    echo -n '.'
  done
  echo ""

  echo -n "Waiting MiniAOD"
  for WAITTARGET in "${WAITLIST_MiniAOD[@]}"
  do
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]]
    then
      condor_wait $WAITTARGET > /dev/null
    else
      wait $WAITTARGET
    fi
    echo -n '.'
  done
  echo ""

  cd $WORKING_DIR

else
    echo "Improper GENERATOR=$GENERATOR"
    exit 1
fi
