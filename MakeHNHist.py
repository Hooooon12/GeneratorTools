import os

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
ptcuts = ["ptcut5","ptcut10","ptcut20"]
channels = ["MuMu"]
masses_NLO = ["40","50","60","70","75","85","90","300","500","600","1000"]
masses_LO = ["40","50","60","70","75","300","500","600","1000"]
#masses = ["300","600","1000"]
masses = ["75","85","90","100","200","300"]

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1.cc")

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"script/HNtype1_Vanderbilt.cc")

#for channel in channels:
#  for mass in masses_NLO:
#    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Sch.cc")
#
#for channel in channels:
#  for mass in masses_LO:
#    os.system("bin/MakeHist_CollectJobs.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Sch.cc")

#for channel in channels:
#  for mass in masses:
#    os.system("bin/MakeHist.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_M{1}_325100".format(channel, mass)+" "+"script/HNtype1_Tch.cc")
#    os.system("bin/MakeHist.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_{0}_M{1}_325100".format(channel, mass)+" "+"script/HNtype1_Tch.cc")

for channel in channels:
  for mass in masses:
    os.system("bin/MakeHist.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+"script/HNtype1_Sch_leptononly.cc")
