/*=====================================================================
 *   File:   MyProEventAction.cc
 *   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    16/11/2013
 *---------------------------------------------------------------------
 *   Description:
 *
 *---------------------------------------------------------------------
 *   History:
 *                           Last update:  28/01/2014   21:25:27
=====================================================================*/

#include "G4Event.hh"
#include "G4VVisManager.hh"
#include "G4Trajectory.hh"
#include "MyProEventAction.h"

//-------------------------------------------------------------------
MyProEventAction::MyProEventAction():fDrawFlag("all"){
}

MyProEventAction::~MyProEventAction(){   
}

//-------------------------------------------------------------------
void MyProEventAction::BeginOfEventAction(const G4Event* aEvent){
  if( aEvent->GetEventID() %10000 == 0 ){
    G4cout<<"---> Begin of event:\t"<<aEvent->GetEventID()<<G4endl;
  }

  //BeginOfEvent(aEvent);

}

//-------------------------------------------------------------------
void MyProEventAction::EndOfEventAction(const G4Event* aEvent){
  //EndOfEvent(aEvent);

  if( aEvent->GetEventID() %10000 == 0 ){
    G4cout<<"\t\tend of event:\t"<<aEvent->GetEventID()<<G4endl;
  }
  if (G4VVisManager::GetConcreteInstance()){
    G4TrajectoryContainer* trajectoryContainer = aEvent->GetTrajectoryContainer();
    G4int n_trajectories = 0; 
    if (trajectoryContainer){
      n_trajectories = trajectoryContainer->entries();
    }
    for( G4int i=0; i < n_trajectories; i++ ){
      G4Trajectory* trj = (G4Trajectory*) ( ( *(aEvent->GetTrajectoryContainer()) )[i] );
      if(fDrawFlag == "all"){
        trj->DrawTrajectory(50);
      } else if ( (fDrawFlag == "charged") && ( trj->GetCharge() != 0.) ) {
        trj->DrawTrajectory(50);
      } else if ( (fDrawFlag == "neutral") && ( trj->GetCharge() == 0.) ) {
        trj->DrawTrajectory(50);
      }
    }
    //  std::getchar();
  }
}

