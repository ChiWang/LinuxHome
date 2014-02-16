/*
 *  $Id: MyProSimEventAction.cc, 2014-02-16 23:14:28 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/11/2013
*/

#include "G4Event.hh"
#include "G4VVisManager.hh"
#include "G4Trajectory.hh"
#include "MyProSimEventAction.h"

//-------------------------------------------------------------------
MyProSimEventAction::MyProSimEventAction():fDrawFlag("all"){
}

MyProSimEventAction::~MyProSimEventAction(){   
}

//-------------------------------------------------------------------
void MyProSimEventAction::BeginOfEventAction(const G4Event* aEvent){
  if( aEvent->GetEventID() %10000 == 0 ){
    G4cout<<"---> Begin of event:\t"<<aEvent->GetEventID()<<G4endl;
  }

  //BeginOfEvent(aEvent);

}

//-------------------------------------------------------------------
void MyProSimEventAction::EndOfEventAction(const G4Event* aEvent){
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

