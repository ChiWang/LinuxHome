/*=============================================================================
#       FileName :          MyX.cc
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
#include "G4RunManager.hh"
#include "G4PhysListFactory.hh"
// G4 User Interface & Visualization
#include "G4UImanager.hh"
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

//______________________________________________________________________________________ user special
// User Defined Standard G4 Program Components
//#include "MyXVisManager.hh"
#include "MyXDetectorConstruction.hh"
#include "MyXPrimaryGeneratorAction.hh"
#include "MyXEventAction.hh"
#include "MyXSteppingAction.hh"
#include "MyXRunAction.hh"
#include "MyXDefs.hh"


G4int main(G4int argc, char** argv ){

  // Coustruct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // User Initializations
  MyXDetectorConstruction* MyXDetector = new MyXDetectorConstruction();
  runManager->SetUserInitialization( MyXDetector );

//(common) use physicsListFactory
  G4PhysListFactory *physListFactory = new G4PhysListFactory();
  G4VUserPhysicsList *physList = physListFactory->GetReferencePhysList("QGSP_BERT");
  runManager->SetUserInitialization(physList);

  // User Action
  MyXRunAction* runAction = new MyXRunAction( MyXDetector );
  MyXEventAction* evtAction = new MyXEventAction( runAction );
  MyXSteppingAction* steppingAction = new MyXSteppingAction( evtAction );
  MyXPrimaryGeneratorAction* primaryGenerator = new MyXPrimaryGeneratorAction;
  runManager->SetUserAction( runAction );
  runManager->SetUserAction( evtAction );
  runManager->SetUserAction( steppingAction );
  runManager->SetUserAction( primaryGenerator );

  // Initialize G4 kernel
  runManager->Initialize();


#ifdef G4VIS_USE
  //visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

		
  // Get the pointer to the User Interface manager
  G4UImanager* UIManager = G4UImanager::GetUIpointer();

  if( argc == 1 ){
    #ifdef G4UI_USE //not difined in setup
      G4UIExecutive* session = new G4UIExecutive(argc, argv);
      #ifdef G4VIS_USE
        UIManager->ApplyCommand("/control/execute ./mac/visFile/vis.mac"); 
      #endif
      if (session->IsGUI()){
       UIManager->ApplyCommand("/control/execute ./mac/visFile/gui.mac");
      }
      session->SessionStart();
      delete session;
    #endif
  }else{
	  G4String command = "/control/execute ";
	  G4String fileName = argv[1];
	  UIManager->ApplyCommand(command + fileName); 
  }

  //job termination
  delete runManager;
  return 0;
}
