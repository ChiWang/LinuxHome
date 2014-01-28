/*=============================================================================
#       FileName :          MyPro.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:36:25
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:36:25
=============================================================================*/

// Standard G4 Program Components
//-------------------------------------------------------------------
#include "G4RunManager.hh"
#include "G4PhysListFactory.hh"
    //+ G4 User Interface & Visualization
#include "G4UImanager.hh"
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

// User Defined Standard G4 Program Components
//-------------------------------------------------------------------
//#include "MyProVisManager.h"
#include "MyProDetectorConstruction.h"
#include "MyProPrimaryGeneratorAction.h"
#include "MyProEventAction.h"
#include "MyProSteppingAction.h"
#include "MyProRunAction.h"

G4int main(G4int argc, char[] argv ){
  G4RunManager *runManager = new G4RunManager;

  // Use physicsListFactory
  G4PhysListFactory *physListFactory = new G4PhysListFactory();
  G4VUserPhysicsList *physList = physListFactory->GetReferencePhysList("QGSP_BERT");
  runManager->SetUserInitialization(physList);

  // User Initializations
  MyProDetectorConstruction *MyProDetector = new MyProDetectorConstruction();
  runManager->SetUserInitialization(MyProDetector);

  // User Action
  MyProRunAction *runAction = new MyProRunAction(MyProDetector);
  MyProEventAction *evtAction = new MyProEventAction(runAction);
  MyProSteppingAction *steppingAction = new MyProSteppingAction(evtAction);
  MyProPrimaryGeneratorAction *primaryGenerator = new MyProPrimaryGeneratorAction;
  runManager->SetUserAction(runAction);
  runManager->SetUserAction(evtAction);
  runManager->SetUserAction(steppingAction);
  runManager->SetUserAction(primaryGenerator);

  // Initialize run manager
  runManager->Initialize();

#ifdef G4VIS_USE
  // Visualization manager
  G4VisManager *visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

  // User Interface manager
  G4UImanager *UIManager = G4UImanager::GetUIpointer();

  if(argc == 1){
    #ifdef G4UI_USE //not difined in setup
    G4UIExecutive *session = new G4UIExecutive(argc, argv);
    #ifdef G4VIS_USE
    UIManager->ApplyCommand("/control/execute ./mac/visFile/vis.mac"); 
    #endif
    if(session->IsGUI()){
     UIManager->ApplyCommand("/control/execute ./mac/visFile/gui.mac");
    }
    session->SessionStart();
    delete session;
    #endif
  }else{
    G4String fileName = argv[1];
    UIManager->ApplyCommand("/control/execute" + fileName); 
  }

  //job termination
  delete runManager;
  delete physListFactory;
  return 0;
}


