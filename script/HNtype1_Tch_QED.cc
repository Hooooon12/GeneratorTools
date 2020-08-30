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
int Ptr2IntIdx(const reco::GenParticle* gen,const vector<reco::GenParticle>& gens){
  int idx = -1;
  for(int i=0;i<gens.size();i++){
    if(&gens[i]==gen) idx = i;
  }
  return idx;
}
vector<int> TrackGenSelfHistory(const vector<reco::GenParticle>& gens,const reco::GenParticle *me){
  int myindex = Ptr2IntIdx(me,gens);
  int mypid = gens.at(myindex).pdgId();

  int currentidx = myindex;
  int motheridx = Ptr2IntIdx((reco::GenParticle*)me->mother(),gens); //JH NOTE mother() returns const reco::Candidate * which cannot be reconciled with const reco::GenParticle*

  while(gens.at(motheridx).pdgId() == mypid){
    currentidx = motheridx;
    motheridx = Ptr2IntIdx((reco::GenParticle*)gens.at(motheridx).mother(),gens); //JH : one generation up
  }
  vector<int> out = {currentidx, motheridx};
  return out;
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
  formatted_output new_cout5(cout,5);
  formatted_output new_cout13(cout,13);
  new_cout5<<Ptr2Idx((reco::GenParticle*)&gen,gens)<<gen.pdgId()<<gen.status()<<Ptr2Idx((reco::GenParticle*)gen.mother(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.mother(1),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(0),gens)<<Ptr2Idx((reco::GenParticle*)gen.daughter(1),gens);
  new_cout13<<gen.px()<<gen.py()<<gen.pz()<<gen.energy()<<gen.pt()<<gen.eta()<<gen.phi();
  new_cout5<<gen.isHardProcess();
  cout<<"<"<<endl;
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
    const reco::GenParticle *hard_l=NULL,*HN_l=NULL,*W_l=NULL;
    const reco::GenParticle *photon_grandgrandma=NULL,*photon_grandma=NULL,*photon_mother=NULL,*photon_sister=NULL;
    vector<const reco::GenParticle*> leptons,hard_partons,N_partons,hard_Ws,forward_partons,hard_photons;
    int Nhard=0;
    for(int i=0;i<gens.size();i++){
      //cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", isHardProcess : " << gens[i].isHardProcess() << endl;
      if(gens[i].isHardProcess()){
        Nhard++;
        cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", px : " << gens[i].px() << ", py : " << gens[i].py() << ", pz : " << gens[i].pz() << ", E : " << gens[i].energy() << ", pt : " << gens[i].pt() << ", eta : " << gens[i].eta() << ", phi : " << gens[i].phi() << endl;
        if(abs(gens[i].pdgId())==24) hard_Ws.push_back(&gens[i]);
        else if(abs(gens[i].pdgId())<=4||gens[i].pdgId()==21) hard_partons.push_back(&gens[i]);
        else if(gens[i].pdgId()==9900014) hard_HN=&gens[i]; 
        else if(gens[i].pdgId()==22) hard_photons.push_back(&gens[i]); //JH : need to consider H to gammagamma
      }
      if(gens[i].pdgId()==9900014) last_HN=&gens[i];
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==hard_partons.at(0)||gens[i].mother()==hard_photons.at(0))){
        hard_l=&gens[i]; //JH : XXX If hard_l is just reco::GenParticle* (w/o const), then it doesn't get &gens[i]
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the hard_l" << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==last_HN)){ //NOTE The mother should be last_HN
        HN_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l" << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(abs(gens[i].mother()->pdgId())==24)){
        W_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the W_l" << endl;
      }
      else if((abs(gens[i].pdgId())==5||abs(gens[i].pdgId())==6)){
        cout << "!!heavy quark!! : " << Ptr2Idx(&gens[i],gens) << endl; //JH just to check
      }

      if(gens[i].isPromptFinalState()){
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13) leptons.push_back(&gens[i]);
      }
    }
    for(int i=0;i<hard_partons.size();i++){
      if(abs((hard_partons.at(i)->mother())->pdgId())==24||(hard_partons.at(i)->mother())->pdgId()==9900014) N_partons.push_back(hard_partons.at(i));
      if(hard_partons.at(i)->mother(0)==hard_photons.at(0)||hard_partons.at(i)->mother(1)==hard_photons.at(0)) forward_partons.push_back(hard_partons.at(i));
    }

    if(hard_Ws.size()>0){
      for(int i=0;i<hard_Ws.size();i++) hard_Ws.at(i) = FindLastCopy(gens,hard_Ws.at(i));
    }
    if(hard_l) hard_l = FindLastCopy(gens,hard_l);
    if(W_l) W_l = FindLastCopy(gens,W_l); 
    if(HN_l) HN_l = FindLastCopy(gens,HN_l);  //NOTE No need this for last_HN; The code itself assigns the last HN to last_HN.

    TLorentzVector vec_photon=MakeTLorentzVector(hard_photons.at(0));
    photon_mother=(reco::GenParticle*)hard_photons.at(0)->mother();
    if(photon_mother->daughter(0)->pdgId()!=22) photon_sister=(reco::GenParticle*)photon_mother->daughter(0);
    else if(photon_mother->daughter(1)) photon_sister=(reco::GenParticle*)photon_mother->daughter(1); //JH : if photon_mother has 2 daughters, then one of the two must be a quark
    else{ //JH : photon_mother was actually a photon
      cout << "!!photon_mother was actually a photon!!" << endl;
      TLorentzVector vec_photon_mother=MakeTLorentzVector(photon_mother);
      TLorentzVector vec_Q=vec_photon_mother-vec_photon;
      cout << "check the Q : " << vec_Q.M() << endl;
      FillHist("check_the_Q",vec_Q.M(),1,20,-1,1); 
      cout << "assigning new photon_mother..." << endl;
      vector<int> photon_history = TrackGenSelfHistory(gens, photon_mother);
      photon_mother=&gens.at(photon_history[1]);
      photon_sister=(reco::GenParticle*)photon_mother->daughter(1);
    }

    if(!photon_sister) cout << "!!photon_sister UNDETECTED!!" << endl;
    
    int IsPhotonFromProton = 0;
    int IsPhotonFromProton1 = 0;
    int IsPhotonFromProton2 = 0;
    int IsPhotonFromProton3 = 0;
    if(photon_mother->pdgId()==2212) IsPhotonFromProton1 = 1;
    else{
      vector<int> photon_history = TrackGenSelfHistory(gens, photon_mother);
      photon_grandma=&gens.at(photon_history[1]);
      if(photon_grandma->pdgId()==2212) IsPhotonFromProton2 = 1;
      else{
        vector<int> photon_history = TrackGenSelfHistory(gens, photon_grandma);
        photon_grandgrandma=&gens.at(photon_history[1]);
        if(photon_grandgrandma->pdgId()==2212) IsPhotonFromProton3 = 1;
      }
    }
    if(IsPhotonFromProton1||IsPhotonFromProton2||IsPhotonFromProton3) IsPhotonFromProton = 1;

    cout << "IsPhotonFromProton (up to 3 generation) : " << IsPhotonFromProton << endl;
    if(!IsPhotonFromProton) cout << "!!No photon from proton!!" << endl;
    cout << "photon's mother idx : " << Ptr2Idx(photon_mother,gens) << ", id : " << photon_mother->pdgId() << ", status : " << photon_mother->status() << ",  px : " << photon_mother->px() << ", py : " << photon_mother->py() << ", pz : " << photon_mother->pz() << ", E : " << photon_mother->energy() << ", pt : " << photon_mother->pt() << ", eta : " << photon_mother->eta() << ", phi : " << photon_mother->phi() << endl;
    cout << "photon's sister idx : " << Ptr2Idx(photon_sister,gens) << ", id : " << photon_sister->pdgId() << ", status : " << photon_sister->status() << ",  px : " << photon_sister->px() << ", py : " << photon_sister->py() << ", pz : " << photon_sister->pz() << ", E : " << photon_sister->energy() << ", pt : " << photon_sister->pt() << ", eta : " << photon_sister->eta() << ", phi : " << photon_sister->phi() << endl;
    TLorentzVector vec_photon_mother=MakeTLorentzVector(photon_mother);
    TLorentzVector vec_photon_sister=MakeTLorentzVector(photon_sister);
    TLorentzVector vec_Q=vec_photon_mother-vec_photon_sister;
    cout << "photon's Q : " << vec_Q.M() << endl;
    if(vec_Q.M()>0) cout << "!!photon has positive Q!!" << endl;
    cout << "photon's Q^2 : " << pow(vec_Q.M(),2) << endl;

    cout << "how many weights : " << weights.size() << endl;
    cout << "event weight : " << weights[0] << endl;

    cout << "N of hard process particles : " << Nhard << endl;

    cout << "detected hard_l : " << Ptr2Idx(hard_l,gens) << endl;
    cout << "detected HN_l : " << Ptr2Idx(HN_l,gens) << endl;
    cout << "detected W_l : " << Ptr2Idx(W_l,gens) << endl;
    cout << "!!hard_l charge : " << GetCharge(hard_l) << "!!" << endl;
    cout << "!!HN_l charge : " << GetCharge(HN_l) << "!!" << endl;
    cout << "!!W_l charge : " << GetCharge(W_l) << "!!" << endl;

    cout << "detected hard_partons : " << endl;
    for(int i=0;i<hard_partons.size();i++) cout << Ptr2Idx(hard_partons.at(i),gens) << endl;
    cout << "detected forward_partons : " << endl;
    for(int i=0;i<forward_partons.size();i++) cout << Ptr2Idx(forward_partons.at(i),gens) << endl;
    cout << "N of forward partons : " << forward_partons.size() << endl;
    
    cout << "N of Ws : " << hard_Ws.size() << endl;
    //if(hard_Ws.size()==1){
    //  cout << "Which : ";
    //    if(Ptr2Idx(hard_Ws.at(0),gens).Atoi()<Ptr2Idx(hard_HN,gens).Atoi()){
    //      cout << "W1" << endl;
    //    }
    //    else cout << "W2" << endl;
    //  cout << "W : " << Ptr2Idx(hard_Ws.at(0),gens) << ", HN : " << Ptr2Idx(hard_HN,gens) << endl;
    //  cout << "W eta : " << hard_Ws.at(0)->eta() << endl; //NOTE W eta extremely changes from hard_W to last_W
    //} //JH : W1 and W2 are meaningless in Tchannel

    cout<<"  Idx  PID  sts mtr1 mtr2  dt1  dt2           px           py           pz            E           pt          eta          phi  hrdp"<<endl;
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

    //Now select meaningful jets among the (fat)jets_lepvetos

    reco::GenJet* leading_jet;
    reco::GenJet* subleading_jet;
    vector<reco::GenJet*> jets_forward_dR03;
    vector<reco::GenJet*> jets_forward;
    vector<reco::GenJet*> jets_forward_j2veto;
    vector<reco::GenJet*> jets_second_forward_dR03;
    vector<reco::GenJet*> jets_second_forward;
    reco::GenJet* second_forward_jet=NULL; //XXX why this cannot call print()?

