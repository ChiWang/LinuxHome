/*=============================================================================
#       FileName :          MyProSteppingAction.cc
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

#include "MyProSteppingAction.h"
#include "MyProAnalysisManager.h"

#include "G4Step.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyProSteppingAction::MyProSteppingAction(){
}

MyProSteppingAction::~MyProSteppingAction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyProSteppingAction::UserSteppingAction( const G4Step* aStep ){
  MyProAnalysisManager::GetInstance()->UserStepping(aStep);

}

