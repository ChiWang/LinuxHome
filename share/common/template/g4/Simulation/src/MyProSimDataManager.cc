/*
 *  $Id: MyProSimDataManager.cc, 2014-02-19 12:16:12 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 19/02/2014
*/

#include <boost/lexical_cast.hpp>

#include "TTree.h"
#include "G4Run.hh"
//#include "G4String.hh"

#include "MyProEvtHeader.h"
#include "MyProSimDataManager.h"

MyProSimDataManager* MyProSimDataManager::fDataManager = 0;

//-------------------------------------------------------------------
MyProSimDataManager::MyProSimDataManager(){
}

MyProSimDataManager::~MyProSimDataManager(){
  if (fDataManager) {
    delete fDataManager;
    fDataManager = 0;
  }
}

//-------------------------------------------------------------------
MyProSimDataManager* MyProSimDataManager::GetDataManager(){
  if (!fDataManager){
    fDataManager = new MyProSimDataManager;
  }
  return fDataManager;
}

//-------------------------------------------------------------------
void BookFile(const G4Run *aRun){
  G4String runName = "MyProSim_run_"; 
  int runID = aRun->GetRunID();
  runName += boost::lexical_cast<string>(runID);

  fTree = new TTree("MyProSimulation",runName);
  fTree->Branch("EventHeader","MyProEvtHeader",&fEventHeader);
// *
// *  TODO: how to book branch of MyProSimSubDetSD::fEvtHitSet
// *
  fTree->Branch("EventSubDet","MyProEvt",);
}

//-------------------------------------------------------------------
void FillEvent(const G4Event *aEvent){
  for (int i=0;i<fSubDetDataManagerSet->size();++i) {
    fSubDetDataManagerSet[i]->HandleThisEvent(aEvent);
  }
  fTree->Fill();
}