/*

    //pick up the (sub)leading jet and inspect the jet constituents
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

      //cout << "leading jet info" << endl << leading_jet->print() << endl;
      //cout << "subleading jet info" << endl << subleading_jet->print() << endl;

*/

      //pick up the forward jet with dR 0.3 matching first, then the closest pt jet will be chosen 
      for(int i=0;i<jets_lepveto.size();i++){
        //for(int j=0;j<forward_partons.size();j++){
        for(int j=0;j<1;j++){ // JH : just for now
          if(deltaR(*jets_lepveto.at(i),*forward_partons.at(j))<0.3){
            jets_forward_dR03.push_back(jets_lepveto.at(i));
          }
        }
      } //dR 0.3 matching done
      if(jets_forward_dR03.size()>1){
        double tmpDiff = 10000.;
        int cand = 0;
        for(int i=0;i<jets_forward_dR03.size();i++){
          if(fabs(jets_forward_dR03.at(i)->pt()-forward_partons.at(0)->pt())<tmpDiff){
            tmpDiff = fabs(jets_forward_dR03.at(i)->pt()-forward_partons.at(0)->pt());
            cand = i;
          }
        }
        jets_forward.push_back(jets_forward_dR03.at(cand));
      }
      else if(jets_forward_dR03.size()==1) jets_forward.push_back(jets_forward_dR03.at(0));

      //cout << "N of forward jets : " << jets_forward.size() << endl;
      //if(jets_forward.size()>0) cout << "forward jet 1 info" << endl << jets_forward.at(0)->print() << endl;
      //if(jets_forward.size()>1) cout << "forward jet 2 info" << endl << jets_forward.at(1)->print() << endl;

