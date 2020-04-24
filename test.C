TString LO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M40.root";
TString LO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M50.root";
TString LO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M60.root";
TString LO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M70.root";
TString LO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M75.root";
TString LO_filename6 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M300.root";
TString LO_filename7 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M600.root";
TString LO_filename8 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M1000.root";
TFile* L40 = new TFile(LO_filename1);
TFile* L50 = new TFile(LO_filename2);
TFile* L60 = new TFile(LO_filename3);
TFile* L70 = new TFile(LO_filename4);
TFile* L75 = new TFile(LO_filename5);
TFile* L300 = new TFile(LO_filename6);
TFile* L600 = new TFile(LO_filename7);
TFile* L1000 = new TFile(LO_filename8);
TString NLO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M40.root";
TString NLO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M50.root";
TString NLO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M60.root";
TString NLO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M70.root";
TString NLO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M75.root";
TString NLO_filename6 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M300.root";
TString NLO_filename7 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M600.root";
TString NLO_filename8 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M1000.root";
TFile* N40 = new TFile(NLO_filename1);
TFile* N50 = new TFile(NLO_filename2);
TFile* N60 = new TFile(NLO_filename3);
TFile* N70 = new TFile(NLO_filename4);
TFile* N75 = new TFile(NLO_filename5);
TFile* N300 = new TFile(NLO_filename6);
TFile* N600 = new TFile(NLO_filename7);
TFile* N1000 = new TFile(NLO_filename8);


gSystem->Exec("mkdir -p Sch_kinematics/LM");
gSystem->Exec("mkdir -p Sch_kinematics/HM");




(l0+dijet)_E
(l0+dijet)_eta
(l0+dijet)_m
(l0+dijet)_pt
(l0+fatjet)_E
(l0+fatjet)_eta
(l0+fatjet)_m
(l0+fatjet)_pt
(l1+dijet)_E
(l1+dijet)_eta
(l1+dijet)_m
(l1+dijet)_pt
(l1+fatjet)_E
(l1+fatjet)_eta
(l1+fatjet)_m
(l1+fatjet)_pt
(SS2l+dijet)_E
(SS2l+dijet)_eta
(SS2l+dijet)_m
(SS2l+dijet)_pt
(SS2l+fatjet)_E
(SS2l+fatjet)_eta
(SS2l+fatjet)_m
(SS2l+fatjet)_pt
DeltaR(jj)
DeltaR(qq)
dijet_E
dijet_eta
dijet_m
dijet_pt
diparton_E
diparton_eta
diparton_m
diparton_pt
diparton_pz
fatjet_E
fatjet_eta
fatjet_m
fatjet_pt
fatjets_eta
fatjets_pt
forward_gluon_E
forward_gluon_eta
forward_gluon_m
forward_gluon_pt
forward_parton_E
forward_parton_eta
forward_parton_m
forward_parton_pt
forward_q_E
forward_q_eta
forward_q_m
forward_q_pt
hard_l_charge
hard_l_E
hard_l_eta
hard_l_pt
HN_l_charge
HN_l_E
HN_l_eta
HN_l_pt
j0_E
j0_eta
j0_m
j0_pt
j1_E
j1_eta
j1_m
j1_pt
jets_eta
jets_pt
l0_E
l0_eta
l0_pt
l1_E
l1_eta
l1_pt
last_HN_E
last_HN_eta
last_HN_m
last_HN_pt
leptons_eta
leptons_pt
METv_E
METv_eta
METv_m
METv_pt
N_q0_E
N_q0_eta
N_q0_m
N_q0_pt
N_q1_E
N_q1_eta
N_q1_m
N_q1_pt
nfatjet
njet
nlep
offshell_W1_E
offshell_W1_eta
offshell_W1_m
offshell_W1_pt
offshell_W2_E
offshell_W2_eta
offshell_W2_m
offshell_W2_pt
onshell_W1_E
onshell_W1_eta
onshell_W1_m
onshell_W1_pt
onshell_W2_E
onshell_W2_eta
onshell_W2_m
onshell_W2_pt
sumw
W1_E
W1_eta
W1_m
W1_pt
W2_E
W2_eta
W2_m
W2_pt
W_E
W_eta
W_l_charge
W_l_E
W_l_eta
W_l_pt
W_m
W_pt
