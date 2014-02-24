/*
 *  $Id: MyProSimSubDetSD.cc, 2014-02-21 19:32:58 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 21/02/2014
*/

#include "MyProSimSubDetSD.h"
#include "MyProEvtHit.h"

MyProSimSubDetSD::MyProSimSubDetSD(G4String name)
 :G4VSensitiveDetector(name)
{
}

MyProSimSubDetSD::~MyProSimSubDetSD(){
}

void MyProSimSubDetSD::Initialize(G4HCofThisEvent *){
// invoked at the begining of an Event
  for (int i=0;i<fEvtHitSet.size();++i){
    delete fEvtHitSet[i];
  }
  fEvtHitSet.clear();
}

G4bool MyProSimSubDetSD::ProcessHits(G4Step *aStep,G4TouchableHistory *ROhist){
// *
// *  TODO:  the uniqueID here is not right
// *
#pragma message("TODO ----> uniqueID is not right")
  uniqueID = ROhist->GetVolume(1)->GetCopyNo();
  int setID = GetIDInHitSet(uniqueID);
  if(setID < 0){
    setID = fEvtHitSet.size();
    fEvtHitSet.push_back(new MyProEvtHit());
  }
  G4ThreeVector pos = aStep->GetPreStepPoint();
  fEvtHitSet[setID]->UpdateThisStep(aStep->GetTotalEnergyDeposit(),pos->getX(),pos->getY(),pos->getZ());
}

//-------------------------------------------------------------------
int MyProSimSubDetSD::GetIDInHitSet(int uniqueID){
  int setID = -1;
  for (int i=0;i<fEvtHitSet.size();++i){
    if (fEvtHitSet[i]->GetUID() == uniqueID) {
      setID = i;
    }
  }
  return setID;
}


