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

void loop(TString infile, TString outfile){
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

    //for(int i=0;i<weights.size();i++){
    //  FillHist("sumw",i,weights[i],200,0,200);
    //}

    double weight;
    if(weights[0]>0) weight = 1;
    else weight = -1;

    const reco::GenParticle *hard_HN=NULL;
    const reco::GenParticle *last_HN=NULL;
    const reco::GenParticle *hard_l=NULL,*LHE_hard_l=NULL,*HN_l=NULL,*W_l=NULL;
    const reco::GenParticle *photon_grandgrandma=NULL,*photon_grandma=NULL,*photon_mother=NULL,*photon_sister=NULL;
    const reco::GenParticle *first_parton=NULL,*second_parton=NULL;
    vector<const reco::GenParticle*> leptons,hard_partons,N_partons,hard_Ws,forward_partons,hard_photons;
    vector<const reco::GenParticle*> hard_HNs;

    int Nhard=0;
    for(int i=0;i<gens.size();i++){
      //cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", isHardProcess : " << gens[i].isHardProcess() << endl;
      if(gens[i].isHardProcess()){
        Nhard++;
        //cout << i << "th particle id : " << gens[i].pdgId() << ", status : " << gens[i].status() << ", charge : " << GetCharge(&gens[i]) << ", px : " << gens[i].px() << ", py : " << gens[i].py() << ", pz : " << gens[i].pz() << ", E : " << gens[i].energy() << ", pt : " << gens[i].pt() << ", eta : " << gens[i].eta() << ", phi : " << gens[i].phi() << endl;
        if(abs(gens[i].pdgId())==24) hard_Ws.push_back(&gens[i]);
        else if(abs(gens[i].pdgId())<=4||gens[i].pdgId()==21) hard_partons.push_back(&gens[i]);
        else if(gens[i].pdgId()==9900014) hard_HN=&gens[i]; 
        else if(gens[i].pdgId()==22) hard_photons.push_back(&gens[i]); //JH : need to consider H to gammagamma
      }
      if(gens[i].pdgId()==9900014){
        last_HN=&gens[i];
        hard_HNs.push_back(&gens[i]);
        FillHist("HN_status",gens[i].status(),1,100,0,100);
      }
      if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==hard_partons.at(0)||gens[i].mother()==hard_photons.at(0))){
        hard_l=&gens[i]; //JH : XXX If hard_l is just reco::GenParticle* (w/o const), then it doesn't get &gens[i]
        //cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the hard_l" << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(gens[i].mother()==last_HN)){ //NOTE The mother should be last_HN
        HN_l=&gens[i];
        //cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the HN_l" << endl;
      }
      else if((abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13)&&(abs(gens[i].mother()->pdgId())==24)){
        W_l=&gens[i];
        //cout << "^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~this is the W_l" << endl;
      }
      else if((abs(gens[i].pdgId())==5||abs(gens[i].pdgId())==6)){
        //cout << "!!heavy quark!! : " << Ptr2Idx(&gens[i],gens) << endl; //JH just to check
      }

      if(gens[i].isPromptFinalState()){
        if(abs(gens[i].pdgId())==11||abs(gens[i].pdgId())==13) leptons.push_back(&gens[i]);
      }
    }

    vector<int> HN_idx, init_q1_idx, init_q2_idx, hard_l_idx, forward_q1_idx, forward_q2_idx, cycle_Nparticles;
    vector< vector<int> > cycle_particles;
    for(int i=0;i<hard_HNs.size();i++){
      HN_idx.push_back(Ptr2IntIdx(hard_HNs.at(i),gens));
      //init_q1_idx.push_back(Ptr2IntIdx(hard_HNs.at(i),gens)-2);
      //init_q2_idx.push_back(Ptr2IntIdx(hard_HNs.at(i),gens)-1);
      //hard_l_idx.push_back(Ptr2IntIdx(hard_HNs.at(i),gens)+1);
    }
    for(int i=1;i<hard_HNs.size();i++){
      cycle_Nparticles.push_back(HN_idx.at(i)-HN_idx.at(i-1));
    } //Note that this will save eacy cycle's Nparticle until N-1th cycle
    for(int i=0;i<cycle_Nparticles.size();i++){
      vector<int> each_cycle_particles;
      for(int j=0;j<cycle_Nparticles.at(i);j++){
        each_cycle_particles.push_back(HN_idx.at(i)-2+j);
      }
      cycle_particles.push_back(each_cycle_particles);
    }

    //cout << "==========TEST==========" << endl;
    for(int i=0;i<cycle_particles.size();i++){
      //cout << i << "th cycle's Nparticles : " << cycle_particles.at(i).size() << endl;
      //cout << "==interesting particles==" << endl;
      for(int j=0;j<cycle_particles.at(i).size();j++){
        int this_idx = cycle_particles.at(i).at(j);
        //if((20<gens[this_idx].status()&&gens[this_idx].status()<30)||(40<gens[this_idx].status()&&gens[this_idx].status()<50)){
        //  cout << "idx : " << this_idx << ", PID : " << gens[this_idx].pdgId() << ", status : " << gens[this_idx].status() << ", px : " << gens[this_idx].px() << ", py : " << gens[this_idx].py() << ", pz : " << gens[this_idx].pz() << ", E : " << gens[this_idx].energy() << ", pt : " << gens[this_idx].pt() << ", eta : " << gens[this_idx].eta() << ", phi : " << gens[this_idx].phi() << endl;
        //}
      }
    }

    int interest_cycle;
    for(int i=0;i<cycle_particles.size();i++){
      if(gens[cycle_particles.at(i).at(0)].pdgId()==22||gens[cycle_particles.at(i).at(1)].pdgId()==22) continue;
      else{
        interest_cycle = i;
        break;
      }
    }

    //cout << "interesting cycle : " << interest_cycle << "th" << endl;
      
    //vector<const reco::GenParticle*> others;
    //for(int j=0;j<cycle_particles.at(interest_cycle);j++){
    //  int this_idx = cycle_particles.at(interest_cycle).at(j);
    //  if(gens[this_idx].status()==41) TLorentzVector vec_photon_mother=MakeTLorentzVector(&gens[this_idx]);
    //  else if(gens[this_idx].status()==42) TLorentzVector vec_first_parton=MakeTLorentzVector(&gens[this_idx]);
    //  else if(gens[this_idx].status()==43) TLorentzVector vec_second_parton=MakeTLorentzVector(&gens[this_idx]);
    //  else if(gens[this_idx].status()==44){
    //    if(gens[this_idx].pdgId()==9900014 TLorentzVector vec_HN=MakeTLorentzVector(&gens[this_idx]);
    //    else if((abs(gens[this_idx].pdgId())==11)||(abs(gens[this_idx].pdgId())==13)) TLorentzVector vec_hard_l=MakeTLorentzVector(&gens[this_idx]);
    //    else others.push_back(&gens[this_idx]);
    //  }
    //}
    
    double px=0;
    double py=0;
    double pz=0;
    double E=0;
    double others_px=0;
    double others_py=0;
    double others_pz=0;
    double others_E=0;
    TLorentzVector vec_hard_l, vec_hard_HN;
    TLorentzVector vec_first_parton, vec_second_parton;

    for(int j=0;j<cycle_particles.at(interest_cycle).size();j++){
      int this_idx = cycle_particles.at(interest_cycle).at(j);
      if((20<gens[this_idx].status()&&gens[this_idx].status()<30)||(40<gens[this_idx].status()&&gens[this_idx].status()<50)){
        px+=gens[this_idx].px();
        py+=gens[this_idx].py();
        pz+=gens[this_idx].pz();
        E+=gens[this_idx].energy();
        if(abs(gens[this_idx].pdgId())==13){
          vec_hard_l=MakeTLorentzVector(&gens[this_idx]);
          vec_first_parton=MakeTLorentzVector(&gens[this_idx+1]);
        }
        else if(gens[this_idx].pdgId()==9900014){
          vec_hard_HN=MakeTLorentzVector(&gens[this_idx]);
        }
        else{
          others_px+=gens[this_idx].px();
          others_py+=gens[this_idx].py();
          others_pz+=gens[this_idx].pz();
          others_E+=gens[this_idx].energy();
        }
        if(gens[this_idx].status()==43){
          vec_second_parton=MakeTLorentzVector(&gens[this_idx]);
        }
      }
      if((gens[cycle_particles.at(interest_cycle).at(0)].mother()->pdgId()!=22)&&(gens[cycle_particles.at(interest_cycle).at(1)].mother()->pdgId()!=22)){
        FillHist("check_consistency",1,1,5,0,5);
      }
      else FillHist("check_consistency",0,1,5,0,5);
    }

    //cout << "px : " << px << endl;
    //cout << "py : " << py << endl;
    
    TLorentzVector vec_others;
    vec_others.SetPxPyPzE(others_px,others_py,others_pz,others_E);
    TLorentzVector vec_HNplusl = vec_hard_l+vec_hard_HN;
    TLorentzVector vec_outgoings = vec_hard_l+vec_hard_HN+vec_others;
    TLorentzVector vec_two_partons = vec_first_parton+vec_second_parton;

    TLorentzVector vec_system;
    vec_system.SetPxPyPzE(px,py,pz,E);

    FillHist("sum_system_px",vec_system.Px(),1,2000,-1000,1000);
    FillHist("sum_system_py",vec_system.Py(),1,2000,-1000,1000);
    FillHist("sum_system_pz",vec_system.Pz(),1,13000,-6500,6500);
    FillHist("sum_system_E",vec_system.E(),1,13000,0,13000);
    FillHist("sum_system_pt",vec_system.Pt(),1,1000,0,1000);
    FillHist("sum_system_eta",vec_system.Eta(),1,100,-5,5);
    FillHist("sum_system_phi",vec_system.Phi(),1,63,-3.15,3.15);
    FillHist("HNplusl_px",vec_HNplusl.Px(),1,2000,-1000,1000);
    FillHist("HNplusl_py",vec_HNplusl.Py(),1,2000,-1000,1000);
    FillHist("HNplusl_pz",vec_HNplusl.Pz(),1,13000,-6500,6500);
    FillHist("HNplusl_E",vec_HNplusl.E(),1,13000,0,13000);
    FillHist("HNplusl_pt",vec_HNplusl.Pt(),1,1000,0,1000);
    FillHist("HNplusl_eta",vec_HNplusl.Eta(),1,100,-5,5);
    FillHist("HNplusl_phi",vec_HNplusl.Phi(),1,63,-3.15,3.15);
    FillHist("outgoing_partons_px",vec_others.Px(),1,2000,-1000,1000);
    FillHist("outgoing_partons_py",vec_others.Py(),1,2000,-1000,1000);
    FillHist("outgoing_partons_pz",vec_others.Pz(),1,13000,-6500,6500);
    FillHist("outgoing_partons_E",vec_others.E(),1,13000,0,13000);
    FillHist("outgoing_partons_pt",vec_others.Pt(),1,1000,0,1000);
    FillHist("outgoing_partons_eta",vec_others.Eta(),1,100,-5,5);
    FillHist("outgoing_partons_phi",vec_others.Phi(),1,63,-3.15,3.15);
    FillHist("two_partons_px",vec_two_partons.Px(),1,2000,-1000,1000);
    FillHist("two_partons_py",vec_two_partons.Py(),1,2000,-1000,1000);
    FillHist("two_partons_pz",vec_two_partons.Pz(),1,13000,-6500,6500);
    FillHist("two_partons_E",vec_two_partons.E(),1,13000,0,13000);
    FillHist("two_partons_pt",vec_two_partons.Pt(),1,1000,0,1000);
    FillHist("two_partons_eta",vec_two_partons.Eta(),1,100,-5,5);
    FillHist("two_partons_phi",vec_two_partons.Phi(),1,63,-3.15,3.15);
    FillHist("HNplusl_Over_outgoing_parton_px",vec_HNplusl.Px()/vec_others.Px(),1,400,-2,2);
    FillHist("HNplusl_Over_outgoing_parton_py",vec_HNplusl.Py()/vec_others.Py(),1,400,-2,2);
    FillHist("HNplusl_Over_outgoing_parton_pt",vec_HNplusl.Pt()/vec_others.Pt(),1,400,-2,2);
    FillHist("HNplusl_Over_two_partons_px",vec_HNplusl.Px()/vec_two_partons.Px(),1,200,-10,10);
    FillHist("HNplusl_Over_two_partons_py",vec_HNplusl.Py()/vec_two_partons.Py(),1,200,-10,10);
    FillHist("HNplusl_Over_two_partons_pt",vec_HNplusl.Pt()/vec_two_partons.Pt(),1,200,-10,10);
    //cout << "HNplusl_px : " << vec_HNplusl.Px() << endl;;
    //cout << "two_partons_px : " << vec_two_partons.Px() << endl;;
    //cout << "HNplusl_py : " << vec_HNplusl.Py() << endl;;
    //cout << "two_partons_py : " << vec_two_partons.Py() << endl;;
    //cout << "HNplusl_pt : " << vec_HNplusl.Pt() << endl;;
    //cout << "two_partons_pt : " << vec_two_partons.Pt() << endl;;
    //cout << "HNplusl_Over_two_partons_px : " << vec_HNplusl.Px()/vec_two_partons.Px() << endl;;
    //cout << "HNplusl_Over_two_partons_py : " << vec_HNplusl.Py()/vec_two_partons.Py() << endl;;
    //cout << "HNplusl_Over_two_partons_pt : " << vec_HNplusl.Pt()/vec_two_partons.Pt() << endl;;
    FillHist("first_parton_px",vec_first_parton.Px(),1,2000,-1000,1000);
    FillHist("first_parton_py",vec_first_parton.Py(),1,2000,-1000,1000);
    FillHist("first_parton_pz",vec_first_parton.Pz(),1,13000,-6500,6500);
    FillHist("first_parton_E",vec_first_parton.E(),1,13000,0,13000);
    FillHist("first_parton_pt",vec_first_parton.Pt(),1,1000,0,1000);
    FillHist("first_parton_eta",vec_first_parton.Eta(),1,100,-5,5);
    FillHist("first_parton_phi",vec_first_parton.Phi(),1,63,-3.15,3.15);
    FillHist("second_parton_px",vec_second_parton.Px(),1,2000,-1000,1000);
    FillHist("second_parton_py",vec_second_parton.Py(),1,2000,-1000,1000);
    FillHist("second_parton_pz",vec_second_parton.Pz(),1,13000,-6500,6500);
    FillHist("second_parton_E",vec_second_parton.E(),1,13000,0,13000);
    FillHist("second_parton_pt",vec_second_parton.Pt(),1,1000,0,1000);
    FillHist("second_parton_eta",vec_second_parton.Eta(),1,100,-5,5);
    FillHist("second_parton_phi",vec_second_parton.Phi(),1,63,-3.15,3.15);
    FillHist("all_outgoing_px",vec_outgoings.Px(),1,2000,-1000,1000);
    FillHist("all_outgoing_py",vec_outgoings.Py(),1,2000,-1000,1000);
    FillHist("all_outgoing_pz",vec_outgoings.Pz(),1,13000,-6500,6500);
    FillHist("all_outgoing_E",vec_outgoings.E(),1,13000,0,13000);
    FillHist("all_outgoing_pt",vec_outgoings.Pt(),1,1000,0,1000);
    FillHist("all_outgoing_eta",vec_outgoings.Eta(),1,100,-5,5);
    FillHist("all_outgoing_phi",vec_outgoings.Phi(),1,63,-3.15,3.15);

    //cout<<"  Idx  PID  sts mtr1 mtr2  dt1  dt2           px           py           pz            E           pt          eta          phi  hrdp"<<endl;
    //PrintGens(gens);

    ievent++;

    //if(ievent==5) break;

    //for(int i=0;i<hard_partons.size();i++){
    //  if(abs((hard_partons.at(i)->mother())->pdgId())==24||(hard_partons.at(i)->mother())->pdgId()==9900014) N_partons.push_back(hard_partons.at(i));
    //  if(hard_partons.at(i)->mother(0)==hard_photons.at(0)||hard_partons.at(i)->mother(1)==hard_photons.at(0)) forward_partons.push_back(hard_partons.at(i));
    //}

    //if(hard_Ws.size()>0){
    //  for(int i=0;i<hard_Ws.size();i++) hard_Ws.at(i) = FindLastCopy(gens,hard_Ws.at(i));
    //}
    //if(hard_l){
    //  LHE_hard_l = hard_l;
    //  hard_l = FindLastCopy(gens,hard_l);
    //}
    //if(W_l) W_l = FindLastCopy(gens,W_l); 
    //if(HN_l) HN_l = FindLastCopy(gens,HN_l);  //NOTE No need this for last_HN; The code itself assigns the last HN to last_HN.

    //TLorentzVector vec_photon=MakeTLorentzVector(hard_photons.at(0));
    //photon_mother=(reco::GenParticle*)hard_photons.at(0)->mother();
    //if(photon_mother->daughter(0)->pdgId()!=22) photon_sister=(reco::GenParticle*)photon_mother->daughter(0);
    //else if(photon_mother->daughter(1)) photon_sister=(reco::GenParticle*)photon_mother->daughter(1); //JH : if photon_mother has 2 daughters, then one of the two must be a quark
    //else{ //JH : photon_mother was actually a photon
    //  cout << "!!photon_mother was actually a photon!!" << endl;
    //  TLorentzVector vec_photon_mother=MakeTLorentzVector(photon_mother);
    //  TLorentzVector vec_Q=vec_photon_mother-vec_photon;
    //  cout << "check the Q : " << vec_Q.M() << endl;
    //  FillHist("Q_between_photons",vec_Q.M(),1,20,-1,1); 
    //  cout << "assigning new photon_mother..." << endl;
    //  vector<int> photon_history = TrackGenSelfHistory(gens, photon_mother);
    //  photon_mother=&gens.at(photon_history[1]);
    //  photon_sister=(reco::GenParticle*)photon_mother->daughter(1);
    //}

    //if(!photon_sister) cout << "!!photon_sister UNDETECTED!!" << endl;
    //
    //int IsPhotonFromProton = 0;
    //int IsPhotonFromProton1 = 0;
    //int IsPhotonFromProton2 = 0;
    //int IsPhotonFromProton3 = 0;
    //if(photon_mother->pdgId()==2212) IsPhotonFromProton1 = 1;
    //else{
    //  vector<int> photon_history = TrackGenSelfHistory(gens, photon_mother);
    //  photon_grandma=&gens.at(photon_history[1]);
    //  if(photon_grandma->pdgId()==2212) IsPhotonFromProton2 = 1;
    //  else{
    //    vector<int> photon_history = TrackGenSelfHistory(gens, photon_grandma);
    //    photon_grandgrandma=&gens.at(photon_history[1]);
    //    if(photon_grandgrandma->pdgId()==2212) IsPhotonFromProton3 = 1;
    //  }
    //}
    //if(IsPhotonFromProton1||IsPhotonFromProton2||IsPhotonFromProton3) IsPhotonFromProton = 1;

    //cout << "IsPhotonFromProton (up to 3 generation) : " << IsPhotonFromProton << endl;
    //if(!IsPhotonFromProton) cout << "!!No photon from proton!!" << endl;
    //cout << "photon's mother idx : " << Ptr2Idx(photon_mother,gens) << ", id : " << photon_mother->pdgId() << ", status : " << photon_mother->status() << ",  px : " << photon_mother->px() << ", py : " << photon_mother->py() << ", pz : " << photon_mother->pz() << ", E : " << photon_mother->energy() << ", pt : " << photon_mother->pt() << ", eta : " << photon_mother->eta() << ", phi : " << photon_mother->phi() << endl;
    //cout << "photon's sister idx : " << Ptr2Idx(photon_sister,gens) << ", id : " << photon_sister->pdgId() << ", status : " << photon_sister->status() << ",  px : " << photon_sister->px() << ", py : " << photon_sister->py() << ", pz : " << photon_sister->pz() << ", E : " << photon_sister->energy() << ", pt : " << photon_sister->pt() << ", eta : " << photon_sister->eta() << ", phi : " << photon_sister->phi() << endl;
    //TLorentzVector vec_photon_mother=MakeTLorentzVector(photon_mother);
    //TLorentzVector vec_photon_sister=MakeTLorentzVector(photon_sister);
    //TLorentzVector vec_Q=vec_photon_mother-vec_photon_sister;
    //cout << "photon's Q : " << vec_Q.M() << endl;
    //if(vec_Q.M()>0) cout << "!!photon has positive Q!!" << endl;
    //cout << "photon's Q^2 : " << pow(vec_Q.M(),2) << endl;

    //cout << "how many weights : " << weights.size() << endl;
    //cout << "event weight : " << weights[0] << endl;

    //cout << "N of hard process particles : " << Nhard << endl;

    //cout << "detected hard_l : " << Ptr2Idx(hard_l,gens) << endl;
    //cout << "detected HN_l : " << Ptr2Idx(HN_l,gens) << endl;
    //cout << "detected W_l : " << Ptr2Idx(W_l,gens) << endl;
    //cout << "!!hard_l charge : " << GetCharge(hard_l) << "!!" << endl;
    //cout << "!!HN_l charge : " << GetCharge(HN_l) << "!!" << endl;
    //cout << "!!W_l charge : " << GetCharge(W_l) << "!!" << endl;

    //cout << "detected hard_partons : " << endl;
    //for(int i=0;i<hard_partons.size();i++) cout << Ptr2Idx(hard_partons.at(i),gens) << endl;
    //cout << "detected forward_partons : " << endl;
    //for(int i=0;i<forward_partons.size();i++) cout << Ptr2Idx(forward_partons.at(i),gens) << endl;
    //cout << "N of forward partons : " << forward_partons.size() << endl;
    //
    //cout << "N of Ws : " << hard_Ws.size() << endl;
    ////if(hard_Ws.size()==1){
    ////  cout << "Which : ";
    ////    if(Ptr2Idx(hard_Ws.at(0),gens).Atoi()<Ptr2Idx(hard_HN,gens).Atoi()){
    ////      cout << "W1" << endl;
    ////    }
    ////    else cout << "W2" << endl;
    ////  cout << "W : " << Ptr2Idx(hard_Ws.at(0),gens) << ", HN : " << Ptr2Idx(hard_HN,gens) << endl;
    ////  cout << "W eta : " << hard_Ws.at(0)->eta() << endl; //NOTE W eta extremely changes from hard_W to last_W
    ////} //JH : W1 and W2 are meaningless in Tchannel

  }

  TFile fout(outfile,"recreate");
  for(const auto& [histname,hist]:hists){
    hist->Write();
  }
  fout.Close();
  
}
