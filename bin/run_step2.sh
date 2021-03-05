#!/bin/bash
echo "I am here:"
pwd
pushd /data9/Users/jihkim/GeneratorTools
echo "cmssw setting..."
source setup.sh
if [ -z $CMSSW_VERSION ]
  then echo "failed. exit"
  exit 1
fi
popd
echo "Now cmsRun"
cmsRun process_step2_cfg.py
