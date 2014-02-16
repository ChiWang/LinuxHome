/*
 *  $Id: MyProSimPrimaryGeneratorAction.h, 2014-02-16 23:18:22 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
*/

#ifndef MyProSimPrimaryGeneratorAction_H
#define MyProSimPrimaryGeneratorAction_H

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;

//-------------------------------------------------------------------
class MyProSimPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
 public:
  MyProSimPrimaryGeneratorAction();
  ~MyProSimPrimaryGeneratorAction();
  void GeneratePrimaries( G4Event *anEvent);
	
 private:
  G4GeneralParticleSource *mGPS;

};

#endif

