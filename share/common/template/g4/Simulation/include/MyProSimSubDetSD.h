/*
 *  $Id: MyProSimSubDetSD.h, 2014-02-21 23:15:32 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 21/02/2014
*/

#ifndef MyProSimSubDetSD_H
#define MyProSimSubDetSD_H

#include <vector>
#include "G4VSensitiveDetector.hh"

class MyProVEvtHit;

class MyProSimSubDetSD : public G4VSensitiveDetector{
public:
  MyProSimSubDetSD(G4String);
  ~MyProSimSubDetSD(G4String);

  void Initialize(G4HCofThisEvent*);
  G4bool ProcessHits(G4Step *aStep,G4TouchableHistory *ROhist);

private:
  std::vector<MyProEvtHit*>    fEvtHitSet;

private:
  int GetIDInHitSet(int uniqueID);

};

#endif
