//
//***************************************************************
//*DISCLAIMER							*
//*								*
//*				Created Jul.22, 2006		*
//***************************************************************
//
//path: epam/src/MyXVisManager.cc

//
//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

#include "MyXSteppingAction.hh"
#include "MyXAnalysisManager.hh"

#include "G4Step.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyXSteppingAction::MyXSteppingAction(){
}

MyXSteppingAction::~MyXSteppingAction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyXSteppingAction::UserSteppingAction( const G4Step* aStep ){
  MyXAnalysisManager::GetInstance()->UserStepping(aStep);

}

