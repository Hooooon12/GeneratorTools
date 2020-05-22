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

    const reco::GenParticle *hard_HN=NULL;
    const reco::GenParticle *last_HN=NULL;
    const reco::GenParticle *hard_l=NULL,*HN_l=NULL,*W_l=NULL,*forward_parton=NULL;
    vector<const reco::GenParticle*> leptons,hard_partons,N_partons,hard_Ws;
    for(int i=0;i<gens.size();i++){
      //cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", isHardProcess : " << gens[i].isHardProcess() << endl;
      if(gens[i].isHardProcess()){
        cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", px : " << gens[i].px() << ", py : " << gens[i].py() << ", pz : " << gens[i].pz() << ", E : " << gens[i].energy() << ", eta : " << gens[i].eta() << endl;
        if(abs(gens[i].pdgId())==24) hard_Ws.push_back(&gens[i]);
        else if(abs(gens[i].pdgId())<=4||gens[i].pdgId()==21) hard_partons.push_back(&gens[i]);
        else if(gens[i].pdgId()==9900012) hard_HN=&gens[i]; 
      }
      if(gens[i].pdgId()==9900012) last_HN=&gens[i];
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==hard_partons.at(0))){
        hard_l=&gens[i]; //JH : XXX If hard_l is just reco::GenParticle* (w/o const), then it doesn't get &gens[i]
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the hard_l : " << hard_l << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==last_HN)){ //NOTE The mother should be last_HN
        HN_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l : " << HN_l << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(abs(gens[i].mother()->pdgId())==24)){
        W_l=&gens[i];
        cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the W_l : " << W_l << endl;
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
      for(int i=0; i<leptons.size(); i++) PrintGen(leptons.at(i));
      PrintGens(gens);
    }

    if(HN_l){ 
      
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
      
      for(int i=0;i<leptons.size();i++){
        cout << "vector leptons pt : " << leptons.at(i)->pt() << endl;
      }
      for(int i=0;i<leptons.size();i++){
        cout << "sorted array leptons pt : " << arr_leptons[i].Pt() << endl;
      }
      for(int i=0;i<jets_lepveto.size();i++){
        cout << "sorted array lepton vetoed jets pt : " << arr_jets[i].Pt() << endl;
      }

      //MakeTLorentzVectors

      //========prompt incoming particles========//
      TLorentzVector vec_init_q1=MakeTLorentzVector(hard_partons.at(0));
      TLorentzVector vec_init_q2=MakeTLorentzVector(hard_partons.at(1));
      TLorentzVector vec_init_diparton=vec_init_q1+vec_init_q2;

      //========onshell Ws========//
      TLorentzVector vec_on_W1, vec_on_W2;
      if(hard_Ws.size()==1){
        if(Ptr2Idx(hard_Ws.at(0),gens).Atoi()<Ptr2Idx(hard_HN,gens).Atoi()){ //NOTE Don't forget Atoi()!
          vec_on_W1=MakeTLorentzVector(hard_Ws.at(0));
        }else{
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
      TLorentzVector vec_l0=arr_leptons[0];
      TLorentzVector vec_l1=arr_leptons[1];
      TLorentzVector vec_N_q0=arr_Npartons[0];
      TLorentzVector vec_N_q1=arr_Npartons[1];
      TLorentzVector vec_forward_parton=MakeTLorentzVector(forward_parton);
      
      //========offshell Ws reconstruction========//
      TLorentzVector vec_off_W1, vec_off_W2;
      if(!vec_on_W1.E()&&vec_on_W2.E()){
        vec_off_W1=vec_hard_l+vec_last_HN;
      }
      else if(vec_on_W1.E()&&!vec_on_W2.E()){
        vec_off_W2=vec_N_q0+vec_N_q1;
      }
      else if(!vec_on_W1.E()&&!vec_on_W2.E()){
        vec_off_W1=vec_hard_l+vec_last_HN;
        vec_off_W2=vec_N_q0+vec_N_q1;
      }

      //========jets, fatjet, METv (only lepton cleaned)========//
      TLorentzVector vec_j0, vec_j1;
      if(jets_lepveto.size()>0) vec_j0=arr_jets[0];
      if(jets_lepveto.size()>1) vec_j1=arr_jets[1];
      TLorentzVector vec_fatjet;
      if(fatjets_lepveto.size()>0) vec_fatjet=arr_fatjets[0];
      TLorentzVector vec_MET=MakeTLorentzVector(MET);

      //========combinatory objects========//
      TLorentzVector vec_dijet;
      if(jets_lepveto.size()>1) vec_dijet=vec_j0+vec_j1;
      TLorentzVector vec_l0_fatjet=vec_l0+vec_fatjet;
      TLorentzVector vec_l1_fatjet=vec_l1+vec_fatjet;
      TLorentzVector vec_l0_dijet=vec_l0+vec_dijet;
      TLorentzVector vec_l1_dijet=vec_l1+vec_dijet;
      TLorentzVector vec_SS2l_fatjet=vec_l0+vec_l1+vec_fatjet;
      TLorentzVector vec_SS2l_dijet=vec_l0+vec_l1+vec_dijet;

      //histograms

      if(hard_Ws.size()==0){
        FillHist("offshell_W1_m",vec_off_W1.M(),1,2000,0,2000);
        FillHist("offshell_W1_pt",vec_off_W1.Pt(),1,2000,0,2000);
        FillHist("offshell_W1_E",vec_off_W1.E(),1,2000,0,2000);
        FillHist("offshell_W1_eta",vec_off_W1.Eta(),1,50,-5,5);
        FillHist("offshell_W2_m",vec_off_W2.M(),1,2000,0,2000);
        FillHist("offshell_W2_pt",vec_off_W2.Pt(),1,2000,0,2000);
        FillHist("offshell_W2_E",vec_off_W2.E(),1,2000,0,2000);
        FillHist("offshell_W2_eta",vec_off_W2.Eta(),1,50,-5,5);
        FillHist("W1_m",vec_off_W1.M(),1,2000,0,2000);
        FillHist("W1_pt",vec_off_W1.Pt(),1,2000,0,2000);
        FillHist("W1_E",vec_off_W1.E(),1,2000,0,2000);
        FillHist("W1_eta",vec_off_W1.Eta(),1,50,-5,5);
        FillHist("W2_m",vec_off_W2.M(),1,2000,0,2000);
        FillHist("W2_pt",vec_off_W2.Pt(),1,2000,0,2000);
        FillHist("W2_E",vec_off_W2.E(),1,2000,0,2000);
        FillHist("W2_eta",vec_off_W2.Eta(),1,50,-5,5);
        FillHist("W_m",vec_off_W1.M(),1,2000,0,2000);
        FillHist("W_pt",vec_off_W1.Pt(),1,2000,0,2000);
        FillHist("W_E",vec_off_W1.E(),1,2000,0,2000);
        FillHist("W_eta",vec_off_W1.Eta(),1,50,-5,5);
        FillHist("W_m",vec_off_W2.M(),1,2000,0,2000);
        FillHist("W_pt",vec_off_W2.Pt(),1,2000,0,2000);
        FillHist("W_E",vec_off_W2.E(),1,2000,0,2000);
        FillHist("W_eta",vec_off_W2.Eta(),1,50,-5,5);
      }
      else if(hard_Ws.size()==1){
        if(vec_on_W1.E()&&!vec_on_W2.E()){
          FillHist("onshell_W1_m",vec_on_W1.M(),1,2000,0,2000);
          FillHist("onshell_W1_pt",vec_on_W1.Pt(),1,2000,0,2000);
          FillHist("onshell_W1_E",vec_on_W1.E(),1,2000,0,2000);
          FillHist("onshell_W1_eta",vec_on_W1.Eta(),1,50,-5,5);
          FillHist("offshell_W2_m",vec_off_W2.M(),1,2000,0,2000);
          FillHist("offshell_W2_pt",vec_off_W2.Pt(),1,2000,0,2000);
          FillHist("offshell_W2_E",vec_off_W2.E(),1,2000,0,2000);
          FillHist("offshell_W2_eta",vec_off_W2.Eta(),1,50,-5,5);
          FillHist("W1_m",vec_on_W1.M(),1,2000,0,2000);
          FillHist("W1_pt",vec_on_W1.Pt(),1,2000,0,2000);
          FillHist("W1_E",vec_on_W1.E(),1,2000,0,2000);
          FillHist("W1_eta",vec_on_W1.Eta(),1,50,-5,5);
          FillHist("W2_m",vec_off_W2.M(),1,2000,0,2000);
          FillHist("W2_pt",vec_off_W2.Pt(),1,2000,0,2000);
          FillHist("W2_E",vec_off_W2.E(),1,2000,0,2000);
          FillHist("W2_eta",vec_off_W2.Eta(),1,50,-5,5);
          FillHist("W_m",vec_on_W1.M(),1,2000,0,2000);
          FillHist("W_pt",vec_on_W1.Pt(),1,2000,0,2000);
          FillHist("W_E",vec_on_W1.E(),1,2000,0,2000);
          FillHist("W_eta",vec_on_W1.Eta(),1,50,-5,5);
          FillHist("W_m",vec_off_W2.M(),1,2000,0,2000);
          FillHist("W_pt",vec_off_W2.Pt(),1,2000,0,2000);
          FillHist("W_E",vec_off_W2.E(),1,2000,0,2000);
          FillHist("W_eta",vec_off_W2.Eta(),1,50,-5,5);
        }
        else if(!vec_on_W1.E()&&vec_on_W2.E()){
          FillHist("offshell_W1_m",vec_off_W1.M(),1,2000,0,2000);
          FillHist("offshell_W1_pt",vec_off_W1.Pt(),1,2000,0,2000);
          FillHist("offshell_W1_E",vec_off_W1.E(),1,2000,0,2000);
          FillHist("offshell_W1_eta",vec_off_W1.Eta(),1,50,-5,5);
          FillHist("onshell_W2_m",vec_on_W2.M(),1,2000,0,2000);
          FillHist("onshell_W2_pt",vec_on_W2.Pt(),1,2000,0,2000);
          FillHist("onshell_W2_E",vec_on_W2.E(),1,2000,0,2000);
          FillHist("onshell_W2_eta",vec_on_W2.Eta(),1,50,-5,5);
          FillHist("W1_m",vec_off_W1.M(),1,2000,0,2000);
          FillHist("W1_pt",vec_off_W1.Pt(),1,2000,0,2000);
          FillHist("W1_E",vec_off_W1.E(),1,2000,0,2000);
          FillHist("W1_eta",vec_off_W1.Eta(),1,50,-5,5);
          FillHist("W2_m",vec_on_W2.M(),1,2000,0,2000);
          FillHist("W2_pt",vec_on_W2.Pt(),1,2000,0,2000);
          FillHist("W2_E",vec_on_W2.E(),1,2000,0,2000);
          FillHist("W2_eta",vec_on_W2.Eta(),1,50,-5,5);
          FillHist("W_m",vec_off_W1.M(),1,2000,0,2000);
          FillHist("W_pt",vec_off_W1.Pt(),1,2000,0,2000);
          FillHist("W_E",vec_off_W1.E(),1,2000,0,2000);
          FillHist("W_eta",vec_off_W1.Eta(),1,50,-5,5);
          FillHist("W_m",vec_on_W2.M(),1,2000,0,2000);
          FillHist("W_pt",vec_on_W2.Pt(),1,2000,0,2000);
          FillHist("W_E",vec_on_W2.E(),1,2000,0,2000);
          FillHist("W_eta",vec_on_W2.Eta(),1,50,-5,5);
        }
      }
      else if(hard_Ws.size()==2){
        FillHist("onshell_W1_m",vec_on_W1.M(),1,2000,0,2000);
        FillHist("onshell_W1_pt",vec_on_W1.Pt(),1,2000,0,2000);
        FillHist("onshell_W1_E",vec_on_W1.E(),1,2000,0,2000);
        FillHist("onshell_W1_eta",vec_on_W1.Eta(),1,50,-5,5);
        FillHist("onshell_W2_m",vec_on_W2.M(),1,2000,0,2000);
        FillHist("onshell_W2_pt",vec_on_W2.Pt(),1,2000,0,2000);
        FillHist("onshell_W2_E",vec_on_W2.E(),1,2000,0,2000);
        FillHist("onshell_W2_eta",vec_on_W2.Eta(),1,50,-5,5);
        FillHist("W1_m",vec_on_W1.M(),1,2000,0,2000);
        FillHist("W1_pt",vec_on_W1.Pt(),1,2000,0,2000);
        FillHist("W1_E",vec_on_W1.E(),1,2000,0,2000);
        FillHist("W1_eta",vec_on_W1.Eta(),1,50,-5,5);
        FillHist("W2_m",vec_on_W2.M(),1,2000,0,2000);
        FillHist("W2_pt",vec_on_W2.Pt(),1,2000,0,2000);
        FillHist("W2_E",vec_on_W2.E(),1,2000,0,2000);
        FillHist("W2_eta",vec_on_W2.Eta(),1,50,-5,5);
        FillHist("W_m",vec_on_W1.M(),1,2000,0,2000);
        FillHist("W_pt",vec_on_W1.Pt(),1,2000,0,2000);
        FillHist("W_E",vec_on_W1.E(),1,2000,0,2000);
        FillHist("W_eta",vec_on_W1.Eta(),1,50,-5,5);
        FillHist("W_m",vec_on_W2.M(),1,2000,0,2000);
        FillHist("W_pt",vec_on_W2.Pt(),1,2000,0,2000);
        FillHist("W_E",vec_on_W2.E(),1,2000,0,2000);
        FillHist("W_eta",vec_on_W2.Eta(),1,50,-5,5);
      }

      FillHist("last_HN_m",vec_last_HN.M(),1,2100,0,2100);
      FillHist("last_HN_pt",vec_last_HN.Pt(),1,2000,0,2000);
      FillHist("last_HN_E",vec_last_HN.E(),1,3000,0,3000);
      FillHist("last_HN_eta",vec_last_HN.Eta(),1,50,-5,5);

      if(forward_parton){
        FillHist("forward_parton_m",vec_forward_parton.M(),1,2000,0,2000);
        FillHist("forward_parton_pt",vec_forward_parton.Pt(),1,2000,0,2000);
        FillHist("forward_parton_E",vec_forward_parton.E(),1,2000,0,2000);
        FillHist("forward_parton_eta",vec_forward_parton.Eta(),1,50,-5,5);
        if(forward_parton->pdgId()==21){
          FillHist("forward_gluon_m",vec_forward_parton.M(),1,2000,0,2000);
          FillHist("forward_gluon_pt",vec_forward_parton.Pt(),1,2000,0,2000);
          FillHist("forward_gluon_E",vec_forward_parton.E(),1,2000,0,2000);
          FillHist("forward_gluon_eta",vec_forward_parton.Eta(),1,50,-5,5);
        }
        else{
          FillHist("forward_q_m",vec_forward_parton.M(),1,2000,0,2000);
          FillHist("forward_q_pt",vec_forward_parton.Pt(),1,2000,0,2000);
          FillHist("forward_q_E",vec_forward_parton.E(),1,2000,0,2000);
          FillHist("forward_q_eta",vec_forward_parton.Eta(),1,50,-5,5);
        }
      }

      FillHist("N_q0_m",vec_N_q0.M(),1,2000,0,2000);
      FillHist("N_q0_pt",vec_N_q0.Pt(),1,2000,0,2000);
      FillHist("N_q0_E",vec_N_q0.E(),1,3000,0,3000);
      FillHist("N_q0_eta",vec_N_q0.Eta(),1,50,-5,5);
      FillHist("N_q1_m",vec_N_q1.M(),1,2000,0,2000);
      FillHist("N_q1_pt",vec_N_q1.Pt(),1,2000,0,2000);
      FillHist("N_q1_E",vec_N_q1.E(),1,3000,0,3000);
      FillHist("N_q1_eta",vec_N_q1.Eta(),1,50,-5,5);

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

      if(hard_l){
        FillHist("hard_l_pt",vec_hard_l.Pt(),1,2000,0,2000);
        FillHist("hard_l_E",vec_hard_l.E(),1,2000,0,2000);
        FillHist("hard_l_eta",vec_hard_l.Eta(),1,50,-5,5);
        FillHist("hard_l_charge",GetCharge(hard_l),1,3,-1,2);
      }
      FillHist("HN_l_pt",vec_HN_l.Pt(),1,2000,0,2000);
      FillHist("HN_l_E",vec_HN_l.E(),1,2000,0,2000);
      FillHist("HN_l_eta",vec_HN_l.Eta(),1,50,-5,5);
      FillHist("HN_l_charge",GetCharge(HN_l),1,3,-1,2);
      if(W_l){
        FillHist("W_l_pt",vec_W_l.Pt(),1,2000,0,2000);
        FillHist("W_l_E",vec_W_l.E(),1,2000,0,2000);
        FillHist("W_l_eta",vec_W_l.Eta(),1,50,-5,5);
        FillHist("W_l_charge",GetCharge(W_l),1,3,-1,2);
      }
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
      FillHist("DeltaR(qq)",vec_N_q0.DeltaR(vec_N_q1),1,50,0,5);
      FillHist("METv_m",vec_MET.M(),1,2000,0,2000);
      FillHist("METv_pt",vec_MET.Pt(),1,2000,0,2000);
      FillHist("METv_E",vec_MET.E(),1,2000,0,2000);
      FillHist("METv_eta",vec_MET.Eta(),1,50,-5,5);
      FillHist("diparton_m",vec_init_diparton.M(),1,2000,0,2000);
      FillHist("diparton_pt",vec_init_diparton.Pt(),1,2000,0,2000);
      FillHist("diparton_E",vec_init_diparton.E(),1,2000,0,2000);
      FillHist("diparton_eta",vec_init_diparton.Eta(),1,4000,-2.0e+11,2.0e+11);
      FillHist("diparton_pz",vec_init_diparton.Pz(),1,4000,-2000,2000);

      //int IsSameCharge = GetCharge(hard_l)*GetCharge(HN_l);
      //FillHist("IsSameChargeLepton",IsSameCharge,1,3,-1,2);

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
