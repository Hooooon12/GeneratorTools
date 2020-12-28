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
  new_cout<<Ptr2Idx((reco::GenParticle*)&gen,gens)<<gen.pdgId()<<gen.status()<<Ptr2Idx((reco::GenParticle*)gen.mother(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.mother(1),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(1),gens)<<gen.isHardProcess();
  cout<<"<\t"<<gen.px()<<"\t"<<gen.py()<<"\t"<<gen.pz()<<"\t"<<gen.energy()<<"\t"<<gen.pt()<<"\t"<<gen.eta()<<"\t"<<gen.phi()<<endl;
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

void loop(TString infile){
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
    cout << "gens size : " << gens.size() << endl;

    fwlite::Handle<std::vector<reco::GenJet>> jets_;
    jets_.getByLabel(ev,"ak4GenJets");
    const vector<reco::GenJet>& jets_all=*jets_.ptr();
    vector<reco::GenJet*> jets;
    for(const auto& jet:jets_all){
      //if(jet.pt()>30) jets.push_back((reco::GenJet*)&jet);
      jets.push_back((reco::GenJet*)&jet); 
    }
    cout << "jets size : " << jets.size() << endl;

    fwlite::Handle<std::vector<reco::GenJet>> fatjets_;
    fatjets_.getByLabel(ev,"ak8GenJets");
    const vector<reco::GenJet>& fatjets_all=*fatjets_.ptr();
    vector<reco::GenJet*> fatjets;
    for(const auto& fatjet:fatjets_all){
      fatjets.push_back((reco::GenJet*)&fatjet);
    } 
    cout << "fatjets size : " << fatjets.size() << endl;
 
    fwlite::Handle<std::vector<reco::GenMET>> METs_;
    METs_.getByLabel(ev,"genMetTrue");
    const vector<reco::GenMET>& METs_all=*METs_.ptr();
    vector<reco::GenMET*> METs;
    for(const auto& MET:METs_all){
      METs.push_back((reco::GenMET*)&MET);
    }
    reco::GenMET* MET=METs.at(0);
    cout << "METs size : " << METs.size() << endl;

    fwlite::Handle<GenEventInfoProduct> geninfo;
    geninfo.getByLabel(ev,"generator");
    const vector<double>& weights=geninfo.ptr()->weights();
    cout << "weights size : " << weights.size() << endl;

    for(int i=0;i<weights.size();i++){
      FillHist("sumw",i,weights[i],200,0,200);
    }

    double weight;
    if(weights[0]>0) weight = 1;
    else weight = -1;

    vector<const reco::GenParticle*> hard_leptons;
    for(int i=2;i<gens.size();i++){
      if((20<=gens[i].status()&&gens[i].status()<=29)||(gens[i].pdgId()!=9900012&&gens[i].mother()->pdgId()==9900012)){
        cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", isHardProcess : " << gens[i].isHardProcess() << endl;
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13){
          hard_leptons.push_back(&gens[i]);
        }
      }
    }

    int LepFlavor = 1;
    for(int i=0; i<hard_leptons.size(); i++){
      LepFlavor *= abs(hard_leptons.at(i)->pdgId());
    }
    if(LepFlavor != 143){
      cout << "This is NOT EMu...?" << endl;
    }

    //cout<<"  Idx  PID  sts mtr1 mtr2  dt1  dt2  hrdp"<<endl;
    //PrintGens(gens);

    ievent++;
  }
  
}
