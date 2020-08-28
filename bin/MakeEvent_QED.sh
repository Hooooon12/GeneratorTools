#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" -o -z "$4" -o -z "$5" ] #JH -o : OR, -z : zero length
then
    echo "usage: $0 Sherpa|MG PROCESSNAME TUNE LHEPATH NEVENT [NCORE]"
    echo "example: $0 Sherpa ttH MG_NLO_CP5 <PATH> 2000 24"
    exit 1
fi

test -z "$GENERATORTOOLS_BASE" && { echo "Please source setup.sh";exit 1; }
source $GENERATORTOOLS_BASE/bin/functions.sh
CheckCMSSW

GENERATOR=$1
PROCESSNAME=$2
TUNE=$3
LHEPATH=$(realpath $4)
NEVENT=$5
NCORE=${6:-1}

echo "GENERATOR=$GENERATOR"
echo "PROCESSNAME=$PROCESSNAME"
echo "TUNE=$TUNE"
echo "LHEPATH=$LHEPATH"
echo "NEVENT=$NEVENT"
echo "NCORE=$NCORE"

echo $NEVENT|grep -q "[^0-9]" && { echo "NEVENT=$NEVENT is not integer... Exiting...";exit 1; }
echo $NCORE|grep -q "[^0-9]" && { echo "NCORE=$NCORE is not integer... Exiting...";exit 1; }
    
if [ "$GENERATOR" = "Sherpa" ]
then
    [ -f $CMSSW_BASE/src/MY/sherpa/python/sherpa_${PROCESSNAME}_MASTER_cff.pyc ] || { echo "No Sherpa python config for $PROCESSNAME... Exiting...";exit 1; }
    echo -n Submitting jobs
    for i in $(seq 1 $NCORE)
    do
	SEED=$RANDOM$(date +%S)
	WORKING_DIR=$GENERATORTOOLS_BASE/Sherpa/Event/$PROCESSNAME/run$SEED
	mkdir -p $WORKING_DIR
	cd $WORKING_DIR
	echo "#!/bin/bash" > run${SEED}.sh
	echo "cd $WORKING_DIR" >>run${SEED}.sh
	echo "time cmsDriver.py MY/sherpa/python/sherpa_${PROCESSNAME}_MASTER_cff.py -s GEN -n $NEVENT --conditions auto:mc --eventcontent RAWSIM  --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=$SEED" >> run${SEED}.sh
	chmod +x run${SEED}.sh
	if [[ $GENERATORTOOLS_USECONDOR ]]
	then
	    condor_submit -batch-name Sherpa_MakeEvent_$PROCESSNAME <<EOF > /dev/null
executable = run${SEED}.sh
output = run${SEED}.out
error = run${SEED}.err
log = run${SEED}.log
#should_transfer_files = YES
#when_to_transfer_output = ON_EXIT
#transfer_output_files = sherpa_${PROCESSNAME}_MASTER_cff_py_GEN.root,sherpa_${PROCESSNAME}_MASTER_cff_py_GEN.py
getenv = true
request_memory = 5G
accounting_group = group_cms
queue
EOF
	else
	    ./run${SEED}.sh 1>run${SEED}.out 2>run${SEED}.err &
	fi
	echo -n '.'
    done
    echo ""
elif [ "$GENERATOR" = "MG" ]
then
    [ -f $CMSSW_BASE/src/MY/mg/python/${PROCESSNAME}_${TUNE}.pyc ] || { echo "No MG python config for $PROCESSNAME or tune ${TUNE}... Exiting...";exit 1; } #JH

    echo -n Submitting jobs
    for i in $(seq 1 $NCORE)
    do
	WORKING_DIR=$GENERATORTOOLS_BASE/MG/Event/$PROCESSNAME/$TUNE #JH
	mkdir -p $WORKING_DIR
	cd $WORKING_DIR
	echo "#!/bin/bash" > run.sh	
	echo "cd $WORKING_DIR" >>run.sh
	echo "time cmsDriver.py MY/mg/python/${PROCESSNAME}_${TUNE}.py -s GEN -n $NEVENT --conditions auto:mc --eventcontent RAWSIM --filein file://$LHEPATH" >> run.sh #JH
	chmod +x run.sh
	if [[ $GENERATORTOOLS_USECONDOR ]]
	then
	    condor_submit -batch-name MG_MakeEvent_${PROCESSNAME}_${TUNE} <<EOF >/dev/null
executable = run.sh
output = run.out
error = run.err
log = run.log
#should_transfer_files = YES
#when_to_transfer_output = ON_EXIT
#transfer_output_files = ${PROCESSNAME}_${TUNE}_GEN.py,${PROCESSNAME}_${TUNE}_GEN.root
getenv = true
request_memory = 5G
accounting_group = group_cms
queue
EOF
	else
	    ./run.sh 1>run.out 2>run.err &
	fi
	echo -n '.'
    done
    echo ""
else
    echo "Improper GENERATOR=$GENERATOR"
    exit 1
fi
