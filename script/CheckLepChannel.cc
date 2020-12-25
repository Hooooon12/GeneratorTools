#include "TLorentzVector.h"
#include "TH1D.h"
#include "TFile.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/METReco/interface/GenMET.h"
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
TLorentzVector MakeTLorentzVector(reco::GenMET* particle){
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
TString Ptr2Idx(const reco::GenParticle* gen,const vector<reco::GenParticle>& gens){
  TString idx = "-";
  for(int i=0;i<gens.size();i++){
    if(&gens[i]==gen) idx = TString::Itoa(i,10);
  }
  return idx;
}
class formatted_output //JH : thanks to https://stackoverflow.com/questions/7248627/setting-width-in-c-output-stream
{
  private:
    int width;
    ostream& stream_obj;

  public:
    formatted_output(ostream& obj, int w): width(w), stream_obj(obj) {}

    template<typename T>
    formatted_output& operator<<(const T& output){
      stream_obj << setw(width) << output;
      return *this;
    }

    formatted_output& operator<<(ostream& (*func)(ostream&)){
      func(stream_obj);
      return *this;
    }
};
void PrintGen(const reco::GenParticle& gen, const vector<reco::GenParticle>& gens){
  formatted_output new_cout(cout,5);
  new_cout<<Ptr2Idx((reco::GenParticle*)&gen,gens)<<gen.pdgId()<<gen.status()<<Ptr2Idx((reco::GenParticle*)gen.mother(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.mother(1),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(1),gens)<<gen.isHardProcess()<<"\t"<<gen.px()<<"\t"<<gen.py()<<"\t"<<gen.pz()<<"\t"<<gen.energy()<<"\t"<<gen.pt()<<"\t"<<gen.eta()<<"\t"<<gen.phi();
  //cout<<"<"<<endl;
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
    //cout<<i<<" "; //JH
    //PrintGen(gens[i]); //JH
    PrintGen(gens[i],gens); 
  }
}
void PrintGens(const vector<reco::GenParticle*>& gens){
  for(unsigned int i=0;i<gens.size();i++){
    cout<<i<<" ";
    PrintGen(gens[i]);
  }
}

void loop(TString infile, TString dummy){
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
 
    fwlite::Handle<std::vector<reco::GenMET>> METs_;
    METs_.getByLabel(ev,"genMetTrue");
    const vector<reco::GenMET>& METs_all=*METs_.ptr();
    vector<reco::GenMET*> METs;
    for(const auto& MET:METs_all){
      METs.push_back((reco::GenMET*)&MET);
    }
    reco::GenMET* MET=METs.at(0);

    fwlite::Handle<GenEventInfoProduct> geninfo;
    geninfo.getByLabel(ev,"generator");
    const vector<double>& weights=geninfo.ptr()->weights();

    for(int i=0;i<weights.size();i++){
      FillHist("sumw",i,weights[i],200,0,200);
    }

    double weight;
    if(weights[0]>0) weight = 1;
    else weight = -1;

    const reco::GenParticle *hard_HN=NULL;
    const reco::GenParticle *last_HN=NULL;
    const reco::GenParticle *hard_l=NULL,*HN_l=NULL,*W_l=NULL,*forward_parton=NULL;
    vector<const reco::GenParticle*> leptons,hard_partons,N_partons,hard_Ws;
    for(int i=0;i<gens.size();i++){
      //cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", isHardProcess : " << gens[i].isHardProcess() << endl;
      if(gens[i].isHardProcess()){
        cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", px : " << gens[i].px() << ", py : " << gens[i].py() << ", pz : " << gens[i].pz() << ", E : " << gens[i].energy() << ", pt : " << gens[i].pt() << ", eta : " << gens[i].eta() << ", phi : " << gens[i].phi() << endl;
        if(abs(gens[i].pdgId())==24) hard_Ws.push_back(&gens[i]);
        else if(abs(gens[i].pdgId())<=4||gens[i].pdgId()==21) hard_partons.push_back(&gens[i]);
        else if(gens[i].pdgId()==9900012) hard_HN=&gens[i]; 
      }
      if(gens[i].pdgId()==9900012) last_HN=&gens[i];
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==hard_partons.at(0))){
        hard_l=&gens[i]; //JH : XXX If hard_l is just reco::GenParticle* (w/o const), then it doesn't get &gens[i]
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the hard_l : " << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==last_HN)){ //NOTE The mother should be last_HN
        HN_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l : " << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(abs(gens[i].mother()->pdgId())==24)){
        W_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the W_l : " << endl;
      }

      if(gens[i].isPromptFinalState()){
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13) leptons.push_back(&gens[i]);
      }
    }
    
    for(int i=0;i<hard_partons.size();i++){
      if(abs((hard_partons.at(i)->mother())->pdgId())==24||(hard_partons.at(i)->mother())->pdgId()==9900012) N_partons.push_back(hard_partons.at(i));
      for(int j=0;j<hard_partons.size();j++){
        if(hard_partons.at(j)->mother()==hard_partons.at(i)) forward_parton=hard_partons.at(j);
      }
    }

    if(hard_Ws.size()>0){
      for(int i=0;i<hard_Ws.size();i++) hard_Ws.at(i) = FindLastCopy(gens,hard_Ws.at(i));
    }
    if(hard_l) hard_l = FindLastCopy(gens,hard_l);
    if(W_l) W_l = FindLastCopy(gens,W_l); 
    HN_l = FindLastCopy(gens,HN_l);  //NOTE No need this for last_HN; The code itself assigns the last HN to last_HN.

    cout << "detected hard_l : " << Ptr2Idx(hard_l,gens) << endl;
    cout << "detected HN_l : " << Ptr2Idx(HN_l,gens) << endl;
    cout << "detected W_l : " << Ptr2Idx(W_l,gens) << endl;
    cout << "!!!!!!!!!!!!!hard_l charge : " << GetCharge(hard_l) << "!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!HN_l charge : " << GetCharge(HN_l) << "!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!W_l charge : " << GetCharge(W_l) << "!!!!!!!!!!!!!" << endl;

    cout << "detected hard_partons : " << endl;
    for(int i=0;i<hard_partons.size();i++) cout << Ptr2Idx(hard_partons.at(i),gens) << endl;
    cout << "detected forward_parton : " << Ptr2Idx(forward_parton,gens) << endl;

    cout << "N of Ws : " << hard_Ws.size() << endl;
    if(hard_Ws.size()==1){
      cout << "Which : ";
        if(Ptr2Idx(hard_Ws.at(0),gens).Atoi()<Ptr2Idx(hard_HN,gens).Atoi()){
          cout << "W1" << endl;
        }else cout << "W2" << endl;
      cout << "W : " << Ptr2Idx(hard_Ws.at(0),gens) << ", HN : " << Ptr2Idx(hard_HN,gens) << endl;
      cout << "W eta : " << hard_Ws.at(0)->eta() << endl; //NOTE W eta extremely changes from hard_W to last_W
    }

    cout<<"  Idx  PID  sts mtr1 mtr2  dt1  dt2  hrdp"<<endl;
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

    //pick up the (sub)leading jet : to inspect jet constituents
    
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
      for(int i=0; i<leptons.size(); i++) PrintGen(*leptons.at(i),gens);
      PrintGens(gens);
    }

    int LepFlavor = 1;
    for(int i=0; i<leptons.size(); i++){
      LepFlavor *= abs(leptons.at(i)->pdgId());
    }
    if(LepFlavor != 143){
      cout << "This is NOT EMu...?" << endl;
    }

    ievent++;
  }
  
}
