{
TString LO_filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M40.root";
TString LO_filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M50.root";
TString LO_filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M60.root";
TString LO_filename4 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M70.root";
TString LO_filename5 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_LO_MuMu_M75.root";
TFile* L40 = new TFile(LO_filename1);
TFile* L50 = new TFile(LO_filename2);
TFile* L60 = new TFile(LO_filename3);
TFile* L70 = new TFile(LO_filename4);
TFile* L75 = new TFile(LO_filename5);
TString NLO_filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M40.root";
TString NLO_filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M50.root";
TString NLO_filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M60.root";
TString NLO_filename4 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M70.root";
TString NLO_filename5 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Sch_MG_HeavyMajoranaNeutrino_SSDiLepton_Schannel_NLO_MuMu_M75.root";
TFile* N40 = new TFile(NLO_filename1);
TFile* N50 = new TFile(NLO_filename2);
TFile* N60 = new TFile(NLO_filename3);
TFile* N70 = new TFile(NLO_filename4);
TFile* N75 = new TFile(NLO_filename5);


gSystem->Exec("mkdir -p Sch_kinematics/LM/comparisons");


TH1D* mlljj_L40 = (TH1D*)L40->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L40 = (TH1D*)L40->Get("(l0+dijet)_m");
TH1D* ml2jj_L40 = (TH1D*)L40->Get("(l1+dijet)_m");
TH1D* dRjj_L40 = (TH1D*)L40->Get("DeltaR(jj)");
TH1D* Npt_L40 = (TH1D*)L40->Get("last_HN_pt");
TH1D* Neta_L40 = (TH1D*)L40->Get("last_HN_eta");
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

//TH1D* mllj_L40 = (TH1D*)L40->Get("(SS2l+dijet)_m");
//TH1D* ml1j_L40 = (TH1D*)L40->Get("(SS2l+dijet)_m");
//TH1D* ml2j_L40 = (TH1D*)L40->Get("(SS2l+dijet)_m");


TH1D* mlljj_L50 = (TH1D*)L50->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L50 = (TH1D*)L50->Get("(l0+dijet)_m");
TH1D* ml2jj_L50 = (TH1D*)L50->Get("(l1+dijet)_m");
TH1D* dRjj_L50 = (TH1D*)L50->Get("DeltaR(jj)");
TH1D* Npt_L50 = (TH1D*)L50->Get("last_HN_pt");
TH1D* Neta_L50 = (TH1D*)L50->Get("last_HN_eta");
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

//TH1D* mllj_L50 = (TH1D*)L50->Get("(SS2l+dijet)_m");
//TH1D* ml1j_L50 = (TH1D*)L50->Get("(SS2l+dijet)_m");
//TH1D* ml2j_L50 = (TH1D*)L50->Get("(SS2l+dijet)_m");


TH1D* mlljj_L60 = (TH1D*)L60->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L60 = (TH1D*)L60->Get("(l0+dijet)_m");
TH1D* ml2jj_L60 = (TH1D*)L60->Get("(l1+dijet)_m");
TH1D* dRjj_L60 = (TH1D*)L60->Get("DeltaR(jj)");
TH1D* Npt_L60 = (TH1D*)L60->Get("last_HN_pt");
TH1D* Neta_L60 = (TH1D*)L60->Get("last_HN_eta");
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

//TH1D* mllj_L60 = (TH1D*)L60->Get("(SS2l+dijet)_m");
//TH1D* ml1j_L60 = (TH1D*)L60->Get("(SS2l+dijet)_m");
//TH1D* ml2j_L60 = (TH1D*)L60->Get("(SS2l+dijet)_m");


TH1D* mlljj_L70 = (TH1D*)L70->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L70 = (TH1D*)L70->Get("(l0+dijet)_m");
TH1D* ml2jj_L70 = (TH1D*)L70->Get("(l1+dijet)_m");
TH1D* dRjj_L70 = (TH1D*)L70->Get("DeltaR(jj)");
TH1D* Npt_L70 = (TH1D*)L70->Get("last_HN_pt");
TH1D* Neta_L70 = (TH1D*)L70->Get("last_HN_eta");
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

//TH1D* mllj_L70 = (TH1D*)L70->Get("(SS2l+dijet)_m");
//TH1D* ml1j_L70 = (TH1D*)L70->Get("(SS2l+dijet)_m");
//TH1D* ml2j_L70 = (TH1D*)L70->Get("(SS2l+dijet)_m");


TH1D* mlljj_L75 = (TH1D*)L75->Get("(SS2l+dijet)_m");
TH1D* ml1jj_L75 = (TH1D*)L75->Get("(l0+dijet)_m");
TH1D* ml2jj_L75 = (TH1D*)L75->Get("(l1+dijet)_m");
TH1D* dRjj_L75 = (TH1D*)L75->Get("DeltaR(jj)");
TH1D* Npt_L75 = (TH1D*)L75->Get("last_HN_pt");
TH1D* Neta_L75 = (TH1D*)L75->Get("last_HN_eta");
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

//TH1D* mllj_L75 = (TH1D*)L75->Get("(SS2l+dijet)_m");
//TH1D* ml1j_L75 = (TH1D*)L75->Get("(SS2l+dijet)_m");
//TH1D* ml2j_L75 = (TH1D*)L75->Get("(SS2l+dijet)_m");


//========================NLO========================//


TH1D* mlljj_N40 = (TH1D*)N40->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N40 = (TH1D*)N40->Get("(l0+dijet)_m");
TH1D* ml2jj_N40 = (TH1D*)N40->Get("(l1+dijet)_m");
TH1D* dRjj_N40 = (TH1D*)N40->Get("DeltaR(jj)");
TH1D* Npt_N40 = (TH1D*)N40->Get("last_HN_pt");
TH1D* Neta_N40 = (TH1D*)N40->Get("last_HN_eta");
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

//TH1D* mllj_N40 = (TH1D*)N40->Get("(SS2l+dijet)_m");
//TH1D* ml1j_N40 = (TH1D*)N40->Get("(SS2l+dijet)_m");
//TH1D* ml2j_N40 = (TH1D*)N40->Get("(SS2l+dijet)_m");


TH1D* mlljj_N50 = (TH1D*)N50->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N50 = (TH1D*)N50->Get("(l0+dijet)_m");
TH1D* ml2jj_N50 = (TH1D*)N50->Get("(l1+dijet)_m");
TH1D* dRjj_N50 = (TH1D*)N50->Get("DeltaR(jj)");
TH1D* Npt_N50 = (TH1D*)N50->Get("last_HN_pt");
TH1D* Neta_N50 = (TH1D*)N50->Get("last_HN_eta");
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

//TH1D* mllj_N50 = (TH1D*)N50->Get("(SS2l+dijet)_m");
//TH1D* ml1j_N50 = (TH1D*)N50->Get("(SS2l+dijet)_m");
//TH1D* ml2j_N50 = (TH1D*)N50->Get("(SS2l+dijet)_m");


TH1D* mlljj_N60 = (TH1D*)N60->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N60 = (TH1D*)N60->Get("(l0+dijet)_m");
TH1D* ml2jj_N60 = (TH1D*)N60->Get("(l1+dijet)_m");
TH1D* dRjj_N60 = (TH1D*)N60->Get("DeltaR(jj)");
TH1D* Npt_N60 = (TH1D*)N60->Get("last_HN_pt");
TH1D* Neta_N60 = (TH1D*)N60->Get("last_HN_eta");
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

//TH1D* mllj_N60 = (TH1D*)N60->Get("(SS2l+dijet)_m");
//TH1D* ml1j_N60 = (TH1D*)N60->Get("(SS2l+dijet)_m");
//TH1D* ml2j_N60 = (TH1D*)N60->Get("(SS2l+dijet)_m");


TH1D* mlljj_N70 = (TH1D*)N70->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N70 = (TH1D*)N70->Get("(l0+dijet)_m");
TH1D* ml2jj_N70 = (TH1D*)N70->Get("(l1+dijet)_m");
TH1D* dRjj_N70 = (TH1D*)N70->Get("DeltaR(jj)");
TH1D* Npt_N70 = (TH1D*)N70->Get("last_HN_pt");
TH1D* Neta_N70 = (TH1D*)N70->Get("last_HN_eta");
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

//TH1D* mllj_N70 = (TH1D*)N70->Get("(SS2l+dijet)_m");
//TH1D* ml1j_N70 = (TH1D*)N70->Get("(SS2l+dijet)_m");
//TH1D* ml2j_N70 = (TH1D*)N70->Get("(SS2l+dijet)_m");


TH1D* mlljj_N75 = (TH1D*)N75->Get("(SS2l+dijet)_m");
TH1D* ml1jj_N75 = (TH1D*)N75->Get("(l0+dijet)_m");
TH1D* ml2jj_N75 = (TH1D*)N75->Get("(l1+dijet)_m");
TH1D* dRjj_N75 = (TH1D*)N75->Get("DeltaR(jj)");
TH1D* Npt_N75 = (TH1D*)N75->Get("last_HN_pt");
TH1D* Neta_N75 = (TH1D*)N75->Get("last_HN_eta");
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

//TH1D* mllj_N75 = (TH1D*)N75->Get("(SS2l+dijet)_m");
//TH1D* ml1j_N75 = (TH1D*)N75->Get("(SS2l+dijet)_m");
//TH1D* ml2j_N75 = (TH1D*)N75->Get("(SS2l+dijet)_m");


// TODO : MET distribution (See Fig.57- in AN17-291)
// TODO : dRqq, q0 pt/eta, q1 pt/eta distribution
// TODO : fraction of l1 gen-matched to Nl out of total 
// TODO : pt+eta efficiency


TCanvas* c1 = new TCanvas("c1","mlljj",200,350,700,650);
TCanvas* c2 = new TCanvas("c2","ml1jj",220,330,700,650);
TCanvas* c3 = new TCanvas("c3","ml2jj",240,310,700,650);
TCanvas* c4 = new TCanvas("c4","Npt",260,290,700,650);
TCanvas* c5 = new TCanvas("c5","Neta",280,270,700,650);
TCanvas* c6 = new TCanvas("c6","Nlpt",300,250,700,650);
TCanvas* c7 = new TCanvas("c7","Nlpt NLO",320,230,700,650);
TCanvas* c8 = new TCanvas("c8","Nleta",340,210,700,650);
TCanvas* c9 = new TCanvas("c9","Wlpt",360,190,700,650);
TCanvas* c10 = new TCanvas("c10","Wleta",380,170,700,650);



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


c2->cd();

ml1jj_L40->SetTitle("m(lljj) #scale[0.8]{(NLO vs LO) : Low mass}");
ml1jj_L40->SetStats(0);
ml1jj_L40->Rebin(10);
ml1jj_L40->GetXaxis()->SetRangeUser(0,300);
ml1jj_L40->GetYaxis()->SetRangeUser(0,30000);
ml1jj_L40->SetLineColor(kRed);
ml1jj_L40->SetLineWidth(3);
ml1jj_L40->SetLineStyle(7);
ml1jj_L40->Draw("hist");
ml1jj_L50->Scale(mlljj_L40->GetEntries()/mlljj_L50->GetEntries());
ml1jj_L50->Rebin(10);
ml1jj_L50->SetLineColor(kOrange+1);
ml1jj_L50->SetLineWidth(3);
ml1jj_L50->SetLineStyle(7);
ml1jj_L50->Draw("same hist");
ml1jj_L60->Scale(mlljj_L40->GetEntries()/mlljj_L60->GetEntries());
ml1jj_L60->Rebin(10);
ml1jj_L60->SetLineColor(kGreen+1);
ml1jj_L60->SetLineWidth(3);
ml1jj_L60->SetLineStyle(7);
ml1jj_L60->Draw("same hist");
ml1jj_L70->Scale(mlljj_L40->GetEntries()/mlljj_L70->GetEntries());
ml1jj_L70->Rebin(10);
ml1jj_L70->SetLineColor(kBlue);
ml1jj_L70->SetLineWidth(3);
ml1jj_L70->SetLineStyle(7);
ml1jj_L70->Draw("same hist");
ml1jj_N40->SetStats(0);
ml1jj_N40->Scale(mlljj_L40->GetEntries()/mlljj_N40->GetEntries());
ml1jj_N40->Rebin(10);
ml1jj_N40->SetLineColor(kRed);
ml1jj_N40->SetLineWidth(2);
ml1jj_N40->Draw("same hist");
ml1jj_N50->Scale(mlljj_L40->GetEntries()/mlljj_N50->GetEntries());
ml1jj_N50->Rebin(10);
ml1jj_N50->SetLineColor(kOrange+1);
ml1jj_N50->SetLineWidth(2);
ml1jj_N50->Draw("same hist");
ml1jj_N60->Scale(mlljj_L40->GetEntries()/mlljj_N60->GetEntries());
ml1jj_N60->Rebin(10);
ml1jj_N60->SetLineColor(kGreen+1);
ml1jj_N60->SetLineWidth(2);
ml1jj_N60->Draw("same hist");
ml1jj_N70->Scale(mlljj_L40->GetEntries()/mlljj_N70->GetEntries());
ml1jj_N70->Rebin(10);
ml1jj_N70->SetLineColor(kBlue);
ml1jj_N70->SetLineWidth(2);
ml1jj_N70->Draw("same hist");

TLegend* mlljj_legend = new TLegend(0.7,0.7,0.9,0.9);
mlljj_legend->AddEntry(mlljj_N40,"m_{N}=40GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L40,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N50,"m_{N}=50GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L50,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N60,"m_{N}=60GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L60,"#scale[0.9]{LO}","l");
mlljj_legend->AddEntry(mlljj_N70,"m_{N}=70GeV, NLO","l");
mlljj_legend->AddEntry(mlljj_L70,"#scale[0.9]{LO}","l");
mlljj_legend->Draw();







c6->cd();

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


c7->cd();

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

//Nlpt_N40->SetStats(0);
//Nlpt_N40->Scale(Nlpt_L40->GetEntries()/Nlpt_N40->GetEntries());
//Nlpt_N40->Rebin(2);
//Nlpt_N40->SetLineColor(kRed);
//Nlpt_N40->SetLineWidth(2);
//Nlpt_N40->Draw("same hist");
//
//Nlpt_N50->Scale(Nlpt_L40->GetEntries()/Nlpt_N50->GetEntries());
//Nlpt_N50->Rebin(2);
//Nlpt_N50->SetLineColor(kOrange+1);
//Nlpt_N50->SetLineWidth(2);
//Nlpt_N50->Draw("same hist");
//
//Nlpt_N60->Scale(Nlpt_L40->GetEntries()/Nlpt_N60->GetEntries());
//Nlpt_N60->Rebin(2);
//Nlpt_N60->SetLineColor(kGreen+1);
//Nlpt_N60->SetLineWidth(2);
//Nlpt_N60->Draw("same hist");
//
//Nlpt_N70->Scale(Nlpt_L40->GetEntries()/Nlpt_N70->GetEntries());
//Nlpt_N70->Rebin(2);
//Nlpt_N70->SetLineColor(kBlue);
//Nlpt_N70->SetLineWidth(2);
//Nlpt_N70->Draw("same hist");

TLegend* Nlpt_NLO_legend = new TLegend(0.62,0.75,0.9,0.9);
Nlpt_NLO_legend->AddEntry(Nlpt_N40_2,"Sch #mu#mu m_{N}=40GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N50_2,"Sch #mu#mu m_{N}=50GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N60_2,"Sch #mu#mu m_{N}=60GeV, NLO","l");
Nlpt_NLO_legend->AddEntry(Nlpt_N70_2,"Sch #mu#mu m_{N}=70GeV, NLO","l");
Nlpt_NLO_legend->Draw();






}
