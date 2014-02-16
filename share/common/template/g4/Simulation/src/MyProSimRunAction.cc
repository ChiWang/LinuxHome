/*
 *  $Id: MyProSimRunAction.cc, 2014-02-16 23:21:10 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/11/2013
*/

#include "G4Run.hh"
#include "G4UImanager.hh"
#include "G4VVisManager.hh"
#include "CLHEP/Random/Random.h"

#include <sys/time.h>
#include "MyProSimRunAction.h"

//-------------------------------------------------------------------
MyProSimRunAction::MyProSimRunAction(){
}

MyProSimRunAction::~MyProSimRunAction(){
}

//-------------------------------------------------------------------
void MyProSimRunAction::BeginOfRunAction(const G4Run* aRun){
  G4cout << "### Run ID = " <<aRun->GetRunID()<< " start." << G4endl;

  //Random Engine
  //CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  //
  //G4long seed = time(0)+getpid();
  //CLHEP::HepRandom::setTheSeed(seed);
  //CLHEP::HepRandom::showEngineStatus();	

  //Create the analysis manager and BeginOfRun
//  BeginOfRun(aRun);

  //
  #ifdef G4VIS_USE
  if(G4VVisManager::GetConcreteInstance()){
    G4UImanager* UIManager = G4UImanager::GetUIpointer();
    UIManager->ApplyCommand("vis/clear/view");
  }
  #endif
}

//-------------------------------------------------------------------
void MyProSimRunAction::EndOfRunAction(const G4Run* aRun){
  //EndOfRun(aRun);
  G4cout<<"\t\t\tEnd of runID = "<<aRun->GetRunID()<<G4endl;
}

