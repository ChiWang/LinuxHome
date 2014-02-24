/*
 *  $Id: MyProSimVUserSubDetDataManager.cc, 2014-02-19 16:25:07 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 19/02/2014
*/

#include "G4Event.hh"
#include "G4SDManager.hh"
#include "MyProSimVUserSubDetDataManager.h"

MyProSimVUserSubDetDataManager::MyProSimVUserSubDetDataManager(){

}

MyProSimVUserSubDetDataManager::~MyProSimVUserSubDetDataManager(){

}

void HandleThisEvent(const G4Event *aEvent){
// *
// *  TODO: not use hits collection at the end of event to cal. total energy.... Do it at G4VSensitiveDetector::ProcessHits()
// *
/*
  G4HCofThisEvent *HCofEvent = aEvent->GetHCofThisEvent();
  if(!HCofEvent) return;
  G4SDManager *SDM = G4SDManager::GetSDMpointer;
  MyProSimSubDetHitsCollection *SubDetHits
*/
}


