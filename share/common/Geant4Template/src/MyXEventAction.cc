/*=============================================================================
#       FileName :          MyXEventAction.cc
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-18   14:14:36
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-18   14:14:36
=============================================================================*/

#include "MyXEventAction.hh"
#include "MyXAnalysisManager.hh"

#include "G4Event.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

MyXEventAction::MyXEventAction():fDrawFlag("all"){
}

MyXEventAction::~MyXEventAction(){   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyXEventAction::BeginOfEventAction( const G4Event* aEvent ){
  if( evtNb %10000 == 0 ){
    G4cout<<"---> Begin of event:\t"<<aEvent->GetEventID()<<G4endl;
  }

  MyXAnalysisManager::GetInstance()->BeginOfEvent(aEvent);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void MyXEventAction::EndOfEventAction(const G4Event* aEvent){
  MyXAnalysisManager::GetInstance()->EndOfEvent(aEvent);

  if( evtNb %10000 == 0 ){
    G4cout<<"\t\tend of event:\t"<<aEvent->GetEventID()<<G4endl;
  }
}



