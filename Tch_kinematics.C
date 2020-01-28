{
TString filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut5_MuMu_M1000.root";
TString filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut10_MuMu_M1000.root";
TString filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut20_MuMu_M1000.root";
TFile* f1 = new TFile(filename1);
TFile* f2 = new TFile(filename2);
TFile* f3 = new TFile(filename3);
TString V_filename1 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Vanderbilt_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_ptcut5_MuMu_M1000.root";
TString V_filename2 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Vanderbilt_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_ptcut10_MuMu_M1000.root";
TString V_filename3 = "/data6/Users/jihkim/GeneratorTools/Hist/HNtype1_Vanderbilt_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_LO_Vanderbilt_ptcut20_MuMu_M1000.root";
TFile* V_f1 = new TFile(V_filename1);
TFile* V_f2 = new TFile(V_filename2);
TFile* V_f3 = new TFile(V_filename3);


gSystem->Exec("mkdir -p Tch_kinematics/comparisons");


TH1D* gpt1 = (TH1D*)f1->Get("gamma_l_pt");
TH1D* gpt2 = (TH1D*)f2->Get("gamma_l_pt");
TH1D* gpt3 = (TH1D*)f3->Get("gamma_l_pt");
TH1D* geta1 = (TH1D*)f1->Get("gamma_l_eta");
TH1D* geta2 = (TH1D*)f2->Get("gamma_l_eta");
TH1D* geta3 = (TH1D*)f3->Get("gamma_l_eta");
TH1D* hnpt1 = (TH1D*)f1->Get("last_HN_pt");
TH1D* hnpt2 = (TH1D*)f2->Get("last_HN_pt");
TH1D* hnpt3 = (TH1D*)f3->Get("last_HN_pt");
TH1D* hneta1 = (TH1D*)f1->Get("last_HN_eta");
TH1D* hneta2 = (TH1D*)f2->Get("last_HN_eta");
TH1D* hneta3 = (TH1D*)f3->Get("last_HN_eta");
TH1D* j0pt1 = (TH1D*)f1->Get("j0_pt");
TH1D* j0pt2 = (TH1D*)f2->Get("j0_pt");
TH1D* j0pt3 = (TH1D*)f3->Get("j0_pt");
TH1D* j0eta1 = (TH1D*)f1->Get("j0_eta");
TH1D* j0eta2 = (TH1D*)f2->Get("j0_eta");
TH1D* j0eta3 = (TH1D*)f3->Get("j0_eta");

TH1D* V_gpt1 = (TH1D*)V_f1->Get("hard_l_pt");
TH1D* V_gpt2 = (TH1D*)V_f2->Get("hard_l_pt");
TH1D* V_gpt3 = (TH1D*)V_f3->Get("hard_l_pt");
TH1D* V_geta1 = (TH1D*)V_f1->Get("hard_l_eta");
TH1D* V_geta2 = (TH1D*)V_f2->Get("hard_l_eta");
TH1D* V_geta3 = (TH1D*)V_f3->Get("hard_l_eta");
TH1D* V_hnpt1 = (TH1D*)V_f1->Get("last_HN_pt");
TH1D* V_hnpt2 = (TH1D*)V_f2->Get("last_HN_pt");
TH1D* V_hnpt3 = (TH1D*)V_f3->Get("last_HN_pt");
TH1D* V_hneta1 = (TH1D*)V_f1->Get("last_HN_eta");
TH1D* V_hneta2 = (TH1D*)V_f2->Get("last_HN_eta");
TH1D* V_hneta3 = (TH1D*)V_f3->Get("last_HN_eta");
TH1D* V_j0pt1 = (TH1D*)V_f1->Get("j0_pt");
TH1D* V_j0pt2 = (TH1D*)V_f2->Get("j0_pt");
TH1D* V_j0pt3 = (TH1D*)V_f3->Get("j0_pt");
TH1D* V_j0eta1 = (TH1D*)V_f1->Get("j0_eta");
TH1D* V_j0eta2 = (TH1D*)V_f2->Get("j0_eta");
TH1D* V_j0eta3 = (TH1D*)V_f3->Get("j0_eta");
TH1D* V_dEtajj1 = (TH1D*)V_f1->Get("delta eta(forward jj)");
TH1D* V_dEtajj2 = (TH1D*)V_f2->Get("delta eta(forward jj)");
TH1D* V_dEtajj3 = (TH1D*)V_f3->Get("delta eta(forward jj)");

TH1D* geta1_SNU = (TH1D*)geta1->Clone("gamma_l_eta_SNU");
TH1D* geta2_SNU = (TH1D*)geta2->Clone("gamma_l_eta_SNU");
TH1D* geta3_SNU = (TH1D*)geta3->Clone("gamma_l_eta_SNU");


TCanvas* c1 = new TCanvas("c1","hard_l pt",200,350,700,650);
TCanvas* c2 = new TCanvas("c2","hard_l eta",250,300,700,650);

TCanvas* c8 = new TCanvas("c8","hard_l eta (SNU)",300,300,700,650);
TCanvas* c9 = new TCanvas("c9","hard_l eta (Vanderbilt)",350,300,700,650);

TCanvas* c3 = new TCanvas("c3","HN pt",300,250,700,650);
TCanvas* c4 = new TCanvas("c4","HN eta",350,200,700,650);
TCanvas* c5 = new TCanvas("c5","j0 pt",400,150,700,650);
TCanvas* c6 = new TCanvas("c6","j0 eta",450,100,700,650);
TCanvas* c7 = new TCanvas("c7","forward jj dEta",500,50,700,650);


c1->cd();

//gpt1->SetTitle("gamma_l pt");
gpt1->SetTitle("hard_l pt");
gpt1->SetStats(0);
gpt1->Scale(2.49*10000/gpt1->GetEntries());
//gpt1->Scale(10000/gpt1->GetEntries());
gpt1->Rebin(10);
gpt1->GetXaxis()->SetRangeUser(0,400);
gpt1->SetLineColor(kRed);
gpt1->SetLineWidth(2);
gpt1->Draw("hist");

gpt2->Scale(1.95*10000/gpt2->GetEntries());
//gpt2->Scale(10000/gpt2->GetEntries());
gpt2->Rebin(10);
gpt2->SetLineColor(kGreen+1);
gpt2->SetLineWidth(2);
gpt2->Draw("same hist");

gpt3->Scale(1.34*10000/gpt3->GetEntries());
//gpt3->Scale(10000/gpt3->GetEntries());
gpt3->Rebin(10);
gpt3->SetLineColor(kBlue);
gpt3->SetLineWidth(2);
gpt3->Draw("same hist");

V_gpt1->SetStats(0);
V_gpt1->Scale(2.49*0.5);
V_gpt1->Rebin(10);
V_gpt1->SetLineColor(kRed);
V_gpt1->SetLineWidth(3);
V_gpt1->SetLineStyle(7);
V_gpt1->Draw("same hist");

V_gpt2->Scale(1.95*0.5);
V_gpt2->Rebin(10);
V_gpt2->SetLineColor(kGreen+1);
V_gpt2->SetLineWidth(3);
V_gpt2->SetLineStyle(7);
V_gpt2->Draw("same hist");

V_gpt3->Scale(1.34*0.5);
V_gpt3->Rebin(10);
V_gpt3->SetLineColor(kBlue);
V_gpt3->SetLineWidth(3);
V_gpt3->SetLineStyle(7);
V_gpt3->Draw("same hist");

TLegend* gpt_legend = new TLegend(0.75,0.75,0.9,0.9);
gpt_legend->AddEntry(gpt1,"ptcut 5","l");
gpt_legend->AddEntry(V_gpt1,"Vanderbilt","l");
gpt_legend->AddEntry(gpt2,"ptcut 10","l");
gpt_legend->AddEntry(V_gpt2,"Vanderbilt","l");
gpt_legend->AddEntry(gpt3,"ptcut 20","l");
gpt_legend->AddEntry(V_gpt3,"Vanderbilt","l");
gpt_legend->Draw();


//
cout << gpt1->Integral() << endl;
cout << V_gpt1->Integral() << endl;
//

c2->cd();

geta1->SetTitle("hard_l eta");
geta1->SetStats(0);
geta1->Scale(2.49*10000/geta1->GetEntries());
geta1->GetYaxis()->SetRangeUser(0,1200);
geta1->SetLineColor(kRed);
geta1->SetLineWidth(2);
geta1->Draw("hist");
geta2->Scale(1.95*10000/geta2->GetEntries());
geta2->SetLineColor(kGreen+1);
geta2->SetLineWidth(2);
geta2->Draw("same hist");
geta3->Scale(1.34*10000/geta3->GetEntries());
geta3->SetLineColor(kBlue);
geta3->SetLineWidth(2);
geta3->Draw("same hist");

V_geta1->SetStats(0);
V_geta1->Scale(2.49*0.5);
V_geta1->SetLineColor(kRed);
V_geta1->SetLineWidth(3);
V_geta1->SetLineStyle(7);
V_geta1->Draw("same hist");
V_geta2->Scale(1.95*0.5);
V_geta2->SetLineColor(kGreen+1);
V_geta2->SetLineWidth(3);
V_geta2->SetLineStyle(7);
V_geta2->Draw("same hist");
V_geta3->Scale(1.34*0.5);
V_geta3->SetLineColor(kBlue);
V_geta3->SetLineWidth(3);
V_geta3->SetLineStyle(7);
V_geta3->Draw("same hist");


TLegend* geta_legend = new TLegend(0.75,0.75,0.9,0.9);
geta_legend->AddEntry(geta1,"ptcut 5","l");
geta_legend->AddEntry(V_geta1,"Vanderbilt","l");
geta_legend->AddEntry(geta2,"ptcut 10","l");
geta_legend->AddEntry(V_geta2,"Vanderbilt","l");
geta_legend->AddEntry(geta3,"ptcut 20","l");
geta_legend->AddEntry(V_geta3,"Vanderbilt","l");
geta_legend->Draw();



c8->cd();

geta1_SNU->SetTitle("hard_l eta (SNU)");
geta1_SNU->SetStats(0);
geta1_SNU->Scale(2.49*10000/geta1->GetEntries());
geta1_SNU->GetYaxis()->SetRangeUser(0,1200);
geta1_SNU->SetLineColor(kRed);
geta1_SNU->SetLineWidth(2);
geta1_SNU->Draw("hist");
geta2_SNU->Scale(1.95*10000/geta2->GetEntries());
geta2_SNU->SetLineColor(kGreen+1);
geta2_SNU->SetLineWidth(2);
geta2_SNU->Draw("same hist");
geta3_SNU->Scale(1.34*10000/geta3->GetEntries());
geta3_SNU->SetLineColor(kBlue);
geta3_SNU->SetLineWidth(2);
geta3_SNU->Draw("same hist");

TLegend* geta_SNU_legend = new TLegend(0.75,0.75,0.9,0.9);
geta_SNU_legend->AddEntry(geta1_SNU,"ptcut 5","l");
geta_SNU_legend->AddEntry(geta2_SNU,"ptcut 10","l");
geta_SNU_legend->AddEntry(geta3_SNU,"ptcut 20","l");
geta_SNU_legend->Draw();



c9->cd();

V_geta1->SetTitle("hard_l eta (Vanderbilt)");
V_geta1->GetYaxis()->SetRangeUser(0,1200);
V_geta1->Draw("same hist");
V_geta2->Draw("same hist");
V_geta3->Draw("same hist");

TLegend* geta_Vanderbilt_legend = new TLegend(0.75,0.75,0.9,0.9);
geta_Vanderbilt_legend->AddEntry(V_geta1,"ptcut 5","l");
geta_Vanderbilt_legend->AddEntry(V_geta2,"ptcut 10","l");
geta_Vanderbilt_legend->AddEntry(V_geta3,"ptcut 20","l");
geta_Vanderbilt_legend->Draw();



c3->cd();

hnpt1->Scale(2.49*10000/hnpt1->GetEntries());
hnpt1->Rebin(10);
hnpt1->GetXaxis()->SetRangeUser(0,600);
hnpt1->SetTitle("HN pt");
hnpt1->SetStats(0);
hnpt1->SetLineColor(kRed);
hnpt1->SetLineWidth(2);
hnpt1->Draw("hist");
hnpt2->Scale(1.95*10000/hnpt2->GetEntries());
hnpt2->Rebin(10);
hnpt2->SetLineColor(kGreen+1);
hnpt2->SetLineWidth(2);
hnpt2->Draw("same hist");
hnpt3->Scale(1.34*10000/hnpt3->GetEntries());
hnpt3->Rebin(10);
hnpt3->SetLineColor(kBlue);
hnpt3->SetLineWidth(2);
hnpt3->Draw("same hist");

V_hnpt1->Scale(2.49*0.5);
V_hnpt1->Rebin(10);
V_hnpt1->SetStats(0);
V_hnpt1->SetLineColor(kRed);
V_hnpt1->SetLineWidth(3);
V_hnpt1->SetLineStyle(7);
V_hnpt1->Draw("same hist");
V_hnpt2->Scale(1.95*0.5);
V_hnpt2->Rebin(10);
V_hnpt2->SetLineColor(kGreen+1);
V_hnpt2->SetLineWidth(3);
V_hnpt2->SetLineStyle(7);
V_hnpt2->Draw("same hist");
V_hnpt3->Scale(1.34*0.5);
V_hnpt3->Rebin(10);
V_hnpt3->SetLineColor(kBlue);
V_hnpt3->SetLineWidth(3);
V_hnpt3->SetLineStyle(7);
V_hnpt3->Draw("same hist");

TLegend* hnpt_legend = new TLegend(0.75,0.75,0.9,0.9);
hnpt_legend->AddEntry(hnpt1,"ptcut 5","l");
hnpt_legend->AddEntry(V_hnpt1,"Vanderbilt","l");
hnpt_legend->AddEntry(hnpt2,"ptcut 10","l");
hnpt_legend->AddEntry(V_hnpt2,"Vanderbilt","l");
hnpt_legend->AddEntry(hnpt3,"ptcut 20","l");
hnpt_legend->AddEntry(V_hnpt3,"Vanderbilt","l");
hnpt_legend->Draw();


c4->cd();

hneta1->Scale(2.49*10000/hneta1->GetEntries());
hneta1->GetYaxis()->SetRangeUser(0,950);
hneta1->SetTitle("HN eta");
hneta1->SetStats(0);
hneta1->SetLineColor(kRed);
hneta1->SetLineWidth(2);
hneta1->Draw("hist");
hneta2->Scale(1.95*10000/hneta2->GetEntries());
hneta2->SetLineColor(kGreen+1);
hneta2->SetLineWidth(2);
hneta2->Draw("same hist");
hneta3->Scale(1.34*10000/hneta3->GetEntries());
hneta3->SetLineColor(kBlue);
hneta3->SetLineWidth(2);
hneta3->Draw("same hist");

V_hneta1->Scale(2.49*0.5);
V_hneta1->SetStats(0);
V_hneta1->SetLineColor(kRed);
V_hneta1->SetLineWidth(3);
V_hneta1->SetLineStyle(7);
V_hneta1->Draw("same hist");
V_hneta2->Scale(1.95*0.5);
V_hneta2->SetLineColor(kGreen+1);
V_hneta2->SetLineWidth(3);
V_hneta2->SetLineStyle(7);
V_hneta2->Draw("same hist");
V_hneta3->Scale(1.34*0.5);
V_hneta3->SetLineColor(kBlue);
V_hneta3->SetLineWidth(3);
V_hneta3->SetLineStyle(7);
V_hneta3->Draw("same hist");

TLegend* hneta_legend = new TLegend(0.75,0.75,0.9,0.9);
hneta_legend->AddEntry(hneta1,"ptcut 5","l");
hneta_legend->AddEntry(V_hneta1,"Vanderbilt","l");
hneta_legend->AddEntry(hneta2,"ptcut 10","l");
hneta_legend->AddEntry(V_hneta2,"Vanderbilt","l");
hneta_legend->AddEntry(hneta3,"ptcut 20","l");
hneta_legend->AddEntry(V_hneta3,"Vanderbilt","l");
hneta_legend->Draw();


c5->cd();

j0pt1->Scale(2.49*10000/j0pt1->GetEntries());
j0pt1->Rebin(10);
j0pt1->GetXaxis()->SetRangeUser(0,800);
j0pt1->SetTitle("j0 pt");
j0pt1->SetStats(0);
j0pt1->SetLineColor(kRed);
j0pt1->SetLineWidth(2);
j0pt1->Draw("hist");
j0pt2->Scale(1.95*10000/j0pt2->GetEntries());
j0pt2->Rebin(10);
j0pt2->SetLineColor(kGreen+1);
j0pt2->SetLineWidth(2);
j0pt2->Draw("same hist");
j0pt3->Scale(1.34*10000/j0pt3->GetEntries());
j0pt3->Rebin(10);
j0pt3->SetLineColor(kBlue);
j0pt3->SetLineWidth(2);
j0pt3->Draw("same hist");

V_j0pt1->Scale(2.49*0.5);
V_j0pt1->Rebin(10);
V_j0pt1->SetStats(0);
V_j0pt1->SetLineColor(kRed);
V_j0pt1->SetLineWidth(3);
V_j0pt1->SetLineStyle(7);
V_j0pt1->Draw("same hist");
V_j0pt2->Scale(1.95*0.5);
V_j0pt2->Rebin(10);
V_j0pt2->SetLineColor(kGreen+1);
V_j0pt2->SetLineWidth(3);
V_j0pt2->SetLineStyle(7);
V_j0pt2->Draw("same hist");
V_j0pt3->Scale(1.34*0.5);
V_j0pt3->Rebin(10);
V_j0pt3->SetLineColor(kBlue);
V_j0pt3->SetLineWidth(3);
V_j0pt3->SetLineStyle(7);
V_j0pt3->Draw("same hist");

TLegend* j0pt_legend = new TLegend(0.75,0.75,0.9,0.9);
j0pt_legend->AddEntry(j0pt1,"ptcut 5","l");
j0pt_legend->AddEntry(V_j0pt1,"Vanderbilt","l");
j0pt_legend->AddEntry(j0pt2,"ptcut 10","l");
j0pt_legend->AddEntry(V_j0pt2,"Vanderbilt","l");
j0pt_legend->AddEntry(j0pt3,"ptcut 20","l");
j0pt_legend->AddEntry(V_j0pt3,"Vanderbilt","l");
j0pt_legend->Draw();



c6->cd();

j0eta1->SetTitle("j0 eta");
j0eta1->SetStats(0);
j0eta1->Scale(2.49*10000/geta1->GetEntries());
j0eta1->GetYaxis()->SetRangeUser(0,2000);
j0eta1->SetLineColor(kRed);
j0eta1->SetLineWidth(2);
j0eta1->Draw("hist");
j0eta2->Scale(1.95*10000/geta2->GetEntries());
j0eta2->SetLineColor(kGreen+1);
j0eta2->SetLineWidth(2);
j0eta2->Draw("same hist");
j0eta3->Scale(1.34*10000/geta3->GetEntries());
j0eta3->SetLineColor(kBlue);
j0eta3->SetLineWidth(2);
j0eta3->Draw("same hist");

V_j0eta1->SetStats(0);
V_j0eta1->Scale(2.49*0.5);
V_j0eta1->SetLineColor(kRed);
V_j0eta1->SetLineWidth(3);
V_j0eta1->SetLineStyle(7);
V_j0eta1->Draw("same hist");
V_j0eta2->Scale(1.95*0.5);
V_j0eta2->SetLineColor(kGreen+1);
V_j0eta2->SetLineWidth(3);
V_j0eta2->SetLineStyle(7);
V_j0eta2->Draw("same hist");
V_j0eta3->Scale(1.34*0.5);
V_j0eta3->SetLineColor(kBlue);
V_j0eta3->SetLineWidth(3);
V_j0eta3->SetLineStyle(7);
V_j0eta3->Draw("same hist");


TLegend* j0eta_legend = new TLegend(0.75,0.75,0.9,0.9);
j0eta_legend->AddEntry(j0eta1,"ptcut 5","l");
j0eta_legend->AddEntry(V_j0eta1,"Vanderbilt","l");
j0eta_legend->AddEntry(j0eta2,"ptcut 10","l");
j0eta_legend->AddEntry(V_j0eta2,"Vanderbilt","l");
j0eta_legend->AddEntry(j0eta3,"ptcut 20","l");
j0eta_legend->AddEntry(V_j0eta3,"Vanderbilt","l");
j0eta_legend->Draw();





c7->cd();

V_dEtajj1->SetTitle("#Delta#eta(forward jj)");
V_dEtajj1->SetStats(0);
V_dEtajj1->Scale(2.02*0.5);
V_dEtajj1->GetYaxis()->SetRangeUser(0,200);
V_dEtajj1->SetLineColor(kRed);
V_dEtajj1->SetLineWidth(2);
V_dEtajj1->Draw("hist");
V_dEtajj2->Scale(1.54*0.5);
V_dEtajj2->SetLineColor(kGreen+1);
V_dEtajj2->SetLineWidth(2);
V_dEtajj2->Draw("same hist");
V_dEtajj3->Scale(0.959*0.5);
V_dEtajj3->SetLineColor(kBlue);
V_dEtajj3->SetLineWidth(2);
V_dEtajj3->Draw("same hist");

TLegend* dEtajj_legend = new TLegend(0.75,0.75,0.9,0.9);
dEtajj_legend->AddEntry(V_dEtajj1,"ptcut 5","l");
dEtajj_legend->AddEntry(V_dEtajj2,"ptcut 10","l");
dEtajj_legend->AddEntry(V_dEtajj3,"ptcut 20","l");
dEtajj_legend->Draw();





c1->SaveAs("Tch_kinematics/comparisons/hard_l_pt.png");
c2->SaveAs("Tch_kinematics/comparisons/hard_l_eta.png");
c3->SaveAs("Tch_kinematics/comparisons/last_HN_pt.png");
c4->SaveAs("Tch_kinematics/comparisons/last_HN_eta.png");
c5->SaveAs("Tch_kinematics/comparisons/j0_pt.png");
c6->SaveAs("Tch_kinematics/comparisons/j0_eta.png");
c7->SaveAs("Tch_kinematics/comparisons/dEta_forward_jj.png");
c8->SaveAs("Tch_kinematics/comparisons/hard_l_eta_SNU.png");
c9->SaveAs("Tch_kinematics/comparisons/hard_l_eta_Vanderbilt.png");

}
