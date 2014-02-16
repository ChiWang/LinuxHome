/*
 *  $Id: MyProVEvtMCHit.cc, 2014-02-17 00:08:54 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 17/02/2014
*/

#include "TVector3.h"
#include "MyProVEvtMCHit.h"

MyProVEvtMCHit::MyProVEvtMCHit()
 :fPosition(0),
  fEnergy(0)
{
  fPosition = new TVector3();
}

MyProVEvtMCHit::~MyProVEvtMCHit(){
  delete fPosition;
}
