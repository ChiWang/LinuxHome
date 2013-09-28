
#include "MyXPrimaryGeneratorAction.hh"

#include "G4GeneralParticleSource.hh"

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

MyXPrimaryGeneratorAction::MyXPrimaryGeneratorAction():GPS( 0 ){
  GPS = new G4GeneralParticleSource();
  // Define here the user default properties for the General Particle Source (GPS)
  // Can be modified through the GPS Messenger (/gps/... commands)

}

MyXPrimaryGeneratorAction::~MyXPrimaryGeneratorAction(){
  delete GPS;
}

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

void MyXPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
  // ****** This method will be invoked at the begining of each event

  //G4cout<<"\n\nXXXXXXXXX\n\nPosition\n\nXXXXXXX\t\t"<<GPS->GetParticlePosition()<<G4endl;
  GPS->GeneratePrimaryVertex( anEvent );
  //G4cout << "&&&&&&&" << G4endl;
}

