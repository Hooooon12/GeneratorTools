import commands as cmd
import subprocess as ps
#import os

NCORE = "10"
TUNE = "python/MG_NLO_CP5_DiLepChargeFilter_cff.py"

#Change HN mass and generate

old_mass = "1000"
new_masses = ["1500","2000"]

old_processes = cmd.getoutput('ls MG/Gridpack | grep M{}'.format(old_mass)).split()

for old_process in old_processes:
  for new_mass in new_masses:
    new_process = old_process[:old_process.rfind('M')+1]+new_mass
    ps.call(("bin/CopyGridpack.sh MG"+" "+old_process+" "+new_process+" "+TUNE).split())
    ps.call("sed -i 's/mn1 "+old_mass+"/mn1 "+new_mass+"/g' *", shell=True, cwd="MG/Card/"+new_process)
    ps.call(("bin/MakeGridpack.sh MG"+" "+new_process+" "+NCORE+" "+TUNE).split())

#Just generate

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
#channels = ["MuMu"]
#masses = ["1000","1500"]
#
#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeGridpack.sh MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+NCORE+" "+TUNE)