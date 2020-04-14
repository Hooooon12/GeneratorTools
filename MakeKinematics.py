import commands as cmd

masses = [40, 50, 60, 70, 75, 300, 600, 1000]
orders = ["LO","NLO"]
histos = [x for item in cmd.getoutput("rootls Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M50.root").split(' ') for x in item.split('\n') if not x == '']
variables = [""]


with open ("test.C",'w') as f:
  #f.write('{\n')

  for order in orders:
    for i in range(len(masses)):
      f.write('TString '+order+'_filename'+str(i+1)+' = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_'+order+'_MuMu_M'+str(masses[i])+'.root";\n')
    for i in range(len(masses)):
      f.write('TFile* '+order[0]+str(masses[i])+' = new TFile('+order+'_filename'+str(i+1)+');\n')

  f.write('\n\n')
  f.write('gSystem->Exec("mkdir -p Sch_kinematics/LM");\n')
  f.write('gSystem->Exec("mkdir -p Sch_kinematics/HM");\n\n\n\n\n')
  
  for histo in histos:
    f.write(histo+'\n')


  #f.write('//========================LO========================//')

#  for order in orders:
#    for mass in masses:
#      for i in range(len(histos)):
#        f.write('')
