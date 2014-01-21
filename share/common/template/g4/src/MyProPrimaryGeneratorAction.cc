/*=============================================================================
#       FileName :          MyProPrimaryGeneratorAction.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:37:59
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:37:59
=============================================================================*/

#include "MyProPrimaryGeneratorAction.hh"

#include "G4GeneralParticleSource.hh"

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

MyProPrimaryGeneratorAction::MyProPrimaryGeneratorAction():GPS( 0 ){
  GPS = new G4GeneralParticleSource();
  // Define here the user default properties for the General Particle Source (GPS)
  // Can be modified through the GPS Messenger (/gps/... commands)

}

MyProPrimaryGeneratorAction::~MyProPrimaryGeneratorAction(){
  delete GPS;
}

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

void MyProPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
  // ****** This method will be invoked at the begining of each event

  //G4cout<<"\n\nXXXXXXXXX\n\nPosition\n\nXXXXXXX\t\t"<<GPS->GetParticlePosition()<<G4endl;
  GPS->GeneratePrimaryVertex( anEvent );
  //G4cout << "&&&&&&&" << G4endl;
}

