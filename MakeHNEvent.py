import os

#ptcuts = ["ptcut5","ptcut10","ptcut15","ptcut20","ptl10_ptj30","ptl20_ptj30"]
ptcuts = ["ptcut5","ptcut10","ptcut20"]
channels = ["MuMu"]
masses = ["40","50","60","70","300","600","1000"]
lowmasses = ["40","50","60","70"]
mixings = ["V0p1","V1"]
NEVENT = "20000"
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
#  for mass in masses:
#    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_{0}_M{1}".format(channel, mass)+" "+NEVENT+" "+NCORE)
    
for channel in channels:
  for mass in masses:
    for mixing in mixings:
      os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}_{2}".format(channel, mass, mixing)+" "+NEVENT+" "+NCORE)

for channel in channels:
  for mass in lowmasses:
    os.system("bin/MakeEvent.sh"+" "+"MG"+" "+"HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_{0}_M{1}_onshell".format(channel, mass)+" "+NEVENT+" "+NCORE)