/*

      //remove forward jet which have subleading jet inside
      for(int i=0;i<jets_forward.size();i++){
        if(jets_forward.at(i)!=subleading_jet) jets_forward_j2veto.push_back(jets_forward.at(i));
      }

      FillHist("forward_jet_matched",jets_forward.size(),weight,5,0,5);
      FillHist("forward_jet_matched_j2veto",jets_forward_j2veto.size(),weight,5,0,5);
      cout << "N of forward_jet_matched : " << jets_forward.size() << endl;
      cout << "N of forward_jet_matched_j2veto : " << jets_forward_j2veto.size() << endl;

*/

      //pick up the SECOND forward jet with dR 0.3 matching first, then the closest pt jet will be chosen 
      for(int i=0;i<jets_lepveto.size();i++){
        if(deltaR(*jets_lepveto.at(i),*photon_sister)<0.3){
          jets_second_forward_dR03.push_back(jets_lepveto.at(i));
        }
      } //dR 0.3 matching done
      if(jets_second_forward_dR03.size()>1){
        double tmpDiff = 10000.;
        int cand = 0;
        for(int i=0;i<jets_second_forward_dR03.size();i++){
          if(fabs(jets_second_forward_dR03.at(i)->pt()-photon_sister->pt())<tmpDiff){
            tmpDiff = fabs(jets_second_forward_dR03.at(i)->pt()-photon_sister->pt());
            cand = i;
          }
        }
        jets_second_forward.push_back(jets_second_forward_dR03.at(cand));
        second_forward_jet = jets_second_forward_dR03.at(cand);
      }
      else if(jets_second_forward_dR03.size()==1){
        jets_second_forward.push_back(jets_second_forward_dR03.at(0));
        second_forward_jet = jets_second_forward_dR03.at(0);
      }

      if(second_forward_jet){
        cout << "SECOND forward jet info :" << endl;
        cout << second_forward_jet << endl;
        cout << second_forward_jet->pt() << endl;
        second_forward_jet->print();
        jets_second_forward.at(0)->print(); //XXX why this doesn't work???
      }
      else cout << "!!SECOND forward jet UNDETECTED!!" << endl;

