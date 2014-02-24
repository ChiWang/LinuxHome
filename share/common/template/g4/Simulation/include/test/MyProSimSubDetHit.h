/*
 *  $Id: MyProSimSubDetHit.h, 2014-02-20 22:32:56 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/02/2014
*/

#ifndef MyProSimSubDetHit_H
#define MyProSimSubDetHit_H

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"

class MyProVEvtHit;

class MyProSimSubDetHit : public G4VHit{
public:
  MyProSimSubDetHit();
  ~MyProSimSubDetHit();
  const MyProSimSubDetHit& operator=(const MyProSimSubDetHit&);
  int operator==(const MyProSimSubDetHit&) const;

  void* operator new(size_t);
  void  operator delete(void*);
  
private:
};

typedef G4THitsCollection<MyProSimSubDetHit> MyProSimSubDetHitsCollection;

extern G4Allocator<MyProSimSubDetHit> MyProSimSubDetHitAllocator;

inline void* MyProSimSubDetHit::operator new(size_t)
{
  void* aHit;
  aHit = (void*) MyProSimSubDetHitAllocator.MallocSingle();
  return aHit;
}

inline void MyProSimSubDetHit::operator delete(void *aHit)
{
  MyProSimSubDetHitAllocator.FreeSingle((MyProSimSubDetHit*) aHit);
}

#endif


