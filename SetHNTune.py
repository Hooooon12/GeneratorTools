import os

channels = ["SF"]
masses = ["85","90","95","100"]

for channel in channels:
  for mass in masses:
    os.system("bin/SetTune.sh"+" "+"MG"+" "+"DYTypeI_NLO_{0}_M{1}".format(channel,mass)+" "+"python/MG_NLO_CP5_KineFilter_cff.py")
