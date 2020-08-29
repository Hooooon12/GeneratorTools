#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" -o -z "$4" ] #JH
then
    echo "usage: $0 Sherpa|MG PROCESSNAME TUNE ROOTSCRIPT"
    echo "example: $0 Sherpa ttH MG_LO_CP5 script/ttV.cc"
    exit 1
fi

test -z "$GENERATORTOOLS_BASE" && { echo "Please source setup.sh";exit 1; }
source $GENERATORTOOLS_BASE/bin/functions.sh
CheckCMSSW

GENERATOR=$1
PROCESSNAME=$2
TUNE=$3
ROOTSCRIPT=$(realpath $4)
EVENT_DIR=$GENERATORTOOLS_BASE/$GENERATOR/Event/$PROCESSNAME/$TUNE

echo "GENERATOR=$GENERATOR"
echo "PROCESSNAME=$PROCESSNAME"
echo "TUNE=$TUNE"
echo "ROOTSCRIPT=$ROOTSCRIPT"
echo "EVENT_DIR=$EVENT_DIR"

echo -n "Check script... "
CHECK=$(root -l -b < <(echo .L $ROOTSCRIPT+) 2>&1)
if echo $CHECK|grep -q -i error #JH
then echo $CHECK; exit 1;
else echo "success"
fi

FILES=($(find $EVENT_DIR -maxdepth 2 -name "*GEN*.root"))
WAITLIST=()
echo Total ${#FILES[@]} root files are detected
echo -n "Submitting jobs"
for FILE in "${FILES[@]}"
do
    cd $GENERATORTOOLS_BASE
    REALPATH=$(realpath $FILE)
    DIRNAME=$(dirname $REALPATH)
    BASENAME=$(basename $REALPATH)

    cd $DIRNAME
    SCRIPT=${GENERATOR}_MakeHists_${PROCESSNAME}.sh
    echo "#!/bin/bash" >$SCRIPT
    echo 'echo -e ".L '$ROOTSCRIPT'+\n loop(\"'$REALPATH'\",\"'$DIRNAME'/hists.root\");\n .q"|root -l -b' >>$SCRIPT
    chmod +x $SCRIPT
    
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]] #JH
    then
	condor_submit -batch-name $SCRIPT <<EOF > /dev/null
executable = $SCRIPT
output = ${SCRIPT/%.sh/.out}
error = ${SCRIPT/%.sh/.err}
log = ${SCRIPT/%.sh/.log}
getenv = true
queue
EOF
	WAITLIST+=($DIRNAME/${SCRIPT/%.sh/.log})
    else 
	./$SCRIPT 1>${SCRIPT/%.sh/.out} 2>${SCRIPT/%.sh/.err} &
	WAITLIST+=($!)
    fi
    echo -n '.'
done
echo ""
echo -n "Waiting jobs"
for WAITTARGET in "${WAITLIST[@]}"
do 
    if [[ $GENERATORTOOLS_USECONDOR = 1 ]] #JH
    then
	condor_wait $WAITTARGET >/dev/null
    else
    echo $WAITTARGET
    echo ${WAITLIST[@]}
	wait ${WAITLIST[@]}
    fi
    echo -n '.'
done
echo ""

hadd -f $GENERATORTOOLS_BASE/Hist/$(basename ${ROOTSCRIPT%.*})_${GENERATOR}_${PROCESSNAME}_${TUNE}.root $EVENT_DIR/hists.root
