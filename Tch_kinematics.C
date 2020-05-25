{
TString LO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_MuMu_M300_325100.root";
TString LO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_MuMu_M600_325100.root";
TString LO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_MuMu_M1000_325100.root";
TString LO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_MuMu_M1500_325100.root";
TString LO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_MuMu_M2000_325100.root";
TFile* L300 = new TFile(LO_filename1);
TFile* L600 = new TFile(LO_filename2);
TFile* L1000 = new TFile(LO_filename3);
TFile* L1500 = new TFile(LO_filename4);
TFile* L2000 = new TFile(LO_filename5);
TString NLO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_MuMu_M300_325100.root";
TString NLO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_MuMu_M600_325100.root";
TString NLO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_MuMu_M1000_325100.root";
TString NLO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_MuMu_M1500_325100.root";
TString NLO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_Tch_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_MuMu_M2000_325100.root";
TFile* N300 = new TFile(NLO_filename1);
TFile* N600 = new TFile(NLO_filename2);
TFile* N1000 = new TFile(NLO_filename3);
TFile* N1500 = new TFile(NLO_filename4);
TFile* N2000 = new TFile(NLO_filename5);


gSystem->Exec("mkdir -p Tch_kinematics");


//========================LO========================//


TH1D* mlljj_L300 = (TH1D*)L300->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L300 = (TH1D*)L300->Get("(l0+dijet)_m");
TH1D* ml2jj_L300 = (TH1D*)L300->Get("(l1+dijet)_m");
TH1D* dRjj_L300 = (TH1D*)L300->Get("DeltaR(jj)");
TH1D* Npt_L300 = (TH1D*)L300->Get("last_HN_pt");
TH1D* Neta_L300 = (TH1D*)L300->Get("last_HN_eta");
TH1D* Nen_L300 = (TH1D*)L300->Get("last_HN_E");
TH1D* W1pt_L300 = (TH1D*)L300->Get("W1_pt");
TH1D* W1eta_L300 = (TH1D*)L300->Get("W1_eta");
TH1D* W1en_L300 = (TH1D*)L300->Get("W1_E");
TH1D* W1mass_L300 = (TH1D*)L300->Get("W1_m");
TH1D* W2pt_L300 = (TH1D*)L300->Get("W2_pt");
TH1D* W2eta_L300 = (TH1D*)L300->Get("W2_eta");
TH1D* W2en_L300 = (TH1D*)L300->Get("W2_E");
TH1D* W2mass_L300 = (TH1D*)L300->Get("W2_m");
TH1D* j1pt_L300 = (TH1D*)L300->Get("j0_pt");
TH1D* j1eta_L300 = (TH1D*)L300->Get("j0_eta");
TH1D* j2pt_L300 = (TH1D*)L300->Get("j1_pt");
TH1D* j2eta_L300 = (TH1D*)L300->Get("j1_eta");
TH1D* l1pt_L300 = (TH1D*)L300->Get("l0_pt");
TH1D* l1eta_L300 = (TH1D*)L300->Get("l0_eta");
TH1D* l2pt_L300 = (TH1D*)L300->Get("l1_pt");
TH1D* l2eta_L300 = (TH1D*)L300->Get("l1_eta");
TH1D* Nlpt_L300 = (TH1D*)L300->Get("HN_l_pt");
TH1D* Nleta_L300 = (TH1D*)L300->Get("HN_l_eta");
//TH1D* Wlpt_L300 = (TH1D*)L300->Get("W_l_pt");
//TH1D* Wleta_L300 = (TH1D*)L300->Get("W_l_eta");
TH1D* hardlpt_L300 = (TH1D*)L300->Get("hard_l_pt");
TH1D* hardleta_L300 = (TH1D*)L300->Get("hard_l_eta");
TH1D* hardqpt_L300 = (TH1D*)L300->Get("forward_q1_pt");
TH1D* hardqeta_L300 = (TH1D*)L300->Get("forward_q1_eta");
TH1D* Wq1pt_L300 = (TH1D*)L300->Get("N_q0_pt");
TH1D* Wq1eta_L300 = (TH1D*)L300->Get("N_q0_eta");
TH1D* Wq2pt_L300 = (TH1D*)L300->Get("N_q1_pt");
TH1D* Wq2eta_L300 = (TH1D*)L300->Get("N_q1_eta");
TH1D* dRqq_L300 = (TH1D*)L300->Get("DeltaR(qq)");
TH1D* MET_L300 = (TH1D*)L300->Get("METv_pt");
TH1D* mjj_L300 = (TH1D*)L300->Get("dijet_m");
TH1D* mJ_L300 = (TH1D*)L300->Get("fatjet_m");
TH1D* mllJ_L300 = (TH1D*)L300->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L300 = (TH1D*)L300->Get("(l0+fatjet)_m");
TH1D* ml2J_L300 = (TH1D*)L300->Get("(l1+fatjet)_m");
TH1D* Jpt_L300 = (TH1D*)L300->Get("fatjet_pt");
TH1D* Jeta_L300 = (TH1D*)L300->Get("fatjet_eta");
TH1D* mW_L300 = (TH1D*)L300->Get("W_m");



TH1D* mlljj_L600 = (TH1D*)L600->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L600 = (TH1D*)L600->Get("(l0+dijet)_m");
TH1D* ml2jj_L600 = (TH1D*)L600->Get("(l1+dijet)_m");
TH1D* dRjj_L600 = (TH1D*)L600->Get("DeltaR(jj)");
TH1D* Npt_L600 = (TH1D*)L600->Get("last_HN_pt");
TH1D* Neta_L600 = (TH1D*)L600->Get("last_HN_eta");
TH1D* Nen_L600 = (TH1D*)L600->Get("last_HN_E");
TH1D* W1pt_L600 = (TH1D*)L600->Get("W1_pt");
TH1D* W1eta_L600 = (TH1D*)L600->Get("W1_eta");
TH1D* W1en_L600 = (TH1D*)L600->Get("W1_E");
TH1D* W1mass_L600 = (TH1D*)L600->Get("W1_m");
TH1D* W2pt_L600 = (TH1D*)L600->Get("W2_pt");
TH1D* W2eta_L600 = (TH1D*)L600->Get("W2_eta");
TH1D* W2en_L600 = (TH1D*)L600->Get("W2_E");
TH1D* W2mass_L600 = (TH1D*)L600->Get("W2_m");
TH1D* j1pt_L600 = (TH1D*)L600->Get("j0_pt");
TH1D* j1eta_L600 = (TH1D*)L600->Get("j0_eta");
TH1D* j2pt_L600 = (TH1D*)L600->Get("j1_pt");
TH1D* j2eta_L600 = (TH1D*)L600->Get("j1_eta");
TH1D* l1pt_L600 = (TH1D*)L600->Get("l0_pt");
TH1D* l1eta_L600 = (TH1D*)L600->Get("l0_eta");
TH1D* l2pt_L600 = (TH1D*)L600->Get("l1_pt");
TH1D* l2eta_L600 = (TH1D*)L600->Get("l1_eta");
TH1D* Nlpt_L600 = (TH1D*)L600->Get("HN_l_pt");
TH1D* Nleta_L600 = (TH1D*)L600->Get("HN_l_eta");
//TH1D* Wlpt_L600 = (TH1D*)L600->Get("W_l_pt");
//TH1D* Wleta_L600 = (TH1D*)L600->Get("W_l_eta");
TH1D* hardlpt_L600 = (TH1D*)L600->Get("hard_l_pt");
TH1D* hardleta_L600 = (TH1D*)L600->Get("hard_l_eta");
TH1D* hardqpt_L600 = (TH1D*)L600->Get("forward_q1_pt");
TH1D* hardqeta_L600 = (TH1D*)L600->Get("forward_q1_eta");
TH1D* Wq1pt_L600 = (TH1D*)L600->Get("N_q0_pt");
TH1D* Wq1eta_L600 = (TH1D*)L600->Get("N_q0_eta");
TH1D* Wq2pt_L600 = (TH1D*)L600->Get("N_q1_pt");
TH1D* Wq2eta_L600 = (TH1D*)L600->Get("N_q1_eta");
TH1D* dRqq_L600 = (TH1D*)L600->Get("DeltaR(qq)");
TH1D* MET_L600 = (TH1D*)L600->Get("METv_pt");
TH1D* mjj_L600 = (TH1D*)L600->Get("dijet_m");
TH1D* mJ_L600 = (TH1D*)L600->Get("fatjet_m");
TH1D* mllJ_L600 = (TH1D*)L600->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L600 = (TH1D*)L600->Get("(l0+fatjet)_m");
TH1D* ml2J_L600 = (TH1D*)L600->Get("(l1+fatjet)_m");
TH1D* Jpt_L600 = (TH1D*)L600->Get("fatjet_pt");
TH1D* Jeta_L600 = (TH1D*)L600->Get("fatjet_eta");
TH1D* mW_L600 = (TH1D*)L600->Get("W_m");




TH1D* mlljj_L1000 = (TH1D*)L1000->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L1000 = (TH1D*)L1000->Get("(l0+dijet)_m");
TH1D* ml2jj_L1000 = (TH1D*)L1000->Get("(l1+dijet)_m");
TH1D* dRjj_L1000 = (TH1D*)L1000->Get("DeltaR(jj)");
TH1D* Npt_L1000 = (TH1D*)L1000->Get("last_HN_pt");
TH1D* Neta_L1000 = (TH1D*)L1000->Get("last_HN_eta");
TH1D* Nen_L1000 = (TH1D*)L1000->Get("last_HN_E");
TH1D* W1pt_L1000 = (TH1D*)L1000->Get("W1_pt");
TH1D* W1eta_L1000 = (TH1D*)L1000->Get("W1_eta");
TH1D* W1en_L1000 = (TH1D*)L1000->Get("W1_E");
TH1D* W1mass_L1000 = (TH1D*)L1000->Get("W1_m");
TH1D* W2pt_L1000 = (TH1D*)L1000->Get("W2_pt");
TH1D* W2eta_L1000 = (TH1D*)L1000->Get("W2_eta");
TH1D* W2en_L1000 = (TH1D*)L1000->Get("W2_E");
TH1D* W2mass_L1000 = (TH1D*)L1000->Get("W2_m");
TH1D* j1pt_L1000 = (TH1D*)L1000->Get("j0_pt");
TH1D* j1eta_L1000 = (TH1D*)L1000->Get("j0_eta");
TH1D* j2pt_L1000 = (TH1D*)L1000->Get("j1_pt");
TH1D* j2eta_L1000 = (TH1D*)L1000->Get("j1_eta");
TH1D* l1pt_L1000 = (TH1D*)L1000->Get("l0_pt");
TH1D* l1eta_L1000 = (TH1D*)L1000->Get("l0_eta");
TH1D* l2pt_L1000 = (TH1D*)L1000->Get("l1_pt");
TH1D* l2eta_L1000 = (TH1D*)L1000->Get("l1_eta");
TH1D* Nlpt_L1000 = (TH1D*)L1000->Get("HN_l_pt");
TH1D* Nleta_L1000 = (TH1D*)L1000->Get("HN_l_eta");
//TH1D* Wlpt_L1000 = (TH1D*)L1000->Get("W_l_pt");
//TH1D* Wleta_L1000 = (TH1D*)L1000->Get("W_l_eta");
TH1D* hardlpt_L1000 = (TH1D*)L1000->Get("hard_l_pt");
TH1D* hardleta_L1000 = (TH1D*)L1000->Get("hard_l_eta");
TH1D* hardqpt_L1000 = (TH1D*)L1000->Get("forward_q1_pt");
TH1D* hardqeta_L1000 = (TH1D*)L1000->Get("forward_q1_eta");
TH1D* Wq1pt_L1000 = (TH1D*)L1000->Get("N_q0_pt");
TH1D* Wq1eta_L1000 = (TH1D*)L1000->Get("N_q0_eta");
TH1D* Wq2pt_L1000 = (TH1D*)L1000->Get("N_q1_pt");
TH1D* Wq2eta_L1000 = (TH1D*)L1000->Get("N_q1_eta");
TH1D* dRqq_L1000 = (TH1D*)L1000->Get("DeltaR(qq)");
TH1D* MET_L1000 = (TH1D*)L1000->Get("METv_pt");
TH1D* mjj_L1000 = (TH1D*)L1000->Get("dijet_m");
TH1D* mJ_L1000 = (TH1D*)L1000->Get("fatjet_m");
TH1D* mllJ_L1000 = (TH1D*)L1000->Get("(SS2l+fatjet)_m");
TH1D* ml1J_L1000 = (TH1D*)L1000->Get("(l0+fatjet)_m");
TH1D* ml2J_L1000 = (TH1D*)L1000->Get("(l1+fatjet)_m");
TH1D* Jpt_L1000 = (TH1D*)L1000->Get("fatjet_pt");
TH1D* Jeta_L1000 = (TH1D*)L1000->Get("fatjet_eta");
TH1D* mW_L1000 = (TH1D*)L1000->Get("W_m");


//========================NLO========================//


TH1D* mlljj_N300 = (TH1D*)N300->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N300 = (TH1D*)N300->Get("(l0+dijet)_m");
TH1D* ml2jj_N300 = (TH1D*)N300->Get("(l1+dijet)_m");
TH1D* dRjj_N300 = (TH1D*)N300->Get("DeltaR(jj)");
TH1D* Npt_N300 = (TH1D*)N300->Get("last_HN_pt");
TH1D* Neta_N300 = (TH1D*)N300->Get("last_HN_eta");
TH1D* Nen_N300 = (TH1D*)N300->Get("last_HN_E");
TH1D* W1pt_N300 = (TH1D*)N300->Get("W1_pt");
TH1D* W1eta_N300 = (TH1D*)N300->Get("W1_eta");
TH1D* W1en_N300 = (TH1D*)N300->Get("W1_E");
TH1D* W1mass_N300 = (TH1D*)N300->Get("W1_m");
TH1D* W2pt_N300 = (TH1D*)N300->Get("W2_pt");
TH1D* W2eta_N300 = (TH1D*)N300->Get("W2_eta");
TH1D* W2en_N300 = (TH1D*)N300->Get("W2_E");
TH1D* W2mass_N300 = (TH1D*)N300->Get("W2_m");
TH1D* j1pt_N300 = (TH1D*)N300->Get("j0_pt");
TH1D* j1eta_N300 = (TH1D*)N300->Get("j0_eta");
TH1D* j2pt_N300 = (TH1D*)N300->Get("j1_pt");
TH1D* j2eta_N300 = (TH1D*)N300->Get("j1_eta");
TH1D* l1pt_N300 = (TH1D*)N300->Get("l0_pt");
TH1D* l1eta_N300 = (TH1D*)N300->Get("l0_eta");
TH1D* l2pt_N300 = (TH1D*)N300->Get("l1_pt");
TH1D* l2eta_N300 = (TH1D*)N300->Get("l1_eta");
TH1D* Nlpt_N300 = (TH1D*)N300->Get("HN_l_pt");
TH1D* Nleta_N300 = (TH1D*)N300->Get("HN_l_eta");
//TH1D* Wlpt_N300 = (TH1D*)N300->Get("W_l_pt");
//TH1D* Wleta_N300 = (TH1D*)N300->Get("W_l_eta");
TH1D* hardlpt_N300 = (TH1D*)N300->Get("hard_l_pt");
TH1D* hardleta_N300 = (TH1D*)N300->Get("hard_l_eta");
TH1D* hardqpt_N300 = (TH1D*)N300->Get("forward_q1_pt");
TH1D* hardqeta_N300 = (TH1D*)N300->Get("forward_q1_eta");
TH1D* Wq1pt_N300 = (TH1D*)N300->Get("N_q0_pt");
TH1D* Wq1eta_N300 = (TH1D*)N300->Get("N_q0_eta");
TH1D* Wq2pt_N300 = (TH1D*)N300->Get("N_q1_pt");
TH1D* Wq2eta_N300 = (TH1D*)N300->Get("N_q1_eta");
TH1D* dRqq_N300 = (TH1D*)N300->Get("DeltaR(qq)");
TH1D* MET_N300 = (TH1D*)N300->Get("METv_pt");
TH1D* mjj_N300 = (TH1D*)N300->Get("dijet_m");
TH1D* mJ_N300 = (TH1D*)N300->Get("fatjet_m");
TH1D* mllJ_N300 = (TH1D*)N300->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N300 = (TH1D*)N300->Get("(l0+fatjet)_m");
TH1D* ml2J_N300 = (TH1D*)N300->Get("(l1+fatjet)_m");
TH1D* Jpt_N300 = (TH1D*)N300->Get("fatjet_pt");
TH1D* Jeta_N300 = (TH1D*)N300->Get("fatjet_eta");
TH1D* mW_N300 = (TH1D*)N300->Get("W_m");



TH1D* mlljj_N600 = (TH1D*)N600->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N600 = (TH1D*)N600->Get("(l0+dijet)_m");
TH1D* ml2jj_N600 = (TH1D*)N600->Get("(l1+dijet)_m");
TH1D* dRjj_N600 = (TH1D*)N600->Get("DeltaR(jj)");
TH1D* Npt_N600 = (TH1D*)N600->Get("last_HN_pt");
TH1D* Neta_N600 = (TH1D*)N600->Get("last_HN_eta");
TH1D* Nen_N600 = (TH1D*)N600->Get("last_HN_E");
TH1D* W1pt_N600 = (TH1D*)N600->Get("W1_pt");
TH1D* W1eta_N600 = (TH1D*)N600->Get("W1_eta");
TH1D* W1en_N600 = (TH1D*)N600->Get("W1_E");
TH1D* W1mass_N600 = (TH1D*)N600->Get("W1_m");
TH1D* W2pt_N600 = (TH1D*)N600->Get("W2_pt");
TH1D* W2eta_N600 = (TH1D*)N600->Get("W2_eta");
TH1D* W2en_N600 = (TH1D*)N600->Get("W2_E");
TH1D* W2mass_N600 = (TH1D*)N600->Get("W2_m");
TH1D* j1pt_N600 = (TH1D*)N600->Get("j0_pt");
TH1D* j1eta_N600 = (TH1D*)N600->Get("j0_eta");
TH1D* j2pt_N600 = (TH1D*)N600->Get("j1_pt");
TH1D* j2eta_N600 = (TH1D*)N600->Get("j1_eta");
TH1D* l1pt_N600 = (TH1D*)N600->Get("l0_pt");
TH1D* l1eta_N600 = (TH1D*)N600->Get("l0_eta");
TH1D* l2pt_N600 = (TH1D*)N600->Get("l1_pt");
TH1D* l2eta_N600 = (TH1D*)N600->Get("l1_eta");
TH1D* Nlpt_N600 = (TH1D*)N600->Get("HN_l_pt");
TH1D* Nleta_N600 = (TH1D*)N600->Get("HN_l_eta");
//TH1D* Wlpt_N600 = (TH1D*)N600->Get("W_l_pt");
//TH1D* Wleta_N600 = (TH1D*)N600->Get("W_l_eta");
TH1D* hardlpt_N600 = (TH1D*)N600->Get("hard_l_pt");
TH1D* hardleta_N600 = (TH1D*)N600->Get("hard_l_eta");
TH1D* hardqpt_N600 = (TH1D*)N600->Get("forward_q1_pt");
TH1D* hardqeta_N600 = (TH1D*)N600->Get("forward_q1_eta");
TH1D* Wq1pt_N600 = (TH1D*)N600->Get("N_q0_pt");
TH1D* Wq1eta_N600 = (TH1D*)N600->Get("N_q0_eta");
TH1D* Wq2pt_N600 = (TH1D*)N600->Get("N_q1_pt");
TH1D* Wq2eta_N600 = (TH1D*)N600->Get("N_q1_eta");
TH1D* dRqq_N600 = (TH1D*)N600->Get("DeltaR(qq)");
TH1D* MET_N600 = (TH1D*)N600->Get("METv_pt");
TH1D* mjj_N600 = (TH1D*)N600->Get("dijet_m");
TH1D* mJ_N600 = (TH1D*)N600->Get("fatjet_m");
TH1D* mllJ_N600 = (TH1D*)N600->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N600 = (TH1D*)N600->Get("(l0+fatjet)_m");
TH1D* ml2J_N600 = (TH1D*)N600->Get("(l1+fatjet)_m");
TH1D* Jpt_N600 = (TH1D*)N600->Get("fatjet_pt");
TH1D* Jeta_N600 = (TH1D*)N600->Get("fatjet_eta");
TH1D* mW_N600 = (TH1D*)N600->Get("W_m");



TH1D* mlljj_N1000 = (TH1D*)N1000->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N1000 = (TH1D*)N1000->Get("(l0+dijet)_m");
TH1D* ml2jj_N1000 = (TH1D*)N1000->Get("(l1+dijet)_m");
TH1D* dRjj_N1000 = (TH1D*)N1000->Get("DeltaR(jj)");
TH1D* Npt_N1000 = (TH1D*)N1000->Get("last_HN_pt");
TH1D* Neta_N1000 = (TH1D*)N1000->Get("last_HN_eta");
TH1D* Nen_N1000 = (TH1D*)N1000->Get("last_HN_E");
TH1D* W1pt_N1000 = (TH1D*)N1000->Get("W1_pt");
TH1D* W1eta_N1000 = (TH1D*)N1000->Get("W1_eta");
TH1D* W1en_N1000 = (TH1D*)N1000->Get("W1_E");
TH1D* W1mass_N1000 = (TH1D*)N1000->Get("W1_m");
TH1D* W2pt_N1000 = (TH1D*)N1000->Get("W2_pt");
TH1D* W2eta_N1000 = (TH1D*)N1000->Get("W2_eta");
TH1D* W2en_N1000 = (TH1D*)N1000->Get("W2_E");
TH1D* W2mass_N1000 = (TH1D*)N1000->Get("W2_m");
TH1D* j1pt_N1000 = (TH1D*)N1000->Get("j0_pt");
TH1D* j1eta_N1000 = (TH1D*)N1000->Get("j0_eta");
TH1D* j2pt_N1000 = (TH1D*)N1000->Get("j1_pt");
TH1D* j2eta_N1000 = (TH1D*)N1000->Get("j1_eta");
TH1D* l1pt_N1000 = (TH1D*)N1000->Get("l0_pt");
TH1D* l1eta_N1000 = (TH1D*)N1000->Get("l0_eta");
TH1D* l2pt_N1000 = (TH1D*)N1000->Get("l1_pt");
TH1D* l2eta_N1000 = (TH1D*)N1000->Get("l1_eta");
TH1D* Nlpt_N1000 = (TH1D*)N1000->Get("HN_l_pt");
TH1D* Nleta_N1000 = (TH1D*)N1000->Get("HN_l_eta");
//TH1D* Wlpt_N1000 = (TH1D*)N1000->Get("W_l_pt");
//TH1D* Wleta_N1000 = (TH1D*)N1000->Get("W_l_eta");
TH1D* hardlpt_N1000 = (TH1D*)N1000->Get("hard_l_pt");
TH1D* hardleta_N1000 = (TH1D*)N1000->Get("hard_l_eta");
TH1D* hardqpt_N1000 = (TH1D*)N1000->Get("forward_q1_pt");
TH1D* hardqeta_N1000 = (TH1D*)N1000->Get("forward_q1_eta");
TH1D* Wq1pt_N1000 = (TH1D*)N1000->Get("N_q0_pt");
TH1D* Wq1eta_N1000 = (TH1D*)N1000->Get("N_q0_eta");
TH1D* Wq2pt_N1000 = (TH1D*)N1000->Get("N_q1_pt");
TH1D* Wq2eta_N1000 = (TH1D*)N1000->Get("N_q1_eta");
TH1D* dRqq_N1000 = (TH1D*)N1000->Get("DeltaR(qq)");
TH1D* MET_N1000 = (TH1D*)N1000->Get("METv_pt");
TH1D* mjj_N1000 = (TH1D*)N1000->Get("dijet_m");
TH1D* mJ_N1000 = (TH1D*)N1000->Get("fatjet_m");
TH1D* mllJ_N1000 = (TH1D*)N1000->Get("(SS2l+fatjet)_m");
TH1D* ml1J_N1000 = (TH1D*)N1000->Get("(l0+fatjet)_m");
TH1D* ml2J_N1000 = (TH1D*)N1000->Get("(l1+fatjet)_m");
TH1D* Jpt_N1000 = (TH1D*)N1000->Get("fatjet_pt");
TH1D* Jeta_N1000 = (TH1D*)N1000->Get("fatjet_eta");
TH1D* mW_N1000 = (TH1D*)N1000->Get("W_m");


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
TCanvas* c29=NULL;
TCanvas* c30=NULL;
TCanvas* c31=NULL;
TCanvas* c32=NULL;
TCanvas* c33=NULL;
TCanvas* c34=NULL;
TCanvas* c35=NULL;
TCanvas* c36=NULL;
TCanvas* c37=NULL;
TCanvas* c38=NULL;


//c1 = new TCanvas("c1","m(lljj)",200,350,700,650);
//c2 = new TCanvas("c2","m(l1jj)",220,330,700,650);
//c3 = new TCanvas("c3","m(l2jj)",240,310,700,650);
c4 = new TCanvas("c4","N pt",260,290,700,650);
c5 = new TCanvas("c5","N eta",280,270,700,650);
//c6 = new TCanvas("c6","N energy",300,250,700,650);
c7 = new TCanvas("c7","Nl pt",320,230,700,650);
////c8 = new TCanvas("c8","Nl pt : NLO",340,210,700,650);
c9 = new TCanvas("c9","Nl eta",360,190,700,650);
//c10 = new TCanvas("c10","W1 pt",380,170,700,650);
//c11 = new TCanvas("c11","W1 eta",400,150,700,650);
//c12 = new TCanvas("c12","W1 mass",420,130,700,650);
//c13 = new TCanvas("c13","W1 energy",440,110,700,650);
c14 = new TCanvas("c14","gammal pt",460,90,700,650);
c15 = new TCanvas("c15","gammal eta",480,70,700,650);
c16 = new TCanvas("c16","j1 pt",250,350,700,650);
c17 = new TCanvas("c17","j1 eta",270,330,700,650);
c18 = new TCanvas("c18","j2 pt",290,310,700,650);
c19 = new TCanvas("c19","j2 eta",310,290,700,650);
//c20 = new TCanvas("c20","fatjet pt",330,270,700,650);
//c21 = new TCanvas("c21","fatjet eta",350,250,700,650);
//c22 = new TCanvas("c22","fatjet mass",370,230,700,650);
//c23 = new TCanvas("c23","dijet mass",390,210,700,650);
//c24 = new TCanvas("c24","m(llJ)",410,190,700,650);
//c25 = new TCanvas("c25","m(l1J)",430,170,700,650);
//c26 = new TCanvas("c26","m(l2J)",450,150,700,650);
//c27 = new TCanvas("c27","hard_q pt",470,130,700,650);
//c28 = new TCanvas("c28","hard_q eta",490,110,700,650);
//c29 = new TCanvas("c29","W_q1 pt",510,90,700,650);
//c30 = new TCanvas("c30","W_q1 eta",530,70,700,650);
//c31 = new TCanvas("c31","W_q2 pt",300,350,700,650);
//c32 = new TCanvas("c32","W_q2 eta",320,330,700,650);
//c33 = new TCanvas("c33","dR(jj)",340,310,700,650);
//c34 = new TCanvas("c34","dR(qq)",360,290,700,650);
//c35 = new TCanvas("c35","W2 pt",380,270,700,650);
//c36 = new TCanvas("c36","W2 eta",400,250,700,650);
//c37 = new TCanvas("c37","W2 mass",420,230,700,650);
//c38 = new TCanvas("c38","MET",440,210,700,650);


if(c1){
c1->cd();

mlljj_L300->SetTitle("m(lljj) #scale[0.8]{(NLO vs LO) : High mass}");
mlljj_L300->SetStats(0);
mlljj_L300->Rebin(50);
//mlljj_L300->GetXaxis()->SetRangeUser(0,300);
//mlljj_L300->GetYaxis()->SetRangeUser(0,30000);
mlljj_L300->SetLineColor(kRed);
mlljj_L300->SetLineWidth(3);
mlljj_L300->SetLineStyle(7);
mlljj_L300->Draw("hist");
mlljj_L600->Scale(mlljj_L300->GetEntries()/mlljj_L600->GetEntries());
mlljj_L600->Rebin(50);
mlljj_L600->SetLineColor(kGreen+1);
mlljj_L600->SetLineWidth(3);
mlljj_L600->SetLineStyle(7);
mlljj_L600->Draw("same hist");
mlljj_L1000->Scale(mlljj_L300->GetEntries()/mlljj_L1000->GetEntries());
mlljj_L1000->Rebin(50);
mlljj_L1000->SetLineColor(kBlue);
mlljj_L1000->SetLineWidth(3);
mlljj_L1000->SetLineStyle(7);
mlljj_L1000->Draw("same hist");
mlljj_N300->SetStats(0);
mlljj_N300->Scale(mlljj_L300->GetEntries()/mlljj_N300->GetEntries());
mlljj_N300->Rebin(50);
mlljj_N300->SetLineColor(kRed);
mlljj_N300->SetLineWidth(2);
mlljj_N300->Draw("same hist");
mlljj_N600->Scale(mlljj_L300->GetEntries()/mlljj_N600->GetEntries());
mlljj_N600->Rebin(50);
mlljj_N600->SetLineColor(kGreen+1);
mlljj_N600->SetLineWidth(2);
mlljj_N600->Draw("same hist");
mlljj_N1000->Scale(mlljj_L300->GetEntries()/mlljj_N1000->GetEntries());
mlljj_N1000->Rebin(50);
mlljj_N1000->SetLineColor(kBlue);
mlljj_N1000->SetLineWidth(2);
mlljj_N1000->Draw("same hist");

TLegend* mlljj_legend = new TLegend(0.62,0.75,0.9,0.9);
mlljj_legend->AddEntry(mlljj_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L300,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L600,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L1000,"#scale[0.9]{LO}","l");
mlljj_legend->Draw();
}


if(c2){
c2->cd();

ml1jj_L300->SetTitle("m(l1jj) #scale[0.8]{(NLO vs LO) : High mass}");
ml1jj_L300->SetStats(0);
ml1jj_L300->Rebin(50);
ml1jj_L300->GetXaxis()->SetRangeUser(0,2000);
ml1jj_L300->GetYaxis()->SetRangeUser(0,35000);
ml1jj_L300->SetLineColor(kRed);
ml1jj_L300->SetLineWidth(3);
ml1jj_L300->SetLineStyle(7);
ml1jj_L300->Draw("hist");
ml1jj_L600->Scale(ml1jj_L300->GetEntries()/ml1jj_L600->GetEntries());
ml1jj_L600->Rebin(50);
ml1jj_L600->SetLineColor(kGreen+1);
ml1jj_L600->SetLineWidth(3);
ml1jj_L600->SetLineStyle(7);
ml1jj_L600->Draw("same hist");
ml1jj_L1000->Scale(ml1jj_L300->GetEntries()/ml1jj_L1000->GetEntries());
ml1jj_L1000->Rebin(50);
ml1jj_L1000->SetLineColor(kBlue);
ml1jj_L1000->SetLineWidth(3);
ml1jj_L1000->SetLineStyle(7);
ml1jj_L1000->Draw("same hist");
ml1jj_N300->SetStats(0);
ml1jj_N300->Scale(ml1jj_L300->GetEntries()/ml1jj_N300->GetEntries());
ml1jj_N300->Rebin(50);
ml1jj_N300->SetLineColor(kRed);
ml1jj_N300->SetLineWidth(2);
ml1jj_N300->Draw("same hist");
ml1jj_N600->Scale(ml1jj_L300->GetEntries()/ml1jj_N600->GetEntries());
ml1jj_N600->Rebin(50);
ml1jj_N600->SetLineColor(kGreen+1);
ml1jj_N600->SetLineWidth(2);
ml1jj_N600->Draw("same hist");
ml1jj_N1000->Scale(ml1jj_L300->GetEntries()/ml1jj_N1000->GetEntries());
ml1jj_N1000->Rebin(50);
ml1jj_N1000->SetLineColor(kBlue);
ml1jj_N1000->SetLineWidth(2);
ml1jj_N1000->Draw("same hist");

TLegend* ml1jj_legend = new TLegend(0.62,0.75,0.9,0.9);
ml1jj_legend->AddEntry(ml1jj_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L300,"#scale[0.9]{LO}","l");
ml1jj_legend->AddEntry(ml1jj_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L600,"#scale[0.9]{LO}","l");
ml1jj_legend->AddEntry(ml1jj_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
ml1jj_legend->AddEntry(ml1jj_L1000,"#scale[0.9]{LO}","l");
ml1jj_legend->Draw();
}


if(c3){
c3->cd();

ml2jj_L300->SetTitle("m(l2jj) #scale[0.8]{(NLO vs LO) : High mass}");
ml2jj_L300->SetStats(0);
ml2jj_L300->Rebin(50);
ml2jj_L300->GetXaxis()->SetRangeUser(0,2000);
//ml2jj_L300->GetYaxis()->SetRangeUser(0,30000);
ml2jj_L300->SetLineColor(kRed);
ml2jj_L300->SetLineWidth(3);
ml2jj_L300->SetLineStyle(7);
ml2jj_L300->Draw("hist");
ml2jj_L600->Scale(ml2jj_L300->GetEntries()/ml2jj_L600->GetEntries());
ml2jj_L600->Rebin(50);
ml2jj_L600->SetLineColor(kGreen+1);
ml2jj_L600->SetLineWidth(3);
ml2jj_L600->SetLineStyle(7);
ml2jj_L600->Draw("same hist");
ml2jj_L1000->Scale(ml2jj_L300->GetEntries()/ml2jj_L1000->GetEntries());
ml2jj_L1000->Rebin(50);
ml2jj_L1000->SetLineColor(kBlue);
ml2jj_L1000->SetLineWidth(3);
ml2jj_L1000->SetLineStyle(7);
ml2jj_L1000->Draw("same hist");
ml2jj_N300->SetStats(0);
ml2jj_N300->Scale(ml2jj_L300->GetEntries()/ml2jj_N300->GetEntries());
ml2jj_N300->Rebin(50);
ml2jj_N300->SetLineColor(kRed);
ml2jj_N300->SetLineWidth(2);
ml2jj_N300->Draw("same hist");
ml2jj_N600->Scale(ml2jj_L300->GetEntries()/ml2jj_N600->GetEntries());
ml2jj_N600->Rebin(50);
ml2jj_N600->SetLineColor(kGreen+1);
ml2jj_N600->SetLineWidth(2);
ml2jj_N600->Draw("same hist");
ml2jj_N1000->Scale(ml2jj_L300->GetEntries()/ml2jj_N1000->GetEntries());
ml2jj_N1000->Rebin(50);
ml2jj_N1000->SetLineColor(kBlue);
ml2jj_N1000->SetLineWidth(2);
ml2jj_N1000->Draw("same hist");

TLegend* ml2jj_legend = new TLegend(0.62,0.75,0.9,0.9);
ml2jj_legend->AddEntry(ml2jj_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L300,"#scale[0.9]{LO}","l");
ml2jj_legend->AddEntry(ml2jj_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L600,"#scale[0.9]{LO}","l");
ml2jj_legend->AddEntry(ml2jj_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
ml2jj_legend->AddEntry(ml2jj_L1000,"#scale[0.9]{LO}","l");
ml2jj_legend->Draw();
}



if(c4){
c4->cd();

Npt_L300->SetTitle("N pt #scale[0.8]{(NLO vs LO) : High mass}");
Npt_L300->SetStats(0);
Npt_L300->Rebin(20);
Npt_L300->GetXaxis()->SetRangeUser(0,600);
Npt_L300->GetYaxis()->SetRangeUser(0,16000);
Npt_L300->GetXaxis()->SetTitle("N p_{T} [GeV]");
Npt_L300->SetLineColor(kRed);
Npt_L300->SetLineWidth(3);
Npt_L300->SetLineStyle(7);
Npt_L300->Draw("hist");
Npt_L600->Scale(Npt_L300->GetEntries()/Npt_L600->GetEntries());
Npt_L600->Rebin(20);
Npt_L600->SetLineColor(kGreen+1);
Npt_L600->SetLineWidth(3);
Npt_L600->SetLineStyle(7);
Npt_L600->Draw("same hist");
Npt_L1000->Scale(Npt_L300->GetEntries()/Npt_L1000->GetEntries());
Npt_L1000->Rebin(20);
Npt_L1000->SetLineColor(kBlue);
Npt_L1000->SetLineWidth(3);
Npt_L1000->SetLineStyle(7);
Npt_L1000->Draw("same hist");
Npt_N300->SetStats(0);
Npt_N300->Scale(Npt_L300->GetEntries()/Npt_N300->GetEntries());
Npt_N300->Rebin(20);
Npt_N300->SetLineColor(kRed);
Npt_N300->SetLineWidth(2);
Npt_N300->Draw("same hist");
Npt_N600->Scale(Npt_L300->GetEntries()/Npt_N600->GetEntries());
Npt_N600->Rebin(20);
Npt_N600->SetLineColor(kGreen+1);
Npt_N600->SetLineWidth(2);
Npt_N600->Draw("same hist");
Npt_N1000->Scale(Npt_L300->GetEntries()/Npt_N1000->GetEntries());
Npt_N1000->Rebin(20);
Npt_N1000->SetLineColor(kBlue);
Npt_N1000->SetLineWidth(2);
Npt_N1000->Draw("same hist");

double Nptdiff_300 = 100*(Npt_N300->GetMean()-Npt_L300->GetMean())/Npt_L300->GetMean();
TString Nptdiff_300_t = Form("%f",Nptdiff_300);
double Nptdiff_600 = 100*(Npt_N600->GetMean()-Npt_L600->GetMean())/Npt_L600->GetMean();
TString Nptdiff_600_t = Form("%f",Nptdiff_600);
double Nptdiff_1000 = 100*(Npt_N1000->GetMean()-Npt_L1000->GetMean())/Npt_L1000->GetMean();
TString Nptdiff_1000_t = Form("%f",Nptdiff_1000);
TLegend* Npt_legend = new TLegend(0.62,0.65,0.9,0.9);
Npt_legend->AddEntry(Npt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Npt_legend->AddEntry(Npt_L300,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+Nptdiff_300_t+"%","");
Npt_legend->AddEntry(Npt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Npt_legend->AddEntry(Npt_L600,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry((TObject*)0,"diff : "+Nptdiff_600_t+"%","");
Npt_legend->AddEntry(Npt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Npt_legend->AddEntry(Npt_L1000,"#scale[0.9]{LO}","l");
Npt_legend->AddEntry((TObject*)0,"diff : "+Nptdiff_1000_t+"%","");
Npt_legend->Draw();
}



if(c5){
c5->cd();

Neta_L300->SetTitle("N eta #scale[0.8]{(NLO vs LO) : High mass}");
Neta_L300->SetStats(0);
Neta_L300->Rebin(2);
Neta_L300->GetXaxis()->SetTitle("N #eta");
Neta_L300->GetYaxis()->SetRangeUser(0,10000);
Neta_L300->SetLineColor(kRed);
Neta_L300->SetLineWidth(3);
Neta_L300->SetLineStyle(7);
Neta_L300->Draw("hist");
Neta_L600->Scale(Neta_L300->GetEntries()/Neta_L600->GetEntries());
Neta_L600->Rebin(2);
Neta_L600->SetLineColor(kGreen+1);
Neta_L600->SetLineWidth(3);
Neta_L600->SetLineStyle(7);
Neta_L600->Draw("same hist");
Neta_L1000->Scale(Neta_L300->GetEntries()/Neta_L1000->GetEntries());
Neta_L1000->Rebin(2);
Neta_L1000->SetLineColor(kBlue);
Neta_L1000->SetLineWidth(3);
Neta_L1000->SetLineStyle(7);
Neta_L1000->Draw("same hist");
Neta_N300->SetStats(0);
Neta_N300->Scale(Neta_L300->GetEntries()/Neta_N300->GetEntries());
Neta_N300->Rebin(2);
Neta_N300->SetLineColor(kRed);
Neta_N300->SetLineWidth(2);
Neta_N300->Draw("same hist");
Neta_N600->Scale(Neta_L300->GetEntries()/Neta_N600->GetEntries());
Neta_N600->Rebin(2);
Neta_N600->SetLineColor(kGreen+1);
Neta_N600->SetLineWidth(2);
Neta_N600->Draw("same hist");
Neta_N1000->Scale(Neta_L300->GetEntries()/Neta_N1000->GetEntries());
Neta_N1000->Rebin(2);
Neta_N1000->SetLineColor(kBlue);
Neta_N1000->SetLineWidth(2);
Neta_N1000->Draw("same hist");

TLegend* Neta_legend = new TLegend(0.62,0.75,0.9,0.9);
Neta_legend->AddEntry(Neta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Neta_legend->AddEntry(Neta_L300,"#scale[0.9]{LO}","l");
Neta_legend->AddEntry(Neta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Neta_legend->AddEntry(Neta_L600,"#scale[0.9]{LO}","l");
Neta_legend->AddEntry(Neta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Neta_legend->AddEntry(Neta_L1000,"#scale[0.9]{LO}","l");
Neta_legend->Draw();
}



if(c6){
c6->cd();

Nen_L300->SetTitle("N energy #scale[0.8]{(NLO vs LO) : High mass}");
Nen_L300->SetStats(0);
Nen_L300->Rebin(50);
//Nen_L300->GetXaxis()->SetRangeUser(0,300);
//Nen_L300->GetYaxis()->SetRangeUser(0,14000);
Nen_L300->SetLineColor(kRed);
Nen_L300->SetLineWidth(3);
Nen_L300->SetLineStyle(7);
Nen_L300->Draw("hist");
Nen_L600->Scale(Nen_L300->GetEntries()/Nen_L600->GetEntries());
Nen_L600->Rebin(50);
Nen_L600->SetLineColor(kGreen+1);
Nen_L600->SetLineWidth(3);
Nen_L600->SetLineStyle(7);
Nen_L600->Draw("same hist");
Nen_L1000->Scale(Nen_L300->GetEntries()/Nen_L1000->GetEntries());
Nen_L1000->Rebin(50);
Nen_L1000->SetLineColor(kBlue);
Nen_L1000->SetLineWidth(3);
Nen_L1000->SetLineStyle(7);
Nen_L1000->Draw("same hist");
Nen_N300->SetStats(0);
Nen_N300->Scale(Nen_L300->GetEntries()/Nen_N300->GetEntries());
Nen_N300->Rebin(50);
Nen_N300->SetLineColor(kRed);
Nen_N300->SetLineWidth(2);
Nen_N300->Draw("same hist");
Nen_N600->Scale(Nen_L300->GetEntries()/Nen_N600->GetEntries());
Nen_N600->Rebin(50);
Nen_N600->SetLineColor(kGreen+1);
Nen_N600->SetLineWidth(2);
Nen_N600->Draw("same hist");
Nen_N1000->Scale(Nen_L300->GetEntries()/Nen_N1000->GetEntries());
Nen_N1000->Rebin(50);
Nen_N1000->SetLineColor(kBlue);
Nen_N1000->SetLineWidth(2);
Nen_N1000->Draw("same hist");

TLegend* Nen_legend = new TLegend(0.62,0.75,0.9,0.9);
Nen_legend->AddEntry(Nen_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Nen_legend->AddEntry(Nen_L300,"#scale[0.9]{LO}","l");
Nen_legend->AddEntry(Nen_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Nen_legend->AddEntry(Nen_L600,"#scale[0.9]{LO}","l");
Nen_legend->AddEntry(Nen_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Nen_legend->AddEntry(Nen_L1000,"#scale[0.9]{LO}","l");
Nen_legend->Draw();
}




if(c7){
c7->cd();

Nlpt_L300->SetTitle("l_{N} pt #scale[0.8]{(NLO vs LO) : High mass}");
Nlpt_L300->SetStats(0);
Nlpt_L300->Rebin(20);
Nlpt_L300->GetXaxis()->SetRangeUser(0,800);
//Nlpt_L300->GetYaxis()->SetRangeUser(0,25000);
Nlpt_L300->GetXaxis()->SetTitle("l_{N} p_{T} [GeV]");
Nlpt_L300->SetLineColor(kRed);
Nlpt_L300->SetLineWidth(3);
Nlpt_L300->SetLineStyle(7);
Nlpt_L300->Draw("hist");
Nlpt_L600->Scale(Nlpt_L300->GetEntries()/Nlpt_L600->GetEntries());
Nlpt_L600->Rebin(20);
Nlpt_L600->SetLineColor(kGreen+1);
Nlpt_L600->SetLineWidth(3);
Nlpt_L600->SetLineStyle(7);
Nlpt_L600->Draw("same hist");
Nlpt_L1000->Scale(Nlpt_L300->GetEntries()/Nlpt_L1000->GetEntries());
Nlpt_L1000->Rebin(20);
Nlpt_L1000->SetLineColor(kBlue);
Nlpt_L1000->SetLineWidth(3);
Nlpt_L1000->SetLineStyle(7);
Nlpt_L1000->Draw("same hist");
Nlpt_N300->SetStats(0);
Nlpt_N300->Scale(Nlpt_L300->GetEntries()/Nlpt_N300->GetEntries());
Nlpt_N300->Rebin(20);
Nlpt_N300->SetLineColor(kRed);
Nlpt_N300->SetLineWidth(2);
Nlpt_N300->Draw("same hist");
Nlpt_N600->Scale(Nlpt_L300->GetEntries()/Nlpt_N600->GetEntries());
Nlpt_N600->Rebin(20);
Nlpt_N600->SetLineColor(kGreen+1);
Nlpt_N600->SetLineWidth(2);
Nlpt_N600->Draw("same hist");
Nlpt_N1000->Scale(Nlpt_L300->GetEntries()/Nlpt_N1000->GetEntries());
Nlpt_N1000->Rebin(20);
Nlpt_N1000->SetLineColor(kBlue);
Nlpt_N1000->SetLineWidth(2);
Nlpt_N1000->Draw("same hist");


double Nlptdiff_300 = 100*(Nlpt_N300->GetMean()-Nlpt_L300->GetMean())/Nlpt_L300->GetMean();
TString Nlptdiff_300_t = Form("%f",Nlptdiff_300);
double Nlptdiff_600 = 100*(Nlpt_N600->GetMean()-Nlpt_L600->GetMean())/Nlpt_L600->GetMean();
TString Nlptdiff_600_t = Form("%f",Nlptdiff_600);
double Nlptdiff_1000 = 100*(Nlpt_N1000->GetMean()-Nlpt_L1000->GetMean())/Nlpt_L1000->GetMean();
TString Nlptdiff_1000_t = Form("%f",Nlptdiff_1000);
TLegend* Nlpt_legend = new TLegend(0.62,0.65,0.9,0.9);
Nlpt_legend->AddEntry(Nlpt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L300,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+Nlptdiff_300_t+"%","");
Nlpt_legend->AddEntry(Nlpt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L600,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry((TObject*)0,"diff : "+Nlptdiff_600_t+"%","");
Nlpt_legend->AddEntry(Nlpt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Nlpt_legend->AddEntry(Nlpt_L1000,"#scale[0.9]{LO}","l");
Nlpt_legend->AddEntry((TObject*)0,"diff : "+Nlptdiff_1000_t+"%","");
Nlpt_legend->Draw();
}




if(c8){
c8->cd();

TH1D* Nlpt_N300_2 = (TH1D*)Nlpt_N300->Clone();
TH1D* Nlpt_N600_2 = (TH1D*)Nlpt_N600->Clone();
TH1D* Nlpt_N1000_2 = (TH1D*)Nlpt_N1000->Clone();

Nlpt_N300_2->SetTitle("l_{N} pt #scale[0.8]{(NLO) : High mass}");
Nlpt_N300_2->SetStats(0);
//Nlpt_N300_2->GetXaxis()->SetRangeUser(0,50);
Nlpt_N300_2->SetLineColor(kRed);
Nlpt_N300_2->SetLineWidth(2);
Nlpt_N300_2->Draw("hist");
Nlpt_N600_2->Scale(Nlpt_L300->GetEntries()/Nlpt_L600->GetEntries());
Nlpt_N600_2->SetLineColor(kBlue);
Nlpt_N600_2->SetLineWidth(2);
Nlpt_N600_2->Draw("same hist");
Nlpt_N1000_2->Scale(Nlpt_L300->GetEntries()/Nlpt_L1000->GetEntries());
Nlpt_N1000_2->SetLineColor(kGreen+2);
Nlpt_N1000_2->SetLineWidth(2);
Nlpt_N1000_2->Draw("same hist");

TLegend* Nlpt_NLO_legend = new TLegend(0.62,0.755,0.9,0.9);
Nlpt_NLO_legend->AddEntry(Nlpt_N300_2,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N600_2,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N1000_2,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Nlpt_NLO_legend->Draw();
}



if(c9){
c9->cd();

Nleta_L300->SetTitle("l_{N} #eta #scale[0.8]{(NLO vs LO) : High mass}");
Nleta_L300->SetStats(0);
Nleta_L300->Rebin(2);
Nleta_L300->GetYaxis()->SetRangeUser(0,17000);
Nleta_L300->GetXaxis()->SetTitle("l_{N} #eta");
Nleta_L300->SetLineColor(kRed);
Nleta_L300->SetLineWidth(3);
Nleta_L300->SetLineStyle(7);
Nleta_L300->Draw("hist");
Nleta_L600->Scale(Nleta_L300->GetEntries()/Nleta_L600->GetEntries());
Nleta_L600->Rebin(2);
Nleta_L600->SetLineColor(kGreen+1);
Nleta_L600->SetLineWidth(3);
Nleta_L600->SetLineStyle(7);
Nleta_L600->Draw("same hist");
Nleta_L1000->Scale(Nleta_L300->GetEntries()/Nleta_L1000->GetEntries());
Nleta_L1000->Rebin(2);
Nleta_L1000->SetLineColor(kBlue);
Nleta_L1000->SetLineWidth(3);
Nleta_L1000->SetLineStyle(7);
Nleta_L1000->Draw("same hist");
Nleta_N300->SetStats(0);
Nleta_N300->Scale(Nleta_L300->GetEntries()/Nleta_N300->GetEntries());
Nleta_N300->Rebin(2);
Nleta_N300->SetLineColor(kRed);
Nleta_N300->SetLineWidth(2);
Nleta_N300->Draw("same hist");
Nleta_N600->Scale(Nleta_L300->GetEntries()/Nleta_N600->GetEntries());
Nleta_N600->Rebin(2);
Nleta_N600->SetLineColor(kGreen+1);
Nleta_N600->SetLineWidth(2);
Nleta_N600->Draw("same hist");
Nleta_N1000->Scale(Nleta_L300->GetEntries()/Nleta_N1000->GetEntries());
Nleta_N1000->Rebin(2);
Nleta_N1000->SetLineColor(kBlue);
Nleta_N1000->SetLineWidth(2);
Nleta_N1000->Draw("same hist");

TLegend* Nleta_legend = new TLegend(0.62,0.75,0.9,0.9);
Nleta_legend->AddEntry(Nleta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L300,"#scale[0.9]{LO}","l");
Nleta_legend->AddEntry(Nleta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L600,"#scale[0.9]{LO}","l");
Nleta_legend->AddEntry(Nleta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Nleta_legend->AddEntry(Nleta_L1000,"#scale[0.9]{LO}","l");
Nleta_legend->Draw();
}


if(c10){
c10->cd();

W1pt_L300->SetTitle("W1 pt #scale[0.8]{(NLO vs LO) : High mass}");
W1pt_L300->SetStats(0);
W1pt_L300->Rebin(5);
W1pt_L300->GetXaxis()->SetRangeUser(0,300);
//W1pt_L300->GetYaxis()->SetRangeUser(0,12000);
W1pt_L300->SetLineColor(kRed);
W1pt_L300->SetLineWidth(3);
W1pt_L300->SetLineStyle(7);
W1pt_L300->Draw("hist");
W1pt_L600->Scale(W1pt_L300->GetEntries()/W1pt_L600->GetEntries());
W1pt_L600->Rebin(5);
W1pt_L600->SetLineColor(kGreen+1);
W1pt_L600->SetLineWidth(3);
W1pt_L600->SetLineStyle(7);
W1pt_L600->Draw("same hist");
W1pt_L1000->Scale(W1pt_L300->GetEntries()/W1pt_L1000->GetEntries());
W1pt_L1000->Rebin(5);
W1pt_L1000->SetLineColor(kBlue);
W1pt_L1000->SetLineWidth(3);
W1pt_L1000->SetLineStyle(7);
W1pt_L1000->Draw("same hist");
W1pt_N300->SetStats(0);
W1pt_N300->Scale(W1pt_L300->GetEntries()/W1pt_N300->GetEntries());
W1pt_N300->Rebin(5);
W1pt_N300->SetLineColor(kRed);
W1pt_N300->SetLineWidth(2);
W1pt_N300->Draw("same hist");
W1pt_N600->Scale(W1pt_L300->GetEntries()/W1pt_N600->GetEntries());
W1pt_N600->Rebin(5);
W1pt_N600->SetLineColor(kGreen+1);
W1pt_N600->SetLineWidth(2);
W1pt_N600->Draw("same hist");
W1pt_N1000->Scale(W1pt_L300->GetEntries()/W1pt_N1000->GetEntries());
W1pt_N1000->Rebin(5);
W1pt_N1000->SetLineColor(kBlue);
W1pt_N1000->SetLineWidth(2);
W1pt_N1000->Draw("same hist");

TLegend* W1pt_legend = new TLegend(0.62,0.75,0.9,0.9);
W1pt_legend->AddEntry(W1pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W1pt_legend->AddEntry(W1pt_L300,"#scale[0.9]{LO}","l");
W1pt_legend->AddEntry(W1pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W1pt_legend->AddEntry(W1pt_L600,"#scale[0.9]{LO}","l");
W1pt_legend->AddEntry(W1pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W1pt_legend->AddEntry(W1pt_L1000,"#scale[0.9]{LO}","l");
W1pt_legend->Draw();
}





if(c11){
c11->cd();

W1eta_L300->SetTitle("W1 eta #scale[0.8]{(NLO vs LO) : High mass}");
W1eta_L300->SetStats(0);
W1eta_L300->Rebin(2);
W1eta_L300->GetYaxis()->SetRangeUser(0,6500);
W1eta_L300->SetLineColor(kRed);
W1eta_L300->SetLineWidth(3);
W1eta_L300->SetLineStyle(7);
W1eta_L300->Draw("hist");
W1eta_L600->Scale(W1eta_L300->GetEntries()/W1eta_L600->GetEntries());
W1eta_L600->Rebin(2);
W1eta_L600->SetLineColor(kGreen+1);
W1eta_L600->SetLineWidth(3);
W1eta_L600->SetLineStyle(7);
W1eta_L600->Draw("same hist");
W1eta_L1000->Scale(W1eta_L300->GetEntries()/W1eta_L1000->GetEntries());
W1eta_L1000->Rebin(2);
W1eta_L1000->SetLineColor(kBlue);
W1eta_L1000->SetLineWidth(3);
W1eta_L1000->SetLineStyle(7);
W1eta_L1000->Draw("same hist");
W1eta_N300->SetStats(0);
W1eta_N300->Scale(W1eta_L300->GetEntries()/W1eta_N300->GetEntries());
W1eta_N300->Rebin(2);
W1eta_N300->SetLineColor(kRed);
W1eta_N300->SetLineWidth(2);
W1eta_N300->Draw("same hist");
W1eta_N600->Scale(W1eta_L300->GetEntries()/W1eta_N600->GetEntries());
W1eta_N600->Rebin(2);
W1eta_N600->SetLineColor(kGreen+1);
W1eta_N600->SetLineWidth(2);
W1eta_N600->Draw("same hist");
W1eta_N1000->Scale(W1eta_L300->GetEntries()/W1eta_N1000->GetEntries());
W1eta_N1000->Rebin(2);
W1eta_N1000->SetLineColor(kBlue);
W1eta_N1000->SetLineWidth(2);
W1eta_N1000->Draw("same hist");

TLegend* W1eta_legend = new TLegend(0.62,0.75,0.9,0.9);
W1eta_legend->AddEntry(W1eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W1eta_legend->AddEntry(W1eta_L300,"#scale[0.9]{LO}","l");
W1eta_legend->AddEntry(W1eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W1eta_legend->AddEntry(W1eta_L600,"#scale[0.9]{LO}","l");
W1eta_legend->AddEntry(W1eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W1eta_legend->AddEntry(W1eta_L1000,"#scale[0.9]{LO}","l");
W1eta_legend->Draw();
}


if(c12){
c12->cd();

W1mass_L300->SetTitle("W1 mass #scale[0.8]{(NLO vs LO) : High mass}");
W1mass_L300->SetStats(0);
W1mass_L300->Rebin(50);
//W1mass_L300->GetXaxis()->SetRangeUser(0,300);
//W1mass_L300->GetYaxis()->SetRangeUser(0,50000);
W1mass_L300->SetLineColor(kRed);
W1mass_L300->SetLineWidth(3);
W1mass_L300->SetLineStyle(7);
W1mass_L300->Draw("hist");
W1mass_L600->Scale(W1mass_L300->GetEntries()/W1mass_L600->GetEntries());
W1mass_L600->Rebin(50);
W1mass_L600->SetLineColor(kGreen+1);
W1mass_L600->SetLineWidth(3);
W1mass_L600->SetLineStyle(7);
W1mass_L600->Draw("same hist");
W1mass_L1000->Scale(W1mass_L300->GetEntries()/W1mass_L1000->GetEntries());
W1mass_L1000->Rebin(50);
W1mass_L1000->SetLineColor(kBlue);
W1mass_L1000->SetLineWidth(3);
W1mass_L1000->SetLineStyle(7);
W1mass_L1000->Draw("same hist");
W1mass_N300->SetStats(0);
W1mass_N300->Scale(W1mass_L300->GetEntries()/W1mass_N300->GetEntries());
W1mass_N300->Rebin(50);
W1mass_N300->SetLineColor(kRed);
W1mass_N300->SetLineWidth(2);
W1mass_N300->Draw("same hist");
W1mass_N600->Scale(W1mass_L300->GetEntries()/W1mass_N600->GetEntries());
W1mass_N600->Rebin(50);
W1mass_N600->SetLineColor(kGreen+1);
W1mass_N600->SetLineWidth(2);
W1mass_N600->Draw("same hist");
W1mass_N1000->Scale(W1mass_L300->GetEntries()/W1mass_N1000->GetEntries());
W1mass_N1000->Rebin(50);
W1mass_N1000->SetLineColor(kBlue);
W1mass_N1000->SetLineWidth(2);
W1mass_N1000->Draw("same hist");

TLegend* W1mass_legend = new TLegend(0.62,0.75,0.9,0.9);
W1mass_legend->AddEntry(W1mass_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W1mass_legend->AddEntry(W1mass_L300,"#scale[0.9]{LO}","l");
W1mass_legend->AddEntry(W1mass_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W1mass_legend->AddEntry(W1mass_L600,"#scale[0.9]{LO}","l");
W1mass_legend->AddEntry(W1mass_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W1mass_legend->AddEntry(W1mass_L1000,"#scale[0.9]{LO}","l");
W1mass_legend->Draw();
}



if(c13){
c13->cd();

W1en_L300->SetTitle("W1 energy #scale[0.8]{(NLO vs LO) : High mass}");
W1en_L300->SetStats(0);
W1en_L300->Rebin(50);
//W1en_L300->GetXaxis()->SetRangeUser(0,300);
//W1en_L300->GetYaxis()->SetRangeUser(0,50000);
W1en_L300->SetLineColor(kRed);
W1en_L300->SetLineWidth(3);
W1en_L300->SetLineStyle(7);
W1en_L300->Draw("hist");
W1en_L600->Scale(W1en_L300->GetEntries()/W1en_L600->GetEntries());
W1en_L600->Rebin(50);
W1en_L600->SetLineColor(kGreen+1);
W1en_L600->SetLineWidth(3);
W1en_L600->SetLineStyle(7);
W1en_L600->Draw("same hist");
W1en_L1000->Scale(W1en_L300->GetEntries()/W1en_L1000->GetEntries());
W1en_L1000->Rebin(50);
W1en_L1000->SetLineColor(kBlue);
W1en_L1000->SetLineWidth(3);
W1en_L1000->SetLineStyle(7);
W1en_L1000->Draw("same hist");
W1en_N300->SetStats(0);
W1en_N300->Scale(W1en_L300->GetEntries()/W1en_N300->GetEntries());
W1en_N300->Rebin(50);
W1en_N300->SetLineColor(kRed);
W1en_N300->SetLineWidth(2);
W1en_N300->Draw("same hist");
W1en_N600->Scale(W1en_L300->GetEntries()/W1en_N600->GetEntries());
W1en_N600->Rebin(50);
W1en_N600->SetLineColor(kGreen+1);
W1en_N600->SetLineWidth(2);
W1en_N600->Draw("same hist");
W1en_N1000->Scale(W1en_L300->GetEntries()/W1en_N1000->GetEntries());
W1en_N1000->Rebin(50);
W1en_N1000->SetLineColor(kBlue);
W1en_N1000->SetLineWidth(2);
W1en_N1000->Draw("same hist");

TLegend* W1en_legend = new TLegend(0.62,0.75,0.9,0.9);
W1en_legend->AddEntry(W1en_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W1en_legend->AddEntry(W1en_L300,"#scale[0.9]{LO}","l");
W1en_legend->AddEntry(W1en_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W1en_legend->AddEntry(W1en_L600,"#scale[0.9]{LO}","l");
W1en_legend->AddEntry(W1en_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W1en_legend->AddEntry(W1en_L1000,"#scale[0.9]{LO}","l");
W1en_legend->Draw();
}




if(c14){
c14->cd();

hardlpt_L300->SetTitle("l_{#gamma} pt #scale[0.8]{(NLO vs LO) : High mass}");
hardlpt_L300->SetStats(0);
hardlpt_L300->Rebin(20);
hardlpt_L300->GetXaxis()->SetRangeUser(0,500);
hardlpt_L300->GetYaxis()->SetRangeUser(0,35000);
hardlpt_L300->GetXaxis()->SetTitle("l_{#gamma} p_{T} [GeV]");
hardlpt_L300->SetLineColor(kRed);
hardlpt_L300->SetLineWidth(3);
hardlpt_L300->SetLineStyle(7);
hardlpt_L300->Draw("hist");
hardlpt_L600->Scale(hardlpt_L300->GetEntries()/hardlpt_L600->GetEntries());
hardlpt_L600->Rebin(20);
hardlpt_L600->SetLineColor(kGreen+1);
hardlpt_L600->SetLineWidth(3);
hardlpt_L600->SetLineStyle(7);
hardlpt_L600->Draw("same hist");
hardlpt_L1000->Scale(hardlpt_L300->GetEntries()/hardlpt_L1000->GetEntries());
hardlpt_L1000->Rebin(20);
hardlpt_L1000->SetLineColor(kBlue);
hardlpt_L1000->SetLineWidth(3);
hardlpt_L1000->SetLineStyle(7);
hardlpt_L1000->Draw("same hist");
hardlpt_N300->SetStats(0);
hardlpt_N300->Scale(hardlpt_L300->GetEntries()/hardlpt_N300->GetEntries());
hardlpt_N300->Rebin(20);
hardlpt_N300->SetLineColor(kRed);
hardlpt_N300->SetLineWidth(2);
hardlpt_N300->Draw("same hist");
hardlpt_N600->Scale(hardlpt_L300->GetEntries()/hardlpt_N600->GetEntries());
hardlpt_N600->Rebin(20);
hardlpt_N600->SetLineColor(kGreen+1);
hardlpt_N600->SetLineWidth(2);
hardlpt_N600->Draw("same hist");
hardlpt_N1000->Scale(hardlpt_L300->GetEntries()/hardlpt_N1000->GetEntries());
hardlpt_N1000->Rebin(20);
hardlpt_N1000->SetLineColor(kBlue);
hardlpt_N1000->SetLineWidth(2);
hardlpt_N1000->Draw("same hist");

double hardlptdiff_300 = 100*(hardlpt_N300->GetMean()-hardlpt_L300->GetMean())/hardlpt_L300->GetMean();
TString hardlptdiff_300_t = Form("%f",hardlptdiff_300);
double hardlptdiff_600 = 100*(hardlpt_N600->GetMean()-hardlpt_L600->GetMean())/hardlpt_L600->GetMean();
TString hardlptdiff_600_t = Form("%f",hardlptdiff_600);
double hardlptdiff_1000 = 100*(hardlpt_N1000->GetMean()-hardlpt_L1000->GetMean())/hardlpt_L1000->GetMean();
TString hardlptdiff_1000_t = Form("%f",hardlptdiff_1000);
TLegend* hardlpt_legend = new TLegend(0.62,0.65,0.9,0.9);
hardlpt_legend->AddEntry(hardlpt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
hardlpt_legend->AddEntry(hardlpt_L300,"#scale[0.9]{LO}","l");
hardlpt_legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+hardlptdiff_300_t+"%","");
hardlpt_legend->AddEntry(hardlpt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
hardlpt_legend->AddEntry(hardlpt_L600,"#scale[0.9]{LO}","l");
hardlpt_legend->AddEntry((TObject*)0,"diff : "+hardlptdiff_600_t+"%","");
hardlpt_legend->AddEntry(hardlpt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
hardlpt_legend->AddEntry(hardlpt_L1000,"#scale[0.9]{LO}","l");
hardlpt_legend->AddEntry((TObject*)0,"diff : "+hardlptdiff_1000_t+"%","");
hardlpt_legend->Draw();
}



if(c15){
c15->cd();

hardleta_L300->SetTitle("l_{#gamma} #eta #scale[0.8]{(NLO vs LO) : High mass}");
hardleta_L300->SetStats(0);
hardleta_L300->Rebin(2);
hardleta_L300->GetYaxis()->SetRangeUser(0,16000);
hardleta_L300->GetXaxis()->SetTitle("l_{#gamma} #eta");
hardleta_L300->SetLineColor(kRed);
hardleta_L300->SetLineWidth(3);
hardleta_L300->SetLineStyle(7);
hardleta_L300->Draw("hist");
hardleta_L600->Scale(hardleta_L300->GetEntries()/hardleta_L600->GetEntries());
hardleta_L600->Rebin(2);
hardleta_L600->SetLineColor(kGreen+1);
hardleta_L600->SetLineWidth(3);
hardleta_L600->SetLineStyle(7);
hardleta_L600->Draw("same hist");
hardleta_L1000->Scale(hardleta_L300->GetEntries()/hardleta_L1000->GetEntries());
hardleta_L1000->Rebin(2);
hardleta_L1000->SetLineColor(kBlue);
hardleta_L1000->SetLineWidth(3);
hardleta_L1000->SetLineStyle(7);
hardleta_L1000->Draw("same hist");
hardleta_N300->SetStats(0);
hardleta_N300->Scale(hardleta_L300->GetEntries()/hardleta_N300->GetEntries());
hardleta_N300->Rebin(2);
hardleta_N300->SetLineColor(kRed);
hardleta_N300->SetLineWidth(2);
hardleta_N300->Draw("same hist");
hardleta_N600->Scale(hardleta_L300->GetEntries()/hardleta_N600->GetEntries());
hardleta_N600->Rebin(2);
hardleta_N600->SetLineColor(kGreen+1);
hardleta_N600->SetLineWidth(2);
hardleta_N600->Draw("same hist");
hardleta_N1000->Scale(hardleta_L300->GetEntries()/hardleta_N1000->GetEntries());
hardleta_N1000->Rebin(2);
hardleta_N1000->SetLineColor(kBlue);
hardleta_N1000->SetLineWidth(2);
hardleta_N1000->Draw("same hist");

TLegend* hardleta_legend = new TLegend(0.62,0.75,0.9,0.9);
hardleta_legend->AddEntry(hardleta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
hardleta_legend->AddEntry(hardleta_L300,"#scale[0.9]{LO}","l");
hardleta_legend->AddEntry(hardleta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
hardleta_legend->AddEntry(hardleta_L600,"#scale[0.9]{LO}","l");
hardleta_legend->AddEntry(hardleta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
hardleta_legend->AddEntry(hardleta_L1000,"#scale[0.9]{LO}","l");
hardleta_legend->Draw();
}



if(c16){
c16->cd();

j1pt_L300->SetTitle("j1 pt #scale[0.8]{(NLO vs LO) : High mass}");
j1pt_L300->SetStats(0);
j1pt_L300->Rebin(20);
j1pt_L300->GetXaxis()->SetRangeUser(0,800);
j1pt_L300->GetYaxis()->SetRangeUser(0,25000);
j1pt_L300->GetXaxis()->SetTitle("j1 p_{T} [GeV]");
j1pt_L300->SetLineColor(kRed);
j1pt_L300->SetLineWidth(3);
j1pt_L300->SetLineStyle(7);
j1pt_L300->Draw("hist");
j1pt_L600->Scale(j1pt_L300->GetEntries()/j1pt_L600->GetEntries());
j1pt_L600->Rebin(20);
j1pt_L600->SetLineColor(kGreen+1);
j1pt_L600->SetLineWidth(3);
j1pt_L600->SetLineStyle(7);
j1pt_L600->Draw("same hist");
j1pt_L1000->Scale(j1pt_L300->GetEntries()/j1pt_L1000->GetEntries());
j1pt_L1000->Rebin(20);
j1pt_L1000->SetLineColor(kBlue);
j1pt_L1000->SetLineWidth(3);
j1pt_L1000->SetLineStyle(7);
j1pt_L1000->Draw("same hist");
j1pt_N300->SetStats(0);
j1pt_N300->Scale(j1pt_L300->GetEntries()/j1pt_N300->GetEntries());
j1pt_N300->Rebin(20);
j1pt_N300->SetLineColor(kRed);
j1pt_N300->SetLineWidth(2);
j1pt_N300->Draw("same hist");
j1pt_N600->Scale(j1pt_L300->GetEntries()/j1pt_N600->GetEntries());
j1pt_N600->Rebin(20);
j1pt_N600->SetLineColor(kGreen+1);
j1pt_N600->SetLineWidth(2);
j1pt_N600->Draw("same hist");
j1pt_N1000->Scale(j1pt_L300->GetEntries()/j1pt_N1000->GetEntries());
j1pt_N1000->Rebin(20);
j1pt_N1000->SetLineColor(kBlue);
j1pt_N1000->SetLineWidth(2);
j1pt_N1000->Draw("same hist");

double j1ptdiff_300 = 100*(j1pt_N300->GetMean()-j1pt_L300->GetMean())/j1pt_L300->GetMean();
TString j1ptdiff_300_t = Form("%f",j1ptdiff_300);
double j1ptdiff_600 = 100*(j1pt_N600->GetMean()-j1pt_L600->GetMean())/j1pt_L600->GetMean();
TString j1ptdiff_600_t = Form("%f",j1ptdiff_600);
double j1ptdiff_1000 = 100*(j1pt_N1000->GetMean()-j1pt_L1000->GetMean())/j1pt_L1000->GetMean();
TString j1ptdiff_1000_t = Form("%f",j1ptdiff_1000);
TLegend* j1pt_legend = new TLegend(0.62,0.65,0.9,0.9);
j1pt_legend->AddEntry(j1pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L300,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+j1ptdiff_300_t+"%","");
j1pt_legend->AddEntry(j1pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L600,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry((TObject*)0,"diff : "+j1ptdiff_600_t+"%","");
j1pt_legend->AddEntry(j1pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
j1pt_legend->AddEntry(j1pt_L1000,"#scale[0.9]{LO}","l");
j1pt_legend->AddEntry((TObject*)0,"diff : "+j1ptdiff_1000_t+"%","");
j1pt_legend->Draw();
}



if(c17){
c17->cd();

j1eta_L300->SetTitle("j1 #eta #scale[0.8]{(NLO vs LO) : High mass}");
j1eta_L300->SetStats(0);
j1eta_L300->Rebin(2);
j1eta_L300->GetYaxis()->SetRangeUser(0,15000);
j1eta_L300->GetXaxis()->SetTitle("j1 #eta");
j1eta_L300->SetLineColor(kRed);
j1eta_L300->SetLineWidth(3);
j1eta_L300->SetLineStyle(7);
j1eta_L300->Draw("hist");
j1eta_L600->Scale(j1eta_L300->GetEntries()/j1eta_L600->GetEntries());
j1eta_L600->Rebin(2);
j1eta_L600->SetLineColor(kGreen+1);
j1eta_L600->SetLineWidth(3);
j1eta_L600->SetLineStyle(7);
j1eta_L600->Draw("same hist");
j1eta_L1000->Scale(j1eta_L300->GetEntries()/j1eta_L1000->GetEntries());
j1eta_L1000->Rebin(2);
j1eta_L1000->SetLineColor(kBlue);
j1eta_L1000->SetLineWidth(3);
j1eta_L1000->SetLineStyle(7);
j1eta_L1000->Draw("same hist");
j1eta_N300->SetStats(0);
j1eta_N300->Scale(j1eta_L300->GetEntries()/j1eta_N300->GetEntries());
j1eta_N300->Rebin(2);
j1eta_N300->SetLineColor(kRed);
j1eta_N300->SetLineWidth(2);
j1eta_N300->Draw("same hist");
j1eta_N600->Scale(j1eta_L300->GetEntries()/j1eta_N600->GetEntries());
j1eta_N600->Rebin(2);
j1eta_N600->SetLineColor(kGreen+1);
j1eta_N600->SetLineWidth(2);
j1eta_N600->Draw("same hist");
j1eta_N1000->Scale(j1eta_L300->GetEntries()/j1eta_N1000->GetEntries());
j1eta_N1000->Rebin(2);
j1eta_N1000->SetLineColor(kBlue);
j1eta_N1000->SetLineWidth(2);
j1eta_N1000->Draw("same hist");

TLegend* j1eta_legend = new TLegend(0.62,0.75,0.9,0.9);
j1eta_legend->AddEntry(j1eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L300,"#scale[0.9]{LO}","l");
j1eta_legend->AddEntry(j1eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L600,"#scale[0.9]{LO}","l");
j1eta_legend->AddEntry(j1eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
j1eta_legend->AddEntry(j1eta_L1000,"#scale[0.9]{LO}","l");
j1eta_legend->Draw();
}


if(c18){
c18->cd();

j2pt_L300->SetTitle("j2 pt #scale[0.8]{(NLO vs LO) : High mass}");
j2pt_L300->SetStats(0);
j2pt_L300->Rebin(10);
j2pt_L300->GetXaxis()->SetRangeUser(0,400);
j2pt_L300->GetYaxis()->SetRangeUser(0,15000);
j2pt_L300->GetXaxis()->SetTitle("j2 p_{T} [GeV]");
j2pt_L300->SetLineColor(kRed);
j2pt_L300->SetLineWidth(3);
j2pt_L300->SetLineStyle(7);
j2pt_L300->Draw("hist");
j2pt_L600->Scale(j2pt_L300->GetEntries()/j2pt_L600->GetEntries());
j2pt_L600->Rebin(10);
j2pt_L600->SetLineColor(kGreen+1);
j2pt_L600->SetLineWidth(3);
j2pt_L600->SetLineStyle(7);
j2pt_L600->Draw("same hist");
j2pt_L1000->Scale(j2pt_L300->GetEntries()/j2pt_L1000->GetEntries());
j2pt_L1000->Rebin(10);
j2pt_L1000->SetLineColor(kBlue);
j2pt_L1000->SetLineWidth(3);
j2pt_L1000->SetLineStyle(7);
j2pt_L1000->Draw("same hist");
j2pt_N300->SetStats(0);
j2pt_N300->Scale(j2pt_L300->GetEntries()/j2pt_N300->GetEntries());
j2pt_N300->Rebin(10);
j2pt_N300->SetLineColor(kRed);
j2pt_N300->SetLineWidth(2);
j2pt_N300->Draw("same hist");
j2pt_N600->Scale(j2pt_L300->GetEntries()/j2pt_N600->GetEntries());
j2pt_N600->Rebin(10);
j2pt_N600->SetLineColor(kGreen+1);
j2pt_N600->SetLineWidth(2);
j2pt_N600->Draw("same hist");
j2pt_N1000->Scale(j2pt_L300->GetEntries()/j2pt_N1000->GetEntries());
j2pt_N1000->Rebin(10);
j2pt_N1000->SetLineColor(kBlue);
j2pt_N1000->SetLineWidth(2);
j2pt_N1000->Draw("same hist");

double j2ptdiff_300 = 100*(j2pt_N300->GetMean()-j2pt_L300->GetMean())/j2pt_L300->GetMean();
TString j2ptdiff_300_t = Form("%f",j2ptdiff_300);
double j2ptdiff_600 = 100*(j2pt_N600->GetMean()-j2pt_L600->GetMean())/j2pt_L600->GetMean();
TString j2ptdiff_600_t = Form("%f",j2ptdiff_600);
double j2ptdiff_1000 = 100*(j2pt_N1000->GetMean()-j2pt_L1000->GetMean())/j2pt_L1000->GetMean();
TString j2ptdiff_1000_t = Form("%f",j2ptdiff_1000);
TLegend* j2pt_legend = new TLegend(0.62,0.65,0.9,0.9);
j2pt_legend->AddEntry(j2pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L300,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+j2ptdiff_300_t+"%","");
j2pt_legend->AddEntry(j2pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L600,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry((TObject*)0,"diff : "+j2ptdiff_600_t+"%","");
j2pt_legend->AddEntry(j2pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
j2pt_legend->AddEntry(j2pt_L1000,"#scale[0.9]{LO}","l");
j2pt_legend->AddEntry((TObject*)0,"diff : "+j2ptdiff_1000_t+"%","");
j2pt_legend->Draw();
}



if(c19){
c19->cd();

j2eta_L300->SetTitle("j2 #eta #scale[0.8]{(NLO vs LO) : High mass}");
j2eta_L300->SetStats(0);
j2eta_L300->Rebin(2);
j2eta_L300->GetYaxis()->SetRangeUser(0,10000);
j2eta_L300->GetXaxis()->SetTitle("j2 #eta");
j2eta_L300->SetLineColor(kRed);
j2eta_L300->SetLineWidth(3);
j2eta_L300->SetLineStyle(7);
j2eta_L300->Draw("hist");
j2eta_L600->Scale(j2eta_L300->GetEntries()/j2eta_L600->GetEntries());
j2eta_L600->Rebin(2);
j2eta_L600->SetLineColor(kGreen+1);
j2eta_L600->SetLineWidth(3);
j2eta_L600->SetLineStyle(7);
j2eta_L600->Draw("same hist");
j2eta_L1000->Scale(j2eta_L300->GetEntries()/j2eta_L1000->GetEntries());
j2eta_L1000->Rebin(2);
j2eta_L1000->SetLineColor(kBlue);
j2eta_L1000->SetLineWidth(3);
j2eta_L1000->SetLineStyle(7);
j2eta_L1000->Draw("same hist");
j2eta_N300->SetStats(0);
j2eta_N300->Scale(j2eta_L300->GetEntries()/j2eta_N300->GetEntries());
j2eta_N300->Rebin(2);
j2eta_N300->SetLineColor(kRed);
j2eta_N300->SetLineWidth(2);
j2eta_N300->Draw("same hist");
j2eta_N600->Scale(j2eta_L300->GetEntries()/j2eta_N600->GetEntries());
j2eta_N600->Rebin(2);
j2eta_N600->SetLineColor(kGreen+1);
j2eta_N600->SetLineWidth(2);
j2eta_N600->Draw("same hist");
j2eta_N1000->Scale(j2eta_L300->GetEntries()/j2eta_N1000->GetEntries());
j2eta_N1000->Rebin(2);
j2eta_N1000->SetLineColor(kBlue);
j2eta_N1000->SetLineWidth(2);
j2eta_N1000->Draw("same hist");

TLegend* j2eta_legend = new TLegend(0.62,0.75,0.9,0.9);
j2eta_legend->AddEntry(j2eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L300,"#scale[0.9]{LO}","l");
j2eta_legend->AddEntry(j2eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L600,"#scale[0.9]{LO}","l");
j2eta_legend->AddEntry(j2eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
j2eta_legend->AddEntry(j2eta_L1000,"#scale[0.9]{LO}","l");
j2eta_legend->Draw();
}



if(c20){
c20->cd();

Jpt_L300->SetTitle("fatjet pt #scale[0.8]{(NLO vs LO) : High mass}");
Jpt_L300->SetStats(0);
Jpt_L300->Rebin(20);
Jpt_L300->GetXaxis()->SetRangeUser(0,1000);
//Jpt_L300->GetYaxis()->SetRangeUser(0,30000);
Jpt_L300->GetXaxis()->SetTitle("fatjet p_{T} [GeV]");
Jpt_L300->SetLineColor(kRed);
Jpt_L300->SetLineWidth(3);
Jpt_L300->SetLineStyle(7);
Jpt_L300->Draw("hist");
Jpt_L600->Scale(Jpt_L300->GetEntries()/Jpt_L600->GetEntries());
Jpt_L600->Rebin(20);
Jpt_L600->SetLineColor(kGreen+1);
Jpt_L600->SetLineWidth(3);
Jpt_L600->SetLineStyle(7);
Jpt_L600->Draw("same hist");
Jpt_L1000->Scale(Jpt_L300->GetEntries()/Jpt_L1000->GetEntries());
Jpt_L1000->Rebin(20);
Jpt_L1000->SetLineColor(kBlue);
Jpt_L1000->SetLineWidth(3);
Jpt_L1000->SetLineStyle(7);
Jpt_L1000->Draw("same hist");
Jpt_N300->SetStats(0);
Jpt_N300->Scale(Jpt_L300->GetEntries()/Jpt_N300->GetEntries());
Jpt_N300->Rebin(20);
Jpt_N300->SetLineColor(kRed);
Jpt_N300->SetLineWidth(2);
Jpt_N300->Draw("same hist");
Jpt_N600->Scale(Jpt_L300->GetEntries()/Jpt_N600->GetEntries());
Jpt_N600->Rebin(20);
Jpt_N600->SetLineColor(kGreen+1);
Jpt_N600->SetLineWidth(2);
Jpt_N600->Draw("same hist");
Jpt_N1000->Scale(Jpt_L300->GetEntries()/Jpt_N1000->GetEntries());
Jpt_N1000->Rebin(20);
Jpt_N1000->SetLineColor(kBlue);
Jpt_N1000->SetLineWidth(2);
Jpt_N1000->Draw("same hist");

TLegend* Jpt_legend = new TLegend(0.62,0.75,0.9,0.9);
Jpt_legend->AddEntry(Jpt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Jpt_legend->AddEntry(Jpt_L300,"#scale[0.9]{LO}","l");
Jpt_legend->AddEntry(Jpt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Jpt_legend->AddEntry(Jpt_L600,"#scale[0.9]{LO}","l");
Jpt_legend->AddEntry(Jpt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Jpt_legend->AddEntry(Jpt_L1000,"#scale[0.9]{LO}","l");
Jpt_legend->Draw();
}



if(c21){
c21->cd();

Jeta_L300->SetTitle("fatjet #eta #scale[0.8]{(NLO vs LO) : High mass}");
Jeta_L300->SetStats(0);
Jeta_L300->Rebin(2);
Jeta_L300->GetYaxis()->SetRangeUser(0,12000);
Jeta_L300->SetLineColor(kRed);
Jeta_L300->SetLineWidth(3);
Jeta_L300->SetLineStyle(7);
Jeta_L300->Draw("hist");
Jeta_L600->Scale(Jeta_L300->GetEntries()/Jeta_L600->GetEntries());
Jeta_L600->Rebin(2);
Jeta_L600->SetLineColor(kGreen+1);
Jeta_L600->SetLineWidth(3);
Jeta_L600->SetLineStyle(7);
Jeta_L600->Draw("same hist");
Jeta_L1000->Scale(Jeta_L300->GetEntries()/Jeta_L1000->GetEntries());
Jeta_L1000->Rebin(2);
Jeta_L1000->SetLineColor(kBlue);
Jeta_L1000->SetLineWidth(3);
Jeta_L1000->SetLineStyle(7);
Jeta_L1000->Draw("same hist");
Jeta_N300->SetStats(0);
Jeta_N300->Scale(Jeta_L300->GetEntries()/Jeta_N300->GetEntries());
Jeta_N300->Rebin(2);
Jeta_N300->SetLineColor(kRed);
Jeta_N300->SetLineWidth(2);
Jeta_N300->Draw("same hist");
Jeta_N600->Scale(Jeta_L300->GetEntries()/Jeta_N600->GetEntries());
Jeta_N600->Rebin(2);
Jeta_N600->SetLineColor(kGreen+1);
Jeta_N600->SetLineWidth(2);
Jeta_N600->Draw("same hist");
Jeta_N1000->Scale(Jeta_L300->GetEntries()/Jeta_N1000->GetEntries());
Jeta_N1000->Rebin(2);
Jeta_N1000->SetLineColor(kBlue);
Jeta_N1000->SetLineWidth(2);
Jeta_N1000->Draw("same hist");

TLegend* Jeta_legend = new TLegend(0.62,0.75,0.9,0.9);
Jeta_legend->AddEntry(Jeta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Jeta_legend->AddEntry(Jeta_L300,"#scale[0.9]{LO}","l");
Jeta_legend->AddEntry(Jeta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Jeta_legend->AddEntry(Jeta_L600,"#scale[0.9]{LO}","l");
Jeta_legend->AddEntry(Jeta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Jeta_legend->AddEntry(Jeta_L1000,"#scale[0.9]{LO}","l");
Jeta_legend->Draw();
}



if(c22){
c22->cd();

mJ_L300->SetTitle("fatjet mass #scale[0.8]{(NLO vs LO) : High mass}");
mJ_L300->SetStats(0);
mJ_L300->Rebin(5);
mJ_L300->GetXaxis()->SetRangeUser(0,200);
mJ_L300->GetYaxis()->SetRangeUser(0,20000);
mJ_L300->SetLineColor(kRed);
mJ_L300->SetLineWidth(3);
mJ_L300->SetLineStyle(7);
mJ_L300->Draw("hist");
mJ_L600->Scale(mJ_L300->GetEntries()/mJ_L600->GetEntries());
mJ_L600->Rebin(5);
mJ_L600->SetLineColor(kGreen+1);
mJ_L600->SetLineWidth(3);
mJ_L600->SetLineStyle(7);
mJ_L600->Draw("same hist");
mJ_L1000->Scale(mJ_L300->GetEntries()/mJ_L1000->GetEntries());
mJ_L1000->Rebin(5);
mJ_L1000->SetLineColor(kBlue);
mJ_L1000->SetLineWidth(3);
mJ_L1000->SetLineStyle(7);
mJ_L1000->Draw("same hist");
mJ_N300->SetStats(0);
mJ_N300->Scale(mJ_L300->GetEntries()/mJ_N300->GetEntries());
mJ_N300->Rebin(5);
mJ_N300->SetLineColor(kRed);
mJ_N300->SetLineWidth(2);
mJ_N300->Draw("same hist");
mJ_N600->Scale(mJ_L300->GetEntries()/mJ_N600->GetEntries());
mJ_N600->Rebin(5);
mJ_N600->SetLineColor(kGreen+1);
mJ_N600->SetLineWidth(2);
mJ_N600->Draw("same hist");
mJ_N1000->Scale(mJ_L300->GetEntries()/mJ_N1000->GetEntries());
mJ_N1000->Rebin(5);
mJ_N1000->SetLineColor(kBlue);
mJ_N1000->SetLineWidth(2);
mJ_N1000->Draw("same hist");

TLegend* mJ_legend = new TLegend(0.62,0.75,0.9,0.9);
mJ_legend->AddEntry(mJ_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
mJ_legend->AddEntry(mJ_L300,"#scale[0.9]{LO}","l");
mJ_legend->AddEntry(mJ_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
mJ_legend->AddEntry(mJ_L600,"#scale[0.9]{LO}","l");
mJ_legend->AddEntry(mJ_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
mJ_legend->AddEntry(mJ_L1000,"#scale[0.9]{LO}","l");
mJ_legend->Draw();
}


if(c23){
c23->cd();

mjj_L300->SetTitle("dijet mass #scale[0.8]{(NLO vs LO) : High mass}");
mjj_L300->SetStats(0);
mjj_L300->Rebin(5);
mjj_L300->GetXaxis()->SetRangeUser(0,200);
mjj_L300->GetYaxis()->SetRangeUser(0,25000);
mjj_L300->SetLineColor(kRed);
mjj_L300->SetLineWidth(3);
mjj_L300->SetLineStyle(7);
mjj_L300->Draw("hist");
mjj_L600->Scale(mjj_L300->GetEntries()/mjj_L600->GetEntries());
mjj_L600->Rebin(5);
mjj_L600->SetLineColor(kGreen+1);
mjj_L600->SetLineWidth(3);
mjj_L600->SetLineStyle(7);
mjj_L600->Draw("same hist");
mjj_L1000->Scale(mjj_L300->GetEntries()/mjj_L1000->GetEntries());
mjj_L1000->Rebin(5);
mjj_L1000->SetLineColor(kBlue);
mjj_L1000->SetLineWidth(3);
mjj_L1000->SetLineStyle(7);
mjj_L1000->Draw("same hist");
mjj_N300->SetStats(0);
mjj_N300->Scale(mjj_L300->GetEntries()/mjj_N300->GetEntries());
mjj_N300->Rebin(5);
mjj_N300->SetLineColor(kRed);
mjj_N300->SetLineWidth(2);
mjj_N300->Draw("same hist");
mjj_N600->Scale(mjj_L300->GetEntries()/mjj_N600->GetEntries());
mjj_N600->Rebin(5);
mjj_N600->SetLineColor(kGreen+1);
mjj_N600->SetLineWidth(2);
mjj_N600->Draw("same hist");
mjj_N1000->Scale(mjj_L300->GetEntries()/mjj_N1000->GetEntries());
mjj_N1000->Rebin(5);
mjj_N1000->SetLineColor(kBlue);
mjj_N1000->SetLineWidth(2);
mjj_N1000->Draw("same hist");

TLegend* mjj_legend = new TLegend(0.62,0.75,0.9,0.9);
mjj_legend->AddEntry(mjj_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
mjj_legend->AddEntry(mjj_L300,"#scale[0.9]{LO}","l");
mjj_legend->AddEntry(mjj_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
mjj_legend->AddEntry(mjj_L600,"#scale[0.9]{LO}","l");
mjj_legend->AddEntry(mjj_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
mjj_legend->AddEntry(mjj_L1000,"#scale[0.9]{LO}","l");
mjj_legend->Draw();
}



if(c24){
c24->cd();

mllJ_L300->SetTitle("m(llJ) #scale[0.8]{(NLO vs LO) : High mass}");
mllJ_L300->SetStats(0);
mllJ_L300->Rebin(50);
//mllJ_L300->GetXaxis()->SetRangeUser(0,300);
//mllJ_L300->GetYaxis()->SetRangeUser(0,30000);
mllJ_L300->SetLineColor(kRed);
mllJ_L300->SetLineWidth(3);
mllJ_L300->SetLineStyle(7);
mllJ_L300->Draw("hist");
mllJ_L600->Scale(mllJ_L300->GetEntries()/mllJ_L600->GetEntries());
mllJ_L600->Rebin(50);
mllJ_L600->SetLineColor(kGreen+1);
mllJ_L600->SetLineWidth(3);
mllJ_L600->SetLineStyle(7);
mllJ_L600->Draw("same hist");
mllJ_L1000->Scale(mllJ_L300->GetEntries()/mllJ_L1000->GetEntries());
mllJ_L1000->Rebin(50);
mllJ_L1000->SetLineColor(kBlue);
mllJ_L1000->SetLineWidth(3);
mllJ_L1000->SetLineStyle(7);
mllJ_L1000->Draw("same hist");
mllJ_N300->SetStats(0);
mllJ_N300->Scale(mllJ_L300->GetEntries()/mllJ_N300->GetEntries());
mllJ_N300->Rebin(50);
mllJ_N300->SetLineColor(kRed);
mllJ_N300->SetLineWidth(2);
mllJ_N300->Draw("same hist");
mllJ_N600->Scale(mllJ_L300->GetEntries()/mllJ_N600->GetEntries());
mllJ_N600->Rebin(50);
mllJ_N600->SetLineColor(kGreen+1);
mllJ_N600->SetLineWidth(2);
mllJ_N600->Draw("same hist");
mllJ_N1000->Scale(mllJ_L300->GetEntries()/mllJ_N1000->GetEntries());
mllJ_N1000->Rebin(50);
mllJ_N1000->SetLineColor(kBlue);
mllJ_N1000->SetLineWidth(2);
mllJ_N1000->Draw("same hist");

TLegend* mllJ_legend = new TLegend(0.62,0.75,0.9,0.9);
mllJ_legend->AddEntry(mllJ_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
mllJ_legend->AddEntry(mllJ_L300,"#scale[0.9]{LO}","l");
mllJ_legend->AddEntry(mllJ_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
mllJ_legend->AddEntry(mllJ_L600,"#scale[0.9]{LO}","l");
mllJ_legend->AddEntry(mllJ_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
mllJ_legend->AddEntry(mllJ_L1000,"#scale[0.9]{LO}","l");
mllJ_legend->Draw();
}


if(c25){
c25->cd();

ml1J_L300->SetTitle("m(l1J) #scale[0.8]{(NLO vs LO) : High mass}");
ml1J_L300->SetStats(0);
ml1J_L300->Rebin(50);
ml1J_L300->GetXaxis()->SetRangeUser(0,2000);
ml1J_L300->GetYaxis()->SetRangeUser(0,50000);
ml1J_L300->SetLineColor(kRed);
ml1J_L300->SetLineWidth(3);
ml1J_L300->SetLineStyle(7);
ml1J_L300->Draw("hist");
ml1J_L600->Scale(ml1J_L300->GetEntries()/ml1J_L600->GetEntries());
ml1J_L600->Rebin(50);
ml1J_L600->SetLineColor(kGreen+1);
ml1J_L600->SetLineWidth(3);
ml1J_L600->SetLineStyle(7);
ml1J_L600->Draw("same hist");
ml1J_L1000->Scale(ml1J_L300->GetEntries()/ml1J_L1000->GetEntries());
ml1J_L1000->Rebin(50);
ml1J_L1000->SetLineColor(kBlue);
ml1J_L1000->SetLineWidth(3);
ml1J_L1000->SetLineStyle(7);
ml1J_L1000->Draw("same hist");
ml1J_N300->SetStats(0);
ml1J_N300->Scale(ml1J_L300->GetEntries()/ml1J_N300->GetEntries());
ml1J_N300->Rebin(50);
ml1J_N300->SetLineColor(kRed);
ml1J_N300->SetLineWidth(2);
ml1J_N300->Draw("same hist");
ml1J_N600->Scale(ml1J_L300->GetEntries()/ml1J_N600->GetEntries());
ml1J_N600->Rebin(50);
ml1J_N600->SetLineColor(kGreen+1);
ml1J_N600->SetLineWidth(2);
ml1J_N600->Draw("same hist");
ml1J_N1000->Scale(ml1J_L300->GetEntries()/ml1J_N1000->GetEntries());
ml1J_N1000->Rebin(50);
ml1J_N1000->SetLineColor(kBlue);
ml1J_N1000->SetLineWidth(2);
ml1J_N1000->Draw("same hist");

TLegend* ml1J_legend = new TLegend(0.62,0.75,0.9,0.9);
ml1J_legend->AddEntry(ml1J_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
ml1J_legend->AddEntry(ml1J_L300,"#scale[0.9]{LO}","l");
ml1J_legend->AddEntry(ml1J_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
ml1J_legend->AddEntry(ml1J_L600,"#scale[0.9]{LO}","l");
ml1J_legend->AddEntry(ml1J_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
ml1J_legend->AddEntry(ml1J_L1000,"#scale[0.9]{LO}","l");
ml1J_legend->Draw();
}


if(c26){
c26->cd();

ml2J_L300->SetTitle("m(l2J) #scale[0.8]{(NLO vs LO) : High mass}");
ml2J_L300->SetStats(0);
ml2J_L300->Rebin(20);
ml2J_L300->GetXaxis()->SetRangeUser(0,1400);
ml2J_L300->GetYaxis()->SetRangeUser(0,30000);
ml2J_L300->SetLineColor(kRed);
ml2J_L300->SetLineWidth(3);
ml2J_L300->SetLineStyle(7);
ml2J_L300->Draw("hist");
ml2J_L600->Scale(ml2J_L300->GetEntries()/ml2J_L600->GetEntries());
ml2J_L600->Rebin(20);
ml2J_L600->SetLineColor(kGreen+1);
ml2J_L600->SetLineWidth(3);
ml2J_L600->SetLineStyle(7);
ml2J_L600->Draw("same hist");
ml2J_L1000->Scale(ml2J_L300->GetEntries()/ml2J_L1000->GetEntries());
ml2J_L1000->Rebin(20);
ml2J_L1000->SetLineColor(kBlue);
ml2J_L1000->SetLineWidth(3);
ml2J_L1000->SetLineStyle(7);
ml2J_L1000->Draw("same hist");
ml2J_N300->SetStats(0);
ml2J_N300->Scale(ml2J_L300->GetEntries()/ml2J_N300->GetEntries());
ml2J_N300->Rebin(20);
ml2J_N300->SetLineColor(kRed);
ml2J_N300->SetLineWidth(2);
ml2J_N300->Draw("same hist");
ml2J_N600->Scale(ml2J_L300->GetEntries()/ml2J_N600->GetEntries());
ml2J_N600->Rebin(20);
ml2J_N600->SetLineColor(kGreen+1);
ml2J_N600->SetLineWidth(2);
ml2J_N600->Draw("same hist");
ml2J_N1000->Scale(ml2J_L300->GetEntries()/ml2J_N1000->GetEntries());
ml2J_N1000->Rebin(20);
ml2J_N1000->SetLineColor(kBlue);
ml2J_N1000->SetLineWidth(2);
ml2J_N1000->Draw("same hist");

TLegend* ml2J_legend = new TLegend(0.62,0.75,0.9,0.9);
ml2J_legend->AddEntry(ml2J_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
ml2J_legend->AddEntry(ml2J_L300,"#scale[0.9]{LO}","l");
ml2J_legend->AddEntry(ml2J_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
ml2J_legend->AddEntry(ml2J_L600,"#scale[0.9]{LO}","l");
ml2J_legend->AddEntry(ml2J_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
ml2J_legend->AddEntry(ml2J_L1000,"#scale[0.9]{LO}","l");
ml2J_legend->Draw();
}





if(c27){
c27->cd();

hardqpt_N300->SetTitle("hard q pt #scale[0.8]{(NLO) : High mass}");
hardqpt_N300->SetStats(0);
hardqpt_N300->Rebin(50);
//hardqpt_N300->GetXaxis()->SetRangeUser(0,120);
//hardqpt_N300->GetYaxis()->SetRangeUser(0,30000);
hardqpt_N300->SetLineColor(kRed);
hardqpt_N300->SetLineWidth(2);
hardqpt_N300->Draw("hist");
hardqpt_N600->Scale(hardqpt_N300->GetEntries()/hardqpt_N600->GetEntries());
hardqpt_N600->Rebin(50);
hardqpt_N600->SetLineColor(kGreen+1);
hardqpt_N600->SetLineWidth(2);
hardqpt_N600->Draw("same hist");
hardqpt_N1000->Scale(hardqpt_N300->GetEntries()/hardqpt_N1000->GetEntries());
hardqpt_N1000->Rebin(50);
hardqpt_N1000->SetLineColor(kBlue);
hardqpt_N1000->SetLineWidth(2);
hardqpt_N1000->Draw("same hist");

TLegend* hardqpt_legend = new TLegend(0.62,0.75,0.9,0.9);
hardqpt_legend->AddEntry(hardqpt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
hardqpt_legend->AddEntry(hardqpt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
hardqpt_legend->AddEntry(hardqpt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
hardqpt_legend->Draw();
}


if(c28){
c28->cd();

hardqeta_N300->SetTitle("hard q #eta #scale[0.8]{(NLO) : High mass}");
hardqeta_N300->SetStats(0);
hardqeta_N300->Rebin(2);
hardqeta_N300->GetYaxis()->SetRangeUser(0,1000);
hardqeta_N300->SetLineColor(kRed);
hardqeta_N300->SetLineWidth(2);
hardqeta_N300->Draw("hist");
hardqeta_N600->Scale(hardqeta_N300->GetEntries()/hardqeta_N600->GetEntries());
hardqeta_N600->Rebin(2);
hardqeta_N600->SetLineColor(kGreen+1);
hardqeta_N600->SetLineWidth(2);
hardqeta_N600->Draw("same hist");
hardqeta_N1000->Scale(hardqeta_N300->GetEntries()/hardqeta_N1000->GetEntries());
hardqeta_N1000->Rebin(2);
hardqeta_N1000->SetLineColor(kBlue);
hardqeta_N1000->SetLineWidth(2);
hardqeta_N1000->Draw("same hist");

TLegend* hardqeta_legend = new TLegend(0.62,0.75,0.9,0.9);
hardqeta_legend->AddEntry(hardqeta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
hardqeta_legend->AddEntry(hardqeta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
hardqeta_legend->AddEntry(hardqeta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
hardqeta_legend->Draw();
}



if(c29){
c29->cd();

Wq1pt_L300->SetTitle("W_q1 pt #scale[0.8]{(NLO vs LO) : High mass}");
Wq1pt_L300->SetStats(0);
Wq1pt_L300->Rebin(20);
Wq1pt_L300->GetXaxis()->SetRangeUser(0,800);
//Wq1pt_L300->GetYaxis()->SetRangeUser(0,30000);
Wq1pt_L300->SetLineColor(kRed);
Wq1pt_L300->SetLineWidth(3);
Wq1pt_L300->SetLineStyle(7);
Wq1pt_L300->Draw("hist");
Wq1pt_L600->Scale(Wq1pt_L300->GetEntries()/Wq1pt_L600->GetEntries());
Wq1pt_L600->Rebin(20);
Wq1pt_L600->SetLineColor(kGreen+1);
Wq1pt_L600->SetLineWidth(3);
Wq1pt_L600->SetLineStyle(7);
Wq1pt_L600->Draw("same hist");
Wq1pt_L1000->Scale(Wq1pt_L300->GetEntries()/Wq1pt_L1000->GetEntries());
Wq1pt_L1000->Rebin(20);
Wq1pt_L1000->SetLineColor(kBlue);
Wq1pt_L1000->SetLineWidth(3);
Wq1pt_L1000->SetLineStyle(7);
Wq1pt_L1000->Draw("same hist");
Wq1pt_N300->SetStats(0);
Wq1pt_N300->Scale(Wq1pt_L300->GetEntries()/Wq1pt_N300->GetEntries());
Wq1pt_N300->Rebin(20);
Wq1pt_N300->SetLineColor(kRed);
Wq1pt_N300->SetLineWidth(2);
Wq1pt_N300->Draw("same hist");
Wq1pt_N600->Scale(Wq1pt_L300->GetEntries()/Wq1pt_N600->GetEntries());
Wq1pt_N600->Rebin(20);
Wq1pt_N600->SetLineColor(kGreen+1);
Wq1pt_N600->SetLineWidth(2);
Wq1pt_N600->Draw("same hist");
Wq1pt_N1000->Scale(Wq1pt_L300->GetEntries()/Wq1pt_N1000->GetEntries());
Wq1pt_N1000->Rebin(20);
Wq1pt_N1000->SetLineColor(kBlue);
Wq1pt_N1000->SetLineWidth(2);
Wq1pt_N1000->Draw("same hist");

TLegend* Wq1pt_legend = new TLegend(0.62,0.75,0.9,0.9);
Wq1pt_legend->AddEntry(Wq1pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Wq1pt_legend->AddEntry(Wq1pt_L300,"#scale[0.9]{LO}","l");
Wq1pt_legend->AddEntry(Wq1pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Wq1pt_legend->AddEntry(Wq1pt_L600,"#scale[0.9]{LO}","l");
Wq1pt_legend->AddEntry(Wq1pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Wq1pt_legend->AddEntry(Wq1pt_L1000,"#scale[0.9]{LO}","l");
Wq1pt_legend->Draw();
}



if(c30){
c30->cd();

Wq1eta_L300->SetTitle("W_q1 #eta #scale[0.8]{(NLO vs LO) : High mass}");
Wq1eta_L300->SetStats(0);
Wq1eta_L300->Rebin(2);
Wq1eta_L300->GetYaxis()->SetRangeUser(0,13000);
Wq1eta_L300->SetLineColor(kRed);
Wq1eta_L300->SetLineWidth(3);
Wq1eta_L300->SetLineStyle(7);
Wq1eta_L300->Draw("hist");
Wq1eta_L600->Scale(Wq1eta_L300->GetEntries()/Wq1eta_L600->GetEntries());
Wq1eta_L600->Rebin(2);
Wq1eta_L600->SetLineColor(kGreen+1);
Wq1eta_L600->SetLineWidth(3);
Wq1eta_L600->SetLineStyle(7);
Wq1eta_L600->Draw("same hist");
Wq1eta_L1000->Scale(Wq1eta_L300->GetEntries()/Wq1eta_L1000->GetEntries());
Wq1eta_L1000->Rebin(2);
Wq1eta_L1000->SetLineColor(kBlue);
Wq1eta_L1000->SetLineWidth(3);
Wq1eta_L1000->SetLineStyle(7);
Wq1eta_L1000->Draw("same hist");
Wq1eta_N300->SetStats(0);
Wq1eta_N300->Scale(Wq1eta_L300->GetEntries()/Wq1eta_N300->GetEntries());
Wq1eta_N300->Rebin(2);
Wq1eta_N300->SetLineColor(kRed);
Wq1eta_N300->SetLineWidth(2);
Wq1eta_N300->Draw("same hist");
Wq1eta_N600->Scale(Wq1eta_L300->GetEntries()/Wq1eta_N600->GetEntries());
Wq1eta_N600->Rebin(2);
Wq1eta_N600->SetLineColor(kGreen+1);
Wq1eta_N600->SetLineWidth(2);
Wq1eta_N600->Draw("same hist");
Wq1eta_N1000->Scale(Wq1eta_L300->GetEntries()/Wq1eta_N1000->GetEntries());
Wq1eta_N1000->Rebin(2);
Wq1eta_N1000->SetLineColor(kBlue);
Wq1eta_N1000->SetLineWidth(2);
Wq1eta_N1000->Draw("same hist");

TLegend* Wq1eta_legend = new TLegend(0.62,0.75,0.9,0.9);
Wq1eta_legend->AddEntry(Wq1eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Wq1eta_legend->AddEntry(Wq1eta_L300,"#scale[0.9]{LO}","l");
Wq1eta_legend->AddEntry(Wq1eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Wq1eta_legend->AddEntry(Wq1eta_L600,"#scale[0.9]{LO}","l");
Wq1eta_legend->AddEntry(Wq1eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Wq1eta_legend->AddEntry(Wq1eta_L1000,"#scale[0.9]{LO}","l");
Wq1eta_legend->Draw();
}


if(c31){
c31->cd();

Wq2pt_L300->SetTitle("W_q2 pt #scale[0.8]{(NLO vs LO) : High mass}");
Wq2pt_L300->SetStats(0);
Wq2pt_L300->Rebin(10);
Wq2pt_L300->GetXaxis()->SetRangeUser(0,400);
//Wq2pt_L300->GetYaxis()->SetRangeUser(0,30000);
Wq2pt_L300->SetLineColor(kRed);
Wq2pt_L300->SetLineWidth(3);
Wq2pt_L300->SetLineStyle(7);
Wq2pt_L300->Draw("hist");
Wq2pt_L600->Scale(Wq2pt_L300->GetEntries()/Wq2pt_L600->GetEntries());
Wq2pt_L600->Rebin(10);
Wq2pt_L600->SetLineColor(kGreen+1);
Wq2pt_L600->SetLineWidth(3);
Wq2pt_L600->SetLineStyle(7);
Wq2pt_L600->Draw("same hist");
Wq2pt_L1000->Scale(Wq2pt_L300->GetEntries()/Wq2pt_L1000->GetEntries());
Wq2pt_L1000->Rebin(10);
Wq2pt_L1000->SetLineColor(kBlue);
Wq2pt_L1000->SetLineWidth(3);
Wq2pt_L1000->SetLineStyle(7);
Wq2pt_L1000->Draw("same hist");
Wq2pt_N300->SetStats(0);
Wq2pt_N300->Scale(Wq2pt_L300->GetEntries()/Wq2pt_N300->GetEntries());
Wq2pt_N300->Rebin(10);
Wq2pt_N300->SetLineColor(kRed);
Wq2pt_N300->SetLineWidth(2);
Wq2pt_N300->Draw("same hist");
Wq2pt_N600->Scale(Wq2pt_L300->GetEntries()/Wq2pt_N600->GetEntries());
Wq2pt_N600->Rebin(10);
Wq2pt_N600->SetLineColor(kGreen+1);
Wq2pt_N600->SetLineWidth(2);
Wq2pt_N600->Draw("same hist");
Wq2pt_N1000->Scale(Wq2pt_L300->GetEntries()/Wq2pt_N1000->GetEntries());
Wq2pt_N1000->Rebin(10);
Wq2pt_N1000->SetLineColor(kBlue);
Wq2pt_N1000->SetLineWidth(2);
Wq2pt_N1000->Draw("same hist");

TLegend* Wq2pt_legend = new TLegend(0.62,0.75,0.9,0.9);
Wq2pt_legend->AddEntry(Wq2pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Wq2pt_legend->AddEntry(Wq2pt_L300,"#scale[0.9]{LO}","l");
Wq2pt_legend->AddEntry(Wq2pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Wq2pt_legend->AddEntry(Wq2pt_L600,"#scale[0.9]{LO}","l");
Wq2pt_legend->AddEntry(Wq2pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Wq2pt_legend->AddEntry(Wq2pt_L1000,"#scale[0.9]{LO}","l");
Wq2pt_legend->Draw();
}



if(c32){
c32->cd();

Wq2eta_L300->SetTitle("W_q2 #eta #scale[0.8]{(NLO vs LO) : High mass}");
Wq2eta_L300->SetStats(0);
Wq2eta_L300->Rebin(2);
Wq2eta_L300->GetYaxis()->SetRangeUser(0,12000);
Wq2eta_L300->SetLineColor(kRed);
Wq2eta_L300->SetLineWidth(3);
Wq2eta_L300->SetLineStyle(7);
Wq2eta_L300->Draw("hist");
Wq2eta_L600->Scale(Wq2eta_L300->GetEntries()/Wq2eta_L600->GetEntries());
Wq2eta_L600->Rebin(2);
Wq2eta_L600->SetLineColor(kGreen+1);
Wq2eta_L600->SetLineWidth(3);
Wq2eta_L600->SetLineStyle(7);
Wq2eta_L600->Draw("same hist");
Wq2eta_L1000->Scale(Wq2eta_L300->GetEntries()/Wq2eta_L1000->GetEntries());
Wq2eta_L1000->Rebin(2);
Wq2eta_L1000->SetLineColor(kBlue);
Wq2eta_L1000->SetLineWidth(3);
Wq2eta_L1000->SetLineStyle(7);
Wq2eta_L1000->Draw("same hist");
Wq2eta_N300->SetStats(0);
Wq2eta_N300->Scale(Wq2eta_L300->GetEntries()/Wq2eta_N300->GetEntries());
Wq2eta_N300->Rebin(2);
Wq2eta_N300->SetLineColor(kRed);
Wq2eta_N300->SetLineWidth(2);
Wq2eta_N300->Draw("same hist");
Wq2eta_N600->Scale(Wq2eta_L300->GetEntries()/Wq2eta_N600->GetEntries());
Wq2eta_N600->Rebin(2);
Wq2eta_N600->SetLineColor(kGreen+1);
Wq2eta_N600->SetLineWidth(2);
Wq2eta_N600->Draw("same hist");
Wq2eta_N1000->Scale(Wq2eta_L300->GetEntries()/Wq2eta_N1000->GetEntries());
Wq2eta_N1000->Rebin(2);
Wq2eta_N1000->SetLineColor(kBlue);
Wq2eta_N1000->SetLineWidth(2);
Wq2eta_N1000->Draw("same hist");

TLegend* Wq2eta_legend = new TLegend(0.62,0.75,0.9,0.9);
Wq2eta_legend->AddEntry(Wq2eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
Wq2eta_legend->AddEntry(Wq2eta_L300,"#scale[0.9]{LO}","l");
Wq2eta_legend->AddEntry(Wq2eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
Wq2eta_legend->AddEntry(Wq2eta_L600,"#scale[0.9]{LO}","l");
Wq2eta_legend->AddEntry(Wq2eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
Wq2eta_legend->AddEntry(Wq2eta_L1000,"#scale[0.9]{LO}","l");
Wq2eta_legend->Draw();
}


if(c33){
c33->cd();

dRjj_L300->SetTitle("dR(jj) #scale[0.8]{(NLO vs LO) : High mass}");
dRjj_L300->SetStats(0);
dRjj_L300->Rebin(2);
dRjj_L300->GetYaxis()->SetRangeUser(0,30000);
dRjj_L300->SetLineColor(kRed);
dRjj_L300->SetLineWidth(3);
dRjj_L300->SetLineStyle(7);
dRjj_L300->Draw("hist");
dRjj_L600->Scale(dRjj_L300->GetEntries()/dRjj_L600->GetEntries());
dRjj_L600->Rebin(2);
dRjj_L600->SetLineColor(kGreen+1);
dRjj_L600->SetLineWidth(3);
dRjj_L600->SetLineStyle(7);
dRjj_L600->Draw("same hist");
dRjj_L1000->Scale(dRjj_L300->GetEntries()/dRjj_L1000->GetEntries());
dRjj_L1000->Rebin(2);
dRjj_L1000->SetLineColor(kBlue);
dRjj_L1000->SetLineWidth(3);
dRjj_L1000->SetLineStyle(7);
dRjj_L1000->Draw("same hist");
dRjj_N300->SetStats(0);
dRjj_N300->Scale(dRjj_L300->GetEntries()/dRjj_N300->GetEntries());
dRjj_N300->Rebin(2);
dRjj_N300->SetLineColor(kRed);
dRjj_N300->SetLineWidth(2);
dRjj_N300->Draw("same hist");
dRjj_N600->Scale(dRjj_L300->GetEntries()/dRjj_N600->GetEntries());
dRjj_N600->Rebin(2);
dRjj_N600->SetLineColor(kGreen+1);
dRjj_N600->SetLineWidth(2);
dRjj_N600->Draw("same hist");
dRjj_N1000->Scale(dRjj_L300->GetEntries()/dRjj_N1000->GetEntries());
dRjj_N1000->Rebin(2);
dRjj_N1000->SetLineColor(kBlue);
dRjj_N1000->SetLineWidth(2);
dRjj_N1000->Draw("same hist");

TLegend* dRjj_legend = new TLegend(0.62,0.75,0.9,0.9);
dRjj_legend->AddEntry(dRjj_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L300,"#scale[0.9]{LO}","l");
dRjj_legend->AddEntry(dRjj_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L600,"#scale[0.9]{LO}","l");
dRjj_legend->AddEntry(dRjj_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
dRjj_legend->AddEntry(dRjj_L1000,"#scale[0.9]{LO}","l");
dRjj_legend->Draw();
}


if(c34){
c34->cd();

dRqq_L300->SetTitle("dR(qq) #scale[0.8]{(NLO vs LO) : High mass}");
dRqq_L300->SetStats(0);
dRqq_L300->Rebin(2);
dRqq_L300->GetYaxis()->SetRangeUser(0,50000);
dRqq_L300->SetLineColor(kRed);
dRqq_L300->SetLineWidth(3);
dRqq_L300->SetLineStyle(7);
dRqq_L300->Draw("hist");
dRqq_L600->Scale(dRqq_L300->GetEntries()/dRqq_L600->GetEntries());
dRqq_L600->Rebin(2);
dRqq_L600->SetLineColor(kGreen+1);
dRqq_L600->SetLineWidth(3);
dRqq_L600->SetLineStyle(7);
dRqq_L600->Draw("same hist");
dRqq_L1000->Scale(dRqq_L300->GetEntries()/dRqq_L1000->GetEntries());
dRqq_L1000->Rebin(2);
dRqq_L1000->SetLineColor(kBlue);
dRqq_L1000->SetLineWidth(3);
dRqq_L1000->SetLineStyle(7);
dRqq_L1000->Draw("same hist");
dRqq_N300->SetStats(0);
dRqq_N300->Scale(dRqq_L300->GetEntries()/dRqq_N300->GetEntries());
dRqq_N300->Rebin(2);
dRqq_N300->SetLineColor(kRed);
dRqq_N300->SetLineWidth(2);
dRqq_N300->Draw("same hist");
dRqq_N600->Scale(dRqq_L300->GetEntries()/dRqq_N600->GetEntries());
dRqq_N600->Rebin(2);
dRqq_N600->SetLineColor(kGreen+1);
dRqq_N600->SetLineWidth(2);
dRqq_N600->Draw("same hist");
dRqq_N1000->Scale(dRqq_L300->GetEntries()/dRqq_N1000->GetEntries());
dRqq_N1000->Rebin(2);
dRqq_N1000->SetLineColor(kBlue);
dRqq_N1000->SetLineWidth(2);
dRqq_N1000->Draw("same hist");

TLegend* dRqq_legend = new TLegend(0.62,0.75,0.9,0.9);
dRqq_legend->AddEntry(dRqq_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L300,"#scale[0.9]{LO}","l");
dRqq_legend->AddEntry(dRqq_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L600,"#scale[0.9]{LO}","l");
dRqq_legend->AddEntry(dRqq_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
dRqq_legend->AddEntry(dRqq_L1000,"#scale[0.9]{LO}","l");
dRqq_legend->Draw();
}




if(c35){
c35->cd();

W2pt_L300->SetTitle("W2 pt #scale[0.8]{(NLO vs LO) : High mass}");
W2pt_L300->SetStats(0);
W2pt_L300->Rebin(20);
W2pt_L300->GetXaxis()->SetRangeUser(0,1000);
//W2pt_L300->GetYaxis()->SetRangeUser(0,8500);
W2pt_L300->SetLineColor(kRed);
W2pt_L300->SetLineWidth(3);
W2pt_L300->SetLineStyle(7);
W2pt_L300->Draw("hist");
W2pt_L600->Scale(W2pt_L300->GetEntries()/W2pt_L600->GetEntries());
W2pt_L600->Rebin(20);
W2pt_L600->SetLineColor(kGreen+1);
W2pt_L600->SetLineWidth(3);
W2pt_L600->SetLineStyle(7);
W2pt_L600->Draw("same hist");
W2pt_L1000->Scale(W2pt_L300->GetEntries()/W2pt_L1000->GetEntries());
W2pt_L1000->Rebin(20);
W2pt_L1000->SetLineColor(kBlue);
W2pt_L1000->SetLineWidth(3);
W2pt_L1000->SetLineStyle(7);
W2pt_L1000->Draw("same hist");
W2pt_N300->SetStats(0);
W2pt_N300->Scale(W2pt_L300->GetEntries()/W2pt_N300->GetEntries());
W2pt_N300->Rebin(20);
W2pt_N300->SetLineColor(kRed);
W2pt_N300->SetLineWidth(2);
W2pt_N300->Draw("same hist");
W2pt_N600->Scale(W2pt_L300->GetEntries()/W2pt_N600->GetEntries());
W2pt_N600->Rebin(20);
W2pt_N600->SetLineColor(kGreen+1);
W2pt_N600->SetLineWidth(2);
W2pt_N600->Draw("same hist");
W2pt_N1000->Scale(W2pt_L300->GetEntries()/W2pt_N1000->GetEntries());
W2pt_N1000->Rebin(20);
W2pt_N1000->SetLineColor(kBlue);
W2pt_N1000->SetLineWidth(2);
W2pt_N1000->Draw("same hist");

TLegend* W2pt_legend = new TLegend(0.62,0.75,0.9,0.9);
W2pt_legend->AddEntry(W2pt_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W2pt_legend->AddEntry(W2pt_L300,"#scale[0.9]{LO}","l");
W2pt_legend->AddEntry(W2pt_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W2pt_legend->AddEntry(W2pt_L600,"#scale[0.9]{LO}","l");
W2pt_legend->AddEntry(W2pt_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W2pt_legend->AddEntry(W2pt_L1000,"#scale[0.9]{LO}","l");
W2pt_legend->Draw();
}





if(c36){
c36->cd();

W2eta_L300->SetTitle("W2 eta #scale[0.8]{(NLO vs LO) : High mass}");
W2eta_L300->SetStats(0);
W2eta_L300->Rebin(2);
W2eta_L300->GetYaxis()->SetRangeUser(0,12000);
W2eta_L300->SetLineColor(kRed);
W2eta_L300->SetLineWidth(3);
W2eta_L300->SetLineStyle(7);
W2eta_L300->Draw("hist");
W2eta_L600->Scale(W2eta_L300->GetEntries()/W2eta_L600->GetEntries());
W2eta_L600->Rebin(2);
W2eta_L600->SetLineColor(kGreen+1);
W2eta_L600->SetLineWidth(3);
W2eta_L600->SetLineStyle(7);
W2eta_L600->Draw("same hist");
W2eta_L1000->Scale(W2eta_L300->GetEntries()/W2eta_L1000->GetEntries());
W2eta_L1000->Rebin(2);
W2eta_L1000->SetLineColor(kBlue);
W2eta_L1000->SetLineWidth(3);
W2eta_L1000->SetLineStyle(7);
W2eta_L1000->Draw("same hist");
W2eta_N300->SetStats(0);
W2eta_N300->Scale(W2eta_L300->GetEntries()/W2eta_N300->GetEntries());
W2eta_N300->Rebin(2);
W2eta_N300->SetLineColor(kRed);
W2eta_N300->SetLineWidth(2);
W2eta_N300->Draw("same hist");
W2eta_N600->Scale(W2eta_L300->GetEntries()/W2eta_N600->GetEntries());
W2eta_N600->Rebin(2);
W2eta_N600->SetLineColor(kGreen+1);
W2eta_N600->SetLineWidth(2);
W2eta_N600->Draw("same hist");
W2eta_N1000->Scale(W2eta_L300->GetEntries()/W2eta_N1000->GetEntries());
W2eta_N1000->Rebin(2);
W2eta_N1000->SetLineColor(kBlue);
W2eta_N1000->SetLineWidth(2);
W2eta_N1000->Draw("same hist");

TLegend* W2eta_legend = new TLegend(0.62,0.75,0.9,0.9);
W2eta_legend->AddEntry(W2eta_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W2eta_legend->AddEntry(W2eta_L300,"#scale[0.9]{LO}","l");
W2eta_legend->AddEntry(W2eta_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W2eta_legend->AddEntry(W2eta_L600,"#scale[0.9]{LO}","l");
W2eta_legend->AddEntry(W2eta_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W2eta_legend->AddEntry(W2eta_L1000,"#scale[0.9]{LO}","l");
W2eta_legend->Draw();
}


if(c37){
c37->cd();

W2mass_L300->SetTitle("W2 mass #scale[0.8]{(NLO vs LO) : High mass}");
W2mass_L300->SetStats(0);
W2mass_L300->Rebin(2);
W2mass_L300->GetXaxis()->SetRangeUser(0,150);
//W2mass_L300->GetYaxis()->SetRangeUser(0,12000);
W2mass_L300->SetLineColor(kRed);
W2mass_L300->SetLineWidth(3);
W2mass_L300->SetLineStyle(7);
W2mass_L300->Draw("hist");
W2mass_L600->Scale(W2mass_L300->GetEntries()/W2mass_L600->GetEntries());
W2mass_L600->Rebin(2);
W2mass_L600->SetLineColor(kGreen+1);
W2mass_L600->SetLineWidth(3);
W2mass_L600->SetLineStyle(7);
W2mass_L600->Draw("same hist");
W2mass_L1000->Scale(W2mass_L300->GetEntries()/W2mass_L1000->GetEntries());
W2mass_L1000->Rebin(2);
W2mass_L1000->SetLineColor(kBlue);
W2mass_L1000->SetLineWidth(3);
W2mass_L1000->SetLineStyle(7);
W2mass_L1000->Draw("same hist");
W2mass_N300->SetStats(0);
W2mass_N300->Scale(W2mass_L300->GetEntries()/W2mass_N300->GetEntries());
W2mass_N300->Rebin(2);
W2mass_N300->SetLineColor(kRed);
W2mass_N300->SetLineWidth(2);
W2mass_N300->Draw("same hist");
W2mass_N600->Scale(W2mass_L300->GetEntries()/W2mass_N600->GetEntries());
W2mass_N600->Rebin(2);
W2mass_N600->SetLineColor(kGreen+1);
W2mass_N600->SetLineWidth(2);
W2mass_N600->Draw("same hist");
W2mass_N1000->Scale(W2mass_L300->GetEntries()/W2mass_N1000->GetEntries());
W2mass_N1000->Rebin(2);
W2mass_N1000->SetLineColor(kBlue);
W2mass_N1000->SetLineWidth(2);
W2mass_N1000->Draw("same hist");

TLegend* W2mass_legend = new TLegend(0.62,0.75,0.9,0.9);
W2mass_legend->AddEntry(W2mass_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
W2mass_legend->AddEntry(W2mass_L300,"#scale[0.9]{LO}","l");
W2mass_legend->AddEntry(W2mass_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
W2mass_legend->AddEntry(W2mass_L600,"#scale[0.9]{LO}","l");
W2mass_legend->AddEntry(W2mass_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
W2mass_legend->AddEntry(W2mass_L1000,"#scale[0.9]{LO}","l");
W2mass_legend->Draw();
}


if(c38){
c38->cd();

MET_L300->SetTitle("MET #scale[0.8]{(NLO vs LO) : High mass}");
MET_L300->SetStats(0);
MET_L300->GetXaxis()->SetRangeUser(0,5);
//MET_L300->GetYaxis()->SetRangeUser(0,8500);
MET_L300->SetLineColor(kRed);
MET_L300->SetLineWidth(3);
MET_L300->SetLineStyle(7);
MET_L300->Draw("hist");
MET_L600->Scale(MET_L300->GetEntries()/MET_L600->GetEntries());
MET_L600->SetLineColor(kGreen+1);
MET_L600->SetLineWidth(3);
MET_L600->SetLineStyle(7);
MET_L600->Draw("same hist");
MET_L1000->Scale(MET_L300->GetEntries()/MET_L1000->GetEntries());
MET_L1000->SetLineColor(kBlue);
MET_L1000->SetLineWidth(3);
MET_L1000->SetLineStyle(7);
MET_L1000->Draw("same hist");
MET_N300->SetStats(0);
MET_N300->Scale(MET_L300->GetEntries()/MET_N300->GetEntries());
MET_N300->SetLineColor(kRed);
MET_N300->SetLineWidth(2);
MET_N300->Draw("same hist");
MET_N600->Scale(MET_L300->GetEntries()/MET_N600->GetEntries());
MET_N600->SetLineColor(kGreen+1);
MET_N600->SetLineWidth(2);
MET_N600->Draw("same hist");
MET_N1000->Scale(MET_L300->GetEntries()/MET_N1000->GetEntries());
MET_N1000->SetLineColor(kBlue);
MET_N1000->SetLineWidth(2);
MET_N1000->Draw("same hist");

TLegend* MET_legend = new TLegend(0.62,0.75,0.9,0.9);
MET_legend->AddEntry(MET_N300,"Sch #mu#mu m_{N}=300GeV, NLO","l");
MET_legend->AddEntry(MET_L300,"#scale[0.9]{LO}","l");
MET_legend->AddEntry(MET_N600,"Sch #mu#mu m_{N}=600GeV, NLO","l");
MET_legend->AddEntry(MET_L600,"#scale[0.9]{LO}","l");
MET_legend->AddEntry(MET_N1000,"Sch #mu#mu m_{N}=1000GeV, NLO","l");
MET_legend->AddEntry(MET_L1000,"#scale[0.9]{LO}","l");
MET_legend->Draw();
}



//c1->SaveAs("Tch_kinematics/mlljj.pdf");
//c2->SaveAs("Tch_kinematics/ml1jj.pdf");
//c3->SaveAs("Tch_kinematics/ml2jj.pdf");
//c4->SaveAs("Tch_kinematics/N_pt.pdf");
//c5->SaveAs("Tch_kinematics/N_eta.pdf");
//c6->SaveAs("Tch_kinematics/N_energy.pdf");
//c7->SaveAs("Tch_kinematics/Nl_pt.pdf");
////c8->SaveAs("Tch_kinematics/Nl_pt_NLO.pdf");
//c9->SaveAs("Tch_kinematics/Nl_eta.pdf");
//c10->SaveAs("Tch_kinematics/W1_pt.pdf");
//c11->SaveAs("Tch_kinematics/W1_eta.pdf");
//c12->SaveAs("Tch_kinematics/W1_mass.pdf");
//c13->SaveAs("Tch_kinematics/W1_energy.pdf");
//c14->SaveAs("Tch_kinematics/Wl_pt.pdf");
//c15->SaveAs("Tch_kinematics/Wl_eta.pdf");
//c16->SaveAs("Tch_kinematics/j1_pt.pdf");
//c17->SaveAs("Tch_kinematics/j1_eta.pdf");
//c18->SaveAs("Tch_kinematics/j2_pt.pdf");
//c19->SaveAs("Tch_kinematics/j2_eta.pdf");
//c20->SaveAs("Tch_kinematics/fatjet_pt.pdf");
//c21->SaveAs("Tch_kinematics/fatjet_eta.pdf");
//c22->SaveAs("Tch_kinematics/fatjet_mass.pdf");
//c23->SaveAs("Tch_kinematics/dijet_mass.pdf");
//c24->SaveAs("Tch_kinematics/mllJ.pdf");
//c25->SaveAs("Tch_kinematics/ml1J.pdf");
//c26->SaveAs("Tch_kinematics/ml2J.pdf");
//c27->SaveAs("Tch_kinematics/hard_q_pt.pdf");
//c28->SaveAs("Tch_kinematics/hard_q_eta.pdf");
//c29->SaveAs("Tch_kinematics/W_q1_pt.pdf");
//c30->SaveAs("Tch_kinematics/W_q1_eta.pdf");
//c31->SaveAs("Tch_kinematics/W_q2_pt.pdf");
//c32->SaveAs("Tch_kinematics/W_q2_eta.pdf");
//c33->SaveAs("Tch_kinematics/dRjj.pdf");
//c34->SaveAs("Tch_kinematics/dRqq.pdf");
//c35->SaveAs("Tch_kinematics/W2_pt.pdf");
//c36->SaveAs("Tch_kinematics/W2_eta.pdf");
//c37->SaveAs("Tch_kinematics/W2_mass.pdf");
//c38->SaveAs("Tch_kinematics/MET.pdf");



}
