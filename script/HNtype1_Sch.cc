#include "TLorentzVector.h"
#include "TH1D.h"
#include "TFile.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/Math/interface/deltaR.h"
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
TLorentzVector* MakeTLorentzVectorArray(vector<const reco::GenParticle*> particles){
  TLorentzVector* out = new TLorentzVector[particles.size()];
  for(int i=0; i<particles.size(); i++){
    TLorentzVector particle = MakeTLorentzVector(particles.at(i));
    out[i].SetPxPyPzE(particle.Px(),particle.Py(),particle.Pz(),particle.E());
  }
  return out;
} 
TLorentzVector* MakeTLorentzVectorArray(vector<reco::GenJet*> particles){
  TLorentzVector* out = new TLorentzVector[particles.size()];
  for(int i=0; i<particles.size(); i++){
    TLorentzVector particle = MakeTLorentzVector(particles.at(i));
    out[i].SetPxPyPzE(particle.Px(),particle.Py(),particle.Pz(),particle.E());
  }
  return out;
} 
//vector<TLorentzVector> MakeTLorentzVectors(vector<reco::GenJet*> particles){
//  vector<TLorentzVector> out;
//  for(const auto& particle:particles) out.push_back(MakeTLorentzVector(particle));
//  return out;
//} //JH : XXX vector of TLorentzVector is not easy
const reco::GenParticle* FindLastCopy(const vector<reco::GenParticle>& gens,const reco::GenParticle *ancestor){
  const reco::GenParticle* last=ancestor;
  for(const auto& gen:gens){
    if(gen.mother()==last&&gen.pdgId()==ancestor->pdgId()){
      last=(reco::GenParticle*)&gen;
    }
  }
  return last;
}
bool PtCompare(TLorentzVector v1, TLorentzVector v2){
  return v1.Pt() > v2.Pt(); 
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
  cout<<&gen<<" "<<gen.pdgId()<<" "<<gen.status()<<" "<<gen.mother(0)<<" "<<gen.mother(1)<<" "<<gen.daughter(0)<<" "<<gen.daughter(1)<<"\t"<<gen.isHardProcess()<<gen.isLastCopy()<<gen.isLastCopyBeforeFSR()<<gen.isPromptDecayed()<<gen.isPromptFinalState()<<endl;
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
      jets.push_back((reco::GenJet*)&jet); 
    }

    fwlite::Handle<std::vector<reco::GenJet>> fatjets_;
    fatjets_.getByLabel(ev,"ak8GenJets");
    const vector<reco::GenJet>& fatjets_all=*fatjets_.ptr();
    vector<reco::GenJet*> fatjets;
    for(const auto& fatjet:fatjets_all){
      fatjets.push_back((reco::GenJet*)&fatjet);
    } 

    fwlite::Handle<GenEventInfoProduct> geninfo;
    geninfo.getByLabel(ev,"generator");
    const vector<double>& weights=geninfo.ptr()->weights();

    for(int i=0;i<weights.size();i++){
      FillHist("sumw",i,weights[i],200,0,200);
    }

    const reco::GenParticle *hard_W=NULL,*hard_HN=NULL;
    const reco::GenParticle *last_W=NULL,*last_HN=NULL;
    const reco::GenParticle *hard_l=NULL,*HN_l=NULL;
    vector<const reco::GenParticle*> leptons,hard_partons;
    for(int i=0;i<gens.size();i++){
      cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << endl;
      if(gens[i].isHardProcess()){
        if(abs(gens[i].pdgId())==24) hard_W=&gens[i];
        else if(abs(gens[i].pdgId())<=6) hard_partons.push_back(&gens[i]);
        else if(gens[i].pdgId()==9900012) hard_HN=&gens[i]; 
      }
      if(abs(gens[i].pdgId())==24) last_W=&gens[i];
      if(gens[i].pdgId()==9900012) last_HN=&gens[i];
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother(0)==hard_partons.at(0)||gens[i].mother(1)==hard_partons.at(0))){
        hard_l=&gens[i]; //JH : XXX If gamma_l is just reco::GenParticle*, then it doesn't get &gens[i]
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the hard_l : " << hard_l << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother(0)==last_HN||gens[i].mother(1)==last_HN)){
        HN_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l : " << HN_l << endl;
      }

      if(gens[i].isPromptFinalState()){
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13) leptons.push_back(&gens[i]);
      }
    }

    //hard_l = FindLastCopy(gens,hard_l); HN_l = FindLastCopy(gens,HN_l); 
    cout << "detected hard_l : " << hard_l << endl;
    cout << "detected HN_l : " << HN_l << endl;
    cout << "!!!!!!!!!!!!!hard_l charge : " << GetCharge(hard_l) << "!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!HN_l charge : " << GetCharge(HN_l) << "!!!!!!!!!!!!!" << endl;
    cout << "detected hard_partons : " << endl;
    for(int i=0;i<hard_partons.size();i++) cout << hard_partons.at(i) << endl;
    PrintGens(gens);

    //clean the jets

    vector<reco::GenJet*> jets_lepveto;
    
    for(int i=0;i<jets.size();i++){
      bool HasLepton = false;
      for(int j=0;j<leptons.size();j++){
        if(deltaR(*jets.at(i),*leptons.at(j))<0.4){
          HasLepton = true;
          break;
        }
      }
      if(HasLepton) continue;

      jets_lepveto.push_back(jets.at(i));
    }

    cout << "N of jets : " << jets.size() << endl;
    cout << "N of lepton vetoed jets : " << jets_lepveto.size() << endl;

    vector<reco::GenJet*> fatjets_lepveto;
    
    for(int i=0;i<fatjets.size();i++){
      bool HasLepton = false;
      for(int j=0;j<leptons.size();j++){
        if(deltaR(*fatjets.at(i),*leptons.at(j))<1.){
          HasLepton = true;
          break;
        }
      }
      if(HasLepton) continue;

      fatjets_lepveto.push_back(fatjets.at(i));
    }

    cout << "N of fatjets : " << fatjets.size() << endl;
    cout << "N of lepton vetoed fatjets : " << fatjets_lepveto.size() << endl;

    //pick up the (sub)leading jet
    
    reco::GenJet* leading_jet;
    reco::GenJet* subleading_jet;

    if(jets_lepveto.size()>0){

      leading_jet = jets_lepveto.at(0);
  
      for(int i=0; i<jets_lepveto.size(); i++){
        if(jets_lepveto.at(i)->pt()>leading_jet->pt()) leading_jet = jets_lepveto.at(i);
      }
      
      subleading_jet = jets_lepveto.at(0);
  
      if(jets_lepveto.size()>1){
        if(subleading_jet->pt()==leading_jet->pt()) subleading_jet = jets_lepveto.at(1);
        for(int i=0; i<jets_lepveto.size(); i++){
          if(jets_lepveto.at(i)->pt()>subleading_jet->pt()){
            if(jets_lepveto.at(i)->pt()==leading_jet->pt()) continue;
            else subleading_jet = jets_lepveto.at(i);
          }
        }
      }

    cout << "leading jet info" << endl << leading_jet->print() << endl;
    cout << "subleading jet info" << endl << subleading_jet->print() << endl;

    }

    if(fatjets_lepveto.size()>0) cout << "fatjet info" << endl << fatjets_lepveto.at(0)->print() << endl;

    if(leptons.size()!=2){
      cout << "@@@@@@@@detected lepton number : " << leptons.size() << "@@@@@@@@" << endl;
      for(int i=0; i<leptons.size(); i++) PrintGen(leptons.at(i));
      PrintGens(gens);
    }

    if(hard_l||HN_l){ 
      
      //sort(leptons.begin(),leptons.end(),PtCompare);
      //sort(jets.begin(),jets.end(),PtCompare);
      //sort(fatjets.begin(),fatjets.end(),PtCompare); //JH : XXX These - sorting vector<reco::GenParticles*> don't work!

      TLorentzVector* arr_leptons=MakeTLorentzVectorArray(leptons);
      TLorentzVector* arr_jets=MakeTLorentzVectorArray(jets_lepveto); 
      TLorentzVector* arr_fatjets=MakeTLorentzVectorArray(fatjets_lepveto); 

      for(int i=0;i<leptons.size();i++){
        cout << "array leptons pt : " << arr_leptons[i].Pt() << endl;
      }

      sort(arr_leptons,arr_leptons+leptons.size(),PtCompare);
      sort(arr_jets,arr_jets+jets_lepveto.size(),PtCompare);
      sort(arr_fatjets,arr_fatjets+fatjets_lepveto.size(),PtCompare);
      
      for(int i=0;i<leptons.size();i++){
        cout << "vector leptons pt : " << leptons.at(i)->pt() << endl;
      }
      for(int i=0;i<leptons.size();i++){
        cout << "sorted array leptons pt : " << arr_leptons[i].Pt() << endl;
      }
      for(int i=0;i<jets_lepveto.size();i++){
        cout << "sorted array lepton vetoed jets pt : " << arr_jets[i].Pt() << endl;
      }

      TLorentzVector vec_hard_W=MakeTLorentzVector(hard_W);
      TLorentzVector vec_last_W=MakeTLorentzVector(last_W);
      TLorentzVector vec_hard_HN=MakeTLorentzVector(hard_HN);
      TLorentzVector vec_last_HN=MakeTLorentzVector(last_HN);

      TLorentzVector vec_hard_l=MakeTLorentzVector(hard_l);
      TLorentzVector vec_HN_l=MakeTLorentzVector(HN_l);
      TLorentzVector vec_l0=arr_leptons[0];
      TLorentzVector vec_l1=arr_leptons[1];
      TLorentzVector vec_j0=arr_jets[0];
      TLorentzVector vec_j1=arr_jets[1];
      TLorentzVector vec_fatjet=arr_fatjets[0];

      TLorentzVector vec_dijet=vec_j0+vec_j1;
      TLorentzVector vec_l0_fatjet=vec_l0+vec_fatjet;
      TLorentzVector vec_l1_fatjet=vec_l1+vec_fatjet;
      TLorentzVector vec_l0_dijet=vec_l0+vec_dijet;
      TLorentzVector vec_l1_dijet=vec_l1+vec_dijet;
      TLorentzVector vec_SS2l_fatjet=vec_l0+vec_l1+vec_fatjet;
      TLorentzVector vec_SS2l_dijet=vec_l0+vec_l1+vec_dijet;

      FillHist("last_W_m",vec_last_W.M(),1,70,50,120);
      FillHist("last_W_pt",vec_last_W.Pt(),1,2000,0,2000);
      FillHist("last_W_E",vec_last_W.E(),1,2000,0,2000);
      FillHist("last_W_eta",vec_last_W.Eta(),1,50,-5,5);
      FillHist("last_HN_m",vec_last_HN.M(),1,2100,0,2100);
      FillHist("last_HN_pt",vec_last_HN.Pt(),1,1000,0,1000);
      FillHist("last_HN_E",vec_last_HN.E(),1,3000,0,3000);
      FillHist("last_HN_eta",vec_last_HN.Eta(),1,50,-5,5);
      if(fatjets_lepveto.size()>0){
        FillHist("fatjet_m",vec_fatjet.M(),1,2000,0,2000);
        FillHist("fatjet_pt",vec_fatjet.Pt(),1,2000,0,2000);
        FillHist("fatjet_E",vec_fatjet.E(),1,3000,0,3000);
        FillHist("fatjet_eta",vec_fatjet.Eta(),1,50,-5,5);
        FillHist("(l0+fatjet)_m",vec_l0_fatjet.M(),1,3000,0,3000);
        FillHist("(l0+fatjet)_pt",vec_l0_fatjet.Pt(),1,3000,0,3000);
        FillHist("(l0+fatjet)_E",vec_l0_fatjet.E(),1,3000,0,3000);
        FillHist("(l0+fatjet)_eta",vec_l0_fatjet.Eta(),1,50,-5,5);
        FillHist("(l1+fatjet)_m",vec_l1_fatjet.M(),1,2000,0,2000);
        FillHist("(l1+fatjet)_pt",vec_l1_fatjet.Pt(),1,1000,0,1000);
        FillHist("(l1+fatjet)_E",vec_l1_fatjet.E(),1,3000,0,3000);
        FillHist("(l1+fatjet)_eta",vec_l1_fatjet.Eta(),1,50,-5,5);
        FillHist("(SS2l+fatjet)_m",vec_SS2l_fatjet.M(),1,2000,0,2000);
        FillHist("(SS2l+fatjet)_pt",vec_SS2l_fatjet.Pt(),1,1000,0,1000);
        FillHist("(SS2l+fatjet)_E",vec_SS2l_fatjet.E(),1,3000,0,3000);
        FillHist("(SS2l+fatjet)_eta",vec_SS2l_fatjet.Eta(),1,50,-5,5);
      }
      if(jets_lepveto.size()>1){
        FillHist("dijet_m",vec_dijet.M(),1,2500,0,2500);
        FillHist("dijet_pt",vec_dijet.Pt(),1,1000,0,1000);
        FillHist("dijet_E",vec_dijet.E(),1,3000,0,3000);
        FillHist("dijet_eta",vec_dijet.Eta(),1,50,-5,5);
        FillHist("(l0+dijet)_m",vec_l0_dijet.M(),1,3500,0,3500);
        FillHist("(l0+dijet)_pt",vec_l0_dijet.Pt(),1,2000,0,2000);
        FillHist("(l0+dijet)_E",vec_l0_dijet.E(),1,3000,0,3000);
        FillHist("(l0+dijet)_eta",vec_l0_dijet.Eta(),1,50,-5,5);
        FillHist("(l1+dijet)_m",vec_l1_dijet.M(),1,3000,0,3000);
        FillHist("(l1+dijet)_pt",vec_l1_dijet.Pt(),1,1000,0,1000);
        FillHist("(l1+dijet)_E",vec_l1_dijet.E(),1,3000,0,3000);
        FillHist("(l1+dijet)_eta",vec_l1_dijet.Eta(),1,50,-5,5);
        FillHist("(SS2l+dijet)_m",vec_SS2l_dijet.M(),1,3500,0,3500);
        FillHist("(SS2l+dijet)_pt",vec_SS2l_dijet.Pt(),1,2000,0,2000);
        FillHist("(SS2l+dijet)_E",vec_SS2l_dijet.E(),1,3000,0,3000);
        FillHist("(SS2l+dijet)_eta",vec_SS2l_dijet.Eta(),1,50,-5,5);
      }

      FillHist("hard_l_pt",vec_hard_l.Pt(),1,1000,0,1000);
      FillHist("hard_l_E",vec_hard_l.E(),1,1000,0,1000);
      FillHist("hard_l_eta",vec_hard_l.Eta(),1,50,-5,5);
      FillHist("hard_l_charge",GetCharge(hard_l),1,3,-1,2);
      FillHist("HN_l_pt",vec_HN_l.Pt(),1,2000,0,2000);
      FillHist("HN_l_E",vec_HN_l.E(),1,2000,0,2000);
      FillHist("HN_l_eta",vec_HN_l.Eta(),1,50,-5,5);
      FillHist("HN_l_charge",GetCharge(HN_l),1,3,-1,2);
      FillHist("l0_pt",vec_l0.Pt(),1,2000,0,2000);
      FillHist("l0_E",vec_l0.E(),1,2000,0,2000);
      FillHist("l0_eta",vec_l0.Eta(),1,50,-5,5);
      FillHist("l1_pt",vec_l1.Pt(),1,1000,0,1000);
      FillHist("l1_E",vec_l1.E(),1,1000,0,1000);
      FillHist("l1_eta",vec_l1.Eta(),1,50,-5,5);
      if(jets_lepveto.size()>0){
        FillHist("j0_m",vec_j0.M(),1,2000,0,2000);
        FillHist("j0_pt",vec_j0.Pt(),1,2000,0,2000);
        FillHist("j0_E",vec_j0.E(),1,2000,0,2000);
        FillHist("j0_eta",vec_j0.Eta(),1,50,-5,5);
      }
      if(jets_lepveto.size()>1){
        FillHist("j1_m",vec_j1.M(),1,2000,0,2000);
        FillHist("j1_pt",vec_j1.Pt(),1,2000,0,2000);
        FillHist("j1_E",vec_j1.E(),1,2000,0,2000);
        FillHist("j1_eta",vec_j1.Eta(),1,50,-5,5);
        FillHist("DeltaR(jj)",vec_j0.DeltaR(vec_j1),1,50,0,5);
      }

      int IsSameCharge = GetCharge(hard_l)*GetCharge(HN_l);
      FillHist("IsSameChargeLepton",IsSameCharge,1,3,-1,2);

      FillHist("nlep",leptons.size(),1,5,0,5);
      FillHist("njet",jets_lepveto.size(),1,50,0,50);
      FillHist("nfatjet",fatjets_lepveto.size(),1,50,0,50);

      for(int i=0; i<leptons.size(); i++){
        FillHist("leptons_pt",leptons.at(i)->pt(),1,1000,0,1000);
      }
      for(int i=0; i<leptons.size(); i++){
        FillHist("leptons_eta",leptons.at(i)->eta(),1,50,-5,5);
      }
      for(int i=0; i<jets_lepveto.size(); i++){
        FillHist("jets_pt",jets_lepveto.at(i)->pt(),1,1000,0,1000);
      }
      for(int i=0; i<jets_lepveto.size(); i++){
        FillHist("jets_eta",jets_lepveto.at(i)->eta(),1,50,-5,5);
      }
      for(int i=0; i<fatjets_lepveto.size(); i++){
        FillHist("fatjets_pt",fatjets_lepveto.at(i)->pt(),1,1000,0,1000);
      }
      for(int i=0; i<fatjets_lepveto.size(); i++){
        FillHist("fatjets_eta",fatjets_lepveto.at(i)->eta(),1,50,-5,5);
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
