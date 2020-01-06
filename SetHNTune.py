import os

ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
channels = ["MuMu"]
masses = ["1000"]

for ptcut in ptcuts:
  for channel in channels:
    for mass in masses:
      os.system("bin/SetTune.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+"python/MG_NLO_CP5_DiLepChargeFilter_cff.py")
