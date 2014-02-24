/*
 *  $Id: MyProEvtHeader.cc, 2014-02-21 22:31:22 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/02/2014
*/

#include <boost/shared_ptr.hpp>
#include "TParticle.h"
#include "TVector3.h"
#include "MyProEvtHeader.h"
#include "MyProParameters.h"

ClassImp(MyProEvtHeader)

MyProEvtHeader*  MyProEvtHeader::fInstance = 0;

//-------------------------------------------------------------------
MyProEvtHeader::MyProEvtHeader()
 :fEventID(-1),
  fParticle(0),
  fInjectPos(0)
{
  fParticle = new TParticle();
  fInjectPos = new TVector3();
  fRunModes.resize(MyProParameters::kSideNo);
}

MyProEvtHeader::~MyProVEvtHit(){
  delete fParticle;
  delete fInjectPos;
}

//-------------------------------------------------------------------
MyProEvtHeader* GetEventHeader(){
  if(fInstance == 0){
// *
// *  TODO: using smart pointer at here
// *
    //boost::shared_ptr<MyProEvtHeader>  fInstance(new MyProEvtHeader);
    fInstance = new MyProEvtHeader();
  }
  return fInstance;
}

//-------------------------------------------------------------------
void SetInjectPosition(double x, double y, double z){
  fInjectPos->SetXYZ(x,y,z);
}

//-------------------------------------------------------------------
void SetRunMode(short SubDet_ID, MyProERunMode mode){
  fRunModes[SubDet_ID]  = mode;
}

