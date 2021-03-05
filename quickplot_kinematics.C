void quickplot_kinematics(TString script, TString name1, TString name2, TString var, TString title, int xran1, int xran2, int yran, int rebin, TString SaveAs = "n"){

  TString Pnt_filename = "/data9/Users/jihkim/GeneratorTools/Hist/HNtype1_"+script+"_MG_"+name1+".root";
  TFile* Pnt_file = new TFile(Pnt_filename);
  TH1D* Pnt_var = (TH1D*)Pnt_file->Get(var);
  
  TString Bar_filename = "/data9/Users/jihkim/GeneratorTools/Hist/HNtype1_"+script+"_MG_"+name2+".root";
  TFile* Bar_file = new TFile(Bar_filename);
  TH1D* Bar_var = (TH1D*)Bar_file->Get(var);

    //gSystem->Exec("rootls "+Bar_filename1);

    TCanvas* c1 = new TCanvas("c1",title,200,350,700,650);
    c1->cd();
  
    Pnt_var->SetTitle(title);
    Pnt_var->SetStats(0);
    Pnt_var->Rebin(rebin);
    Pnt_var->GetXaxis()->SetRangeUser(xran1,xran2);
    Pnt_var->GetYaxis()->SetRangeUser(0,yran);
    if(var.Contains("pt")) Pnt_var->GetXaxis()->SetTitle(title+" [GeV]");
    else Pnt_var->GetXaxis()->SetTitle(title);
    //Pnt_var->SetLineColor(kRed);
    Pnt_var->SetLineWidth(3);
    Pnt_var->SetLineStyle(7);
    Pnt_var->Draw("hist");
    Bar_var->SetStats(0);
    Bar_var->Scale(Pnt_var->GetEntries()/Bar_var->GetEntries());
    Bar_var->Rebin(rebin);
    Bar_var->SetLineColor(kRed);
    Bar_var->SetLineWidth(2);
    Bar_var->Draw("same hist");
    
    TLegend* legend;
    if(var.Contains("pt")){
      double ptdiff = 100*(Bar_var->GetMean()-Pnt_var->GetMean())/Pnt_var->GetMean();
      TString ptdiff_t = Form("%f",ptdiff);
      legend = new TLegend(0.62,0.65,0.9,0.9);
      legend->AddEntry(Pnt_var,name1,"l");
      legend->AddEntry(Bar_var,name2,"l");
      legend->AddEntry((TObject*)0,"#bf{mean p_{T}} diff : "+ptdiff_t+"%","");
      legend->Draw();
    }
    else{
      legend = new TLegend(0.62,0.75,0.9,0.9);
      legend->AddEntry(Pnt_var,name1,"l");
      legend->AddEntry(Bar_var,name2,"l");
      legend->Draw();
    }

    if(SaveAs=="y") c1->SaveAs("./"+var+".png");

}
