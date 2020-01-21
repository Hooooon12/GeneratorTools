#!/bin/bash

if [ -z "$1" -o -z "$2" -o -z "$3" ]
then
    echo "usage: $0 Sherpa|MG PROCESSNAME ROOTSCRIPT"
    echo "example: $0 Sherpa ttH script/ttV.cc"
    exit 1
fi

test -z "$GENERATORTOOLS_BASE" && { echo "Please source setup.sh";exit 1; }
source $GENERATORTOOLS_BASE/bin/functions.sh
CheckCMSSW

GENERATOR=$1
PROCESSNAME=$2
ROOTSCRIPT=$(realpath $3)
EVENT_DIR=$GENERATORTOOLS_BASE/$GENERATOR/Event/$PROCESSNAME

echo "GENERATOR=$GENERATOR"
echo "PROCESSNAME=$PROCESSNAME"
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

REALPATH=()
DIRNAME=()

for FILE in "${FILES[@]}"
do
  REALPATH+=($(realpath $FILE))
  DIRNAME+=($(dirname ${REALPATH[-1]}))
done

export REALPATHLIST=${REALPATH[0]}
export DIRNAMELIST=${DIRNAME[0]}
for i in ${REALPATH[@]:1}
do
  REALPATHLIST+=,$i
  DIRNAMELIST+=,$(dirname $i)
done

SCRIPT=${GENERATOR}_MakeHist_${PROCESSNAME}.sh

cd $EVENT_DIR

echo "#!/bin/bash" >$SCRIPT
echo "ITER=$(echo \`printf \$1\`)" >>$SCRIPT
echo "REALPATH=(\$(echo \"\$REALPATHLIST\" | tr ',' '\n'))" >>$SCRIPT
echo "DIRNAME=(\$(echo \"\$DIRNAMELIST\" | tr ',' '\n'))" >>$SCRIPT
echo 'echo -e ".L '$ROOTSCRIPT'+\n loop(\"${REALPATH[${ITER}]}\",\"${DIRNAME[${ITER}]}/hists.root\");\n .q"|root -l -b' >>$SCRIPT
chmod +x $SCRIPT

condor_submit -batch-name $SCRIPT <<EOF > /dev/null
executable = $SCRIPT
arguments = \$(Process)
output = run\$(Process).out
error = run\$(Process).err
log = condor.log
getenv = true
queue ${#FILES[@]}
EOF
	WAITLIST+=(${EVENT_DIR}/condor.log)
    echo -n '.'
echo ""
echo -n "Waiting jobs"
for WAITTARGET in "${WAITLIST[@]}"
do 
	condor_wait $WAITTARGET >/dev/null
  echo -n '.'
done
echo ""

for i in $(seq 1 ${#FILES[@]})
do
  mv ${EVENT_DIR}/run$(($i-1)).out ${DIRNAME[$(($i-1))]}/$(basename ${ROOTSCRIPT%.*})_${SCRIPT/%.sh/.out}
  mv ${EVENT_DIR}/run$(($i-1)).err ${DIRNAME[$(($i-1))]}/$(basename ${ROOTSCRIPT%.*})_${SCRIPT/%.sh/.err}
done

hadd -f $GENERATORTOOLS_BASE/Hist/$(basename ${ROOTSCRIPT%.*})_${GENERATOR}_${PROCESSNAME}.root $EVENT_DIR/run*/hists.root
