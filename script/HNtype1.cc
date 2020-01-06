#include "TLorentzVector.h"
#include "TH1D.h"
#include "TFile.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/FWLite/interface/Event.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
map<TString,TH1D*> hists;
int GetCharge(reco::LeafCandidate* particle){
  int q;
  if(particle) q = particle->charge();
  return q;
}
int GetCharge(const reco::GenParticle* particle){
  return GetCharge((reco::LeafCandidate*)particle);
}
TLorentzVector MakeTLorentzVector(reco::LeafCandidate* particle){
  TLorentzVector vec;
  if(particle) vec.SetPxPyPzE(particle->px(),particle->py(),particle->pz(),particle->energy());
  return vec;
}
TLorentzVector MakeTLorentzVector(const reco::GenParticle* particle){
  return MakeTLorentzVector((reco::LeafCandidate*)particle);
}
TLorentzVector MakeTLorentzVector(reco::GenJet* particle){
  return MakeTLorentzVector((reco::LeafCandidate*)particle);
}
TLorentzVector MakeTLorentzVector(tuple<reco::GenJet*,reco::GenJet*> particles){
  return MakeTLorentzVector(get<0>(particles))+MakeTLorentzVector(get<1>(particles));
}
TLorentzVector MakeTLorentzVector(vector<reco::GenParticle*> particles){
  TLorentzVector out;
  for(const auto& particle:particles) out+=MakeTLorentzVector(particle);
  return out;
}
void FillHist(TString histname, double value, double weight, int n_bin, double x_min, double x_max){
  auto it = hists.find(histname);
  TH1D* hist=NULL;
  if( it==hists.end() ){
    hist = new TH1D(histname, "", n_bin, x_min, x_max);
    hists[histname] = hist;
  }else hist=it->second;
  hist->Fill(value, weight);  
}
void PrintGen(const reco::GenParticle& gen){
  cout<<&gen<<" "<<gen.pdgId()<<" "<<gen.status()<<" "<<gen.mother(0)<<" "<<gen.mother(1)<<"\t"<<gen.isHardProcess()<<gen.isLastCopy()<<gen.isLastCopyBeforeFSR()<<gen.isPromptDecayed()<<gen.isPromptFinalState()<<endl;
}
void PrintGen(const reco::GenParticle* gen){
  if(gen) PrintGen(*gen);
  else cout<<"[PrintGen] NULL pointer"<<endl;
}
void PrintGens(const vector<reco::GenParticle>& gens){
  for(unsigned int i=0;i<gens.size();i++){
    //if(gens[i].isHardProcess())  cout<<i<<" "<<&gens[i]<<" "<<gens[i].pdgId()<<" "<<gens[i].status()<<" "<<gens[i].mother()<<"\t"<<gens[i].energy()<<" "<<gens[i].p()<<" "<<gens[i].eta()<<" "<<gens[i].phi()<<endl;                                                                                 
    cout<<i<<" ";
    PrintGen(gens[i]);
  }
}
void PrintGens(const vector<reco::GenParticle*>& gens){
  for(unsigned int i=0;i<gens.size();i++){
    cout<<i<<" ";
    PrintGen(gens[i]);
  }
}

