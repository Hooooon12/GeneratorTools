{
TString filename1 = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut5_MuMu_M1000.root";
TString filename2 = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut10_MuMu_M1000.root";
TString filename3 = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut15_MuMu_M1000.root";
TString filename4 = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptcut20_MuMu_M1000.root";
//TString filename = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptl10_ptj30_MuMu_M1000.root";
//TString filename = "/data4/Users/jihkim/GeneratorTools/Hist/HNtype1_MG_HeavyMajoranaNeutrino_SSDiLepton_Tchannel_NLO_ptl20_ptj30_MuMu_M1000.root";
TFile* f1 = new TFile(filename1);
TFile* f2 = new TFile(filename2);
TFile* f3 = new TFile(filename3);
TFile* f4 = new TFile(filename4);

//TString samplename = filename(filename.Last('/')+58,filename.Length());
//samplename.ReplaceAll(".root","");

gSystem->Exec("mkdir Tch_kinematics");

vector<TString> histname;
histname.push_back("gamma_l_pt");
histname.push_back("gamma_l_eta");
histname.push_back("last_HN_pt");
histname.push_back("last_HN_eta");


TH1D* gpt1 = (TH1D*)f1->Get("gamma_l_pt");
TH1D* gpt2 = (TH1D*)f2->Get("gamma_l_pt");
TH1D* gpt3 = (TH1D*)f3->Get("gamma_l_pt");
TH1D* gpt4 = (TH1D*)f4->Get("gamma_l_pt");

TH1D* geta1 = (TH1D*)f1->Get("gamma_l_eta");
TH1D* geta2 = (TH1D*)f2->Get("gamma_l_eta");
TH1D* geta3 = (TH1D*)f3->Get("gamma_l_eta");
TH1D* geta4 = (TH1D*)f4->Get("gamma_l_eta");

TH1D* hnpt1 = (TH1D*)f1->Get("last_HN_pt");
TH1D* hnpt2 = (TH1D*)f2->Get("last_HN_pt");
TH1D* hnpt3 = (TH1D*)f3->Get("last_HN_pt");
TH1D* hnpt4 = (TH1D*)f4->Get("last_HN_pt");

TH1D* hneta1 = (TH1D*)f1->Get("last_HN_eta");
TH1D* hneta2 = (TH1D*)f2->Get("last_HN_eta");
TH1D* hneta3 = (TH1D*)f3->Get("last_HN_eta");
TH1D* hneta4 = (TH1D*)f4->Get("last_HN_eta");


//TCanvas* c1 = new TCanvas("c1","gamma_l pt",200,350,700,650);
TCanvas* c1_scale = new TCanvas("c1_scale_xsec","gamma_l pt",200,350,700,650);
TCanvas* c2 = new TCanvas("c2","gamma_l eta",250,300,700,650);
TCanvas* c3 = new TCanvas("c3","HN pt",300,250,700,650);
TCanvas* c4 = new TCanvas("c4","HN eta",350,200,700,650);

TH1D* gpt1_scale = (TH1D*)gpt1->Clone("gamma_l_pt");
TH1D* gpt2_scale = (TH1D*)gpt2->Clone("gamma_l_pt");
TH1D* gpt3_scale = (TH1D*)gpt3->Clone("gamma_l_pt");
TH1D* gpt4_scale = (TH1D*)gpt4->Clone("gamma_l_pt");

//c1->cd();
//
//gpt1->Rebin(10);
//gpt1->GetXaxis()->SetRangeUser(0,400);
//gpt1->SetTitle("gamma_l pt");
//gpt1->SetStats(0);
//gpt1->SetLineColor(kRed);
//gpt1->SetLineWidth(2);
//gpt1->Draw("hist");
//
//gpt2->Rebin(10);
//gpt2->GetXaxis()->SetRangeUser(0,400);
//gpt2->SetLineColor(kOrange);
//gpt2->SetLineWidth(2);
//gpt2->Draw("same hist");
//
//gpt3->Rebin(10);
//gpt3->GetXaxis()->SetRangeUser(0,400);
//gpt3->SetLineColor(8);
//gpt3->SetLineWidth(2);
//gpt3->Draw("same hist");
//
//gpt4->Rebin(10);
//gpt4->GetXaxis()->SetRangeUser(0,400);
//gpt4->SetLineColor(kBlue);
//gpt4->SetLineWidth(2);
//gpt4->Draw("same hist");
//
//TLegend* gpt_legend = new TLegend(0.7,0.75,0.9,0.9);
//gpt_legend->AddEntry(gpt1,"ptcut 5","l");
//gpt_legend->AddEntry(gpt2,"ptcut 10","l");
//gpt_legend->AddEntry(gpt3,"ptcut 15","l");
//gpt_legend->AddEntry(gpt4,"ptcut 20","l");
//gpt_legend->Draw();

c1_scale->cd();

gpt1_scale->SetTitle("gamma_l pt");
gpt1_scale->SetStats(0);
gpt1_scale->Scale(2.49*10000/gpt1_scale->GetEntries());
gpt1_scale->Rebin(10);
gpt1_scale->GetXaxis()->SetRangeUser(0,400);
gpt1_scale->SetLineColor(kRed);
gpt1_scale->SetLineWidth(2);
gpt1_scale->Draw("hist");

gpt2_scale->Scale(1.95*10000/gpt2_scale->GetEntries());
gpt2_scale->Rebin(10);
gpt2_scale->GetXaxis()->SetRangeUser(0,400);
gpt2_scale->SetLineColor(kOrange);
gpt2_scale->SetLineWidth(2);
gpt2_scale->Draw("same hist");

gpt3_scale->Scale(1.59*10000/gpt3_scale->GetEntries());
gpt3_scale->Rebin(10);
gpt3_scale->GetXaxis()->SetRangeUser(0,400);
gpt3_scale->SetLineColor(8);
gpt3_scale->SetLineWidth(2);
gpt3_scale->Draw("same hist");

gpt4_scale->Scale(1.34*10000/gpt4_scale->GetEntries());
gpt4_scale->Rebin(10);
gpt4_scale->GetXaxis()->SetRangeUser(0,400);
gpt4_scale->SetLineColor(kBlue);
gpt4_scale->SetLineWidth(2);
gpt4_scale->Draw("same hist");

TLegend* gpt_scale_legend = new TLegend(0.75,0.75,0.9,0.9);
gpt_scale_legend->AddEntry(gpt1_scale,"ptcut 5","l");
gpt_scale_legend->AddEntry(gpt2_scale,"ptcut 10","l");
gpt_scale_legend->AddEntry(gpt3_scale,"ptcut 15","l");
gpt_scale_legend->AddEntry(gpt4_scale,"ptcut 20","l");
gpt_scale_legend->Draw();


c2->cd();

geta1->SetTitle("gamma_l eta");
geta1->SetStats(0);
geta1->Scale(2.49*10000/geta1->GetEntries());
geta1->GetYaxis()->SetRangeUser(0,800);
geta1->SetLineColor(kRed);
geta1->SetLineWidth(2);
geta1->Draw("hist");
geta2->Scale(1.95*10000/geta2->GetEntries());
geta2->SetLineColor(kOrange);
geta2->SetLineWidth(2);
geta2->Draw("same hist");
geta3->Scale(1.59*10000/geta3->GetEntries());
geta3->SetLineColor(8);
geta3->SetLineWidth(2);
geta3->Draw("same hist");
geta4->Scale(1.34*10000/geta4->GetEntries());
geta4->SetLineColor(kBlue);
geta4->SetLineWidth(2);
geta4->Draw("same hist");

TLegend* geta_legend = new TLegend(0.75,0.75,0.9,0.9);
geta_legend->AddEntry(geta1,"ptcut 5","l");
geta_legend->AddEntry(geta2,"ptcut 10","l");
geta_legend->AddEntry(geta3,"ptcut 15","l");
geta_legend->AddEntry(geta4,"ptcut 20","l");
geta_legend->Draw();


c3->cd();

hnpt1->Scale(2.49*10000/hnpt1->GetEntries());
hnpt1->Rebin(10);
hnpt1->GetXaxis()->SetRangeUser(0,400);
hnpt1->SetTitle("HN pt");
hnpt1->SetStats(0);
hnpt1->SetLineColor(kRed);
hnpt1->SetLineWidth(2);
hnpt1->Draw("hist");
hnpt2->Scale(1.95*10000/hnpt2->GetEntries());
hnpt2->Rebin(10);
hnpt2->GetXaxis()->SetRangeUser(0,400);
hnpt2->SetLineColor(kOrange);
hnpt2->SetLineWidth(2);
hnpt2->Draw("same hist");
hnpt3->Scale(1.59*10000/hnpt3->GetEntries());
hnpt3->Rebin(10);
hnpt3->GetXaxis()->SetRangeUser(0,400);
hnpt3->SetLineColor(8);
hnpt3->SetLineWidth(2);
hnpt3->Draw("same hist");
hnpt4->Scale(1.34*10000/hnpt4->GetEntries());
hnpt4->Rebin(10);
hnpt4->GetXaxis()->SetRangeUser(0,400);
hnpt4->SetLineColor(kBlue);
hnpt4->SetLineWidth(2);
hnpt4->Draw("same hist");

TLegend* hnpt_legend = new TLegend(0.75,0.75,0.9,0.9);
hnpt_legend->AddEntry(hnpt1,"ptcut 5","l");
hnpt_legend->AddEntry(hnpt2,"ptcut 10","l");
hnpt_legend->AddEntry(hnpt3,"ptcut 15","l");
hnpt_legend->AddEntry(hnpt4,"ptcut 20","l");
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
hneta2->SetLineColor(kOrange);
hneta2->SetLineWidth(2);
hneta2->Draw("same hist");
hneta3->Scale(1.59*10000/hneta3->GetEntries());
hneta3->SetLineColor(8);
hneta3->SetLineWidth(2);
hneta3->Draw("same hist");
hneta4->Scale(1.34*10000/hneta4->GetEntries());
hneta4->SetLineColor(kBlue);
hneta4->SetLineWidth(2);
hneta4->Draw("same hist");

TLegend* hneta_legend = new TLegend(0.75,0.75,0.9,0.9);
hneta_legend->AddEntry(hneta1,"ptcut 5","l");
hneta_legend->AddEntry(hneta2,"ptcut 10","l");
hneta_legend->AddEntry(hneta3,"ptcut 15","l");
hneta_legend->AddEntry(hneta4,"ptcut 20","l");
hneta_legend->Draw();

c1_scale->SaveAs("Tch_kinematics/gamma_l_pt.png");
c2->SaveAs("Tch_kinematics/gamma_l_eta.png");
c3->SaveAs("Tch_kinematics/last_HN_pt.png");
c4->SaveAs("Tch_kinematics/last_HN_eta.png");

}
