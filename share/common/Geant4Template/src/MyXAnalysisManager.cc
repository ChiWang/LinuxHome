/*=============================================================================
#       FileName :          MyXAnalysisManager.cc
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-24   10:06:58
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-24   10:06:58
=============================================================================*/

#include "G4ParticleDefinition.hh"
#include "G4ThreeVector.hh"
#include "G4Track.hh"

#include "G4Run.hh"
#include "G4Event.hh"
#include "G4Step.hh"
#include "MyXAnalysisManager.hh"

MyXAnalysisManager* MyXAnalysisManager::fInstance=0;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyXAnalysisManager::MyXAnalysisManager()
 :fRFile=0
{}

MyXAnalysisManager::~MyXAnalysisManager(){
}

MyXAnalysisManager* MyXAnalysisManager::GetInstance(){
  if (fInstance == 0) {
    fInstance = new MyXAnalysisManager()
  }
  return fInstance;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyXAnalysisManager::BeginOfRun(const G4Run* aRun){

}

void MyXAnalysisManager::EndOfRun(const G4Run* aRun){

}

void MyXAnalysisManager::BeginOfEvent(const G4Event* aEvent){

}

void MyXAnalysisManager::EndOfEvent(const G4Event* aEvent){
  runaction->epamDataTree->Fill();
}

void MyXAnalysisManager::UserStepping(const G4Step* aStep){
  G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
  G4String preVolumeName = preStepPoint->GetPhysicalVolume()->GetName();
  G4int copynumber = preStepPoint->GetPhysicalVolume()->GetCopyNo();
  
  // Record Energy Deposit
  if ( preVolumeName == "SiliconMatrix" ){
     stepInfo.firstLayerScintillatorStrip[copynumber] = aStep->GetTotalEnergyDeposit();
  } else if ( preVolumeName == "layerSecondRear" ){
     secondLayerInfo.secondLayerScintillatorStrip[copynumber] = aStep->GetTotalEnergyDeposit(); 
  }else if(preVolumeName == "W1Plane"){
      stepInfo.firstLayerScintillatorStrip[300] = aStep->GetTotalEnergyDeposit();
  }else if(preVolumeName == "W2Plane"){
      stepInfo.firstLayerScintillatorStrip[301] = aStep->GetTotalEnergyDeposit();
  }else if(preVolumeName == "FePlane"){   //W
      stepInfo.firstLayerScintillatorStrip[302] = aStep->GetTotalEnergyDeposit();
  }else if(preVolumeName == "TriggerPlane"){
      stepInfo.firstLayerScintillatorStrip[303] = aStep->GetTotalEnergyDeposit();
  }else if (preVolumeName == "layerThirdRear"){
	thirdLayerInfo.thirdLayerScintillatorStrip[copynumber] = aStep->GetTotalEnergyDeposit();
  }else if( preVolumeName == "calorimeterThird" ){//------------------------------Calorimeter--------------------
     calorimeterStripThirdInfo.calorimeterStripThird[copynumber] = aStep->GetTotalEnergyDeposit();
  }

  // :::: End of Storing Energy

  G4Track* aTrack = aStep->GetTrack();
  if( aTrack->GetTrackID() == 1 && aTrack->GetParentID() == 0 ){ // Primary particle
    if( aTrack->GetCurrentStepNumber() == 1 ){ // First Step
      G4ParticleDefinition* particle = aTrack->GetDefinition();
      particleInfo.particleZ = (G4int) particle->GetPDGCharge();
      particleInfo.particleA = particle->GetBaryonNumber();
      particleInfo.particleMass = particle->GetPDGMass();
      particleInfo.particleEnergy = aTrack->GetKineticEnergy();
      
      G4ThreeVector primaryVertex = aTrack->GetVertexPosition();
      G4ThreeVector primaryDirection = aTrack->GetVertexMomentumDirection();
      
      particleInfo.particlePosition[0] = primaryVertex.x();
      particleInfo.particlePosition[1] = primaryVertex.y();
      particleInfo.particlePosition[2] = primaryVertex.z();
      
      particleInfo.particleDirection[0] = primaryDirection.x();
      particleInfo.particleDirection[1] = primaryDirection.y();
      particleInfo.particleDirection[2] = primaryDirection.z();
      
    } // :::: End of first step
  }//////End of Primary particle
}

void DrawTrajectory(const G4Event* aEvent){
  if (G4VVisManager::GetConcreteInstance()){
    G4TrajectoryContainer* trajectoryContainer = aEvent->GetTrajectoryContainer();
    G4int n_trajectories = 0; 
    if (trajectoryContainer){
      n_trajectories = trajectoryContainer->entries();
    }
    for( G4int i=0; i < n_trajectories; i++ ){
      G4Trajectory* trj = (G4Trajectory*) ( ( *(aEvent->GetTrajectoryContainer()) )[i] );
      if (drawFlag == "all"){
        trj->DrawTrajectory(50);
      } else if ( (drawFlag == "charged") && ( trj->GetCharge() != 0.) ) {
        trj->DrawTrajectory(50);
      } else if ( (drawFlag == "neutral") && ( trj->GetCharge() == 0.) ) {
        trj->DrawTrajectory(50);
      }
    }
    //  std::getchar();
  }
}