/*

      //See if subleading jet contains forward parton
      int HasForwardParton = 0;
      for(int j=0;j<forward_partons.size();j++){
        if(deltaR(*subleading_jet,*forward_partons.at(j))<0.4){
          HasForwardParton = 1;
          break;
        }
      }
      FillHist("j2_contains_forward",HasForwardParton,weight,2,0,2);

    }

    //See if fatjet contains forward parton
    int HasForwardParton = 0;
    for(int j=0;j<forward_partons.size();j++){
      if(deltaR(*fatjets_lepveto.at(0),*forward_partons.at(j))<0.8){
        HasForwardParton = 1;
        break;
      }
    }
    FillHist("fatjet_contains_forward",HasForwardParton,weight,2,0,2);

    //if(fatjets_lepveto.size()>0) cout << "fatjet info" << endl << fatjets_lepveto.at(0)->print() << endl;

    //if(leptons.size()!=2){
    //  cout << "@@@@@@@@detected lepton number : " << leptons.size() << "@@@@@@@@" << endl;
    //  for(int i=0; i<leptons.size(); i++) PrintGen(leptons.at(i));
    //  PrintGens(gens);
    //}

*/

    if(true){ 
      
      //sort(leptons.begin(),leptons.end(),PtCompare);
      //sort(jets.begin(),jets.end(),PtCompare);
      //sort(fatjets.begin(),fatjets.end(),PtCompare); //JH : XXX These - sorting vector<reco::GenParticles*> don't work!

      TLorentzVector* arr_leptons=MakeTLorentzVectorArray(leptons);
      TLorentzVector* arr_Npartons=MakeTLorentzVectorArray(N_partons);
      TLorentzVector* arr_jets=MakeTLorentzVectorArray(jets_lepveto); 
      TLorentzVector* arr_fatjets=MakeTLorentzVectorArray(fatjets_lepveto); 

      sort(arr_leptons,arr_leptons+leptons.size(),PtCompare);
      sort(arr_Npartons,arr_Npartons+N_partons.size(),PtCompare);
      sort(arr_jets,arr_jets+jets_lepveto.size(),PtCompare);
      sort(arr_fatjets,arr_fatjets+fatjets_lepveto.size(),PtCompare);
      
      //for(int i=0;i<leptons.size();i++){
      //  cout << "vector leptons pt : " << leptons.at(i)->pt() << endl;
      //}
      //for(int i=0;i<leptons.size();i++){
      //  cout << "sorted array leptons pt : " << arr_leptons[i].Pt() << endl;
      //}
      //for(int i=0;i<jets_lepveto.size();i++){
      //  cout << "sorted array lepton vetoed jets pt : " << arr_jets[i].Pt() << endl;
      //}

      //MakeTLorentzVectors

      //========prompt incoming particles========// 
      //TLorentzVector vec_init_q1=MakeTLorentzVector(hard_partons.at(0));
      //TLorentzVector vec_init_q2=MakeTLorentzVector(hard_partons.at(1));
      //TLorentzVector vec_init_diparton=vec_init_q1+vec_init_q2;

      //========onshell Ws========//
      TLorentzVector vec_on_W1, vec_on_W2;
      if(hard_Ws.size()==1){
        if(Ptr2Idx(hard_Ws.at(0),gens).Atoi()<Ptr2Idx(hard_HN,gens).Atoi()){ //NOTE Don't forget Atoi()!
          vec_on_W1=MakeTLorentzVector(hard_Ws.at(0));
        }
        else{
          vec_on_W2=MakeTLorentzVector(hard_Ws.at(0));
        }
      }
      else if(hard_Ws.size()==2){
        vec_on_W1=MakeTLorentzVector(hard_Ws.at(0));
        vec_on_W2=MakeTLorentzVector(hard_Ws.at(1));
      }
      
      //========HN========//
      TLorentzVector vec_last_HN=MakeTLorentzVector(last_HN);

      //========prompt decay particles========//
      TLorentzVector vec_hard_l=MakeTLorentzVector(hard_l);
      TLorentzVector vec_W_l=MakeTLorentzVector(W_l); //NOTE hard_l and W_l are complementary;
      TLorentzVector vec_HN_l=MakeTLorentzVector(HN_l);
      TLorentzVector vec_l1=arr_leptons[0];
      TLorentzVector vec_l2=arr_leptons[1];
      TLorentzVector vec_N_q1=arr_Npartons[0];
      TLorentzVector vec_N_q2=arr_Npartons[1];
      TLorentzVector vec_forward_parton1, vec_forward_parton2;
      if(forward_partons.size()>0) vec_forward_parton1=MakeTLorentzVector(forward_partons.at(0));
      if(forward_partons.size()>1) vec_forward_parton2=MakeTLorentzVector(forward_partons.at(1));
      
      //========offshell Ws reconstruction========//
      TLorentzVector vec_off_W1, vec_off_W2;
      if(!vec_on_W1.E()&&vec_on_W2.E()){
        vec_off_W1=vec_hard_l+vec_last_HN;
      }
      else if(vec_on_W1.E()&&!vec_on_W2.E()){
        vec_off_W2=vec_N_q1+vec_N_q2;
      }
      else if(!vec_on_W1.E()&&!vec_on_W2.E()){
        vec_off_W1=vec_hard_l+vec_last_HN;
        vec_off_W2=vec_N_q1+vec_N_q2;
      }

      //========jets, fatjet, METv (only lepton cleaned)========//
      TLorentzVector vec_j1, vec_j2;
      if(jets_lepveto.size()>0) vec_j1=arr_jets[0];
      if(jets_lepveto.size()>1) vec_j2=arr_jets[1];
      TLorentzVector vec_forward_j, vec_second_forward_j;
      if(jets_forward.size()>0) vec_forward_j=MakeTLorentzVector(jets_forward.at(0));
      if(second_forward_jet) vec_second_forward_j=MakeTLorentzVector(second_forward_jet);
      TLorentzVector vec_fatjet;
      if(fatjets_lepveto.size()>0) vec_fatjet=arr_fatjets[0];
      TLorentzVector vec_MET=MakeTLorentzVector(MET);

      //========combinatory objects========//
      TLorentzVector vec_dijet;
      if(jets_lepveto.size()>1) vec_dijet=vec_j1+vec_j2;
      TLorentzVector vec_l1_fatjet=vec_l1+vec_fatjet;
      TLorentzVector vec_l2_fatjet=vec_l2+vec_fatjet;
      TLorentzVector vec_l1_dijet=vec_l1+vec_dijet;
      TLorentzVector vec_l2_dijet=vec_l2+vec_dijet;
      TLorentzVector vec_SS2l_fatjet=vec_l1+vec_l2+vec_fatjet;
      TLorentzVector vec_SS2l_dijet=vec_l1+vec_l2+vec_dijet;
      TLorentzVector vec_l1_q1=vec_l1+vec_N_q1;

      //histograms

/*

      //W kinematics
      if(hard_Ws.size()==0){
        FillHist("offshell_W1_m",vec_off_W1.M(),weight,2000,0,2000);
        FillHist("offshell_W1_pt",vec_off_W1.Pt(),weight,2000,0,2000);
        FillHist("offshell_W1_E",vec_off_W1.E(),weight,2000,0,2000);
        FillHist("offshell_W1_eta",vec_off_W1.Eta(),weight,100,-5,5);
        FillHist("offshell_W2_m",vec_off_W2.M(),weight,2000,0,2000);
        FillHist("offshell_W2_pt",vec_off_W2.Pt(),weight,2000,0,2000);
        FillHist("offshell_W2_E",vec_off_W2.E(),weight,2000,0,2000);
        FillHist("offshell_W2_eta",vec_off_W2.Eta(),weight,100,-5,5);
        FillHist("W1_m",vec_off_W1.M(),weight,2000,0,2000);
        FillHist("W1_pt",vec_off_W1.Pt(),weight,2000,0,2000);
        FillHist("W1_E",vec_off_W1.E(),weight,2000,0,2000);
        FillHist("W1_eta",vec_off_W1.Eta(),weight,100,-5,5);
        FillHist("W2_m",vec_off_W2.M(),weight,2000,0,2000);
        FillHist("W2_pt",vec_off_W2.Pt(),weight,2000,0,2000);
        FillHist("W2_E",vec_off_W2.E(),weight,2000,0,2000);
        FillHist("W2_eta",vec_off_W2.Eta(),weight,100,-5,5);
        FillHist("W_m",vec_off_W1.M(),weight,2000,0,2000);
        FillHist("W_pt",vec_off_W1.Pt(),weight,2000,0,2000);
        FillHist("W_E",vec_off_W1.E(),weight,2000,0,2000);
        FillHist("W_eta",vec_off_W1.Eta(),weight,100,-5,5);
        FillHist("W_m",vec_off_W2.M(),weight,2000,0,2000);
        FillHist("W_pt",vec_off_W2.Pt(),weight,2000,0,2000);
        FillHist("W_E",vec_off_W2.E(),weight,2000,0,2000);
        FillHist("W_eta",vec_off_W2.Eta(),weight,100,-5,5);
      }
      else if(hard_Ws.size()==1){
        if(vec_on_W1.E()&&!vec_on_W2.E()){
          FillHist("onshell_W1_m",vec_on_W1.M(),weight,2000,0,2000);
          FillHist("onshell_W1_pt",vec_on_W1.Pt(),weight,2000,0,2000);
          FillHist("onshell_W1_E",vec_on_W1.E(),weight,2000,0,2000);
          FillHist("onshell_W1_eta",vec_on_W1.Eta(),weight,100,-5,5);
          FillHist("offshell_W2_m",vec_off_W2.M(),weight,2000,0,2000);
          FillHist("offshell_W2_pt",vec_off_W2.Pt(),weight,2000,0,2000);
          FillHist("offshell_W2_E",vec_off_W2.E(),weight,2000,0,2000);
          FillHist("offshell_W2_eta",vec_off_W2.Eta(),weight,100,-5,5);
          FillHist("W1_m",vec_on_W1.M(),weight,2000,0,2000);
          FillHist("W1_pt",vec_on_W1.Pt(),weight,2000,0,2000);
          FillHist("W1_E",vec_on_W1.E(),weight,2000,0,2000);
          FillHist("W1_eta",vec_on_W1.Eta(),weight,100,-5,5);
          FillHist("W2_m",vec_off_W2.M(),weight,2000,0,2000);
          FillHist("W2_pt",vec_off_W2.Pt(),weight,2000,0,2000);
          FillHist("W2_E",vec_off_W2.E(),weight,2000,0,2000);
          FillHist("W2_eta",vec_off_W2.Eta(),weight,100,-5,5);
          FillHist("W_m",vec_on_W1.M(),weight,2000,0,2000);
          FillHist("W_pt",vec_on_W1.Pt(),weight,2000,0,2000);
          FillHist("W_E",vec_on_W1.E(),weight,2000,0,2000);
          FillHist("W_eta",vec_on_W1.Eta(),weight,100,-5,5);
          FillHist("W_m",vec_off_W2.M(),weight,2000,0,2000);
          FillHist("W_pt",vec_off_W2.Pt(),weight,2000,0,2000);
          FillHist("W_E",vec_off_W2.E(),weight,2000,0,2000);
          FillHist("W_eta",vec_off_W2.Eta(),weight,100,-5,5);
        }
        else if(!vec_on_W1.E()&&vec_on_W2.E()){
          FillHist("offshell_W1_m",vec_off_W1.M(),weight,2000,0,2000);
          FillHist("offshell_W1_pt",vec_off_W1.Pt(),weight,2000,0,2000);
          FillHist("offshell_W1_E",vec_off_W1.E(),weight,2000,0,2000);
          FillHist("offshell_W1_eta",vec_off_W1.Eta(),weight,100,-5,5);
          FillHist("onshell_W2_m",vec_on_W2.M(),weight,2000,0,2000);
          FillHist("onshell_W2_pt",vec_on_W2.Pt(),weight,2000,0,2000);
          FillHist("onshell_W2_E",vec_on_W2.E(),weight,2000,0,2000);
          FillHist("onshell_W2_eta",vec_on_W2.Eta(),weight,100,-5,5);
          FillHist("W1_m",vec_off_W1.M(),weight,2000,0,2000);
          FillHist("W1_pt",vec_off_W1.Pt(),weight,2000,0,2000);
          FillHist("W1_E",vec_off_W1.E(),weight,2000,0,2000);
          FillHist("W1_eta",vec_off_W1.Eta(),weight,100,-5,5);
          FillHist("W2_m",vec_on_W2.M(),weight,2000,0,2000);
          FillHist("W2_pt",vec_on_W2.Pt(),weight,2000,0,2000);
          FillHist("W2_E",vec_on_W2.E(),weight,2000,0,2000);
          FillHist("W2_eta",vec_on_W2.Eta(),weight,100,-5,5);
          FillHist("W_m",vec_off_W1.M(),weight,2000,0,2000);
          FillHist("W_pt",vec_off_W1.Pt(),weight,2000,0,2000);
          FillHist("W_E",vec_off_W1.E(),weight,2000,0,2000);
          FillHist("W_eta",vec_off_W1.Eta(),weight,100,-5,5);
          FillHist("W_m",vec_on_W2.M(),weight,2000,0,2000);
          FillHist("W_pt",vec_on_W2.Pt(),weight,2000,0,2000);
          FillHist("W_E",vec_on_W2.E(),weight,2000,0,2000);
          FillHist("W_eta",vec_on_W2.Eta(),weight,100,-5,5);
        }
      }
      else if(hard_Ws.size()==2){
        FillHist("onshell_W1_m",vec_on_W1.M(),weight,2000,0,2000);
        FillHist("onshell_W1_pt",vec_on_W1.Pt(),weight,2000,0,2000);
        FillHist("onshell_W1_E",vec_on_W1.E(),weight,2000,0,2000);
        FillHist("onshell_W1_eta",vec_on_W1.Eta(),weight,100,-5,5);
        FillHist("onshell_W2_m",vec_on_W2.M(),weight,2000,0,2000);
        FillHist("onshell_W2_pt",vec_on_W2.Pt(),weight,2000,0,2000);
        FillHist("onshell_W2_E",vec_on_W2.E(),weight,2000,0,2000);
        FillHist("onshell_W2_eta",vec_on_W2.Eta(),weight,100,-5,5);
        FillHist("W1_m",vec_on_W1.M(),weight,2000,0,2000);
        FillHist("W1_pt",vec_on_W1.Pt(),weight,2000,0,2000);
        FillHist("W1_E",vec_on_W1.E(),weight,2000,0,2000);
        FillHist("W1_eta",vec_on_W1.Eta(),weight,100,-5,5);
        FillHist("W2_m",vec_on_W2.M(),weight,2000,0,2000);
        FillHist("W2_pt",vec_on_W2.Pt(),weight,2000,0,2000);
        FillHist("W2_E",vec_on_W2.E(),weight,2000,0,2000);
        FillHist("W2_eta",vec_on_W2.Eta(),weight,100,-5,5);
        FillHist("W_m",vec_on_W1.M(),weight,2000,0,2000);
        FillHist("W_pt",vec_on_W1.Pt(),weight,2000,0,2000);
        FillHist("W_E",vec_on_W1.E(),weight,2000,0,2000);
        FillHist("W_eta",vec_on_W1.Eta(),weight,100,-5,5);
        FillHist("W_m",vec_on_W2.M(),weight,2000,0,2000);
        FillHist("W_pt",vec_on_W2.Pt(),weight,2000,0,2000);
        FillHist("W_E",vec_on_W2.E(),weight,2000,0,2000);
        FillHist("W_eta",vec_on_W2.Eta(),weight,100,-5,5);
      }

*/

      //N kinematics
      FillHist("last_HN_m",vec_last_HN.M(),weight,2100,0,2100);
      FillHist("last_HN_pt",vec_last_HN.Pt(),weight,2000,0,2000);
      FillHist("last_HN_E",vec_last_HN.E(),weight,3000,0,3000);
      FillHist("last_HN_eta",vec_last_HN.Eta(),weight,100,-5,5);

      //forward parton kinematics
      if(forward_partons.size()>0){
        FillHist("forward_parton1_m",vec_forward_parton1.M(),weight,2000,0,2000);
        FillHist("forward_parton1_pt",vec_forward_parton1.Pt(),weight,2000,0,2000);
        FillHist("forward_parton1_E",vec_forward_parton1.E(),weight,2000,0,2000);
        FillHist("forward_parton1_eta",vec_forward_parton1.Eta(),weight,100,-5,5);
        if(forward_partons.at(0)->pdgId()==21){
          FillHist("forward_gluon1_m",vec_forward_parton1.M(),weight,2000,0,2000);
          FillHist("forward_gluon1_pt",vec_forward_parton1.Pt(),weight,2000,0,2000);
          FillHist("forward_gluon1_E",vec_forward_parton1.E(),weight,2000,0,2000);
          FillHist("forward_gluon1_eta",vec_forward_parton1.Eta(),weight,100,-5,5);
        }
        else{
          FillHist("forward_q1_m",vec_forward_parton1.M(),weight,2000,0,2000);
          FillHist("forward_q1_pt",vec_forward_parton1.Pt(),weight,2000,0,2000);
          FillHist("forward_q1_E",vec_forward_parton1.E(),weight,2000,0,2000);
          FillHist("forward_q1_eta",vec_forward_parton1.Eta(),weight,100,-5,5);
        }
      }
      if(forward_partons.size()>1){
        FillHist("forward_parton2_m",vec_forward_parton2.M(),weight,2000,0,2000);
        FillHist("forward_parton2_pt",vec_forward_parton2.Pt(),weight,2000,0,2000);
        FillHist("forward_parton2_E",vec_forward_parton2.E(),weight,2000,0,2000);
        FillHist("forward_parton2_eta",vec_forward_parton2.Eta(),weight,100,-5,5);
        if(forward_partons.at(1)->pdgId()==21){
          FillHist("forward_gluon2_m",vec_forward_parton2.M(),weight,2000,0,2000);
          FillHist("forward_gluon2_pt",vec_forward_parton2.Pt(),weight,2000,0,2000);
          FillHist("forward_gluon2_E",vec_forward_parton2.E(),weight,2000,0,2000);
          FillHist("forward_gluon2_eta",vec_forward_parton2.Eta(),weight,100,-5,5);
        }
        else{
          FillHist("forward_q2_m",vec_forward_parton2.M(),weight,2000,0,2000);
          FillHist("forward_q2_pt",vec_forward_parton2.Pt(),weight,2000,0,2000);
          FillHist("forward_q2_E",vec_forward_parton2.E(),weight,2000,0,2000);
          FillHist("forward_q2_eta",vec_forward_parton2.Eta(),weight,100,-5,5);
        }
      }

/*

      //N parton kinematics
      FillHist("N_q1_m",vec_N_q1.M(),weight,2000,0,2000);
      FillHist("N_q1_pt",vec_N_q1.Pt(),weight,2000,0,2000);
      FillHist("N_q1_E",vec_N_q1.E(),weight,3000,0,3000);
      FillHist("N_q1_eta",vec_N_q1.Eta(),weight,100,-5,5);
      FillHist("N_q2_m",vec_N_q2.M(),weight,2000,0,2000);
      FillHist("N_q2_pt",vec_N_q2.Pt(),weight,2000,0,2000);
      FillHist("N_q2_E",vec_N_q2.E(),weight,3000,0,3000);
      FillHist("N_q2_eta",vec_N_q2.Eta(),weight,100,-5,5);

      //fatjet kinematics
      if(fatjets_lepveto.size()>0){
        FillHist("fatjet_m",vec_fatjet.M(),weight,2000,0,2000);
        FillHist("fatjet_pt",vec_fatjet.Pt(),weight,2000,0,2000);
        FillHist("fatjet_E",vec_fatjet.E(),weight,3000,0,3000);
        FillHist("fatjet_eta",vec_fatjet.Eta(),weight,100,-5,5);
        if(vec_fatjet.Pt()>200.&&fabs(vec_fatjet.Eta())<2.7){
          FillHist("fatjet_sel_m",vec_fatjet.M(),weight,2000,0,2000);
          FillHist("fatjet_sel_pt",vec_fatjet.Pt(),weight,2000,0,2000);
          FillHist("fatjet_sel_E",vec_fatjet.E(),weight,3000,0,3000);
          FillHist("fatjet_sel_eta",vec_fatjet.Eta(),weight,100,-5,5);
        }
        FillHist("(l1+fatjet)_m",vec_l1_fatjet.M(),weight,3000,0,3000);
        FillHist("(l1+fatjet)_pt",vec_l1_fatjet.Pt(),weight,3000,0,3000);
        FillHist("(l1+fatjet)_E",vec_l1_fatjet.E(),weight,3000,0,3000);
        FillHist("(l1+fatjet)_eta",vec_l1_fatjet.Eta(),weight,100,-5,5);
        FillHist("(l2+fatjet)_m",vec_l2_fatjet.M(),weight,2000,0,2000);
        FillHist("(l2+fatjet)_pt",vec_l2_fatjet.Pt(),weight,1000,0,1000);
        FillHist("(l2+fatjet)_E",vec_l2_fatjet.E(),weight,3000,0,3000);
        FillHist("(l2+fatjet)_eta",vec_l2_fatjet.Eta(),weight,100,-5,5);
        FillHist("(SS2l+fatjet)_m",vec_SS2l_fatjet.M(),weight,2000,0,2000);
        FillHist("(SS2l+fatjet)_pt",vec_SS2l_fatjet.Pt(),weight,1000,0,1000);
        FillHist("(SS2l+fatjet)_E",vec_SS2l_fatjet.E(),weight,3000,0,3000);
        FillHist("(SS2l+fatjet)_eta",vec_SS2l_fatjet.Eta(),weight,100,-5,5);
      }

*/

      //jet kinematics
/*
      if(jets_lepveto.size()>1){
        FillHist("dijet_m",vec_dijet.M(),weight,2500,0,2500);
        FillHist("dijet_pt",vec_dijet.Pt(),weight,1000,0,1000);
        FillHist("dijet_E",vec_dijet.E(),weight,3000,0,3000);
        FillHist("dijet_eta",vec_dijet.Eta(),weight,100,-5,5);
        FillHist("(l1+dijet)_m",vec_l1_dijet.M(),weight,3500,0,3500);
        FillHist("(l1+dijet)_pt",vec_l1_dijet.Pt(),weight,2000,0,2000);
        FillHist("(l1+dijet)_E",vec_l1_dijet.E(),weight,3000,0,3000);
        FillHist("(l1+dijet)_eta",vec_l1_dijet.Eta(),weight,100,-5,5);
        FillHist("(l2+dijet)_m",vec_l2_dijet.M(),weight,3000,0,3000);
        FillHist("(l2+dijet)_pt",vec_l2_dijet.Pt(),weight,1000,0,1000);
        FillHist("(l2+dijet)_E",vec_l2_dijet.E(),weight,3000,0,3000);
        FillHist("(l2+dijet)_eta",vec_l2_dijet.Eta(),weight,100,-5,5);
        FillHist("(SS2l+dijet)_m",vec_SS2l_dijet.M(),weight,3500,0,3500);
        FillHist("(SS2l+dijet)_pt",vec_SS2l_dijet.Pt(),weight,2000,0,2000);
        FillHist("(SS2l+dijet)_E",vec_SS2l_dijet.E(),weight,3000,0,3000);
        FillHist("(SS2l+dijet)_eta",vec_SS2l_dijet.Eta(),weight,100,-5,5);
      }
*/
      if(jets_forward.size()>0){
        FillHist("forward_jet_m",vec_forward_j.M(),weight,2000,0,2000);
        FillHist("forward_jet_pt",vec_forward_j.Pt(),weight,2000,0,2000);
        FillHist("forward_jet_E",vec_forward_j.E(),weight,2000,0,2000);
        FillHist("forward_jet_eta",vec_forward_j.Eta(),weight,100,-5,5);
      }
      //FillHist("(l1+q1)_m",vec_l1_q1.M(),weight,3500,0,3500);

/*

      //lepton kinematics
      if(hard_l){
        FillHist("hard_l_pt",vec_hard_l.Pt(),weight,2000,0,2000);
        FillHist("hard_l_E",vec_hard_l.E(),weight,2000,0,2000);
        FillHist("hard_l_eta",vec_hard_l.Eta(),weight,100,-5,5);
        FillHist("hard_l_charge",GetCharge(hard_l),weight,3,-1,2);
      }
      if(HN_l){
        FillHist("HN_l_pt",vec_HN_l.Pt(),weight,2000,0,2000);
        FillHist("HN_l_E",vec_HN_l.E(),weight,2000,0,2000);
        FillHist("HN_l_eta",vec_HN_l.Eta(),weight,100,-5,5);
        FillHist("HN_l_charge",GetCharge(HN_l),weight,3,-1,2);
      }
      if(W_l){
        FillHist("W_l_pt",vec_W_l.Pt(),weight,2000,0,2000);
        FillHist("W_l_E",vec_W_l.E(),weight,2000,0,2000);
        FillHist("W_l_eta",vec_W_l.Eta(),weight,100,-5,5);
        FillHist("W_l_charge",GetCharge(W_l),weight,3,-1,2);
      }

      //leading, subleading objects kinematics
      FillHist("l1_pt",vec_l1.Pt(),weight,2000,0,2000);
      FillHist("l1_E",vec_l1.E(),weight,2000,0,2000);
      FillHist("l1_eta",vec_l1.Eta(),weight,100,-5,5);
      if(vec_l1.Pt()>10.&&fabs(vec_l1.Eta())<2.4){
        FillHist("l1_sel_pt",vec_l1.Pt(),weight,2000,0,2000);
        FillHist("l1_sel_E",vec_l1.E(),weight,2000,0,2000);
        FillHist("l1_sel_eta",vec_l1.Eta(),weight,100,-5,5);
      }
      FillHist("l2_pt",vec_l2.Pt(),weight,1000,0,1000);
      FillHist("l2_E",vec_l2.E(),weight,1000,0,1000);
      FillHist("l2_eta",vec_l2.Eta(),weight,100,-5,5);
      if(vec_l2.Pt()>10.&&fabs(vec_l2.Eta())<2.4){ //eta 2.4 : mumu channel assumed
        FillHist("l2_sel_pt",vec_l2.Pt(),weight,1000,0,1000);
        FillHist("l2_sel_E",vec_l2.E(),weight,1000,0,1000);
        FillHist("l2_sel_eta",vec_l2.Eta(),weight,100,-5,5);
      }

      if(jets_lepveto.size()>0){
        FillHist("j1_m",vec_j1.M(),weight,2000,0,2000);
        FillHist("j1_pt",vec_j1.Pt(),weight,2000,0,2000);
        FillHist("j1_E",vec_j1.E(),weight,2000,0,2000);
        FillHist("j1_eta",vec_j1.Eta(),weight,100,-5,5);
        if(vec_j1.Pt()>20.&&fabs(vec_j1.Eta())<2.7){
          FillHist("j1_sel_m",vec_j1.M(),weight,2000,0,2000);
          FillHist("j1_sel_pt",vec_j1.Pt(),weight,2000,0,2000);
          FillHist("j1_sel_E",vec_j1.E(),weight,2000,0,2000);
          FillHist("j1_sel_eta",vec_j1.Eta(),weight,100,-5,5);
        }
      }
      if(jets_lepveto.size()>1){
        FillHist("j2_m",vec_j2.M(),weight,2000,0,2000);
        FillHist("j2_pt",vec_j2.Pt(),weight,2000,0,2000);
        FillHist("j2_E",vec_j2.E(),weight,2000,0,2000);
        FillHist("j2_eta",vec_j2.Eta(),weight,100,-5,5);
        FillHist("DeltaR(jj)",vec_j1.DeltaR(vec_j2),weight,50,0,5);
        if(vec_j2.Pt()>20.&&fabs(vec_j2.Eta())<2.7&&vec_j2.Pt()>20.&&fabs(vec_j2.Eta())<2.7){
          FillHist("j2_sel_m",vec_j2.M(),weight,2000,0,2000);
          FillHist("j2_sel_pt",vec_j2.Pt(),weight,2000,0,2000);
          FillHist("j2_sel_E",vec_j2.E(),weight,2000,0,2000);
          FillHist("j2_sel_eta",vec_j2.Eta(),weight,100,-5,5);
          FillHist("DeltaR(jj)_sel",vec_j1.DeltaR(vec_j2),weight,50,0,5);
        }
        if(fabs(vec_j2.Eta())<1.5){
          FillHist("j2_loweta_m",vec_j2.M(),weight,2000,0,2000);
          FillHist("j2_loweta_pt",vec_j2.Pt(),weight,2000,0,2000);
          FillHist("j2_loweta_E",vec_j2.E(),weight,2000,0,2000);
          FillHist("j2_loweta_eta",vec_j2.Eta(),weight,100,-5,5);
        }
        if(fabs(vec_j2.Eta())>1.5){
          FillHist("j2_higheta_m",vec_j2.M(),weight,2000,0,2000);
          FillHist("j2_higheta_pt",vec_j2.Pt(),weight,2000,0,2000);
          FillHist("j2_higheta_E",vec_j2.E(),weight,2000,0,2000);
          FillHist("j2_higheta_eta",vec_j2.Eta(),weight,100,-5,5);
        }
      }

      //MET, various dR distribution, etc.
      FillHist("DeltaR(qq)",vec_N_q1.DeltaR(vec_N_q2),weight,50,0,5);
      FillHist("DeltaR(q1forwardparton)",vec_N_q1.DeltaR(vec_forward_parton1),weight,50,0,5);
      FillHist("DeltaR(q2forwardparton)",vec_N_q2.DeltaR(vec_forward_parton1),weight,50,0,5);
      FillHist("DeltaR(q1fatjet)",vec_N_q1.DeltaR(vec_fatjet),weight,50,0,5);
      FillHist("DeltaR(q2fatjet)",vec_N_q2.DeltaR(vec_fatjet),weight,50,0,5);
      FillHist("DeltaR(Wfatjet)",vec_on_W2.DeltaR(vec_fatjet),weight,50,0,5);
      FillHist("DeltaR(j2forwardparton)",vec_j2.DeltaR(vec_forward_parton1),weight,50,0,5);
      FillHist("METv_m",vec_MET.M(),weight,2000,0,2000);
      FillHist("METv_pt",vec_MET.Pt(),weight,2000,0,2000);
      FillHist("METv_E",vec_MET.E(),weight,2000,0,2000);
      FillHist("METv_eta",vec_MET.Eta(),weight,100,-5,5);
      //FillHist("diparton_m",vec_init_diparton.M(),weight,2000,0,2000);
      //FillHist("diparton_pt",vec_init_diparton.Pt(),weight,2000,0,2000);
      //FillHist("diparton_E",vec_init_diparton.E(),weight,2000,0,2000);
      //FillHist("diparton_eta",vec_init_diparton.Eta(),weight,4000,-2.0e+11,2.0e+11);
      //FillHist("diparton_pz",vec_init_diparton.Pz(),weight,4000,-2000,2000);

      //int IsSameCharge = GetCharge(hard_l)*GetCharge(HN_l);
      //FillHist("IsSameChargeLepton",IsSameCharge,weight,3,-1,2);
      int IsForwardHarderthanq2 = vec_forward_parton1.Pt()>vec_N_q2.Pt();
      FillHist("IsForwardHarderthanq2",IsForwardHarderthanq2,weight,2,0,2);

      //number of objects
      FillHist("nlep",leptons.size(),weight,5,0,5);
      FillHist("njet",jets_lepveto.size(),weight,50,0,50);
      FillHist("nfatjet",fatjets_lepveto.size(),weight,50,0,50);

      //objects pt, eta
      for(int i=0; i<leptons.size(); i++){
        FillHist("leptons_pt",leptons.at(i)->pt(),weight,1000,0,1000);
        FillHist("leptons_eta",leptons.at(i)->eta(),weight,100,-5,5);
      }
      for(int i=0; i<jets_lepveto.size(); i++){
        FillHist("jets_pt",jets_lepveto.at(i)->pt(),weight,1000,0,1000);
        FillHist("jets_eta",jets_lepveto.at(i)->eta(),weight,100,-5,5);
      }
      for(int i=0; i<fatjets_lepveto.size(); i++){
        FillHist("fatjets_pt",fatjets_lepveto.at(i)->pt(),weight,1000,0,1000);
        FillHist("fatjets_eta",fatjets_lepveto.at(i)->eta(),weight,100,-5,5);
      }

      //weight
      FillHist("weight",weights[0],1,2000,-1.0e-06,1.0e-06);

*/

      //photon-related information
      TLorentzVector vec_photon_mother_reco=vec_photon+vec_photon_sister;
      if(IsPhotonFromProton1) FillHist("IsPhotonFromProton",1,1,4,0,4);
      else if(IsPhotonFromProton2) FillHist("IsPhotonFromProton",2,1,4,0,4);
      else if(IsPhotonFromProton3) FillHist("IsPhotonFromProton",3,1,4,0,4);
      else FillHist("IsPhotonFromProton",0,1,4,0,4);
      FillHist("Q",vec_Q.M(),1,2500,-2000,500); 
      FillHist("Q2",pow(vec_Q.M(),2),1,40000,0,4000000); 
      FillHist("second_forward_parton_pt",vec_photon_sister.Pt(),1,2000,0,2000);
      FillHist("second_forward_parton_eta",vec_photon_sister.Eta(),1,100,-5,5);
      FillHist("second_forward_parton_phi",vec_photon_sister.Phi(),1,63,-3.15,3.15);
      FillHist("second_forward_parton_px",vec_photon_sister.Px(),1,2000,-1000,1000);
      FillHist("second_forward_parton_py",vec_photon_sister.Py(),1,2000,-1000,1000);
      FillHist("second_forward_parton_pz",vec_photon_sister.Pz(),1,13000,-6500,6500);
      FillHist("second_forward_parton_pz_abs",fabs(vec_photon_sister.Pz()),1,6500,0,6500);
      FillHist("second_forward_parton_E",vec_photon_sister.E(),1,6500,0,6500);
      FillHist("second_forward_parton_PID",photon_sister->pdgId(),1,2510,-10,2500);
      FillHist("photon_mother_pt",vec_photon_mother.Pt(),1,2000,0,2000);
      FillHist("photon_mother_eta",vec_photon_mother.Eta(),1,100,-5,5);
      FillHist("photon_mother_phi",vec_photon_mother.Phi(),1,63,-3.15,3.15);
      FillHist("photon_mother_px",vec_photon_mother.Px(),1,2000,-1000,1000);
      FillHist("photon_mother_py",vec_photon_mother.Py(),1,2000,-1000,1000);
      FillHist("photon_mother_pz",vec_photon_mother.Pz(),1,13000,-6500,6500);
      FillHist("photon_mother_pz_abs",fabs(vec_photon_mother.Pz()),1,6500,0,6500);
      FillHist("photon_mother_E",vec_photon_mother.E(),1,6500,0,6500);
      FillHist("photon_mother_PID",photon_mother->pdgId(),1,2510,-10,2500);
      FillHist("photon_pt",vec_photon.Pt(),1,10,0,10);
      FillHist("photon_eta",vec_photon.Eta(),1,100,-5,5);
      FillHist("photon_phi",vec_photon.Phi(),1,63,-3.15,3.15);
      FillHist("photon_E",vec_photon.E(),1,6500,0,6500);
      FillHist("photon_px",vec_photon.Px(),1,2000,-1000,1000);
      FillHist("photon_py",vec_photon.Py(),1,2000,-1000,1000);
      FillHist("photon_pz",vec_photon.Pz(),1,13000,-6500,6500);
      FillHist("photon_pz_abs",fabs(vec_photon.Pz()),1,6500,0,6500);
      FillHist("photon_mother_reco_pt",vec_photon_mother_reco.Pt(),1,2000,0,2000);
      FillHist("photon_mother_reco_eta",vec_photon_mother_reco.Eta(),1,100,-5,5);
      FillHist("photon_mother_reco_phi",vec_photon_mother_reco.Phi(),1,63,-3.15,3.15);
      FillHist("photon_mother_reco_E",vec_photon_mother_reco.E(),1,6500,0,6500);
      FillHist("photon_mother_reco_px",vec_photon_mother_reco.Px(),1,2000,-1000,1000);
      FillHist("photon_mother_reco_py",vec_photon_mother_reco.Py(),1,2000,-1000,1000);
      FillHist("photon_mother_reco_pz",vec_photon_mother_reco.Pz(),1,13000,-6500,6500);
      FillHist("photon_mother_reco_pz_abs",fabs(vec_photon_mother_reco.Pz()),1,6500,0,6500);
      FillHist("drDiff",vec_photon_mother.DeltaR(vec_photon_mother_reco),1,50,0,5);
      FillHist("PxDiff",fabs(vec_photon_mother_reco.Px()-vec_photon_mother.Px()),1,1000,0,1000);
      FillHist("PyDiff",fabs(vec_photon_mother_reco.Py()-vec_photon_mother.Py()),1,1000,0,1000);
      FillHist("PzDiff",fabs(vec_photon_mother_reco.Pz()-vec_photon_mother.Pz()),1,1000,0,1000);
      FillHist("EnergyDiff",fabs(vec_photon_mother_reco.E()-vec_photon_mother.E()),1,1000,0,1000);
      //if(fabs(vec_photon_mother_reco.Px()-vec_photon_mother.Px())<1.) FillHist("IsPxWellRecoed",1,1,2,0,2);
      //else FillHist("IsPxWellRecoed",0,1,2,0,2);
      //if(fabs(vec_photon_mother_reco.Py()-vec_photon_mother.Py())<1.) FillHist("IsPyWellRecoed",1,1,2,0,2);
      //else FillHist("IsPyWellRecoed",0,1,2,0,2);
      //if(fabs(vec_photon_mother_reco.Pz()-vec_photon_mother.Pz())<1.) FillHist("IsPzWellRecoed",1,1,2,0,2);
      //else FillHist("IsPzWellRecoed",0,1,2,0,2);
      //if(fabs(vec_photon_mother_reco.E()-vec_photon_mother.E())<1.) FillHist("IsEnergyWellRecoed",1,1,2,0,2);
      //else FillHist("IsEnergyWellRecoed",0,1,2,0,2);
      if(jets_forward.size()>0&&second_forward_jet){
        if(jets_forward.at(0)->pt()==second_forward_jet->pt()&&jets_forward.at(0)->eta()==second_forward_jet->eta()) FillHist("IsForwardsAreSame",1,1,2,0,2);
        else FillHist("IsForwardsAreSame",0,1,2,0,2);
      }
      if(second_forward_jet){
        FillHist("second_forward_jet_pt",vec_second_forward_j.Pt(),weight,2000,0,2000);
        FillHist("second_forward_jet_eta",vec_second_forward_j.Eta(),weight,100,-5,5);
        FillHist("second_forward_jet_phi",vec_second_forward_j.Phi(),1,63,-3.15,3.15);
      }

    }
    else{
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
