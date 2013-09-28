/*=============================================================================
#       FileName :          MyXRunAction.cc
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-18   09:50:23
#
#------------------------------------------------------------------------------
#       Description  :
#           implement of BeginOfRunAction(const G4Run*) and EndOfRunAction(const G4Run*)

#       giving to User'sAnalysisManager to do thoes work, so if you need to modify thoes methods do it in class of User'sAnalysisManager
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-18   09:50:23
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


