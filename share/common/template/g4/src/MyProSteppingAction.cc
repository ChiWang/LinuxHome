/*=====================================================================
 *   File:   MyProSteppingAction.cc
 *   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    16/11/2013
 *---------------------------------------------------------------------
 *   Description:
 *
 *---------------------------------------------------------------------
 *   History:
 *                           Last update:  28/01/2014   21:30:31
=====================================================================*/

#include "G4Track.hh"
#include "G4Step.hh"
#include "MyProSteppingAction.h"

//-------------------------------------------------------------------
MyProSteppingAction::MyProSteppingAction(){
}

MyProSteppingAction::~MyProSteppingAction(){
}

//-------------------------------------------------------------------
void MyProSteppingAction::UserSteppingAction( const G4Step* aStep ){
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

