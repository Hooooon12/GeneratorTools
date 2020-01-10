import os

ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
channels = ["MuMu"]
masses = ["50","500","1000"]
NEVENT = "1000"
NCORE = "20"

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+NEVENT+" "+NCORE)

for channel in channels:
  for mass in masses:
    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+NEVENT+" "+NCORE)
