import os

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
ptcuts = ["ptcut5","ptcut10","ptcut20"]
channels = ["MuMu"]
masses = ["300","600","1000"]

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1.cc")

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1_Vanderbilt.cc")

#for channel in channels:
#  for mass in masses:
#    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1.cc")

for channel in channels:
  for mass in masses:
    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Tch.cc")
