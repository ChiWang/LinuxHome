/*=============================================================================
#       FileName :          MyXPrimaryGeneratorAction.hh
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

#ifndef MyXPrimaryGeneratorAction_H
#define MyXPrimaryGeneratorAction_H 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

class MyXPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
public:
  MyXPrimaryGeneratorAction();
  ~MyXPrimaryGeneratorAction();
  void GeneratePrimaries( G4Event* anEvent);
	
private:
  G4GeneralParticleSource* GPS;

};

#endif

