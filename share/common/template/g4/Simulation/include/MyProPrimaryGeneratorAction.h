/*
 *  $Id: MyProPrimaryGeneratorAction.h, 2014-02-15 23:25:21 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
*/

#ifndef MyProPrimaryGeneratorAction_H
#define MyProPrimaryGeneratorAction_H 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

class MyProPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
public:
  MyProPrimaryGeneratorAction();
  ~MyProPrimaryGeneratorAction();
  void GeneratePrimaries( G4Event* anEvent);
	
private:
  G4GeneralParticleSource* GPS;

};

#endif