void loop(TString infile,TString outfile){
  //cout << "Loading FW Lite setup." << endl;
  //gSystem->Load("libFWCoreFWLite.so");
  //FWLiteEnabler::enable();
  //gSystem->Load("libDataFormatsFWLite.so");
  //gSystem->Load("libDataFormatsPatCandidates.so");

  TFile f(infile);
  fwlite::Event ev(&f);
  int ievent=0;
  for(ev.toBegin();!ev.atEnd();++ev){
    //if(ievent>3) break;
    //if(ievent%1000==0) cout<<ievent<<endl;
    cout <<"=============" << ievent << "th Event=============" <<endl;
    fwlite::Handle<std::vector<reco::GenParticle>> gens_;
    gens_.getByLabel(ev,"genParticles");
    const vector<reco::GenParticle>& gens=*gens_.ptr();

    fwlite::Handle<std::vector<reco::GenJet>> jets_;
    jets_.getByLabel(ev,"ak4GenJets");
    const vector<reco::GenJet>& jets_all=*jets_.ptr();
    vector<reco::GenJet*> jets;
    for(const auto& jet:jets_all){
      //if(jet.pt()>30) jets.push_back((reco::GenJet*)&jet);
      jets.push_back((reco::GenJet*)&jet); //JH
    }

    fwlite::Handle<std::vector<reco::GenJet>> fatjets_;
    fatjets_.getByLabel(ev,"ak8GenJets");
    const vector<reco::GenJet>& fatjets_all=*fatjets_.ptr();
    vector<reco::GenJet*> fatjets;
    for(const auto& fatjet:fatjets_all){
      fatjets.push_back((reco::GenJet*)&fatjet);
    } //JH

    fwlite::Handle<GenEventInfoProduct> geninfo;
    geninfo.getByLabel(ev,"generator");
    const vector<double>& weights=geninfo.ptr()->weights();

    for(int i=0;i<weights.size();i++){
      FillHist("sumw",i,weights[i],200,0,200);
    }

    const reco::GenParticle *hard_W=NULL,*hard_HN=NULL,*hard_photon=NULL;
    const reco::GenParticle *last_W=NULL,*last_HN=NULL;
    const reco::GenParticle *gamma_l=NULL,*HN_l=NULL;
    vector<const reco::GenParticle*> leptons;
    for(int i=0;i<gens.size();i++){
      cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << endl;
      if(gens[i].isHardProcess()){
        if(abs(gens[i].pdgId())==24) hard_W=&gens[i];
        else if(gens[i].pdgId()==9900012) hard_HN=&gens[i]; 
        else if(gens[i].pdgId()==22) hard_photon=&gens[i]; 
      }
      if(abs(gens[i].pdgId())==24) last_W=&gens[i];
      if(gens[i].pdgId()==9900012) last_HN=&gens[i];
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother(0)==hard_photon||gens[i].mother(1)==hard_photon)){
        gamma_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the gamma_l : " << gamma_l << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother(0)==last_HN||gens[i].mother(1)==last_HN)){
        HN_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l : " << HN_l << endl;
      }

      //if(gens[i].pdgId()==22&&gens[i].status()==1) photons.push_back(&gens[i]);
      if(gens[i].isPromptFinalState()){
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13) leptons.push_back(&gens[i]);
      }
    }

    cout << "detected gamma_l : " << gamma_l << endl;
    cout << "detected HN_l : " << HN_l << endl;
    cout << "!!!!!!!!!!!!!gamma_l charge : " << GetCharge(gamma_l) << "!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!HN_l charge : " << GetCharge(HN_l) << "!!!!!!!!!!!!!" << endl;

    if(!gamma_l) PrintGens(gens);
    if(gamma_l==HN_l) PrintGens(gens);

    if(0){
      PrintGen(hard_W);
      PrintGen(gamma_l);
      PrintGen(HN_l);
      for(int i=0;i<leptons.size();i++){
        PrintGen(leptons.at(i));
      }
      if(!HN_l){
  PrintGens(gens);
  exit(1);
      }
    }

    if(gamma_l||HN_l){ //JH
      //TLorentzVector vec_hard_WW=vec_hard_Wp+vec_hard_Wm;
      //TLorentzVector vec_hardCM_Wp=vec_hard_Wp;
      //vec_hardCM_Wp.Boost(-vec_hard_WW.BoostVector());
      //TLorentzVector vec_hardCM_Wm=vec_hard_Wm;
      //vec_hardCM_Wm.Boost(-vec_hard_WW.BoostVector());
      
      TLorentzVector vec_hard_W=MakeTLorentzVector(hard_W);
      TLorentzVector vec_last_W=MakeTLorentzVector(last_W);
      TLorentzVector vec_hard_HN=MakeTLorentzVector(hard_HN);
      TLorentzVector vec_last_HN=MakeTLorentzVector(last_HN);

      TLorentzVector vec_gamma_l=MakeTLorentzVector(gamma_l);
      TLorentzVector vec_HN_l=MakeTLorentzVector(HN_l);
      //TLorentzVector vec_HD_Wp=vec_HD_lbar+vec_HD_nu;
      //TLorentzVector vec_HD_Wm=vec_HD_l+vec_HD_nubar;
      //TLorentzVector vec_HDCM_l=vec_HD_l;
      //vec_HDCM_l.Boost(-vec_hard_Wm.BoostVector());
      //TLorentzVector vec_HDCM_lbar=vec_HD_lbar;
      //vec_HDCM_lbar.Boost(-vec_hard_Wp.BoostVector());
      
      //TLorentzVector vec_l=MakeTLorentzVector(l);
      //TLorentzVector vec_lbar=MakeTLorentzVector(lbar);
      //TLorentzVector vec_nu=MakeTLorentzVector(nu);
      //TLorentzVector vec_nubar=MakeTLorentzVector(nubar);
      //TLorentzVector vec_dressed_l=vec_l;
      //TLorentzVector vec_dressed_lbar=vec_lbar;

      //vector<TLorentzVector> vec_leptons;

      //for(const auto& lepton:leptons){
      //  TLorentzVector vec_lepton=MakeTLorentzVector(lepton);
      //  vec_leptons.push_back(vec_lepton);
      //}

//      for(const auto& photon:photons){
//  TLorentzVector vec_photon=MakeTLorentzVector(photon);
//  double delr_l=vec_photon.DeltaR(vec_l);
//  double delr_lbar=vec_photon.DeltaR(vec_lbar);
//  if(delr_l<delr_lbar&&delr_l<0.4) vec_dressed_l+=vec_photon;
//  else if(delr_l>delr_lbar&&delr_lbar<0.4) vec_dressed_lbar+=vec_photon;
//      }    

      //TLorentzVector vec_Wp=vec_lbar+vec_nu;
      //TLorentzVector vec_Wm=vec_l+vec_nubar;
      //TLorentzVector vec_dressed_Wp=vec_dressed_lbar+vec_nu;
      //TLorentzVector vec_dressed_Wm=vec_dressed_l+vec_nubar;
      //TLorentzVector vec_WW=vec_Wp+vec_Wm;


      //FillHist("WW_m",vec_WW.M(),weights[0],50,30,130);
      //FillHist("WW_pt",vec_WW.Pt(),weights[0],50,0,100);
      //FillHist("WW_rap",vec_WW.Rapidity(),weights[0],50,-5,5);

      FillHist("hard_W_m",vec_hard_W.M(),1,70,50,120);
      FillHist("last_W_m",vec_last_W.M(),1,70,50,120);
      FillHist("hard_HN_m",vec_hard_HN.M(),1,20,990,1010);
      FillHist("last_HN_m",vec_last_HN.M(),1,20,990,1010);

      //FillHist("HN_pt",vec_HN.Pt(),1,50,0,100);
      //FillHist("HN_eta",vec_HN.Eta(),1,50,-5,5);
      //FillHist("HN_m",vec_HN.M(),1,50,-5,5); //JH : These are reserved for reconstructed(l+2jet) HN which will be defined later

      FillHist("gamma_l_pt",vec_gamma_l.Pt(),1,1000,0,1000);
      FillHist("gamma_l_eta",vec_gamma_l.Eta(),1,50,-5,5);
      FillHist("gamma_l_charge",GetCharge(gamma_l),1,3,-1,2);
      FillHist("HN_l_pt",vec_HN_l.Pt(),1,1000,0,1000);
      FillHist("HN_l_eta",vec_HN_l.Eta(),1,50,-5,5);
      FillHist("HN_l_charge",GetCharge(HN_l),1,3,-1,2);

      //int IsSameCharge = gamma_l->charge()*HN_l->charge();
      //FillHist("IsSameCharge",IsSameCharge,1,3,-1,2);

      FillHist("nlep",leptons.size(),1,5,0,5);
      FillHist("njet",jets.size(),1,50,0,50);
      FillHist("nfatjet",fatjets.size(),1,50,0,50);

      //for(int i=0; i<leptons.size(); i++){
      //  FillHist("lepton_pt",leptons.at(i)->pt(),1,1000,0,1000);
      //}
      //for(int i=0; i<leptons.size(); i++){
      //  FillHist("lepton_eta",leptons.at(i)->eta(),1,50,-5,5);
      //}
      for(int i=0; i<jets.size(); i++){
        FillHist("jet_pt",jets.at(i)->pt(),1,1000,0,1000);
      }
      for(int i=0; i<jets.size(); i++){
        FillHist("jet_eta",jets.at(i)->eta(),1,50,-5,5);
      }
      for(int i=0; i<fatjets.size(); i++){
        FillHist("fatjet_pt",fatjets.at(i)->pt(),1,1000,0,1000);
      }
      for(int i=0; i<fatjets.size(); i++){
        FillHist("fatjet_eta",fatjets.at(i)->eta(),1,50,-5,5);
      }

    }else{
      cout<<"Something wrong"<<endl;
      PrintGens(gens);
      exit(1);
    }
    ievent++;
  }
  
  TFile fout(outfile,"recreate");
  for(const auto& [histname,hist]:hists){
    hist->Write();
  }
  fout.Close();
}
