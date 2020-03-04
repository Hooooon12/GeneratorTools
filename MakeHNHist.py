import os

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
ptcuts = ["ptcut5","ptcut10","ptcut20"]
channels = ["MuMu"]
masses = ["40","50","60","70","75","500","1000"]
masses_LO = masses+["100","200","300","600","800","1200","1500"]

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1.cc")

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1_Vanderbilt.cc")

for channel in channels:
  for mass in masses:
    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Sch.cc")

for channel in channels:
  for mass in masses_LO:
    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Sch.cc")

#for channel in channels:
#  for mass in masses:
#    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Tch.cc")
