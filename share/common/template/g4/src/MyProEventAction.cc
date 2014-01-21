/*=============================================================================
#       FileName :          MyProEventAction.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:37:53
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:37:53
=============================================================================*/

#include "MyProEventAction.hh"
#include "MyProAnalysisManager.hh"

#include "G4Event.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

MyProEventAction::MyProEventAction():fDrawFlag("all"){
}

MyProEventAction::~MyProEventAction(){   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyProEventAction::BeginOfEventAction( const G4Event* aEvent ){
  if( evtNb %10000 == 0 ){
    G4cout<<"---> Begin of event:\t"<<aEvent->GetEventID()<<G4endl;
  }

  MyProAnalysisManager::GetInstance()->BeginOfEvent(aEvent);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyProEventAction::EndOfEventAction(const G4Event* aEvent){
  MyProAnalysisManager::GetInstance()->EndOfEvent(aEvent);

  if( evtNb %10000 == 0 ){
    G4cout<<"\t\tend of event:\t"<<aEvent->GetEventID()<<G4endl;
  }
}



