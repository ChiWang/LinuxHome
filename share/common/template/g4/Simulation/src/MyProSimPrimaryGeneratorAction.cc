/*
 *  $Id: MyProSimPrimaryGeneratorAction.cc, 2014-02-16 23:18:14 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/11/2013
*/ 

#include "G4GeneralParticleSource.hh"
#include "MyProSimPrimaryGeneratorAction.h"

//-------------------------------------------------------------------
MyProSimPrimaryGeneratorAction::MyProSimPrimaryGeneratorAction():fGPS( 0 ){
  fGPS = new G4GeneralParticleSource();
  // Define here the user default properties for the General Particle Source (GPS)
  // Can be modified through the GPS Messenger (/gps/... commands)
}

MyProSimPrimaryGeneratorAction::~MyProSimPrimaryGeneratorAction(){
  delete fGPS;
}

//-------------------------------------------------------------------
void MyProSimPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
  // ****** This method will be invoked at the begining of each event

  //G4cout<<"\n\nXXXXXXXXX\n\nPosition\n\nXXXXXXX\t\t"<<GPS->GetParticlePosition()<<G4endl;
  fGPS->GeneratePrimaryVertex( anEvent );
  //G4cout << "&&&&&&&" << G4endl;
}

