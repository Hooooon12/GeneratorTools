#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" ]
then
    echo "usage: $0 Sherpa|MG PROCESSNAME NEVENT [NCORE]"
    echo "example: $0 Sherpa ttH 2000 24"
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

    echo -n Submitting jobs
	WORKING_DIR=$GENERATORTOOLS_BASE/MG/Sample/$PROCESSNAME
	mkdir -p $WORKING_DIR
	cd $WORKING_DIR
	echo "#!/bin/bash" > run.sh	
	echo "cd $WORKING_DIR" >>run.sh
	echo "cmsDriver.py MY/mg/python/${PROCESSNAME}.py --fileout file:${PROCESSNAME}_GS.root --mc --eventcontent RAWSIM --datatier GEN-SIM --conditions 102X_upgrade2018_realistic_v20 --beamspot Realistic25ns13TeVEarly2018Collision --step LHE,GEN,SIM --geometry DB:Extended --era Run2_2018 --python_filename ${PROCESSNAME}_GS_cfg.py --customise Configuration/DataProcessing/Utils.addMonitoring --customise_commands process.source.numberEventsInLuminosityBlock=\"cms.untracked.uint32(1408450)\" -n $NEVENT" >> run.sh
	chmod +x run.sh
	if [[ $GENERATORTOOLS_USECONDOR ]]
	then
	    condor_submit -batch-name MG_MakeSample_$PROCESSNAME <<EOF >/dev/null
executable = run.sh
output = run.out
error = run.err
log = run.log
getenv = true
request_memory = 5G
request_cpus = $NCORE
accounting_group = group_cms
queue
EOF
	else
	    ./run${SEED}.sh 1>run${SEED}.out 2>run${SEED}.err &
	fi
	echo -n '.'
    echo ""
else
    echo "Improper GENERATOR=$GENERATOR"
    exit 1
fi
