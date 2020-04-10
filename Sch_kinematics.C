{
TString LO_filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M40.root";
TString LO_filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M50.root";
TString LO_filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M60.root";
TString LO_filename4 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M70.root";
TString LO_filename5 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M75.root";
TString LO_filename6 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M300.root";
TString LO_filename7 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M600.root";
TString LO_filename8 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M1000.root";
TFile* L40 = new TFile(LO_filename1);
TFile* L50 = new TFile(LO_filename2);
TFile* L60 = new TFile(LO_filename3);
TFile* L70 = new TFile(LO_filename4);
TFile* L75 = new TFile(LO_filename5);
TFile* L300 = new TFile(LO_filename6);
TFile* L600 = new TFile(LO_filename7);
TFile* L1000 = new TFile(LO_filename8);
TString NLO_filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M40.root";
TString NLO_filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M50.root";
TString NLO_filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M60.root";
TString NLO_filename4 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M70.root";
TString NLO_filename5 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M75.root";
TString NLO_filename6 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M300.root";
TString NLO_filename7 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M600.root";
TString NLO_filename8 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M1000.root";
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


//========================LO========================//


TH1D* mlljj_L40 = (TH1D*)L40->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L40 = (TH1D*)L40->Get("(l0+dijet)_m");
TH1D* ml2jj_L40 = (TH1D*)L40->Get("(l1+dijet)_m");
TH1D* dRjj_L40 = (TH1D*)L40->Get("DeltaR(jj)");
TH1D* Npt_L40 = (TH1D*)L40->Get("last_HN_pt");
TH1D* Neta_L40 = (TH1D*)L40->Get("last_HN_eta");
TH1D* Nen_L40 = (TH1D*)L40->Get("last_HN_E");
TH1D* Wpt_L40 = (TH1D*)L40->Get("last_W_pt");
TH1D* Weta_L40 = (TH1D*)L40->Get("last_W_eta");
TH1D* Wen_L40 = (TH1D*)L40->Get("last_W_E");
TH1D* j1pt_L40 = (TH1D*)L40->Get("j0_pt");
TH1D* j1eta_L40 = (TH1D*)L40->Get("j0_eta");
TH1D* j2pt_L40 = (TH1D*)L40->Get("j1_pt");
TH1D* j2eta_L40 = (TH1D*)L40->Get("j1_eta");
TH1D* l1pt_L40 = (TH1D*)L40->Get("l0_pt");
TH1D* l1eta_L40 = (TH1D*)L40->Get("l0_eta");
TH1D* l2pt_L40 = (TH1D*)L40->Get("l1_pt");
TH1D* l2eta_L40 = (TH1D*)L40->Get("l1_eta");
TH1D* Nlpt_L40 = (TH1D*)L40->Get("HN_l_pt");
TH1D* Nleta_L40 = (TH1D*)L40->Get("HN_l_eta");
TH1D* Wlpt_L40 = (TH1D*)L40->Get("W_l_pt");
TH1D* Wleta_L40 = (TH1D*)L40->Get("W_l_eta");
TH1D* hardlpt_L40 = (TH1D*)L40->Get("hard_l_pt");
TH1D* hardleta_L40 = (TH1D*)L40->Get("hard_l_eta");
TH1D* hardqpt_L40 = (TH1D*)L40->Get("forward_q_pt");
TH1D* hardqeta_L40 = (TH1D*)L40->Get("forward_q_eta");
TH1D* Nq1pt_L40 = (TH1D*)L40->Get("N_q0_pt");
TH1D* Nq1eta_L40 = (TH1D*)L40->Get("N_q0_eta");
TH1D* Nq2pt_L40 = (TH1D*)L40->Get("N_q1_pt");
TH1D* Nq2eta_L40 = (TH1D*)L40->Get("N_q1_eta");
TH1D* dRqq_L40 = (TH1D*)L40->Get("DeltaR(qq)");
TH1D* MET_L40 = (TH1D*)L40->Get("MET_pt");
TH1D* mjj_L40 = (TH1D*)L40->Get("dijet_m");
TH1D* mJ_L40 = (TH1D*)L40->Get("fatjet_m");
TH1D* mllJ_L40 = (TH1D*)L40->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L40 = (TH1D*)L40->Get("(l0+fatjet)_m");
TH1D* ml2J_L40 = (TH1D*)L40->Get("(l1+fatjet)_m");
TH1D* Jpt_L40 = (TH1D*)L40->Get("fatjet_pt");
TH1D* Jeta_L40 = (TH1D*)L40->Get("fatjet_eta");
TH1D* mWoff_L40 = (TH1D*)L40->Get("offshell_W_m");



TH1D* mlljj_L50 = (TH1D*)L50->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L50 = (TH1D*)L50->Get("(l0+dijet)_m");
TH1D* ml2jj_L50 = (TH1D*)L50->Get("(l1+dijet)_m");
TH1D* dRjj_L50 = (TH1D*)L50->Get("DeltaR(jj)");
TH1D* Npt_L50 = (TH1D*)L50->Get("last_HN_pt");
TH1D* Neta_L50 = (TH1D*)L50->Get("last_HN_eta");
TH1D* Nen_L50 = (TH1D*)L50->Get("last_HN_E");
TH1D* Wpt_L50 = (TH1D*)L50->Get("last_W_pt");
TH1D* Weta_L50 = (TH1D*)L50->Get("last_W_eta");
TH1D* Wen_L50 = (TH1D*)L50->Get("last_W_E");
TH1D* j1pt_L50 = (TH1D*)L50->Get("j0_pt");
TH1D* j1eta_L50 = (TH1D*)L50->Get("j0_eta");
TH1D* j2pt_L50 = (TH1D*)L50->Get("j1_pt");
TH1D* j2eta_L50 = (TH1D*)L50->Get("j1_eta");
TH1D* l1pt_L50 = (TH1D*)L50->Get("l0_pt");
TH1D* l1eta_L50 = (TH1D*)L50->Get("l0_eta");
TH1D* l2pt_L50 = (TH1D*)L50->Get("l1_pt");
TH1D* l2eta_L50 = (TH1D*)L50->Get("l1_eta");
TH1D* Nlpt_L50 = (TH1D*)L50->Get("HN_l_pt");
TH1D* Nleta_L50 = (TH1D*)L50->Get("HN_l_eta");
TH1D* Wlpt_L50 = (TH1D*)L50->Get("W_l_pt");
TH1D* Wleta_L50 = (TH1D*)L50->Get("W_l_eta");
TH1D* hardlpt_L50 = (TH1D*)L50->Get("hard_l_pt");
TH1D* hardleta_L50 = (TH1D*)L50->Get("hard_l_eta");
TH1D* hardqpt_L50 = (TH1D*)L50->Get("forward_q_pt");
TH1D* hardqeta_L50 = (TH1D*)L50->Get("forward_q_eta");
TH1D* Nq1pt_L50 = (TH1D*)L50->Get("N_q0_pt");
TH1D* Nq1eta_L50 = (TH1D*)L50->Get("N_q0_eta");
TH1D* Nq2pt_L50 = (TH1D*)L50->Get("N_q1_pt");
TH1D* Nq2eta_L50 = (TH1D*)L50->Get("N_q1_eta");
TH1D* dRqq_L50 = (TH1D*)L50->Get("DeltaR(qq)");
TH1D* MET_L50 = (TH1D*)L50->Get("MET_pt");
TH1D* mjj_L50 = (TH1D*)L50->Get("dijet_m");
TH1D* mJ_L50 = (TH1D*)L50->Get("fatjet_m");
TH1D* mllJ_L50 = (TH1D*)L50->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L50 = (TH1D*)L50->Get("(l0+fatjet)_m");
TH1D* ml2J_L50 = (TH1D*)L50->Get("(l1+fatjet)_m");
TH1D* Jpt_L50 = (TH1D*)L50->Get("fatjet_pt");
TH1D* Jeta_L50 = (TH1D*)L50->Get("fatjet_eta");
TH1D* mWoff_L50 = (TH1D*)L50->Get("offshell_W_m");




TH1D* mlljj_L60 = (TH1D*)L60->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L60 = (TH1D*)L60->Get("(l0+dijet)_m");
TH1D* ml2jj_L60 = (TH1D*)L60->Get("(l1+dijet)_m");
TH1D* dRjj_L60 = (TH1D*)L60->Get("DeltaR(jj)");
TH1D* Npt_L60 = (TH1D*)L60->Get("last_HN_pt");
TH1D* Neta_L60 = (TH1D*)L60->Get("last_HN_eta");
TH1D* Nen_L60 = (TH1D*)L60->Get("last_HN_E");
TH1D* Wpt_L60 = (TH1D*)L60->Get("last_W_pt");
TH1D* Weta_L60 = (TH1D*)L60->Get("last_W_eta");
TH1D* Wen_L60 = (TH1D*)L60->Get("last_W_E");
TH1D* j1pt_L60 = (TH1D*)L60->Get("j0_pt");
TH1D* j1eta_L60 = (TH1D*)L60->Get("j0_eta");
TH1D* j2pt_L60 = (TH1D*)L60->Get("j1_pt");
TH1D* j2eta_L60 = (TH1D*)L60->Get("j1_eta");
TH1D* l1pt_L60 = (TH1D*)L60->Get("l0_pt");
TH1D* l1eta_L60 = (TH1D*)L60->Get("l0_eta");
TH1D* l2pt_L60 = (TH1D*)L60->Get("l1_pt");
TH1D* l2eta_L60 = (TH1D*)L60->Get("l1_eta");
TH1D* Nlpt_L60 = (TH1D*)L60->Get("HN_l_pt");
TH1D* Nleta_L60 = (TH1D*)L60->Get("HN_l_eta");
TH1D* Wlpt_L60 = (TH1D*)L60->Get("W_l_pt");
TH1D* Wleta_L60 = (TH1D*)L60->Get("W_l_eta");
TH1D* hardlpt_L60 = (TH1D*)L60->Get("hard_l_pt");
TH1D* hardleta_L60 = (TH1D*)L60->Get("hard_l_eta");
TH1D* hardqpt_L60 = (TH1D*)L60->Get("forward_q_pt");
TH1D* hardqeta_L60 = (TH1D*)L60->Get("forward_q_eta");
TH1D* Nq1pt_L60 = (TH1D*)L60->Get("N_q0_pt");
TH1D* Nq1eta_L60 = (TH1D*)L60->Get("N_q0_eta");
TH1D* Nq2pt_L60 = (TH1D*)L60->Get("N_q1_pt");
TH1D* Nq2eta_L60 = (TH1D*)L60->Get("N_q1_eta");
TH1D* dRqq_L60 = (TH1D*)L60->Get("DeltaR(qq)");
TH1D* MET_L60 = (TH1D*)L60->Get("MET_pt");
TH1D* mjj_L60 = (TH1D*)L60->Get("dijet_m");
TH1D* mJ_L60 = (TH1D*)L60->Get("fatjet_m");
TH1D* mllJ_L60 = (TH1D*)L60->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L60 = (TH1D*)L60->Get("(l0+fatjet)_m");
TH1D* ml2J_L60 = (TH1D*)L60->Get("(l1+fatjet)_m");
TH1D* Jpt_L60 = (TH1D*)L60->Get("fatjet_pt");
TH1D* Jeta_L60 = (TH1D*)L60->Get("fatjet_eta");
TH1D* mWoff_L60 = (TH1D*)L60->Get("offshell_W_m");



TH1D* mlljj_L70 = (TH1D*)L70->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L70 = (TH1D*)L70->Get("(l0+dijet)_m");
TH1D* ml2jj_L70 = (TH1D*)L70->Get("(l1+dijet)_m");
TH1D* dRjj_L70 = (TH1D*)L70->Get("DeltaR(jj)");
TH1D* Npt_L70 = (TH1D*)L70->Get("last_HN_pt");
TH1D* Neta_L70 = (TH1D*)L70->Get("last_HN_eta");
TH1D* Nen_L70 = (TH1D*)L70->Get("last_HN_E");
TH1D* Wpt_L70 = (TH1D*)L70->Get("last_W_pt");
TH1D* Weta_L70 = (TH1D*)L70->Get("last_W_eta");
TH1D* Wen_L70 = (TH1D*)L70->Get("last_W_E");
TH1D* j1pt_L70 = (TH1D*)L70->Get("j0_pt");
TH1D* j1eta_L70 = (TH1D*)L70->Get("j0_eta");
TH1D* j2pt_L70 = (TH1D*)L70->Get("j1_pt");
TH1D* j2eta_L70 = (TH1D*)L70->Get("j1_eta");
TH1D* l1pt_L70 = (TH1D*)L70->Get("l0_pt");
TH1D* l1eta_L70 = (TH1D*)L70->Get("l0_eta");
TH1D* l2pt_L70 = (TH1D*)L70->Get("l1_pt");
TH1D* l2eta_L70 = (TH1D*)L70->Get("l1_eta");
TH1D* Nlpt_L70 = (TH1D*)L70->Get("HN_l_pt");
TH1D* Nleta_L70 = (TH1D*)L70->Get("HN_l_eta");
TH1D* Wlpt_L70 = (TH1D*)L70->Get("W_l_pt");
TH1D* Wleta_L70 = (TH1D*)L70->Get("W_l_eta");
TH1D* hardlpt_L70 = (TH1D*)L70->Get("hard_l_pt");
TH1D* hardleta_L70 = (TH1D*)L70->Get("hard_l_eta");
TH1D* hardqpt_L70 = (TH1D*)L70->Get("forward_q_pt");
TH1D* hardqeta_L70 = (TH1D*)L70->Get("forward_q_eta");
TH1D* Nq1pt_L70 = (TH1D*)L70->Get("N_q0_pt");
TH1D* Nq1eta_L70 = (TH1D*)L70->Get("N_q0_eta");
TH1D* Nq2pt_L70 = (TH1D*)L70->Get("N_q1_pt");
TH1D* Nq2eta_L70 = (TH1D*)L70->Get("N_q1_eta");
TH1D* dRqq_L70 = (TH1D*)L70->Get("DeltaR(qq)");
TH1D* MET_L70 = (TH1D*)L70->Get("MET_pt");
TH1D* mjj_L70 = (TH1D*)L70->Get("dijet_m");
TH1D* mJ_L70 = (TH1D*)L70->Get("fatjet_m");
TH1D* mllJ_L70 = (TH1D*)L70->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L70 = (TH1D*)L70->Get("(l0+fatjet)_m");
TH1D* ml2J_L70 = (TH1D*)L70->Get("(l1+fatjet)_m");
TH1D* Jpt_L70 = (TH1D*)L70->Get("fatjet_pt");
TH1D* Jeta_L70 = (TH1D*)L70->Get("fatjet_eta");
TH1D* mWoff_L70 = (TH1D*)L70->Get("offshell_W_m");



TH1D* mlljj_L75 = (TH1D*)L75->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L75 = (TH1D*)L75->Get("(l0+dijet)_m");
TH1D* ml2jj_L75 = (TH1D*)L75->Get("(l1+dijet)_m");
TH1D* dRjj_L75 = (TH1D*)L75->Get("DeltaR(jj)");
TH1D* Npt_L75 = (TH1D*)L75->Get("last_HN_pt");
TH1D* Neta_L75 = (TH1D*)L75->Get("last_HN_eta");
TH1D* Nen_L75 = (TH1D*)L75->Get("last_HN_E");
TH1D* Wpt_L75 = (TH1D*)L75->Get("last_W_pt");
TH1D* Weta_L75 = (TH1D*)L75->Get("last_W_eta");
TH1D* Wen_L75 = (TH1D*)L75->Get("last_W_E");
TH1D* j1pt_L75 = (TH1D*)L75->Get("j0_pt");
TH1D* j1eta_L75 = (TH1D*)L75->Get("j0_eta");
TH1D* j2pt_L75 = (TH1D*)L75->Get("j1_pt");
TH1D* j2eta_L75 = (TH1D*)L75->Get("j1_eta");
TH1D* l1pt_L75 = (TH1D*)L75->Get("l0_pt");
TH1D* l1eta_L75 = (TH1D*)L75->Get("l0_eta");
TH1D* l2pt_L75 = (TH1D*)L75->Get("l1_pt");
TH1D* l2eta_L75 = (TH1D*)L75->Get("l1_eta");
TH1D* Nlpt_L75 = (TH1D*)L75->Get("HN_l_pt");
TH1D* Nleta_L75 = (TH1D*)L75->Get("HN_l_eta");
TH1D* Wlpt_L75 = (TH1D*)L75->Get("W_l_pt");
TH1D* Wleta_L75 = (TH1D*)L75->Get("W_l_eta");
TH1D* hardlpt_L75 = (TH1D*)L75->Get("hard_l_pt");
TH1D* hardleta_L75 = (TH1D*)L75->Get("hard_l_eta");
TH1D* hardqpt_L75 = (TH1D*)L75->Get("forward_q_pt");
TH1D* hardqeta_L75 = (TH1D*)L75->Get("forward_q_eta");
TH1D* Nq1pt_L75 = (TH1D*)L75->Get("N_q0_pt");
TH1D* Nq1eta_L75 = (TH1D*)L75->Get("N_q0_eta");
TH1D* Nq2pt_L75 = (TH1D*)L75->Get("N_q1_pt");
TH1D* Nq2eta_L75 = (TH1D*)L75->Get("N_q1_eta");
TH1D* dRqq_L75 = (TH1D*)L75->Get("DeltaR(qq)");
TH1D* MET_L75 = (TH1D*)L75->Get("MET_pt");
TH1D* mjj_L75 = (TH1D*)L75->Get("dijet_m");
TH1D* mJ_L75 = (TH1D*)L75->Get("fatjet_m");
TH1D* mllJ_L75 = (TH1D*)L75->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L75 = (TH1D*)L75->Get("(l0+fatjet)_m");
TH1D* ml2J_L75 = (TH1D*)L75->Get("(l1+fatjet)_m");
TH1D* Jpt_L75 = (TH1D*)L75->Get("fatjet_pt");
TH1D* Jeta_L75 = (TH1D*)L75->Get("fatjet_eta");
TH1D* mWoff_L75 = (TH1D*)L75->Get("offshell_W_m");



//========================NLO========================//


TH1D* mlljj_N40 = (TH1D*)N40->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N40 = (TH1D*)N40->Get("(l0+dijet)_m");
TH1D* ml2jj_N40 = (TH1D*)N40->Get("(l1+dijet)_m");
TH1D* dRjj_N40 = (TH1D*)N40->Get("DeltaR(jj)");
TH1D* Npt_N40 = (TH1D*)N40->Get("last_HN_pt");
TH1D* Neta_N40 = (TH1D*)N40->Get("last_HN_eta");
TH1D* Nen_N40 = (TH1D*)N40->Get("last_HN_E");
TH1D* Wpt_N40 = (TH1D*)N40->Get("last_W_pt");
TH1D* Weta_N40 = (TH1D*)N40->Get("last_W_eta");
TH1D* Wen_N40 = (TH1D*)N40->Get("last_W_E");
TH1D* j1pt_N40 = (TH1D*)N40->Get("j0_pt");
TH1D* j1eta_N40 = (TH1D*)N40->Get("j0_eta");
TH1D* j2pt_N40 = (TH1D*)N40->Get("j1_pt");
TH1D* j2eta_N40 = (TH1D*)N40->Get("j1_eta");
TH1D* l1pt_N40 = (TH1D*)N40->Get("l0_pt");
TH1D* l1eta_N40 = (TH1D*)N40->Get("l0_eta");
TH1D* l2pt_N40 = (TH1D*)N40->Get("l1_pt");
TH1D* l2eta_N40 = (TH1D*)N40->Get("l1_eta");
TH1D* Nlpt_N40 = (TH1D*)N40->Get("HN_l_pt");
TH1D* Nleta_N40 = (TH1D*)N40->Get("HN_l_eta");
TH1D* Wlpt_N40 = (TH1D*)N40->Get("W_l_pt");
TH1D* Wleta_N40 = (TH1D*)N40->Get("W_l_eta");
TH1D* hardlpt_N40 = (TH1D*)N40->Get("hard_l_pt");
TH1D* hardleta_N40 = (TH1D*)N40->Get("hard_l_eta");
TH1D* hardqpt_N40 = (TH1D*)N40->Get("forward_q_pt");
TH1D* hardqeta_N40 = (TH1D*)N40->Get("forward_q_eta");
TH1D* Nq1pt_N40 = (TH1D*)N40->Get("N_q0_pt");
TH1D* Nq1eta_N40 = (TH1D*)N40->Get("N_q0_eta");
TH1D* Nq2pt_N40 = (TH1D*)N40->Get("N_q1_pt");
TH1D* Nq2eta_N40 = (TH1D*)N40->Get("N_q1_eta");
TH1D* dRqq_N40 = (TH1D*)N40->Get("DeltaR(qq)");
TH1D* MET_N40 = (TH1D*)N40->Get("MET_pt");
TH1D* mjj_N40 = (TH1D*)N40->Get("dijet_m");
TH1D* mJ_N40 = (TH1D*)N40->Get("fatjet_m");
TH1D* mllJ_N40 = (TH1D*)N40->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N40 = (TH1D*)N40->Get("(l0+fatjet)_m");
TH1D* ml2J_N40 = (TH1D*)N40->Get("(l1+fatjet)_m");
TH1D* Jpt_N40 = (TH1D*)N40->Get("fatjet_pt");
TH1D* Jeta_N40 = (TH1D*)N40->Get("fatjet_eta");
TH1D* mWoff_N40 = (TH1D*)N40->Get("offshell_W_m");



TH1D* mlljj_N50 = (TH1D*)N50->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N50 = (TH1D*)N50->Get("(l0+dijet)_m");
TH1D* ml2jj_N50 = (TH1D*)N50->Get("(l1+dijet)_m");
TH1D* dRjj_N50 = (TH1D*)N50->Get("DeltaR(jj)");
TH1D* Npt_N50 = (TH1D*)N50->Get("last_HN_pt");
TH1D* Neta_N50 = (TH1D*)N50->Get("last_HN_eta");
TH1D* Nen_N50 = (TH1D*)N50->Get("last_HN_E");
TH1D* Wpt_N50 = (TH1D*)N50->Get("last_W_pt");
TH1D* Weta_N50 = (TH1D*)N50->Get("last_W_eta");
TH1D* Wen_N50 = (TH1D*)N50->Get("last_W_E");
TH1D* j1pt_N50 = (TH1D*)N50->Get("j0_pt");
TH1D* j1eta_N50 = (TH1D*)N50->Get("j0_eta");
TH1D* j2pt_N50 = (TH1D*)N50->Get("j1_pt");
TH1D* j2eta_N50 = (TH1D*)N50->Get("j1_eta");
TH1D* l1pt_N50 = (TH1D*)N50->Get("l0_pt");
TH1D* l1eta_N50 = (TH1D*)N50->Get("l0_eta");
TH1D* l2pt_N50 = (TH1D*)N50->Get("l1_pt");
TH1D* l2eta_N50 = (TH1D*)N50->Get("l1_eta");
TH1D* Nlpt_N50 = (TH1D*)N50->Get("HN_l_pt");
TH1D* Nleta_N50 = (TH1D*)N50->Get("HN_l_eta");
TH1D* Wlpt_N50 = (TH1D*)N50->Get("W_l_pt");
TH1D* Wleta_N50 = (TH1D*)N50->Get("W_l_eta");
TH1D* hardlpt_N50 = (TH1D*)N50->Get("hard_l_pt");
TH1D* hardleta_N50 = (TH1D*)N50->Get("hard_l_eta");
TH1D* hardqpt_N50 = (TH1D*)N50->Get("forward_q_pt");
TH1D* hardqeta_N50 = (TH1D*)N50->Get("forward_q_eta");
TH1D* Nq1pt_N50 = (TH1D*)N50->Get("N_q0_pt");
TH1D* Nq1eta_N50 = (TH1D*)N50->Get("N_q0_eta");
TH1D* Nq2pt_N50 = (TH1D*)N50->Get("N_q1_pt");
TH1D* Nq2eta_N50 = (TH1D*)N50->Get("N_q1_eta");
TH1D* dRqq_N50 = (TH1D*)N50->Get("DeltaR(qq)");
TH1D* MET_N50 = (TH1D*)N50->Get("MET_pt");
TH1D* mjj_N50 = (TH1D*)N50->Get("dijet_m");
TH1D* mJ_N50 = (TH1D*)N50->Get("fatjet_m");
TH1D* mllJ_N50 = (TH1D*)N50->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N50 = (TH1D*)N50->Get("(l0+fatjet)_m");
TH1D* ml2J_N50 = (TH1D*)N50->Get("(l1+fatjet)_m");
TH1D* Jpt_N50 = (TH1D*)N50->Get("fatjet_pt");
TH1D* Jeta_N50 = (TH1D*)N50->Get("fatjet_eta");
TH1D* mWoff_N50 = (TH1D*)N50->Get("offshell_W_m");



TH1D* mlljj_N60 = (TH1D*)N60->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N60 = (TH1D*)N60->Get("(l0+dijet)_m");
TH1D* ml2jj_N60 = (TH1D*)N60->Get("(l1+dijet)_m");
TH1D* dRjj_N60 = (TH1D*)N60->Get("DeltaR(jj)");
TH1D* Npt_N60 = (TH1D*)N60->Get("last_HN_pt");
TH1D* Neta_N60 = (TH1D*)N60->Get("last_HN_eta");
TH1D* Nen_N60 = (TH1D*)N60->Get("last_HN_E");
TH1D* Wpt_N60 = (TH1D*)N60->Get("last_W_pt");
TH1D* Weta_N60 = (TH1D*)N60->Get("last_W_eta");
TH1D* Wen_N60 = (TH1D*)N60->Get("last_W_E");
TH1D* j1pt_N60 = (TH1D*)N60->Get("j0_pt");
TH1D* j1eta_N60 = (TH1D*)N60->Get("j0_eta");
TH1D* j2pt_N60 = (TH1D*)N60->Get("j1_pt");
TH1D* j2eta_N60 = (TH1D*)N60->Get("j1_eta");
TH1D* l1pt_N60 = (TH1D*)N60->Get("l0_pt");
TH1D* l1eta_N60 = (TH1D*)N60->Get("l0_eta");
TH1D* l2pt_N60 = (TH1D*)N60->Get("l1_pt");
TH1D* l2eta_N60 = (TH1D*)N60->Get("l1_eta");
TH1D* Nlpt_N60 = (TH1D*)N60->Get("HN_l_pt");
TH1D* Nleta_N60 = (TH1D*)N60->Get("HN_l_eta");
TH1D* Wlpt_N60 = (TH1D*)N60->Get("W_l_pt");
TH1D* Wleta_N60 = (TH1D*)N60->Get("W_l_eta");
TH1D* hardlpt_N60 = (TH1D*)N60->Get("hard_l_pt");
TH1D* hardleta_N60 = (TH1D*)N60->Get("hard_l_eta");
TH1D* hardqpt_N60 = (TH1D*)N60->Get("forward_q_pt");
TH1D* hardqeta_N60 = (TH1D*)N60->Get("forward_q_eta");
TH1D* Nq1pt_N60 = (TH1D*)N60->Get("N_q0_pt");
TH1D* Nq1eta_N60 = (TH1D*)N60->Get("N_q0_eta");
TH1D* Nq2pt_N60 = (TH1D*)N60->Get("N_q1_pt");
TH1D* Nq2eta_N60 = (TH1D*)N60->Get("N_q1_eta");
TH1D* dRqq_N60 = (TH1D*)N60->Get("DeltaR(qq)");
TH1D* MET_N60 = (TH1D*)N60->Get("MET_pt");
TH1D* mjj_N60 = (TH1D*)N60->Get("dijet_m");
TH1D* mJ_N60 = (TH1D*)N60->Get("fatjet_m");
TH1D* mllJ_N60 = (TH1D*)N60->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N60 = (TH1D*)N60->Get("(l0+fatjet)_m");
TH1D* ml2J_N60 = (TH1D*)N60->Get("(l1+fatjet)_m");
TH1D* Jpt_N60 = (TH1D*)N60->Get("fatjet_pt");
TH1D* Jeta_N60 = (TH1D*)N60->Get("fatjet_eta");
TH1D* mWoff_N60 = (TH1D*)N60->Get("offshell_W_m");



TH1D* mlljj_N70 = (TH1D*)N70->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N70 = (TH1D*)N70->Get("(l0+dijet)_m");
TH1D* ml2jj_N70 = (TH1D*)N70->Get("(l1+dijet)_m");
TH1D* dRjj_N70 = (TH1D*)N70->Get("DeltaR(jj)");
TH1D* Npt_N70 = (TH1D*)N70->Get("last_HN_pt");
TH1D* Neta_N70 = (TH1D*)N70->Get("last_HN_eta");
TH1D* Nen_N70 = (TH1D*)N70->Get("last_HN_E");
TH1D* Wpt_N70 = (TH1D*)N70->Get("last_W_pt");
TH1D* Weta_N70 = (TH1D*)N70->Get("last_W_eta");
TH1D* Wen_N70 = (TH1D*)N70->Get("last_W_E");
TH1D* j1pt_N70 = (TH1D*)N70->Get("j0_pt");
TH1D* j1eta_N70 = (TH1D*)N70->Get("j0_eta");
TH1D* j2pt_N70 = (TH1D*)N70->Get("j1_pt");
TH1D* j2eta_N70 = (TH1D*)N70->Get("j1_eta");
TH1D* l1pt_N70 = (TH1D*)N70->Get("l0_pt");
TH1D* l1eta_N70 = (TH1D*)N70->Get("l0_eta");
TH1D* l2pt_N70 = (TH1D*)N70->Get("l1_pt");
TH1D* l2eta_N70 = (TH1D*)N70->Get("l1_eta");
TH1D* Nlpt_N70 = (TH1D*)N70->Get("HN_l_pt");
TH1D* Nleta_N70 = (TH1D*)N70->Get("HN_l_eta");
TH1D* Wlpt_N70 = (TH1D*)N70->Get("W_l_pt");
TH1D* Wleta_N70 = (TH1D*)N70->Get("W_l_eta");
TH1D* hardlpt_N70 = (TH1D*)N70->Get("hard_l_pt");
TH1D* hardleta_N70 = (TH1D*)N70->Get("hard_l_eta");
TH1D* hardqpt_N70 = (TH1D*)N70->Get("forward_q_pt");
TH1D* hardqeta_N70 = (TH1D*)N70->Get("forward_q_eta");
TH1D* Nq1pt_N70 = (TH1D*)N70->Get("N_q0_pt");
TH1D* Nq1eta_N70 = (TH1D*)N70->Get("N_q0_eta");
TH1D* Nq2pt_N70 = (TH1D*)N70->Get("N_q1_pt");
TH1D* Nq2eta_N70 = (TH1D*)N70->Get("N_q1_eta");
TH1D* dRqq_N70 = (TH1D*)N70->Get("DeltaR(qq)");
TH1D* MET_N70 = (TH1D*)N70->Get("MET_pt");
TH1D* mjj_N70 = (TH1D*)N70->Get("dijet_m");
TH1D* mJ_N70 = (TH1D*)N70->Get("fatjet_m");
TH1D* mllJ_N70 = (TH1D*)N70->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N70 = (TH1D*)N70->Get("(l0+fatjet)_m");
TH1D* ml2J_N70 = (TH1D*)N70->Get("(l1+fatjet)_m");
TH1D* Jpt_N70 = (TH1D*)N70->Get("fatjet_pt");
TH1D* Jeta_N70 = (TH1D*)N70->Get("fatjet_eta");
TH1D* mWoff_N70 = (TH1D*)N70->Get("offshell_W_m");



TH1D* mlljj_N75 = (TH1D*)N75->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N75 = (TH1D*)N75->Get("(l0+dijet)_m");
TH1D* ml2jj_N75 = (TH1D*)N75->Get("(l1+dijet)_m");
TH1D* dRjj_N75 = (TH1D*)N75->Get("DeltaR(jj)");
TH1D* Npt_N75 = (TH1D*)N75->Get("last_HN_pt");
TH1D* Neta_N75 = (TH1D*)N75->Get("last_HN_eta");
TH1D* Nen_N75 = (TH1D*)N75->Get("last_HN_E");
TH1D* Wpt_N75 = (TH1D*)N75->Get("last_W_pt");
TH1D* Weta_N75 = (TH1D*)N75->Get("last_W_eta");
TH1D* Wen_N75 = (TH1D*)N75->Get("last_W_E");
TH1D* j1pt_N75 = (TH1D*)N75->Get("j0_pt");
TH1D* j1eta_N75 = (TH1D*)N75->Get("j0_eta");
TH1D* j2pt_N75 = (TH1D*)N75->Get("j1_pt");
TH1D* j2eta_N75 = (TH1D*)N75->Get("j1_eta");
TH1D* l1pt_N75 = (TH1D*)N75->Get("l0_pt");
TH1D* l1eta_N75 = (TH1D*)N75->Get("l0_eta");
TH1D* l2pt_N75 = (TH1D*)N75->Get("l1_pt");
TH1D* l2eta_N75 = (TH1D*)N75->Get("l1_eta");
TH1D* Nlpt_N75 = (TH1D*)N75->Get("HN_l_pt");
TH1D* Nleta_N75 = (TH1D*)N75->Get("HN_l_eta");
TH1D* Wlpt_N75 = (TH1D*)N75->Get("W_l_pt");
TH1D* Wleta_N75 = (TH1D*)N75->Get("W_l_eta");
TH1D* hardlpt_N75 = (TH1D*)N75->Get("hard_l_pt");
TH1D* hardleta_N75 = (TH1D*)N75->Get("hard_l_eta");
TH1D* hardqpt_N75 = (TH1D*)N75->Get("forward_q_pt");
TH1D* hardqeta_N75 = (TH1D*)N75->Get("forward_q_eta");
TH1D* Nq1pt_N75 = (TH1D*)N75->Get("N_q0_pt");
TH1D* Nq1eta_N75 = (TH1D*)N75->Get("N_q0_eta");
TH1D* Nq2pt_N75 = (TH1D*)N75->Get("N_q1_pt");
TH1D* Nq2eta_N75 = (TH1D*)N75->Get("N_q1_eta");
TH1D* dRqq_N75 = (TH1D*)N75->Get("DeltaR(qq)");
TH1D* MET_N75 = (TH1D*)N75->Get("MET_pt");
TH1D* mjj_N75 = (TH1D*)N75->Get("dijet_m");
TH1D* mJ_N75 = (TH1D*)N75->Get("fatjet_m");
TH1D* mllJ_N75 = (TH1D*)N75->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N75 = (TH1D*)N75->Get("(l0+fatjet)_m");
TH1D* ml2J_N75 = (TH1D*)N75->Get("(l1+fatjet)_m");
TH1D* Jpt_N75 = (TH1D*)N75->Get("fatjet_pt");
TH1D* Jeta_N75 = (TH1D*)N75->Get("fatjet_eta");
TH1D* mWoff_N75 = (TH1D*)N75->Get("offshell_W_m");



// TODO : MET distribution (See Fig.57- in AN17-291)
// TODO : dRqq, q0 pt/eta, q1 pt/eta distribution (Fig. 7)
// TODO : fraction of l1 gen-matched to Nl out of total (Fig.5 )
// TODO : pt+eta efficiency


TCanvas* c1=NULL;
TCanvas* c2=NULL;
TCanvas* c3=NULL;
TCanvas* c4=NULL;
TCanvas* c5=NULL;
TCanvas* c6=NULL;
TCanvas* c7=NULL;
TCanvas* c8=NULL;
TCanvas* c9=NULL;
TCanvas* c10=NULL;
TCanvas* c11=NULL;
TCanvas* c12=NULL;
TCanvas* c13=NULL;
TCanvas* c14=NULL;
TCanvas* c15=NULL;
TCanvas* c16=NULL;
TCanvas* c17=NULL;
TCanvas* c18=NULL;
TCanvas* c19=NULL;
TCanvas* c20=NULL;
TCanvas* c21=NULL;
TCanvas* c22=NULL;
TCanvas* c23=NULL;
TCanvas* c24=NULL;
TCanvas* c25=NULL;
TCanvas* c26=NULL;
TCanvas* c27=NULL;
TCanvas* c28=NULL;
c1 = new TCanvas("c1","m(lljj)",200,350,700,650);
c2 = new TCanvas("c2","m(l1jj)",220,330,700,650);
c3 = new TCanvas("c3","m(l2jj)",240,310,700,650);
c4 = new TCanvas("c4","N pt",260,290,700,650);
c5 = new TCanvas("c5","N eta",280,270,700,650);
c6 = new TCanvas("c6","N energy",300,250,700,650);
c7 = new TCanvas("c7","Nl pt",320,230,700,650);
c8 = new TCanvas("c8","Nl pt : NLO",340,210,700,650);
c9 = new TCanvas("c9","Nl eta",360,190,700,650);
c10 = new TCanvas("c10","W pt",380,170,700,650);
c11 = new TCanvas("c11","W eta",400,150,700,650);
c12 = new TCanvas("c12","W energy",420,130,700,650);
c13 = new TCanvas("c13","Wl pt",440,110,700,650);
c14 = new TCanvas("c14","Wl pt : NLO",460,90,700,650);
c15 = new TCanvas("c15","Wl eta",480,70,700,650);
c16 = new TCanvas("c16","j1 pt",250,350,700,650);
c17 = new TCanvas("c17","j1 eta",270,330,700,650);
c18 = new TCanvas("c18","j2 pt",290,310,700,650);
c19 = new TCanvas("c19","j2 eta",310,290,700,650);
c20 = new TCanvas("c20","hard_l pt",330,270,700,650);
c21 = new TCanvas("c21","hard_q pt",350,250,700,650);
c22 = new TCanvas("c22","hard_q eta",370,230,700,650);
c23 = new TCanvas("c23","W_q1 pt",390,210,700,650);
c24 = new TCanvas("c24","W_q1 eta",410,190,700,650);
c25 = new TCanvas("c25","W_q2 pt",430,170,700,650);
c26 = new TCanvas("c26","W_q2 eta",450,150,700,650);
c27 = new TCanvas("c27","dR(jj)",470,130,700,650);
c28 = new TCanvas("c28","dR(qq)",490,110,700,650);


if(c1){
c1->cd();

mlljj_L40->SetTitle("m(lljj) #scale[0.8]{(NLO vs LO) : Low mass}");
mlljj_L40->SetStats(0);
mlljj_L40->Rebin(10);
mlljj_L40->GetXaxis()->SetRangeUser(0,300);
mlljj_L40->GetYaxis()->SetRangeUser(0,30000);
mlljj_L40->SetLineColor(kRed);
mlljj_L40->SetLineWidth(3);
mlljj_L40->SetLineStyle(7);
mlljj_L40->Draw("hist");

//mlljj_L50->Scale((0.1957/Npt_L50->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_L50->Scale(mlljj_L40->GetEntries()/mlljj_L50->GetEntries());
mlljj_L50->Rebin(10);
mlljj_L50->SetLineColor(kOrange+1);
mlljj_L50->SetLineWidth(3);
mlljj_L50->SetLineStyle(7);
mlljj_L50->Draw("same hist");

//mlljj_L60->Scale((0.1096/Npt_L60->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_L60->Scale(mlljj_L40->GetEntries()/mlljj_L60->GetEntries());
mlljj_L60->Rebin(10);
mlljj_L60->SetLineColor(kGreen+1);
mlljj_L60->SetLineWidth(3);
mlljj_L60->SetLineStyle(7);
mlljj_L60->Draw("same hist");

//mlljj_L70->Scale((0.03668/Npt_L70->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_L70->Scale(mlljj_L40->GetEntries()/mlljj_L70->GetEntries());
mlljj_L70->Rebin(10);
mlljj_L70->SetLineColor(kBlue);
mlljj_L70->SetLineWidth(3);
mlljj_L70->SetLineStyle(7);
mlljj_L70->Draw("same hist");

mlljj_N40->SetStats(0);
//mlljj_N40->Scale((0.3098/Npt_N40->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_N40->Scale(mlljj_L40->GetEntries()/mlljj_N40->GetEntries());
mlljj_N40->Rebin(10);
mlljj_N40->SetLineColor(kRed);
mlljj_N40->SetLineWidth(2);
mlljj_N40->Draw("same hist");

//mlljj_N50->Scale((0.2188/Npt_N50->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_N50->Scale(mlljj_L40->GetEntries()/mlljj_N50->GetEntries());
mlljj_N50->Rebin(10);
mlljj_N50->SetLineColor(kOrange+1);
mlljj_N50->SetLineWidth(2);
mlljj_N50->Draw("same hist");

//mlljj_N60->Scale((0.1232/Npt_N60->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_N60->Scale(mlljj_L40->GetEntries()/mlljj_N60->GetEntries());
mlljj_N60->Rebin(10);
mlljj_N60->SetLineColor(kGreen+1);
mlljj_N60->SetLineWidth(2);
mlljj_N60->Draw("same hist");

//mlljj_N70->Scale((0.04192/Npt_N70->GetEntries())*(Npt_L40->GetEntries()/0.2754));
mlljj_N70->Scale(mlljj_L40->GetEntries()/mlljj_N70->GetEntries());
mlljj_N70->Rebin(10);
mlljj_N70->SetLineColor(kBlue);
mlljj_N70->SetLineWidth(2);
mlljj_N70->Draw("same hist");

TLegend* mlljj_legend = new TLegend(0.62,0.7,0.9,0.9);
mlljj_legend->AddEntry(mlljj_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L40,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L50,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L60,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L70,"#scale[0.9]{LO}","l");
mlljj_legend->Draw();
}


if(c2){
c2->cd();

ml1jj_L40->SetTitle("m(l1jj) #scale[0.8]{(NLO vs LO) : Low mass}");
ml1jj_L40->SetStats(0);
ml1jj_L40->Rebin(10);
ml1jj_L40->GetXaxis()->SetRangeUser(0,300);
ml1jj_L40->GetYaxis()->SetRangeUser(0,30000);
ml1jj_L40->SetLineColor(kRed);
ml1jj_L40->SetLineWidth(3);
ml1jj_L40->SetLineStyle(7);
ml1jj_L40->Draw("hist");
ml1jj_L50->Scale(ml1jj_L40->GetEntries()/ml1jj_L50->GetEntries());
ml1jj_L50->Rebin(10);
ml1jj_L50->SetLineColor(kOrange+1);
ml1jj_L50->SetLineWidth(3);
ml1jj_L50->SetLineStyle(7);
ml1jj_L50->Draw("same hist");
ml1jj_L60->Scale(ml1jj_L40->GetEntries()/ml1jj_L60->GetEntries());
ml1jj_L60->Rebin(10);
ml1jj_L60->SetLineColor(kGreen+1);
ml1jj_L60->SetLineWidth(3);
ml1jj_L60->SetLineStyle(7);
ml1jj_L60->Draw("same hist");
ml1jj_L70->Scale(ml1jj_L40->GetEntries()/ml1jj_L70->GetEntries());
ml1jj_L70->Rebin(10);
ml1jj_L70->SetLineColor(kBlue);
ml1jj_L70->SetLineWidth(3);
ml1jj_L70->SetLineStyle(7);
ml1jj_L70->Draw("same hist");
ml1jj_N40->SetStats(0);
ml1jj_N40->Scale(ml1jj_L40->GetEntries()/ml1jj_N40->GetEntries());
ml1jj_N40->Rebin(10);
ml1jj_N40->SetLineColor(kRed);
ml1jj_N40->SetLineWidth(2);
ml1jj_N40->Draw("same hist");
ml1jj_N50->Scale(ml1jj_L40->GetEntries()/ml1jj_N50->GetEntries());
ml1jj_N50->Rebin(10);
ml1jj_N50->SetLineColor(kOrange+1);
ml1jj_N50->SetLineWidth(2);
ml1jj_N50->Draw("same hist");
ml1jj_N60->Scale(ml1jj_L40->GetEntries()/ml1jj_N60->GetEntries());
ml1jj_N60->Rebin(10);
ml1jj_N60->SetLineColor(kGreen+1);
ml1jj_N60->SetLineWidth(2);
ml1jj_N60->Draw("same hist");
ml1jj_N70->Scale(ml1jj_L40->GetEntries()/ml1jj_N70->GetEntries());
ml1jj_N70->Rebin(10);
ml1jj_N70->SetLineColor(kBlue);
ml1jj_N70->SetLineWidth(2);
ml1jj_N70->Draw("same hist");

TLegend* ml1jj_legend = new TLegend(0.62,0.7,0.9,0.9);
ml1jj_legend->AddEntry(ml1jj_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L40,"#scale[0.9]{LO}","l");
ml1jj_legend->AddEntry(ml1jj_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L50,"#scale[0.9]{LO}","l");
ml1jj_legend->AddEntry(ml1jj_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L60,"#scale[0.9]{LO}","l");
ml1jj_legend->AddEntry(ml1jj_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L70,"#scale[0.9]{LO}","l");
ml1jj_legend->Draw();
}


if(c3){
c3->cd();

ml2jj_L40->SetTitle("m(l2jj) #scale[0.8]{(NLO vs LO) : Low mass}");
ml2jj_L40->SetStats(0);
ml2jj_L40->Rebin(10);
ml2jj_L40->GetXaxis()->SetRangeUser(0,300);
ml2jj_L40->GetYaxis()->SetRangeUser(0,30000);
ml2jj_L40->SetLineColor(kRed);
ml2jj_L40->SetLineWidth(3);
ml2jj_L40->SetLineStyle(7);
ml2jj_L40->Draw("hist");
ml2jj_L50->Scale(ml2jj_L40->GetEntries()/ml2jj_L50->GetEntries());
ml2jj_L50->Rebin(10);
ml2jj_L50->SetLineColor(kOrange+1);
ml2jj_L50->SetLineWidth(3);
ml2jj_L50->SetLineStyle(7);
ml2jj_L50->Draw("same hist");
ml2jj_L60->Scale(ml2jj_L40->GetEntries()/ml2jj_L60->GetEntries());
ml2jj_L60->Rebin(10);
ml2jj_L60->SetLineColor(kGreen+1);
ml2jj_L60->SetLineWidth(3);
ml2jj_L60->SetLineStyle(7);
ml2jj_L60->Draw("same hist");
ml2jj_L70->Scale(ml2jj_L40->GetEntries()/ml2jj_L70->GetEntries());
ml2jj_L70->Rebin(10);
ml2jj_L70->SetLineColor(kBlue);
ml2jj_L70->SetLineWidth(3);
ml2jj_L70->SetLineStyle(7);
ml2jj_L70->Draw("same hist");
ml2jj_N40->SetStats(0);
ml2jj_N40->Scale(ml2jj_L40->GetEntries()/ml2jj_N40->GetEntries());
ml2jj_N40->Rebin(10);
ml2jj_N40->SetLineColor(kRed);
ml2jj_N40->SetLineWidth(2);
ml2jj_N40->Draw("same hist");
ml2jj_N50->Scale(ml2jj_L40->GetEntries()/ml2jj_N50->GetEntries());
ml2jj_N50->Rebin(10);
ml2jj_N50->SetLineColor(kOrange+1);
ml2jj_N50->SetLineWidth(2);
ml2jj_N50->Draw("same hist");
ml2jj_N60->Scale(ml2jj_L40->GetEntries()/ml2jj_N60->GetEntries());
ml2jj_N60->Rebin(10);
ml2jj_N60->SetLineColor(kGreen+1);
ml2jj_N60->SetLineWidth(2);
ml2jj_N60->Draw("same hist");
ml2jj_N70->Scale(ml2jj_L40->GetEntries()/ml2jj_N70->GetEntries());
ml2jj_N70->Rebin(10);
ml2jj_N70->SetLineColor(kBlue);
ml2jj_N70->SetLineWidth(2);
ml2jj_N70->Draw("same hist");

TLegend* ml2jj_legend = new TLegend(0.62,0.7,0.9,0.9);
ml2jj_legend->AddEntry(ml2jj_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L40,"#scale[0.9]{LO}","l");
ml2jj_legend->AddEntry(ml2jj_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L50,"#scale[0.9]{LO}","l");
ml2jj_legend->AddEntry(ml2jj_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L60,"#scale[0.9]{LO}","l");
ml2jj_legend->AddEntry(ml2jj_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L70,"#scale[0.9]{LO}","l");
ml2jj_legend->Draw();
}



if(c4){
c4->cd();

Npt_L40->SetTitle("N pt #scale[0.8]{(NLO vs LO) : Low mass}");
Npt_L40->SetStats(0);
Npt_L40->Rebin(2);
Npt_L40->GetXaxis()->SetRangeUser(0,80);
Npt_L40->GetYaxis()->SetRangeUser(0,12000);
Npt_L40->SetLineColor(kRed);
Npt_L40->SetLineWidth(3);
Npt_L40->SetLineStyle(7);
Npt_L40->Draw("hist");
Npt_L50->Scale(Npt_L40->GetEntries()/Npt_L50->GetEntries());
Npt_L50->Rebin(2);
Npt_L50->SetLineColor(kOrange+1);
Npt_L50->SetLineWidth(3);
Npt_L50->SetLineStyle(7);
Npt_L50->Draw("same hist");
Npt_L60->Scale(Npt_L40->GetEntries()/Npt_L60->GetEntries());
Npt_L60->Rebin(2);
Npt_L60->SetLineColor(kGreen+1);
Npt_L60->SetLineWidth(3);
Npt_L60->SetLineStyle(7);
Npt_L60->Draw("same hist");
Npt_L70->Scale(Npt_L40->GetEntries()/Npt_L70->GetEntries());
Npt_L70->Rebin(2);
Npt_L70->SetLineColor(kBlue);
Npt_L70->SetLineWidth(3);
Npt_L70->SetLineStyle(7);
Npt_L70->Draw("same hist");
Npt_N40->SetStats(0);
Npt_N40->Scale(Npt_L40->GetEntries()/Npt_N40->GetEntries());
Npt_N40->Rebin(2);
Npt_N40->SetLineColor(kRed);
Npt_N40->SetLineWidth(2);
Npt_N40->Draw("same hist");
Npt_N50->Scale(Npt_L40->GetEntries()/Npt_N50->GetEntries());
Npt_N50->Rebin(2);
Npt_N50->SetLineColor(kOrange+1);
Npt_N50->SetLineWidth(2);
Npt_N50->Draw("same hist");
Npt_N60->Scale(Npt_L40->GetEntries()/Npt_N60->GetEntries());
Npt_N60->Rebin(2);
Npt_N60->SetLineColor(kGreen+1);
Npt_N60->SetLineWidth(2);
Npt_N60->Draw("same hist");
Npt_N70->Scale(Npt_L40->GetEntries()/Npt_N70->GetEntries());
Npt_N70->Rebin(2);
Npt_N70->SetLineColor(kBlue);
Npt_N70->SetLineWidth(2);
Npt_N70->Draw("same hist");

TLegend* Npt_legend = new TLegend(0.62,0.7,0.9,0.9);
Npt_legend->AddEntry(Npt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Npt_legend->AddEntry(Npt_L40,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry(Npt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Npt_legend->AddEntry(Npt_L50,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry(Npt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Npt_legend->AddEntry(Npt_L60,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry(Npt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Npt_legend->AddEntry(Npt_L70,"#scale[0.9]{LO}","l");
Npt_legend->Draw();
}










if(c5){
c5->cd();

Neta_L40->SetTitle("N eta #scale[0.8]{(NLO vs LO) : Low mass}");
Neta_L40->SetStats(0);
Neta_L40->Rebin(2);
Neta_L40->GetYaxis()->SetRangeUser(0,7000);
Neta_L40->SetLineColor(kRed);
Neta_L40->SetLineWidth(3);
Neta_L40->SetLineStyle(7);
Neta_L40->Draw("hist");
Neta_L50->Scale(Neta_L40->GetEntries()/Neta_L50->GetEntries());
Neta_L50->Rebin(2);
Neta_L50->SetLineColor(kOrange+1);
Neta_L50->SetLineWidth(3);
Neta_L50->SetLineStyle(7);
Neta_L50->Draw("same hist");
Neta_L60->Scale(Neta_L40->GetEntries()/Neta_L60->GetEntries());
Neta_L60->Rebin(2);
Neta_L60->SetLineColor(kGreen+1);
Neta_L60->SetLineWidth(3);
Neta_L60->SetLineStyle(7);
Neta_L60->Draw("same hist");
Neta_L70->Scale(Neta_L40->GetEntries()/Neta_L70->GetEntries());
Neta_L70->Rebin(2);
Neta_L70->SetLineColor(kBlue);
Neta_L70->SetLineWidth(3);
Neta_L70->SetLineStyle(7);
Neta_L70->Draw("same hist");
Neta_N40->SetStats(0);
Neta_N40->Scale(Neta_L40->GetEntries()/Neta_N40->GetEntries());
Neta_N40->Rebin(2);
Neta_N40->SetLineColor(kRed);
Neta_N40->SetLineWidth(2);
Neta_N40->Draw("same hist");
Neta_N50->Scale(Neta_L40->GetEntries()/Neta_N50->GetEntries());
Neta_N50->Rebin(2);
Neta_N50->SetLineColor(kOrange+1);
Neta_N50->SetLineWidth(2);
Neta_N50->Draw("same hist");
Neta_N60->Scale(Neta_L40->GetEntries()/Neta_N60->GetEntries());
Neta_N60->Rebin(2);
Neta_N60->SetLineColor(kGreen+1);
Neta_N60->SetLineWidth(2);
Neta_N60->Draw("same hist");
Neta_N70->Scale(Neta_L40->GetEntries()/Neta_N70->GetEntries());
Neta_N70->Rebin(2);
Neta_N70->SetLineColor(kBlue);
Neta_N70->SetLineWidth(2);
Neta_N70->Draw("same hist");

TLegend* Neta_legend = new TLegend(0.62,0.7,0.9,0.9);
Neta_legend->AddEntry(Neta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Neta_legend->AddEntry(Neta_L40,"#scale[0.9]{LO}","l");
Neta_legend->AddEntry(Neta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Neta_legend->AddEntry(Neta_L50,"#scale[0.9]{LO}","l");
Neta_legend->AddEntry(Neta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Neta_legend->AddEntry(Neta_L60,"#scale[0.9]{LO}","l");
Neta_legend->AddEntry(Neta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Neta_legend->AddEntry(Neta_L70,"#scale[0.9]{LO}","l");
Neta_legend->Draw();
}



if(c6){
c6->cd();

Nen_L40->SetTitle("N energy #scale[0.8]{(NLO vs LO) : Low mass}");
Nen_L40->SetStats(0);
Nen_L40->Rebin(10);
Nen_L40->GetXaxis()->SetRangeUser(0,300);
Nen_L40->GetYaxis()->SetRangeUser(0,14000);
Nen_L40->SetLineColor(kRed);
Nen_L40->SetLineWidth(3);
Nen_L40->SetLineStyle(7);
Nen_L40->Draw("hist");
Nen_L50->Scale(Nen_L40->GetEntries()/Nen_L50->GetEntries());
Nen_L50->Rebin(10);
Nen_L50->SetLineColor(kOrange+1);
Nen_L50->SetLineWidth(3);
Nen_L50->SetLineStyle(7);
Nen_L50->Draw("same hist");
Nen_L60->Scale(Nen_L40->GetEntries()/Nen_L60->GetEntries());
Nen_L60->Rebin(10);
Nen_L60->SetLineColor(kGreen+1);
Nen_L60->SetLineWidth(3);
Nen_L60->SetLineStyle(7);
Nen_L60->Draw("same hist");
Nen_L70->Scale(Nen_L40->GetEntries()/Nen_L70->GetEntries());
Nen_L70->Rebin(10);
Nen_L70->SetLineColor(kBlue);
Nen_L70->SetLineWidth(3);
Nen_L70->SetLineStyle(7);
Nen_L70->Draw("same hist");
Nen_N40->SetStats(0);
Nen_N40->Scale(Nen_L40->GetEntries()/Nen_N40->GetEntries());
Nen_N40->Rebin(10);
Nen_N40->SetLineColor(kRed);
Nen_N40->SetLineWidth(2);
Nen_N40->Draw("same hist");
Nen_N50->Scale(Nen_L40->GetEntries()/Nen_N50->GetEntries());
Nen_N50->Rebin(10);
Nen_N50->SetLineColor(kOrange+1);
Nen_N50->SetLineWidth(2);
Nen_N50->Draw("same hist");
Nen_N60->Scale(Nen_L40->GetEntries()/Nen_N60->GetEntries());
Nen_N60->Rebin(10);
Nen_N60->SetLineColor(kGreen+1);
Nen_N60->SetLineWidth(2);
Nen_N60->Draw("same hist");
Nen_N70->Scale(Nen_L40->GetEntries()/Nen_N70->GetEntries());
Nen_N70->Rebin(10);
Nen_N70->SetLineColor(kBlue);
Nen_N70->SetLineWidth(2);
Nen_N70->Draw("same hist");

TLegend* Nen_legend = new TLegend(0.62,0.7,0.9,0.9);
Nen_legend->AddEntry(Nen_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nen_legend->AddEntry(Nen_L40,"#scale[0.9]{LO}","l");
Nen_legend->AddEntry(Nen_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nen_legend->AddEntry(Nen_L50,"#scale[0.9]{LO}","l");
Nen_legend->AddEntry(Nen_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nen_legend->AddEntry(Nen_L60,"#scale[0.9]{LO}","l");
Nen_legend->AddEntry(Nen_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nen_legend->AddEntry(Nen_L70,"#scale[0.9]{LO}","l");
Nen_legend->Draw();
}






if(c7){
c7->cd();

Nlpt_L40->SetTitle("l_{N} pt #scale[0.8]{(NLO vs LO) : Low mass}");
Nlpt_L40->SetStats(0);
Nlpt_L40->Rebin(2);
Nlpt_L40->GetXaxis()->SetRangeUser(0,50);
//Nlpt_L40->GetYaxis()->SetRangeUser(0,25000);
Nlpt_L40->SetLineColor(kRed);
Nlpt_L40->SetLineWidth(3);
Nlpt_L40->SetLineStyle(7);
Nlpt_L40->Draw("hist");

Nlpt_L50->Scale(Nlpt_L40->GetEntries()/Nlpt_L50->GetEntries());
Nlpt_L50->Rebin(2);
Nlpt_L50->SetLineColor(kOrange+1);
Nlpt_L50->SetLineWidth(3);
Nlpt_L50->SetLineStyle(7);
Nlpt_L50->Draw("same hist");

Nlpt_L60->Scale(Nlpt_L40->GetEntries()/Nlpt_L60->GetEntries());
Nlpt_L60->Rebin(2);
Nlpt_L60->SetLineColor(kGreen+1);
Nlpt_L60->SetLineWidth(3);
Nlpt_L60->SetLineStyle(7);
Nlpt_L60->Draw("same hist");

Nlpt_L70->Scale(Nlpt_L40->GetEntries()/Nlpt_L70->GetEntries());
Nlpt_L70->Rebin(2);
Nlpt_L70->SetLineColor(kBlue);
Nlpt_L70->SetLineWidth(3);
Nlpt_L70->SetLineStyle(7);
Nlpt_L70->Draw("same hist");

Nlpt_N40->SetStats(0);
Nlpt_N40->Scale(Nlpt_L40->GetEntries()/Nlpt_N40->GetEntries());
Nlpt_N40->Rebin(2);
Nlpt_N40->SetLineColor(kRed);
Nlpt_N40->SetLineWidth(2);
Nlpt_N40->Draw("same hist");

Nlpt_N50->Scale(Nlpt_L40->GetEntries()/Nlpt_N50->GetEntries());
Nlpt_N50->Rebin(2);
Nlpt_N50->SetLineColor(kOrange+1);
Nlpt_N50->SetLineWidth(2);
Nlpt_N50->Draw("same hist");

Nlpt_N60->Scale(Nlpt_L40->GetEntries()/Nlpt_N60->GetEntries());
Nlpt_N60->Rebin(2);
Nlpt_N60->SetLineColor(kGreen+1);
Nlpt_N60->SetLineWidth(2);
Nlpt_N60->Draw("same hist");

Nlpt_N70->Scale(Nlpt_L40->GetEntries()/Nlpt_N70->GetEntries());
Nlpt_N70->Rebin(2);
Nlpt_N70->SetLineColor(kBlue);
Nlpt_N70->SetLineWidth(2);
Nlpt_N70->Draw("same hist");

TLegend* Nlpt_legend = new TLegend(0.62,0.7,0.9,0.9);
Nlpt_legend->AddEntry(Nlpt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L40,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry(Nlpt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L50,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry(Nlpt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L60,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry(Nlpt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L70,"#scale[0.9]{LO}","l");
Nlpt_legend->Draw();
}




if(c8){
c8->cd();

TH1D* Nlpt_N40_2 = (TH1D*)Nlpt_N40->Clone();
TH1D* Nlpt_N50_2 = (TH1D*)Nlpt_N50->Clone();
TH1D* Nlpt_N60_2 = (TH1D*)Nlpt_N60->Clone();
TH1D* Nlpt_N70_2 = (TH1D*)Nlpt_N70->Clone();

Nlpt_N40_2->SetTitle("l_{N} pt #scale[0.8]{(NLO) : Low mass}");
Nlpt_N40_2->SetStats(0);
Nlpt_N40_2->GetXaxis()->SetRangeUser(0,50);
Nlpt_N40_2->SetLineColor(kRed);
Nlpt_N40_2->SetLineWidth(2);
Nlpt_N40_2->Draw("hist");
Nlpt_N50_2->Scale(Nlpt_L40->GetEntries()/Nlpt_L50->GetEntries());
Nlpt_N50_2->SetLineColor(kBlue);
Nlpt_N50_2->SetLineWidth(2);
Nlpt_N50_2->Draw("same hist");
Nlpt_N60_2->Scale(Nlpt_L40->GetEntries()/Nlpt_L60->GetEntries());
Nlpt_N60_2->SetLineColor(kGreen+2);
Nlpt_N60_2->SetLineWidth(2);
Nlpt_N60_2->Draw("same hist");
Nlpt_N70_2->Scale(Nlpt_L40->GetEntries()/Nlpt_L70->GetEntries());
Nlpt_N70_2->SetLineColor(kCyan);
Nlpt_N70_2->SetLineWidth(2);
Nlpt_N70_2->Draw("same hist");

TLegend* Nlpt_NLO_legend = new TLegend(0.62,0.75,0.9,0.9);
Nlpt_NLO_legend->AddEntry(Nlpt_N40_2,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N50_2,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N60_2,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N70_2,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nlpt_NLO_legend->Draw();
}



if(c9){
c9->cd();

Nleta_L40->SetTitle("l_{N} #eta #scale[0.8]{(NLO vs LO) : Low mass}");
Nleta_L40->SetStats(0);
Nleta_L40->Rebin(2);
Nleta_L40->GetYaxis()->SetRangeUser(0,7200);
Nleta_L40->SetLineColor(kRed);
Nleta_L40->SetLineWidth(3);
Nleta_L40->SetLineStyle(7);
Nleta_L40->Draw("hist");
Nleta_L50->Scale(Nleta_L40->GetEntries()/Nleta_L50->GetEntries());
Nleta_L50->Rebin(2);
Nleta_L50->SetLineColor(kOrange+1);
Nleta_L50->SetLineWidth(3);
Nleta_L50->SetLineStyle(7);
Nleta_L50->Draw("same hist");
Nleta_L60->Scale(Nleta_L40->GetEntries()/Nleta_L60->GetEntries());
Nleta_L60->Rebin(2);
Nleta_L60->SetLineColor(kGreen+1);
Nleta_L60->SetLineWidth(3);
Nleta_L60->SetLineStyle(7);
Nleta_L60->Draw("same hist");
Nleta_L70->Scale(Nleta_L40->GetEntries()/Nleta_L70->GetEntries());
Nleta_L70->Rebin(2);
Nleta_L70->SetLineColor(kBlue);
Nleta_L70->SetLineWidth(3);
Nleta_L70->SetLineStyle(7);
Nleta_L70->Draw("same hist");
Nleta_N40->SetStats(0);
Nleta_N40->Scale(Nleta_L40->GetEntries()/Nleta_N40->GetEntries());
Nleta_N40->Rebin(2);
Nleta_N40->SetLineColor(kRed);
Nleta_N40->SetLineWidth(2);
Nleta_N40->Draw("same hist");
Nleta_N50->Scale(Nleta_L40->GetEntries()/Nleta_N50->GetEntries());
Nleta_N50->Rebin(2);
Nleta_N50->SetLineColor(kOrange+1);
Nleta_N50->SetLineWidth(2);
Nleta_N50->Draw("same hist");
Nleta_N60->Scale(Nleta_L40->GetEntries()/Nleta_N60->GetEntries());
Nleta_N60->Rebin(2);
Nleta_N60->SetLineColor(kGreen+1);
Nleta_N60->SetLineWidth(2);
Nleta_N60->Draw("same hist");
Nleta_N70->Scale(Nleta_L40->GetEntries()/Nleta_N70->GetEntries());
Nleta_N70->Rebin(2);
Nleta_N70->SetLineColor(kBlue);
Nleta_N70->SetLineWidth(2);
Nleta_N70->Draw("same hist");

TLegend* Nleta_legend = new TLegend(0.62,0.7,0.9,0.9);
Nleta_legend->AddEntry(Nleta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L40,"#scale[0.9]{LO}","l");
Nleta_legend->AddEntry(Nleta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L50,"#scale[0.9]{LO}","l");
Nleta_legend->AddEntry(Nleta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L60,"#scale[0.9]{LO}","l");
Nleta_legend->AddEntry(Nleta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L70,"#scale[0.9]{LO}","l");
Nleta_legend->Draw();
}


if(c10){
c10->cd();

Wpt_L40->SetTitle("W pt #scale[0.8]{(NLO vs LO) : Low mass}");
Wpt_L40->SetStats(0);
Wpt_L40->Rebin(2);
Wpt_L40->GetXaxis()->SetRangeUser(0,80);
//Wpt_L40->GetYaxis()->SetRangeUser(0,12000);
Wpt_L40->SetLineColor(kRed);
Wpt_L40->SetLineWidth(3);
Wpt_L40->SetLineStyle(7);
Wpt_L40->Draw("hist");
Wpt_L50->Scale(Wpt_L40->GetEntries()/Wpt_L50->GetEntries());
Wpt_L50->Rebin(2);
Wpt_L50->SetLineColor(kOrange+1);
Wpt_L50->SetLineWidth(3);
Wpt_L50->SetLineStyle(7);
Wpt_L50->Draw("same hist");
Wpt_L60->Scale(Wpt_L40->GetEntries()/Wpt_L60->GetEntries());
Wpt_L60->Rebin(2);
Wpt_L60->SetLineColor(kGreen+1);
Wpt_L60->SetLineWidth(3);
Wpt_L60->SetLineStyle(7);
Wpt_L60->Draw("same hist");
Wpt_L70->Scale(Wpt_L40->GetEntries()/Wpt_L70->GetEntries());
Wpt_L70->Rebin(2);
Wpt_L70->SetLineColor(kBlue);
Wpt_L70->SetLineWidth(3);
Wpt_L70->SetLineStyle(7);
Wpt_L70->Draw("same hist");
Wpt_N40->SetStats(0);
Wpt_N40->Scale(Wpt_L40->GetEntries()/Wpt_N40->GetEntries());
Wpt_N40->Rebin(2);
Wpt_N40->SetLineColor(kRed);
Wpt_N40->SetLineWidth(2);
Wpt_N40->Draw("same hist");
Wpt_N50->Scale(Wpt_L40->GetEntries()/Wpt_N50->GetEntries());
Wpt_N50->Rebin(2);
Wpt_N50->SetLineColor(kOrange+1);
Wpt_N50->SetLineWidth(2);
Wpt_N50->Draw("same hist");
Wpt_N60->Scale(Wpt_L40->GetEntries()/Wpt_N60->GetEntries());
Wpt_N60->Rebin(2);
Wpt_N60->SetLineColor(kGreen+1);
Wpt_N60->SetLineWidth(2);
Wpt_N60->Draw("same hist");
Wpt_N70->Scale(Wpt_L40->GetEntries()/Wpt_N70->GetEntries());
Wpt_N70->Rebin(2);
Wpt_N70->SetLineColor(kBlue);
Wpt_N70->SetLineWidth(2);
Wpt_N70->Draw("same hist");

TLegend* Wpt_legend = new TLegend(0.62,0.7,0.9,0.9);
Wpt_legend->AddEntry(Wpt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Wpt_legend->AddEntry(Wpt_L40,"#scale[0.9]{LO}","l");
Wpt_legend->AddEntry(Wpt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Wpt_legend->AddEntry(Wpt_L50,"#scale[0.9]{LO}","l");
Wpt_legend->AddEntry(Wpt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Wpt_legend->AddEntry(Wpt_L60,"#scale[0.9]{LO}","l");
Wpt_legend->AddEntry(Wpt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Wpt_legend->AddEntry(Wpt_L70,"#scale[0.9]{LO}","l");
Wpt_legend->Draw();
}





if(c11){
c11->cd();

Weta_L40->SetTitle("W eta #scale[0.8]{(NLO vs LO) : Low mass}");
Weta_L40->SetStats(0);
Weta_L40->Rebin(2);
Weta_L40->GetYaxis()->SetRangeUser(0,6500);
Weta_L40->SetLineColor(kRed);
Weta_L40->SetLineWidth(3);
Weta_L40->SetLineStyle(7);
Weta_L40->Draw("hist");
Weta_L50->Scale(Weta_L40->GetEntries()/Weta_L50->GetEntries());
Weta_L50->Rebin(2);
Weta_L50->SetLineColor(kOrange+1);
Weta_L50->SetLineWidth(3);
Weta_L50->SetLineStyle(7);
Weta_L50->Draw("same hist");
Weta_L60->Scale(Weta_L40->GetEntries()/Weta_L60->GetEntries());
Weta_L60->Rebin(2);
Weta_L60->SetLineColor(kGreen+1);
Weta_L60->SetLineWidth(3);
Weta_L60->SetLineStyle(7);
Weta_L60->Draw("same hist");
Weta_L70->Scale(Weta_L40->GetEntries()/Weta_L70->GetEntries());
Weta_L70->Rebin(2);
Weta_L70->SetLineColor(kBlue);
Weta_L70->SetLineWidth(3);
Weta_L70->SetLineStyle(7);
Weta_L70->Draw("same hist");
Weta_N40->SetStats(0);
Weta_N40->Scale(Weta_L40->GetEntries()/Weta_N40->GetEntries());
Weta_N40->Rebin(2);
Weta_N40->SetLineColor(kRed);
Weta_N40->SetLineWidth(2);
Weta_N40->Draw("same hist");
Weta_N50->Scale(Weta_L40->GetEntries()/Weta_N50->GetEntries());
Weta_N50->Rebin(2);
Weta_N50->SetLineColor(kOrange+1);
Weta_N50->SetLineWidth(2);
Weta_N50->Draw("same hist");
Weta_N60->Scale(Weta_L40->GetEntries()/Weta_N60->GetEntries());
Weta_N60->Rebin(2);
Weta_N60->SetLineColor(kGreen+1);
Weta_N60->SetLineWidth(2);
Weta_N60->Draw("same hist");
Weta_N70->Scale(Weta_L40->GetEntries()/Weta_N70->GetEntries());
Weta_N70->Rebin(2);
Weta_N70->SetLineColor(kBlue);
Weta_N70->SetLineWidth(2);
Weta_N70->Draw("same hist");

TLegend* Weta_legend = new TLegend(0.62,0.7,0.9,0.9);
Weta_legend->AddEntry(Weta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Weta_legend->AddEntry(Weta_L40,"#scale[0.9]{LO}","l");
Weta_legend->AddEntry(Weta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Weta_legend->AddEntry(Weta_L50,"#scale[0.9]{LO}","l");
Weta_legend->AddEntry(Weta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Weta_legend->AddEntry(Weta_L60,"#scale[0.9]{LO}","l");
Weta_legend->AddEntry(Weta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Weta_legend->AddEntry(Weta_L70,"#scale[0.9]{LO}","l");
Weta_legend->Draw();
}


if(c12){
c12->cd();

Wen_L40->SetTitle("W energy #scale[0.8]{(NLO vs LO) : Low mass}");
Wen_L40->SetStats(0);
Wen_L40->Rebin(10);
Wen_L40->GetXaxis()->SetRangeUser(0,300);
//Wen_L40->GetYaxis()->SetRangeUser(0,12000);
Wen_L40->SetLineColor(kRed);
Wen_L40->SetLineWidth(3);
Wen_L40->SetLineStyle(7);
Wen_L40->Draw("hist");
Wen_L50->Scale(Wen_L40->GetEntries()/Wen_L50->GetEntries());
Wen_L50->Rebin(10);
Wen_L50->SetLineColor(kOrange+1);
Wen_L50->SetLineWidth(3);
Wen_L50->SetLineStyle(7);
Wen_L50->Draw("same hist");
Wen_L60->Scale(Wen_L40->GetEntries()/Wen_L60->GetEntries());
Wen_L60->Rebin(10);
Wen_L60->SetLineColor(kGreen+1);
Wen_L60->SetLineWidth(3);
Wen_L60->SetLineStyle(7);
Wen_L60->Draw("same hist");
Wen_L70->Scale(Wen_L40->GetEntries()/Wen_L70->GetEntries());
Wen_L70->Rebin(10);
Wen_L70->SetLineColor(kBlue);
Wen_L70->SetLineWidth(3);
Wen_L70->SetLineStyle(7);
Wen_L70->Draw("same hist");
Wen_N40->SetStats(0);
Wen_N40->Scale(Wen_L40->GetEntries()/Wen_N40->GetEntries());
Wen_N40->Rebin(10);
Wen_N40->SetLineColor(kRed);
Wen_N40->SetLineWidth(2);
Wen_N40->Draw("same hist");
Wen_N50->Scale(Wen_L40->GetEntries()/Wen_N50->GetEntries());
Wen_N50->Rebin(10);
Wen_N50->SetLineColor(kOrange+1);
Wen_N50->SetLineWidth(2);
Wen_N50->Draw("same hist");
Wen_N60->Scale(Wen_L40->GetEntries()/Wen_N60->GetEntries());
Wen_N60->Rebin(10);
Wen_N60->SetLineColor(kGreen+1);
Wen_N60->SetLineWidth(2);
Wen_N60->Draw("same hist");
Wen_N70->Scale(Wen_L40->GetEntries()/Wen_N70->GetEntries());
Wen_N70->Rebin(10);
Wen_N70->SetLineColor(kBlue);
Wen_N70->SetLineWidth(2);
Wen_N70->Draw("same hist");

TLegend* Wen_legend = new TLegend(0.62,0.7,0.9,0.9);
Wen_legend->AddEntry(Wen_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Wen_legend->AddEntry(Wen_L40,"#scale[0.9]{LO}","l");
Wen_legend->AddEntry(Wen_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Wen_legend->AddEntry(Wen_L50,"#scale[0.9]{LO}","l");
Wen_legend->AddEntry(Wen_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Wen_legend->AddEntry(Wen_L60,"#scale[0.9]{LO}","l");
Wen_legend->AddEntry(Wen_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Wen_legend->AddEntry(Wen_L70,"#scale[0.9]{LO}","l");
Wen_legend->Draw();
}





if(c13){
c13->cd();

Wlpt_L40->SetTitle("l_{W} pt #scale[0.8]{(NLO vs LO) : Low mass}");
Wlpt_L40->SetStats(0);
Wlpt_L40->Rebin(2);
Wlpt_L40->GetXaxis()->SetRangeUser(0,80);
Wlpt_L40->GetYaxis()->SetRangeUser(0,30000);
Wlpt_L40->SetLineColor(kRed);
Wlpt_L40->SetLineWidth(3);
Wlpt_L40->SetLineStyle(7);
Wlpt_L40->Draw("hist");
Wlpt_L50->Scale(Wlpt_L40->GetEntries()/Wlpt_L50->GetEntries());
Wlpt_L50->Rebin(2);
Wlpt_L50->SetLineColor(kOrange+1);
Wlpt_L50->SetLineWidth(3);
Wlpt_L50->SetLineStyle(7);
Wlpt_L50->Draw("same hist");
Wlpt_L60->Scale(Wlpt_L40->GetEntries()/Wlpt_L60->GetEntries());
Wlpt_L60->Rebin(2);
Wlpt_L60->SetLineColor(kGreen+1);
Wlpt_L60->SetLineWidth(3);
Wlpt_L60->SetLineStyle(7);
Wlpt_L60->Draw("same hist");
Wlpt_L70->Scale(Wlpt_L40->GetEntries()/Wlpt_L70->GetEntries());
Wlpt_L70->Rebin(2);
Wlpt_L70->SetLineColor(kBlue);
Wlpt_L70->SetLineWidth(3);
Wlpt_L70->SetLineStyle(7);
Wlpt_L70->Draw("same hist");
Wlpt_N40->SetStats(0);
Wlpt_N40->Scale(Wlpt_L40->GetEntries()/Wlpt_N40->GetEntries());
Wlpt_N40->Rebin(2);
Wlpt_N40->SetLineColor(kRed);
Wlpt_N40->SetLineWidth(2);
Wlpt_N40->Draw("same hist");
Wlpt_N50->Scale(Wlpt_L40->GetEntries()/Wlpt_N50->GetEntries());
Wlpt_N50->Rebin(2);
Wlpt_N50->SetLineColor(kOrange+1);
Wlpt_N50->SetLineWidth(2);
Wlpt_N50->Draw("same hist");
Wlpt_N60->Scale(Wlpt_L40->GetEntries()/Wlpt_N60->GetEntries());
Wlpt_N60->Rebin(2);
Wlpt_N60->SetLineColor(kGreen+1);
Wlpt_N60->SetLineWidth(2);
Wlpt_N60->Draw("same hist");
Wlpt_N70->Scale(Wlpt_L40->GetEntries()/Wlpt_N70->GetEntries());
Wlpt_N70->Rebin(2);
Wlpt_N70->SetLineColor(kBlue);
Wlpt_N70->SetLineWidth(2);
Wlpt_N70->Draw("same hist");

TLegend* Wlpt_legend = new TLegend(0.62,0.7,0.9,0.9);
Wlpt_legend->AddEntry(Wlpt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Wlpt_legend->AddEntry(Wlpt_L40,"#scale[0.9]{LO}","l");
Wlpt_legend->AddEntry(Wlpt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Wlpt_legend->AddEntry(Wlpt_L50,"#scale[0.9]{LO}","l");
Wlpt_legend->AddEntry(Wlpt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Wlpt_legend->AddEntry(Wlpt_L60,"#scale[0.9]{LO}","l");
Wlpt_legend->AddEntry(Wlpt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Wlpt_legend->AddEntry(Wlpt_L70,"#scale[0.9]{LO}","l");
Wlpt_legend->Draw();
}


if(c14){
c14->cd();

TH1D* Wlpt_N40_2 = (TH1D*)Wlpt_N40->Clone();
TH1D* Wlpt_N50_2 = (TH1D*)Wlpt_N50->Clone();
TH1D* Wlpt_N60_2 = (TH1D*)Wlpt_N60->Clone();
TH1D* Wlpt_N70_2 = (TH1D*)Wlpt_N70->Clone();

Wlpt_N40_2->SetTitle("l_{W} pt #scale[0.8]{(NLO) : Low mass}");
Wlpt_N40_2->SetStats(0);
Wlpt_N40_2->GetXaxis()->SetRangeUser(0,80);
Wlpt_N40_2->GetYaxis()->SetRangeUser(0,30000);
Wlpt_N40_2->SetLineColor(kRed);
Wlpt_N40_2->SetLineWidth(2);
Wlpt_N40_2->Draw("hist");
Wlpt_N50_2->Scale(Wlpt_L40->GetEntries()/Wlpt_L50->GetEntries());
Wlpt_N50_2->SetLineColor(kBlue);
Wlpt_N50_2->SetLineWidth(2);
Wlpt_N50_2->Draw("same hist");
Wlpt_N60_2->Scale(Wlpt_L40->GetEntries()/Wlpt_L60->GetEntries());
Wlpt_N60_2->SetLineColor(kGreen+2);
Wlpt_N60_2->SetLineWidth(2);
Wlpt_N60_2->Draw("same hist");
Wlpt_N70_2->Scale(Wlpt_L40->GetEntries()/Wlpt_L70->GetEntries());
Wlpt_N70_2->SetLineColor(kCyan);
Wlpt_N70_2->SetLineWidth(2);
Wlpt_N70_2->Draw("same hist");

TLegend* Wlpt_NLO_legend = new TLegend(0.62,0.75,0.9,0.9);
Wlpt_NLO_legend->AddEntry(Wlpt_N40_2,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Wlpt_NLO_legend->AddEntry(Wlpt_N50_2,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Wlpt_NLO_legend->AddEntry(Wlpt_N60_2,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Wlpt_NLO_legend->AddEntry(Wlpt_N70_2,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Wlpt_NLO_legend->Draw();
}



if(c15){
c15->cd();

Wleta_L40->SetTitle("l_{W} #eta #scale[0.8]{(NLO vs LO) : Low mass}");
Wleta_L40->SetStats(0);
Wleta_L40->Rebin(2);
Wleta_L40->GetYaxis()->SetRangeUser(0,7500);
Wleta_L40->SetLineColor(kRed);
Wleta_L40->SetLineWidth(3);
Wleta_L40->SetLineStyle(7);
Wleta_L40->Draw("hist");
Wleta_L50->Scale(Wleta_L40->GetEntries()/Wleta_L50->GetEntries());
Wleta_L50->Rebin(2);
Wleta_L50->SetLineColor(kOrange+1);
Wleta_L50->SetLineWidth(3);
Wleta_L50->SetLineStyle(7);
Wleta_L50->Draw("same hist");
Wleta_L60->Scale(Wleta_L40->GetEntries()/Wleta_L60->GetEntries());
Wleta_L60->Rebin(2);
Wleta_L60->SetLineColor(kGreen+1);
Wleta_L60->SetLineWidth(3);
Wleta_L60->SetLineStyle(7);
Wleta_L60->Draw("same hist");
Wleta_L70->Scale(Wleta_L40->GetEntries()/Wleta_L70->GetEntries());
Wleta_L70->Rebin(2);
Wleta_L70->SetLineColor(kBlue);
Wleta_L70->SetLineWidth(3);
Wleta_L70->SetLineStyle(7);
Wleta_L70->Draw("same hist");
Wleta_N40->SetStats(0);
Wleta_N40->Scale(Wleta_L40->GetEntries()/Wleta_N40->GetEntries());
Wleta_N40->Rebin(2);
Wleta_N40->SetLineColor(kRed);
Wleta_N40->SetLineWidth(2);
Wleta_N40->Draw("same hist");
Wleta_N50->Scale(Wleta_L40->GetEntries()/Wleta_N50->GetEntries());
Wleta_N50->Rebin(2);
Wleta_N50->SetLineColor(kOrange+1);
Wleta_N50->SetLineWidth(2);
Wleta_N50->Draw("same hist");
Wleta_N60->Scale(Wleta_L40->GetEntries()/Wleta_N60->GetEntries());
Wleta_N60->Rebin(2);
Wleta_N60->SetLineColor(kGreen+1);
Wleta_N60->SetLineWidth(2);
Wleta_N60->Draw("same hist");
Wleta_N70->Scale(Wleta_L40->GetEntries()/Wleta_N70->GetEntries());
Wleta_N70->Rebin(2);
Wleta_N70->SetLineColor(kBlue);
Wleta_N70->SetLineWidth(2);
Wleta_N70->Draw("same hist");

TLegend* Wleta_legend = new TLegend(0.62,0.7,0.9,0.9);
Wleta_legend->AddEntry(Wleta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Wleta_legend->AddEntry(Wleta_L40,"#scale[0.9]{LO}","l");
Wleta_legend->AddEntry(Wleta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Wleta_legend->AddEntry(Wleta_L50,"#scale[0.9]{LO}","l");
Wleta_legend->AddEntry(Wleta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Wleta_legend->AddEntry(Wleta_L60,"#scale[0.9]{LO}","l");
Wleta_legend->AddEntry(Wleta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Wleta_legend->AddEntry(Wleta_L70,"#scale[0.9]{LO}","l");
Wleta_legend->Draw();
}



if(c16){
c16->cd();

j1pt_L40->SetTitle("j1 pt #scale[0.8]{(NLO vs LO) : Low mass}");
j1pt_L40->SetStats(0);
j1pt_L40->Rebin(2);
j1pt_L40->GetXaxis()->SetRangeUser(0,80);
//j1pt_L40->GetYaxis()->SetRangeUser(0,30000);
j1pt_L40->SetLineColor(kRed);
j1pt_L40->SetLineWidth(3);
j1pt_L40->SetLineStyle(7);
j1pt_L40->Draw("hist");
j1pt_L50->Scale(j1pt_L40->GetEntries()/j1pt_L50->GetEntries());
j1pt_L50->Rebin(2);
j1pt_L50->SetLineColor(kOrange+1);
j1pt_L50->SetLineWidth(3);
j1pt_L50->SetLineStyle(7);
j1pt_L50->Draw("same hist");
j1pt_L60->Scale(j1pt_L40->GetEntries()/j1pt_L60->GetEntries());
j1pt_L60->Rebin(2);
j1pt_L60->SetLineColor(kGreen+1);
j1pt_L60->SetLineWidth(3);
j1pt_L60->SetLineStyle(7);
j1pt_L60->Draw("same hist");
j1pt_L70->Scale(j1pt_L40->GetEntries()/j1pt_L70->GetEntries());
j1pt_L70->Rebin(2);
j1pt_L70->SetLineColor(kBlue);
j1pt_L70->SetLineWidth(3);
j1pt_L70->SetLineStyle(7);
j1pt_L70->Draw("same hist");
j1pt_N40->SetStats(0);
j1pt_N40->Scale(j1pt_L40->GetEntries()/j1pt_N40->GetEntries());
j1pt_N40->Rebin(2);
j1pt_N40->SetLineColor(kRed);
j1pt_N40->SetLineWidth(2);
j1pt_N40->Draw("same hist");
j1pt_N50->Scale(j1pt_L40->GetEntries()/j1pt_N50->GetEntries());
j1pt_N50->Rebin(2);
j1pt_N50->SetLineColor(kOrange+1);
j1pt_N50->SetLineWidth(2);
j1pt_N50->Draw("same hist");
j1pt_N60->Scale(j1pt_L40->GetEntries()/j1pt_N60->GetEntries());
j1pt_N60->Rebin(2);
j1pt_N60->SetLineColor(kGreen+1);
j1pt_N60->SetLineWidth(2);
j1pt_N60->Draw("same hist");
j1pt_N70->Scale(j1pt_L40->GetEntries()/j1pt_N70->GetEntries());
j1pt_N70->Rebin(2);
j1pt_N70->SetLineColor(kBlue);
j1pt_N70->SetLineWidth(2);
j1pt_N70->Draw("same hist");

TLegend* j1pt_legend = new TLegend(0.62,0.7,0.9,0.9);
j1pt_legend->AddEntry(j1pt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L40,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry(j1pt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L50,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry(j1pt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L60,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry(j1pt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L70,"#scale[0.9]{LO}","l");
j1pt_legend->Draw();
}



if(c17){
c17->cd();

j1eta_L40->SetTitle("j1 #eta #scale[0.8]{(NLO vs LO) : Low mass}");
j1eta_L40->SetStats(0);
j1eta_L40->Rebin(2);
j1eta_L40->GetYaxis()->SetRangeUser(0,7500);
j1eta_L40->SetLineColor(kRed);
j1eta_L40->SetLineWidth(3);
j1eta_L40->SetLineStyle(7);
j1eta_L40->Draw("hist");
j1eta_L50->Scale(j1eta_L40->GetEntries()/j1eta_L50->GetEntries());
j1eta_L50->Rebin(2);
j1eta_L50->SetLineColor(kOrange+1);
j1eta_L50->SetLineWidth(3);
j1eta_L50->SetLineStyle(7);
j1eta_L50->Draw("same hist");
j1eta_L60->Scale(j1eta_L40->GetEntries()/j1eta_L60->GetEntries());
j1eta_L60->Rebin(2);
j1eta_L60->SetLineColor(kGreen+1);
j1eta_L60->SetLineWidth(3);
j1eta_L60->SetLineStyle(7);
j1eta_L60->Draw("same hist");
j1eta_L70->Scale(j1eta_L40->GetEntries()/j1eta_L70->GetEntries());
j1eta_L70->Rebin(2);
j1eta_L70->SetLineColor(kBlue);
j1eta_L70->SetLineWidth(3);
j1eta_L70->SetLineStyle(7);
j1eta_L70->Draw("same hist");
j1eta_N40->SetStats(0);
j1eta_N40->Scale(j1eta_L40->GetEntries()/j1eta_N40->GetEntries());
j1eta_N40->Rebin(2);
j1eta_N40->SetLineColor(kRed);
j1eta_N40->SetLineWidth(2);
j1eta_N40->Draw("same hist");
j1eta_N50->Scale(j1eta_L40->GetEntries()/j1eta_N50->GetEntries());
j1eta_N50->Rebin(2);
j1eta_N50->SetLineColor(kOrange+1);
j1eta_N50->SetLineWidth(2);
j1eta_N50->Draw("same hist");
j1eta_N60->Scale(j1eta_L40->GetEntries()/j1eta_N60->GetEntries());
j1eta_N60->Rebin(2);
j1eta_N60->SetLineColor(kGreen+1);
j1eta_N60->SetLineWidth(2);
j1eta_N60->Draw("same hist");
j1eta_N70->Scale(j1eta_L40->GetEntries()/j1eta_N70->GetEntries());
j1eta_N70->Rebin(2);
j1eta_N70->SetLineColor(kBlue);
j1eta_N70->SetLineWidth(2);
j1eta_N70->Draw("same hist");

TLegend* j1eta_legend = new TLegend(0.62,0.7,0.9,0.9);
j1eta_legend->AddEntry(j1eta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L40,"#scale[0.9]{LO}","l");
j1eta_legend->AddEntry(j1eta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L50,"#scale[0.9]{LO}","l");
j1eta_legend->AddEntry(j1eta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L60,"#scale[0.9]{LO}","l");
j1eta_legend->AddEntry(j1eta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L70,"#scale[0.9]{LO}","l");
j1eta_legend->Draw();
}


if(c18){
c18->cd();

j2pt_L40->SetTitle("j2 pt #scale[0.8]{(NLO vs LO) : Low mass}");
j2pt_L40->SetStats(0);
j2pt_L40->Rebin(2);
j2pt_L40->GetXaxis()->SetRangeUser(0,80);
//j2pt_L40->GetYaxis()->SetRangeUser(0,30000);
j2pt_L40->SetLineColor(kRed);
j2pt_L40->SetLineWidth(3);
j2pt_L40->SetLineStyle(7);
j2pt_L40->Draw("hist");
j2pt_L50->Scale(j2pt_L40->GetEntries()/j2pt_L50->GetEntries());
j2pt_L50->Rebin(2);
j2pt_L50->SetLineColor(kOrange+1);
j2pt_L50->SetLineWidth(3);
j2pt_L50->SetLineStyle(7);
j2pt_L50->Draw("same hist");
j2pt_L60->Scale(j2pt_L40->GetEntries()/j2pt_L60->GetEntries());
j2pt_L60->Rebin(2);
j2pt_L60->SetLineColor(kGreen+1);
j2pt_L60->SetLineWidth(3);
j2pt_L60->SetLineStyle(7);
j2pt_L60->Draw("same hist");
j2pt_L70->Scale(j2pt_L40->GetEntries()/j2pt_L70->GetEntries());
j2pt_L70->Rebin(2);
j2pt_L70->SetLineColor(kBlue);
j2pt_L70->SetLineWidth(3);
j2pt_L70->SetLineStyle(7);
j2pt_L70->Draw("same hist");
j2pt_N40->SetStats(0);
j2pt_N40->Scale(j2pt_L40->GetEntries()/j2pt_N40->GetEntries());
j2pt_N40->Rebin(2);
j2pt_N40->SetLineColor(kRed);
j2pt_N40->SetLineWidth(2);
j2pt_N40->Draw("same hist");
j2pt_N50->Scale(j2pt_L40->GetEntries()/j2pt_N50->GetEntries());
j2pt_N50->Rebin(2);
j2pt_N50->SetLineColor(kOrange+1);
j2pt_N50->SetLineWidth(2);
j2pt_N50->Draw("same hist");
j2pt_N60->Scale(j2pt_L40->GetEntries()/j2pt_N60->GetEntries());
j2pt_N60->Rebin(2);
j2pt_N60->SetLineColor(kGreen+1);
j2pt_N60->SetLineWidth(2);
j2pt_N60->Draw("same hist");
j2pt_N70->Scale(j2pt_L40->GetEntries()/j2pt_N70->GetEntries());
j2pt_N70->Rebin(2);
j2pt_N70->SetLineColor(kBlue);
j2pt_N70->SetLineWidth(2);
j2pt_N70->Draw("same hist");

TLegend* j2pt_legend = new TLegend(0.62,0.7,0.9,0.9);
j2pt_legend->AddEntry(j2pt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L40,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry(j2pt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L50,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry(j2pt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L60,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry(j2pt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L70,"#scale[0.9]{LO}","l");
j2pt_legend->Draw();
}



if(c19){
c19->cd();

j2eta_L40->SetTitle("j2 #eta #scale[0.8]{(NLO vs LO) : Low mass}");
j2eta_L40->SetStats(0);
j2eta_L40->Rebin(2);
j2eta_L40->GetYaxis()->SetRangeUser(0,7500);
j2eta_L40->SetLineColor(kRed);
j2eta_L40->SetLineWidth(3);
j2eta_L40->SetLineStyle(7);
j2eta_L40->Draw("hist");
j2eta_L50->Scale(j2eta_L40->GetEntries()/j2eta_L50->GetEntries());
j2eta_L50->Rebin(2);
j2eta_L50->SetLineColor(kOrange+1);
j2eta_L50->SetLineWidth(3);
j2eta_L50->SetLineStyle(7);
j2eta_L50->Draw("same hist");
j2eta_L60->Scale(j2eta_L40->GetEntries()/j2eta_L60->GetEntries());
j2eta_L60->Rebin(2);
j2eta_L60->SetLineColor(kGreen+1);
j2eta_L60->SetLineWidth(3);
j2eta_L60->SetLineStyle(7);
j2eta_L60->Draw("same hist");
j2eta_L70->Scale(j2eta_L40->GetEntries()/j2eta_L70->GetEntries());
j2eta_L70->Rebin(2);
j2eta_L70->SetLineColor(kBlue);
j2eta_L70->SetLineWidth(3);
j2eta_L70->SetLineStyle(7);
j2eta_L70->Draw("same hist");
j2eta_N40->SetStats(0);
j2eta_N40->Scale(j2eta_L40->GetEntries()/j2eta_N40->GetEntries());
j2eta_N40->Rebin(2);
j2eta_N40->SetLineColor(kRed);
j2eta_N40->SetLineWidth(2);
j2eta_N40->Draw("same hist");
j2eta_N50->Scale(j2eta_L40->GetEntries()/j2eta_N50->GetEntries());
j2eta_N50->Rebin(2);
j2eta_N50->SetLineColor(kOrange+1);
j2eta_N50->SetLineWidth(2);
j2eta_N50->Draw("same hist");
j2eta_N60->Scale(j2eta_L40->GetEntries()/j2eta_N60->GetEntries());
j2eta_N60->Rebin(2);
j2eta_N60->SetLineColor(kGreen+1);
j2eta_N60->SetLineWidth(2);
j2eta_N60->Draw("same hist");
j2eta_N70->Scale(j2eta_L40->GetEntries()/j2eta_N70->GetEntries());
j2eta_N70->Rebin(2);
j2eta_N70->SetLineColor(kBlue);
j2eta_N70->SetLineWidth(2);
j2eta_N70->Draw("same hist");

TLegend* j2eta_legend = new TLegend(0.62,0.7,0.9,0.9);
j2eta_legend->AddEntry(j2eta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L40,"#scale[0.9]{LO}","l");
j2eta_legend->AddEntry(j2eta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L50,"#scale[0.9]{LO}","l");
j2eta_legend->AddEntry(j2eta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L60,"#scale[0.9]{LO}","l");
j2eta_legend->AddEntry(j2eta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L70,"#scale[0.9]{LO}","l");
j2eta_legend->Draw();
}



if(c20){
c20->cd();

hardlpt_L40->SetTitle("hard lepton pt #scale[0.8]{(NLO vs LO) : Low mass}");
hardlpt_L40->SetStats(0);
hardlpt_L40->Rebin(2);
hardlpt_L40->GetXaxis()->SetRangeUser(0,120);
hardlpt_L40->GetYaxis()->SetRangeUser(0,50);
hardlpt_L40->SetLineColor(kRed);
hardlpt_L40->SetLineWidth(3);
hardlpt_L40->SetLineStyle(7);
hardlpt_L40->Draw("hist");
//hardlpt_L50->Scale(hardlpt_L40->GetEntries()/hardlpt_L50->GetEntries());
//hardlpt_L50->Rebin(2);
//hardlpt_L50->SetLineColor(kOrange+1);
//hardlpt_L50->SetLineWidth(3);
//hardlpt_L50->SetLineStyle(7);
//hardlpt_L50->Draw("same hist");
//hardlpt_L60->Scale(hardlpt_L40->GetEntries()/hardlpt_L60->GetEntries());
//hardlpt_L60->Rebin(2);
//hardlpt_L60->SetLineColor(kGreen+1);
//hardlpt_L60->SetLineWidth(3);
//hardlpt_L60->SetLineStyle(7);
//hardlpt_L60->Draw("same hist");
hardlpt_L70->Scale(hardlpt_L40->GetEntries()/hardlpt_L70->GetEntries());
hardlpt_L70->Rebin(2);
hardlpt_L70->SetLineColor(kBlue);
hardlpt_L70->SetLineWidth(3);
hardlpt_L70->SetLineStyle(7);
hardlpt_L70->Draw("same hist");
hardlpt_N40->SetStats(0);
hardlpt_N40->Scale(hardlpt_L40->GetEntries()/hardlpt_N40->GetEntries());
hardlpt_N40->Rebin(2);
hardlpt_N40->SetLineColor(kRed);
hardlpt_N40->SetLineWidth(2);
hardlpt_N40->Draw("same hist");
//hardlpt_N50->Scale(hardlpt_L40->GetEntries()/hardlpt_N50->GetEntries());
//hardlpt_N50->Rebin(2);
//hardlpt_N50->SetLineColor(kOrange+1);
//hardlpt_N50->SetLineWidth(2);
//hardlpt_N50->Draw("same hist");
//hardlpt_N60->Scale(hardlpt_L40->GetEntries()/hardlpt_N60->GetEntries());
//hardlpt_N60->Rebin(2);
//hardlpt_N60->SetLineColor(kGreen+1);
//hardlpt_N60->SetLineWidth(2);
//hardlpt_N60->Draw("same hist");
hardlpt_N70->Scale(hardlpt_L40->GetEntries()/hardlpt_N70->GetEntries());
hardlpt_N70->Rebin(2);
hardlpt_N70->SetLineColor(kBlue);
hardlpt_N70->SetLineWidth(2);
hardlpt_N70->Draw("same hist");

TLegend* hardlpt_legend = new TLegend(0.62,0.7,0.9,0.9);
hardlpt_legend->AddEntry(hardlpt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
hardlpt_legend->AddEntry(hardlpt_L40,"#scale[0.9]{LO}","l");
//hardlpt_legend->AddEntry(hardlpt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
//hardlpt_legend->AddEntry(hardlpt_L50,"#scale[0.9]{LO}","l");
//hardlpt_legend->AddEntry(hardlpt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
//hardlpt_legend->AddEntry(hardlpt_L60,"#scale[0.9]{LO}","l");
hardlpt_legend->AddEntry(hardlpt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
hardlpt_legend->AddEntry(hardlpt_L70,"#scale[0.9]{LO}","l");
hardlpt_legend->Draw();
}



if(c21){
c21->cd();

hardqpt_N40->SetTitle("hard q pt #scale[0.8]{(NLO) : Low mass}");
hardqpt_N40->SetStats(0);
hardqpt_N40->Rebin(2);
hardqpt_N40->GetXaxis()->SetRangeUser(0,120);
//hardqpt_N40->GetYaxis()->SetRangeUser(0,30000);
hardqpt_N40->SetLineColor(kRed);
hardqpt_N40->SetLineWidth(2);
hardqpt_N40->Draw("hist");
hardqpt_N50->Scale(hardqpt_N40->GetEntries()/hardqpt_N50->GetEntries());
hardqpt_N50->Rebin(2);
hardqpt_N50->SetLineColor(kOrange+1);
hardqpt_N50->SetLineWidth(2);
hardqpt_N50->Draw("same hist");
hardqpt_N60->Scale(hardqpt_N40->GetEntries()/hardqpt_N60->GetEntries());
hardqpt_N60->Rebin(2);
hardqpt_N60->SetLineColor(kGreen+1);
hardqpt_N60->SetLineWidth(2);
hardqpt_N60->Draw("same hist");
hardqpt_N70->Scale(hardqpt_N40->GetEntries()/hardqpt_N70->GetEntries());
hardqpt_N70->Rebin(2);
hardqpt_N70->SetLineColor(kBlue);
hardqpt_N70->SetLineWidth(2);
hardqpt_N70->Draw("same hist");

TLegend* hardqpt_legend = new TLegend(0.62,0.7,0.9,0.9);
hardqpt_legend->AddEntry(hardqpt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
hardqpt_legend->AddEntry(hardqpt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
hardqpt_legend->AddEntry(hardqpt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
hardqpt_legend->AddEntry(hardqpt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
hardqpt_legend->Draw();
}


if(c22){
c22->cd();

hardqeta_N40->SetTitle("hard q #eta #scale[0.8]{(NLO) : Low mass}");
hardqeta_N40->SetStats(0);
hardqeta_N40->Rebin(2);
hardqeta_N40->GetYaxis()->SetRangeUser(0,2000);
hardqeta_N40->SetLineColor(kRed);
hardqeta_N40->SetLineWidth(2);
hardqeta_N40->Draw("hist");
hardqeta_N50->Scale(hardqeta_N40->GetEntries()/hardqeta_N50->GetEntries());
hardqeta_N50->Rebin(2);
hardqeta_N50->SetLineColor(kOrange+1);
hardqeta_N50->SetLineWidth(2);
hardqeta_N50->Draw("same hist");
hardqeta_N60->Scale(hardqeta_N40->GetEntries()/hardqeta_N60->GetEntries());
hardqeta_N60->Rebin(2);
hardqeta_N60->SetLineColor(kGreen+1);
hardqeta_N60->SetLineWidth(2);
hardqeta_N60->Draw("same hist");
hardqeta_N70->Scale(hardqeta_N40->GetEntries()/hardqeta_N70->GetEntries());
hardqeta_N70->Rebin(2);
hardqeta_N70->SetLineColor(kBlue);
hardqeta_N70->SetLineWidth(2);
hardqeta_N70->Draw("same hist");

TLegend* hardqeta_legend = new TLegend(0.62,0.7,0.9,0.9);
hardqeta_legend->AddEntry(hardqeta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
hardqeta_legend->AddEntry(hardqeta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
hardqeta_legend->AddEntry(hardqeta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
hardqeta_legend->AddEntry(hardqeta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
hardqeta_legend->Draw();
}



if(c23){
c23->cd();

Nq1pt_L40->SetTitle("W_q1 pt #scale[0.8]{(NLO vs LO) : Low mass}");
Nq1pt_L40->SetStats(0);
Nq1pt_L40->Rebin(2);
Nq1pt_L40->GetXaxis()->SetRangeUser(0,80);
//Nq1pt_L40->GetYaxis()->SetRangeUser(0,30000);
Nq1pt_L40->SetLineColor(kRed);
Nq1pt_L40->SetLineWidth(3);
Nq1pt_L40->SetLineStyle(7);
Nq1pt_L40->Draw("hist");
Nq1pt_L50->Scale(Nq1pt_L40->GetEntries()/Nq1pt_L50->GetEntries());
Nq1pt_L50->Rebin(2);
Nq1pt_L50->SetLineColor(kOrange+1);
Nq1pt_L50->SetLineWidth(3);
Nq1pt_L50->SetLineStyle(7);
Nq1pt_L50->Draw("same hist");
Nq1pt_L60->Scale(Nq1pt_L40->GetEntries()/Nq1pt_L60->GetEntries());
Nq1pt_L60->Rebin(2);
Nq1pt_L60->SetLineColor(kGreen+1);
Nq1pt_L60->SetLineWidth(3);
Nq1pt_L60->SetLineStyle(7);
Nq1pt_L60->Draw("same hist");
Nq1pt_L70->Scale(Nq1pt_L40->GetEntries()/Nq1pt_L70->GetEntries());
Nq1pt_L70->Rebin(2);
Nq1pt_L70->SetLineColor(kBlue);
Nq1pt_L70->SetLineWidth(3);
Nq1pt_L70->SetLineStyle(7);
Nq1pt_L70->Draw("same hist");
Nq1pt_N40->SetStats(0);
Nq1pt_N40->Scale(Nq1pt_L40->GetEntries()/Nq1pt_N40->GetEntries());
Nq1pt_N40->Rebin(2);
Nq1pt_N40->SetLineColor(kRed);
Nq1pt_N40->SetLineWidth(2);
Nq1pt_N40->Draw("same hist");
Nq1pt_N50->Scale(Nq1pt_L40->GetEntries()/Nq1pt_N50->GetEntries());
Nq1pt_N50->Rebin(2);
Nq1pt_N50->SetLineColor(kOrange+1);
Nq1pt_N50->SetLineWidth(2);
Nq1pt_N50->Draw("same hist");
Nq1pt_N60->Scale(Nq1pt_L40->GetEntries()/Nq1pt_N60->GetEntries());
Nq1pt_N60->Rebin(2);
Nq1pt_N60->SetLineColor(kGreen+1);
Nq1pt_N60->SetLineWidth(2);
Nq1pt_N60->Draw("same hist");
Nq1pt_N70->Scale(Nq1pt_L40->GetEntries()/Nq1pt_N70->GetEntries());
Nq1pt_N70->Rebin(2);
Nq1pt_N70->SetLineColor(kBlue);
Nq1pt_N70->SetLineWidth(2);
Nq1pt_N70->Draw("same hist");

TLegend* Nq1pt_legend = new TLegend(0.62,0.7,0.9,0.9);
Nq1pt_legend->AddEntry(Nq1pt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nq1pt_legend->AddEntry(Nq1pt_L40,"#scale[0.9]{LO}","l");
Nq1pt_legend->AddEntry(Nq1pt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nq1pt_legend->AddEntry(Nq1pt_L50,"#scale[0.9]{LO}","l");
Nq1pt_legend->AddEntry(Nq1pt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nq1pt_legend->AddEntry(Nq1pt_L60,"#scale[0.9]{LO}","l");
Nq1pt_legend->AddEntry(Nq1pt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nq1pt_legend->AddEntry(Nq1pt_L70,"#scale[0.9]{LO}","l");
Nq1pt_legend->Draw();
}



if(c24){
c24->cd();

Nq1eta_L40->SetTitle("W_q1 #eta #scale[0.8]{(NLO vs LO) : Low mass}");
Nq1eta_L40->SetStats(0);
Nq1eta_L40->Rebin(2);
Nq1eta_L40->GetYaxis()->SetRangeUser(0,7500);
Nq1eta_L40->SetLineColor(kRed);
Nq1eta_L40->SetLineWidth(3);
Nq1eta_L40->SetLineStyle(7);
Nq1eta_L40->Draw("hist");
Nq1eta_L50->Scale(Nq1eta_L40->GetEntries()/Nq1eta_L50->GetEntries());
Nq1eta_L50->Rebin(2);
Nq1eta_L50->SetLineColor(kOrange+1);
Nq1eta_L50->SetLineWidth(3);
Nq1eta_L50->SetLineStyle(7);
Nq1eta_L50->Draw("same hist");
Nq1eta_L60->Scale(Nq1eta_L40->GetEntries()/Nq1eta_L60->GetEntries());
Nq1eta_L60->Rebin(2);
Nq1eta_L60->SetLineColor(kGreen+1);
Nq1eta_L60->SetLineWidth(3);
Nq1eta_L60->SetLineStyle(7);
Nq1eta_L60->Draw("same hist");
Nq1eta_L70->Scale(Nq1eta_L40->GetEntries()/Nq1eta_L70->GetEntries());
Nq1eta_L70->Rebin(2);
Nq1eta_L70->SetLineColor(kBlue);
Nq1eta_L70->SetLineWidth(3);
Nq1eta_L70->SetLineStyle(7);
Nq1eta_L70->Draw("same hist");
Nq1eta_N40->SetStats(0);
Nq1eta_N40->Scale(Nq1eta_L40->GetEntries()/Nq1eta_N40->GetEntries());
Nq1eta_N40->Rebin(2);
Nq1eta_N40->SetLineColor(kRed);
Nq1eta_N40->SetLineWidth(2);
Nq1eta_N40->Draw("same hist");
Nq1eta_N50->Scale(Nq1eta_L40->GetEntries()/Nq1eta_N50->GetEntries());
Nq1eta_N50->Rebin(2);
Nq1eta_N50->SetLineColor(kOrange+1);
Nq1eta_N50->SetLineWidth(2);
Nq1eta_N50->Draw("same hist");
Nq1eta_N60->Scale(Nq1eta_L40->GetEntries()/Nq1eta_N60->GetEntries());
Nq1eta_N60->Rebin(2);
Nq1eta_N60->SetLineColor(kGreen+1);
Nq1eta_N60->SetLineWidth(2);
Nq1eta_N60->Draw("same hist");
Nq1eta_N70->Scale(Nq1eta_L40->GetEntries()/Nq1eta_N70->GetEntries());
Nq1eta_N70->Rebin(2);
Nq1eta_N70->SetLineColor(kBlue);
Nq1eta_N70->SetLineWidth(2);
Nq1eta_N70->Draw("same hist");

TLegend* Nq1eta_legend = new TLegend(0.62,0.7,0.9,0.9);
Nq1eta_legend->AddEntry(Nq1eta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nq1eta_legend->AddEntry(Nq1eta_L40,"#scale[0.9]{LO}","l");
Nq1eta_legend->AddEntry(Nq1eta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nq1eta_legend->AddEntry(Nq1eta_L50,"#scale[0.9]{LO}","l");
Nq1eta_legend->AddEntry(Nq1eta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nq1eta_legend->AddEntry(Nq1eta_L60,"#scale[0.9]{LO}","l");
Nq1eta_legend->AddEntry(Nq1eta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nq1eta_legend->AddEntry(Nq1eta_L70,"#scale[0.9]{LO}","l");
Nq1eta_legend->Draw();
}


if(c25){
c25->cd();

Nq2pt_L40->SetTitle("W_q2 pt #scale[0.8]{(NLO vs LO) : Low mass}");
Nq2pt_L40->SetStats(0);
Nq2pt_L40->Rebin(2);
Nq2pt_L40->GetXaxis()->SetRangeUser(0,50);
//Nq2pt_L40->GetYaxis()->SetRangeUser(0,30000);
Nq2pt_L40->SetLineColor(kRed);
Nq2pt_L40->SetLineWidth(3);
Nq2pt_L40->SetLineStyle(7);
Nq2pt_L40->Draw("hist");
Nq2pt_L50->Scale(Nq2pt_L40->GetEntries()/Nq2pt_L50->GetEntries());
Nq2pt_L50->Rebin(2);
Nq2pt_L50->SetLineColor(kOrange+1);
Nq2pt_L50->SetLineWidth(3);
Nq2pt_L50->SetLineStyle(7);
Nq2pt_L50->Draw("same hist");
Nq2pt_L60->Scale(Nq2pt_L40->GetEntries()/Nq2pt_L60->GetEntries());
Nq2pt_L60->Rebin(2);
Nq2pt_L60->SetLineColor(kGreen+1);
Nq2pt_L60->SetLineWidth(3);
Nq2pt_L60->SetLineStyle(7);
Nq2pt_L60->Draw("same hist");
Nq2pt_L70->Scale(Nq2pt_L40->GetEntries()/Nq2pt_L70->GetEntries());
Nq2pt_L70->Rebin(2);
Nq2pt_L70->SetLineColor(kBlue);
Nq2pt_L70->SetLineWidth(3);
Nq2pt_L70->SetLineStyle(7);
Nq2pt_L70->Draw("same hist");
Nq2pt_N40->SetStats(0);
Nq2pt_N40->Scale(Nq2pt_L40->GetEntries()/Nq2pt_N40->GetEntries());
Nq2pt_N40->Rebin(2);
Nq2pt_N40->SetLineColor(kRed);
Nq2pt_N40->SetLineWidth(2);
Nq2pt_N40->Draw("same hist");
Nq2pt_N50->Scale(Nq2pt_L40->GetEntries()/Nq2pt_N50->GetEntries());
Nq2pt_N50->Rebin(2);
Nq2pt_N50->SetLineColor(kOrange+1);
Nq2pt_N50->SetLineWidth(2);
Nq2pt_N50->Draw("same hist");
Nq2pt_N60->Scale(Nq2pt_L40->GetEntries()/Nq2pt_N60->GetEntries());
Nq2pt_N60->Rebin(2);
Nq2pt_N60->SetLineColor(kGreen+1);
Nq2pt_N60->SetLineWidth(2);
Nq2pt_N60->Draw("same hist");
Nq2pt_N70->Scale(Nq2pt_L40->GetEntries()/Nq2pt_N70->GetEntries());
Nq2pt_N70->Rebin(2);
Nq2pt_N70->SetLineColor(kBlue);
Nq2pt_N70->SetLineWidth(2);
Nq2pt_N70->Draw("same hist");

TLegend* Nq2pt_legend = new TLegend(0.62,0.7,0.9,0.9);
Nq2pt_legend->AddEntry(Nq2pt_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nq2pt_legend->AddEntry(Nq2pt_L40,"#scale[0.9]{LO}","l");
Nq2pt_legend->AddEntry(Nq2pt_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nq2pt_legend->AddEntry(Nq2pt_L50,"#scale[0.9]{LO}","l");
Nq2pt_legend->AddEntry(Nq2pt_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nq2pt_legend->AddEntry(Nq2pt_L60,"#scale[0.9]{LO}","l");
Nq2pt_legend->AddEntry(Nq2pt_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nq2pt_legend->AddEntry(Nq2pt_L70,"#scale[0.9]{LO}","l");
Nq2pt_legend->Draw();
}



if(c26){
c26->cd();

Nq2eta_L40->SetTitle("W_q2 #eta #scale[0.8]{(NLO vs LO) : Low mass}");
Nq2eta_L40->SetStats(0);
Nq2eta_L40->Rebin(2);
Nq2eta_L40->GetYaxis()->SetRangeUser(0,7500);
Nq2eta_L40->SetLineColor(kRed);
Nq2eta_L40->SetLineWidth(3);
Nq2eta_L40->SetLineStyle(7);
Nq2eta_L40->Draw("hist");
Nq2eta_L50->Scale(Nq2eta_L40->GetEntries()/Nq2eta_L50->GetEntries());
Nq2eta_L50->Rebin(2);
Nq2eta_L50->SetLineColor(kOrange+1);
Nq2eta_L50->SetLineWidth(3);
Nq2eta_L50->SetLineStyle(7);
Nq2eta_L50->Draw("same hist");
Nq2eta_L60->Scale(Nq2eta_L40->GetEntries()/Nq2eta_L60->GetEntries());
Nq2eta_L60->Rebin(2);
Nq2eta_L60->SetLineColor(kGreen+1);
Nq2eta_L60->SetLineWidth(3);
Nq2eta_L60->SetLineStyle(7);
Nq2eta_L60->Draw("same hist");
Nq2eta_L70->Scale(Nq2eta_L40->GetEntries()/Nq2eta_L70->GetEntries());
Nq2eta_L70->Rebin(2);
Nq2eta_L70->SetLineColor(kBlue);
Nq2eta_L70->SetLineWidth(3);
Nq2eta_L70->SetLineStyle(7);
Nq2eta_L70->Draw("same hist");
Nq2eta_N40->SetStats(0);
Nq2eta_N40->Scale(Nq2eta_L40->GetEntries()/Nq2eta_N40->GetEntries());
Nq2eta_N40->Rebin(2);
Nq2eta_N40->SetLineColor(kRed);
Nq2eta_N40->SetLineWidth(2);
Nq2eta_N40->Draw("same hist");
Nq2eta_N50->Scale(Nq2eta_L40->GetEntries()/Nq2eta_N50->GetEntries());
Nq2eta_N50->Rebin(2);
Nq2eta_N50->SetLineColor(kOrange+1);
Nq2eta_N50->SetLineWidth(2);
Nq2eta_N50->Draw("same hist");
Nq2eta_N60->Scale(Nq2eta_L40->GetEntries()/Nq2eta_N60->GetEntries());
Nq2eta_N60->Rebin(2);
Nq2eta_N60->SetLineColor(kGreen+1);
Nq2eta_N60->SetLineWidth(2);
Nq2eta_N60->Draw("same hist");
Nq2eta_N70->Scale(Nq2eta_L40->GetEntries()/Nq2eta_N70->GetEntries());
Nq2eta_N70->Rebin(2);
Nq2eta_N70->SetLineColor(kBlue);
Nq2eta_N70->SetLineWidth(2);
Nq2eta_N70->Draw("same hist");

TLegend* Nq2eta_legend = new TLegend(0.62,0.7,0.9,0.9);
Nq2eta_legend->AddEntry(Nq2eta_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nq2eta_legend->AddEntry(Nq2eta_L40,"#scale[0.9]{LO}","l");
Nq2eta_legend->AddEntry(Nq2eta_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nq2eta_legend->AddEntry(Nq2eta_L50,"#scale[0.9]{LO}","l");
Nq2eta_legend->AddEntry(Nq2eta_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nq2eta_legend->AddEntry(Nq2eta_L60,"#scale[0.9]{LO}","l");
Nq2eta_legend->AddEntry(Nq2eta_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nq2eta_legend->AddEntry(Nq2eta_L70,"#scale[0.9]{LO}","l");
Nq2eta_legend->Draw();
}


if(c27){
c27->cd();

dRjj_L40->SetTitle("dR(jj) #scale[0.8]{(NLO vs LO) : Low mass}");
dRjj_L40->SetStats(0);
dRjj_L40->Rebin(2);
dRjj_L40->GetYaxis()->SetRangeUser(0,14000);
dRjj_L40->SetLineColor(kRed);
dRjj_L40->SetLineWidth(3);
dRjj_L40->SetLineStyle(7);
dRjj_L40->Draw("hist");
dRjj_L50->Scale(dRjj_L40->GetEntries()/dRjj_L50->GetEntries());
dRjj_L50->Rebin(2);
dRjj_L50->SetLineColor(kOrange+1);
dRjj_L50->SetLineWidth(3);
dRjj_L50->SetLineStyle(7);
dRjj_L50->Draw("same hist");
dRjj_L60->Scale(dRjj_L40->GetEntries()/dRjj_L60->GetEntries());
dRjj_L60->Rebin(2);
dRjj_L60->SetLineColor(kGreen+1);
dRjj_L60->SetLineWidth(3);
dRjj_L60->SetLineStyle(7);
dRjj_L60->Draw("same hist");
dRjj_L70->Scale(dRjj_L40->GetEntries()/dRjj_L70->GetEntries());
dRjj_L70->Rebin(2);
dRjj_L70->SetLineColor(kBlue);
dRjj_L70->SetLineWidth(3);
dRjj_L70->SetLineStyle(7);
dRjj_L70->Draw("same hist");
dRjj_N40->SetStats(0);
dRjj_N40->Scale(dRjj_L40->GetEntries()/dRjj_N40->GetEntries());
dRjj_N40->Rebin(2);
dRjj_N40->SetLineColor(kRed);
dRjj_N40->SetLineWidth(2);
dRjj_N40->Draw("same hist");
dRjj_N50->Scale(dRjj_L40->GetEntries()/dRjj_N50->GetEntries());
dRjj_N50->Rebin(2);
dRjj_N50->SetLineColor(kOrange+1);
dRjj_N50->SetLineWidth(2);
dRjj_N50->Draw("same hist");
dRjj_N60->Scale(dRjj_L40->GetEntries()/dRjj_N60->GetEntries());
dRjj_N60->Rebin(2);
dRjj_N60->SetLineColor(kGreen+1);
dRjj_N60->SetLineWidth(2);
dRjj_N60->Draw("same hist");
dRjj_N70->Scale(dRjj_L40->GetEntries()/dRjj_N70->GetEntries());
dRjj_N70->Rebin(2);
dRjj_N70->SetLineColor(kBlue);
dRjj_N70->SetLineWidth(2);
dRjj_N70->Draw("same hist");

TLegend* dRjj_legend = new TLegend(0.62,0.7,0.9,0.9);
dRjj_legend->AddEntry(dRjj_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L40,"#scale[0.9]{LO}","l");
dRjj_legend->AddEntry(dRjj_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L50,"#scale[0.9]{LO}","l");
dRjj_legend->AddEntry(dRjj_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L60,"#scale[0.9]{LO}","l");
dRjj_legend->AddEntry(dRjj_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L70,"#scale[0.9]{LO}","l");
dRjj_legend->Draw();
}


if(c28){
c28->cd();

dRqq_L40->SetTitle("dR(qq) #scale[0.8]{(NLO vs LO) : Low mass}");
dRqq_L40->SetStats(0);
dRqq_L40->Rebin(2);
dRqq_L40->GetYaxis()->SetRangeUser(0,14000);
dRqq_L40->SetLineColor(kRed);
dRqq_L40->SetLineWidth(3);
dRqq_L40->SetLineStyle(7);
dRqq_L40->Draw("hist");
dRqq_L50->Scale(dRqq_L40->GetEntries()/dRqq_L50->GetEntries());
dRqq_L50->Rebin(2);
dRqq_L50->SetLineColor(kOrange+1);
dRqq_L50->SetLineWidth(3);
dRqq_L50->SetLineStyle(7);
dRqq_L50->Draw("same hist");
dRqq_L60->Scale(dRqq_L40->GetEntries()/dRqq_L60->GetEntries());
dRqq_L60->Rebin(2);
dRqq_L60->SetLineColor(kGreen+1);
dRqq_L60->SetLineWidth(3);
dRqq_L60->SetLineStyle(7);
dRqq_L60->Draw("same hist");
dRqq_L70->Scale(dRqq_L40->GetEntries()/dRqq_L70->GetEntries());
dRqq_L70->Rebin(2);
dRqq_L70->SetLineColor(kBlue);
dRqq_L70->SetLineWidth(3);
dRqq_L70->SetLineStyle(7);
dRqq_L70->Draw("same hist");
dRqq_N40->SetStats(0);
dRqq_N40->Scale(dRqq_L40->GetEntries()/dRqq_N40->GetEntries());
dRqq_N40->Rebin(2);
dRqq_N40->SetLineColor(kRed);
dRqq_N40->SetLineWidth(2);
dRqq_N40->Draw("same hist");
dRqq_N50->Scale(dRqq_L40->GetEntries()/dRqq_N50->GetEntries());
dRqq_N50->Rebin(2);
dRqq_N50->SetLineColor(kOrange+1);
dRqq_N50->SetLineWidth(2);
dRqq_N50->Draw("same hist");
dRqq_N60->Scale(dRqq_L40->GetEntries()/dRqq_N60->GetEntries());
dRqq_N60->Rebin(2);
dRqq_N60->SetLineColor(kGreen+1);
dRqq_N60->SetLineWidth(2);
dRqq_N60->Draw("same hist");
dRqq_N70->Scale(dRqq_L40->GetEntries()/dRqq_N70->GetEntries());
dRqq_N70->Rebin(2);
dRqq_N70->SetLineColor(kBlue);
dRqq_N70->SetLineWidth(2);
dRqq_N70->Draw("same hist");

TLegend* dRqq_legend = new TLegend(0.62,0.7,0.9,0.9);
dRqq_legend->AddEntry(dRqq_N40,"Sch #mu#mu m_{N}=40GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L40,"#scale[0.9]{LO}","l");
dRqq_legend->AddEntry(dRqq_N50,"Sch #mu#mu m_{N}=50GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L50,"#scale[0.9]{LO}","l");
dRqq_legend->AddEntry(dRqq_N60,"Sch #mu#mu m_{N}=60GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L60,"#scale[0.9]{LO}","l");
dRqq_legend->AddEntry(dRqq_N70,"Sch #mu#mu m_{N}=70GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L70,"#scale[0.9]{LO}","l");
dRqq_legend->Draw();
}


c1->SaveAs("Sch_kinematics/LM/mlljj.png");
c2->SaveAs("Sch_kinematics/LM/ml1jj.png");
c3->SaveAs("Sch_kinematics/LM/ml2jj.png");
c4->SaveAs("Sch_kinematics/LM/N_pt.png");
c5->SaveAs("Sch_kinematics/LM/N_eta.png");
c6->SaveAs("Sch_kinematics/LM/N_energy.png");
c7->SaveAs("Sch_kinematics/LM/Nl_pt.png");
c8->SaveAs("Sch_kinematics/LM/Nl_pt_NLO.png");
c9->SaveAs("Sch_kinematics/LM/Nl_eta.png");
c10->SaveAs("Sch_kinematics/LM/W_pt.png");
c11->SaveAs("Sch_kinematics/LM/W_eta.png");
c12->SaveAs("Sch_kinematics/LM/W_energy.png");
c13->SaveAs("Sch_kinematics/LM/Wl_pt.png");
c14->SaveAs("Sch_kinematics/LM/Wl_pt_NLO.png");
c15->SaveAs("Sch_kinematics/LM/Wl_eta.png");
c16->SaveAs("Sch_kinematics/LM/j1_pt.png");
c17->SaveAs("Sch_kinematics/LM/j1_eta.png");
c18->SaveAs("Sch_kinematics/LM/j2_pt.png");
c19->SaveAs("Sch_kinematics/LM/j2_eta.png");
c20->SaveAs("Sch_kinematics/LM/hard_l_pt.png");
c21->SaveAs("Sch_kinematics/LM/hard_q_pt.png");
c22->SaveAs("Sch_kinematics/LM/hard_q_eta.png");
c23->SaveAs("Sch_kinematics/LM/W_q1_pt.png");
c24->SaveAs("Sch_kinematics/LM/W_q1_eta.png");
c25->SaveAs("Sch_kinematics/LM/W_q2_pt.png");
c26->SaveAs("Sch_kinematics/LM/W_q2_eta.png");
c27->SaveAs("Sch_kinematics/LM/dRjj.png");
c28->SaveAs("Sch_kinematics/LM/dRqq.png");



}
