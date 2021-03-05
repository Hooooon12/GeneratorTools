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
echo "Copying grid certificate..."
cp "x509up_u"* "/tmp/x509up_u"`id -u` #voms-proxy-init --voms cms -valid 240:00 and cp /tmp/x509up_u`id -u` <local directory> before run this
ls -hlt /tmp/
echo "Now cmsRun"
cmsRun process_step1_cfg.py #cmsDriver.py <...> --no_exec
