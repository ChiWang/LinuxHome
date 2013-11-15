/*=============================================================================
#       FileName :          MyXRunAction.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:38:09
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:38:09
=============================================================================*/

#include "MyXRunAction.hh"
#include "MyXAnalysisManager.hh"

#include "G4Run.hh"

#include "G4UImanager.hh"
#include "G4VVisManager.hh"

#include <sys/time.h>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

MyXRunAction::MyXRunAction(){
}

MyXRunAction::~MyXRunAction(){
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyXRunAction::BeginOfRunAction(const G4Run* aRun){
  G4cout << "### Run ID = " <<aRun->GetRunID()<< " start." << G4endl;

  //Random Engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  
  G4long seed = time(0)+getpid();
  CLHEP::HepRandom::setTheSeed(seed);
  CLHEP::HepRandom::showEngineStatus();	

  //Create the analysis manager and BeginOfRun
  MyXAnalysisManager* analysis = MyXAnalysisManager::GetInstance();
  analysis->BeginOfRun(aRun);

  //
  #ifdef G4VIS_USE
    if(G4VVisManager::GetConcreteInstance()){
      G4UImanager* UIManager = G4UImanager::GetUIpointer();
      UIManager->ApplyCommand("vis/clear/view");
    }
  #endif
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyXRunAction::EndOfRunAction(const G4Run* aRun){
  MyXAnalysisManager::GetInstance()->EndOfRun(aRun);
  G4cout<<"\t\t\tEnd of runID = "<<aRun->GetRunID()<<G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


