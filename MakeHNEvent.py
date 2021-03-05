import os

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
ptcuts = ["ptl6","ptl8","ptl10"]
#channels = ["MuMu"]
channels = ["SF"]
masses = ["85","90","95","100"]
lowmasses = ["40","50","60","70"]
highmasses = ["100","200"]
mixings = ["V0p1","V1"]
NEVENT = "10000"
NCORE = "10"

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+NEVENT+" "+NCORE)

#for ptcut in ptcuts:
#  for channel in channels:
#    for mass in masses:
#      os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_{0}_{1}_M{2}".format(ptcut, channel, mass)+" "+NEVENT+" "+NCORE)

#for channel in channels:
#  for mass in highmasses:
#    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_{0}_M{1}_325100".format(channel, mass)+" "+NEVENT+" "+NCORE)
 
#for channel in channels:
#  for mass in highmasses:
#    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_M{1}_325100".format(channel, mass)+" "+NEVENT+" "+NCORE)

#for channel in channels:
#  for mass in highmasses:
#    for ptcut in ptcuts:
#      os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_{0}_M{1}_{2}_ptj20".format(channel, mass, ptcut)+" "+NEVENT+" "+NCORE)

for channel in channels:
  for mass in masses:
    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"DYTypeI_NLO_{0}_M{1}".format(channel, mass)+" "+NEVENT+" "+NCORE)
#
#for channel in channels:
#  for mass in lowmasses:
#    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}_onshell".format(channel, mass)+" "+NEVENT+" "+NCORE)


#for channel in channels:
#  for mass in highmasses:
#    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}".format(channel, mass)+" "+NEVENT+" "+NCORE)
