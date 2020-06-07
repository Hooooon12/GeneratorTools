void plot_kinematics(TString channel, TString var, TString title, int xran, int yran, int rebin){

TString LO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_LO_MuMu_M300_325100.root";
TString LO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_LO_MuMu_M600_325100.root";
TString LO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_LO_MuMu_M1000_325100.root";
TString LO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_LO_MuMu_M1500_325100.root";
TString LO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_LO_MuMu_M2000_325100.root";
TFile* LO_file1 = new TFile(LO_filename1);
TFile* LO_file2 = new TFile(LO_filename2);
TFile* LO_file3 = new TFile(LO_filename3);
TFile* LO_file4 = new TFile(LO_filename4);
TFile* LO_file5 = new TFile(LO_filename5);
TH1D* LO_var1 = (TH1D*)LO_file1->Get(var);
TH1D* LO_var2 = (TH1D*)LO_file2->Get(var);
TH1D* LO_var3 = (TH1D*)LO_file3->Get(var);
TH1D* LO_var4 = (TH1D*)LO_file4->Get(var);
TH1D* LO_var5 = (TH1D*)LO_file5->Get(var);

TString NLO_filename1 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_NLO_MuMu_M300_325100.root";
TString NLO_filename2 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_NLO_MuMu_M600_325100.root";
TString NLO_filename3 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_NLO_MuMu_M1000_325100.root";
TString NLO_filename4 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_NLO_MuMu_M1500_325100.root";
TString NLO_filename5 = "/data8/Users/jihkim/GeneratorTools/Hist/HNtype1_"+channel+"_MG_HeavyMajoranaNeutrino_SSDiLepton_"+channel+"_NLO_MuMu_M2000_325100.root";
TFile* NLO_file1 = new TFile(NLO_filename1);
TFile* NLO_file2 = new TFile(NLO_filename2);
TFile* NLO_file3 = new TFile(NLO_filename3);
TFile* NLO_file4 = new TFile(NLO_filename4);
TFile* NLO_file5 = new TFile(NLO_filename5);
TH1D* NLO_var1 = (TH1D*)NLO_file1->Get(var);
TH1D* NLO_var2 = (TH1D*)NLO_file2->Get(var);
TH1D* NLO_var3 = (TH1D*)NLO_file3->Get(var);
TH1D* NLO_var4 = (TH1D*)NLO_file4->Get(var);
TH1D* NLO_var5 = (TH1D*)NLO_file5->Get(var);

  if(channel=="Schannel") {}
  
  
  if(channel=="Tchannel"){
    //gSystem->Exec("rootls "+NLO_filename1);

    TCanvas* c1 = new TCanvas("c1",title,200,350,700,650);
    c1->cd();
  
    LO_var1->SetTitle(title+" #scale[0.8]{(LO vs NLO)}");
    LO_var1->SetStats(0);
    LO_var1->Rebin(rebin);
    LO_var1->GetXaxis()->SetRangeUser(0,xran);
    LO_var1->GetYaxis()->SetRangeUser(0,yran);
    LO_var1->GetXaxis()->SetTitle(title);
    LO_var1->SetLineColor(kRed);
    LO_var1->SetLineWidth(3);
    LO_var1->SetLineStyle(7);
    LO_var1->Draw("hist");
    LO_var2->Scale(LO_var1->GetEntries()/LO_var2->Integral());
    LO_var2->Rebin(rebin);
    LO_var2->SetLineColor(kGreen+1);
    LO_var2->SetLineWidth(3);
    LO_var2->SetLineStyle(7);
    LO_var2->Draw("same hist");
    LO_var3->Scale(LO_var1->GetEntries()/LO_var3->Integral());
    LO_var3->Rebin(rebin);
    LO_var3->SetLineColor(kBlue);
    LO_var3->SetLineWidth(3);
    LO_var3->SetLineStyle(7);
    LO_var3->Draw("same hist");
    NLO_var1->SetStats(0);
    NLO_var1->Scale(LO_var1->GetEntries()/NLO_var1->Integral());
    NLO_var1->Rebin(rebin);
    NLO_var1->SetLineColor(kRed);
    NLO_var1->SetLineWidth(2);
    NLO_var1->Draw("same hist");
    NLO_var2->Scale(LO_var1->GetEntries()/NLO_var2->Integral());
    NLO_var2->Rebin(rebin);
    NLO_var2->SetLineColor(kGreen+1);
    NLO_var2->SetLineWidth(2);
    NLO_var2->Draw("same hist");
    NLO_var3->Scale(LO_var1->GetEntries()/NLO_var3->Integral());
    NLO_var3->Rebin(rebin);
    NLO_var3->SetLineColor(kBlue);
    NLO_var3->SetLineWidth(2);
    NLO_var3->Draw("same hist");
    
    TLegend* legend = new TLegend(0.62,0.75,0.9,0.9);
    legend->AddEntry(NLO_var1,"Tch #mu#mu m_{N}=300GeV, NLO","l");
    legend->AddEntry(LO_var1,"#scale[0.9]{LO}","l");
    legend->AddEntry(NLO_var2,"Tch #mu#mu m_{N}=600GeV, NLO","l");
    legend->AddEntry(LO_var2,"#scale[0.9]{LO}","l");
    legend->AddEntry(NLO_var3,"Tch #mu#mu m_{N}=1000GeV, NLO","l");
    legend->AddEntry(LO_var3,"#scale[0.9]{LO}","l");
    legend->Draw();
  
  }

}
