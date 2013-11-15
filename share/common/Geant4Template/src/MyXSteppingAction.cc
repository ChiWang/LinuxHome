/*=============================================================================
#       FileName :          MyXSteppingAction.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:38:20
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:38:20
=============================================================================*/

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

