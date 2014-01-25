/*=============================================================================
#       FileName :          MyProPrimaryGeneratorAction.h
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-20   15:54:33
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-20   15:54:33
=============================================================================*/

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

