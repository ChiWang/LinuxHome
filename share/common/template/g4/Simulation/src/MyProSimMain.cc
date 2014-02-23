/*
 *  $Id: MyProSimMain.cc, 2014-02-19 11:43:03 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/11/2013
*/

// Standard G4 Program Components
//-------------------------------------------------------------------
#include "G4RunManager.hh"
#include "G4PhysListFactory.hh"
#include "G4UImanager.hh"
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

// User Defined Standard G4 Program Components
//-------------------------------------------------------------------
//#include "MyProSimVisManager.h"
#include "MyProSimDetectorConstruction.h"
#include "MyProSimPrimaryGeneratorAction.h"
#include "MyProSimRunAction.h"
#include "MyProSimEventAction.h"
#include "MyProSimSteppingAction.h"

G4int main(G4int argc, char* argv[]){
  G4RunManager *runManager = new G4RunManager;

  // Physics List
  G4PhysListFactory *physListFactory = new G4PhysListFactory();
  G4VUserPhysicsList *physList = physListFactory->GetReferencePhysList("QGSP_BERT");
  runManager->SetUserInitialization(physList);

  // Detector
  runManager->SetUserInitialization(new MyProSimDetectorConstruction);

  // Initialize geometry and physics
  runManager->Initialize();

  // User Action
  runManager->SetUserAction(new MyProSimPrimaryGeneratorAction);
  runManager->SetUserAction(new MyProSimRunAction);
  runManager->SetUserAction(new MyProSimEventAction);
  runManager->SetUserAction(new MyProSimSteppingAction);

#ifdef G4VIS_USE
  // Visualization manager
  G4VisManager *visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

  // User Interface manager
  G4UImanager *UIManager = G4UImanager::GetUIpointer();

  if(argc == 1){
    G4String fileName = argv[1];
    UIManager->ApplyCommand("/control/execute" + fileName); 
  }else{
#ifdef G4UI_USE //not difined in setup
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
    UIManager->ApplyCommand("/control/execute ./mac/visFile/vis.mac"); 
#endif
    if(ui->IsGUI()){
     UIManager->ApplyCommand("/control/execute ./mac/visFile/gui.mac");
    }
    ui->SessionStart();
    delete ui;
#endif
  }

  // job termination
#ifdef G4VIS_USE
  delete visManager;
#endif
  delete physListFactory;
  delete runManager;
  return 0;
}


