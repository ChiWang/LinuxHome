/*
 *  $Id: MyProEvtHeader.h, 2014-02-24 10:21:24 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/02/2014
*/

#ifndef MyProEvtHeader_H
#define MyProEvtHeader_H

#include <vector>
#include "TObject.h"

class TParticle;
class TVector3;

class MyProEvtHeader : public TObject{
public:
  enum MyProERunMode{
    kUnknow = -1,
    kCompress = 5,
    kCalPed = 6,
    kCalADC = 7,
  };
  static MyProEvtHeader* GetEventHeader();
  ~MyProEvtHeader();
  MyProEvtHeader();

  void SetEventID(long id)              {fEventID = id;}
  long GetEventID() const               {return fEventID;}
  void SetParticle(TParticle *par)      {fParticle = par;}
  TParticle* GetParticle() const        {return fParticle;}
  TVector3*  GetInjectPosition() const  {return fInjectPos;}
  void SetInjectPosition(double x,double y, double z);
  void SetRunMode(short SubDet_ID,MyProERunMode mode);  // SubDet_ID = 0 ~ MyProParameters::kSubDetNo - 1. From the direction of injection.
  MyProERunMode GetRunMode(short SubDet_ID) const {return fRunModes[SubDet_ID];}

private:
  static MyProEvtHeader     *fInstance; //! not save it

private:
  long          fEventID;               // event id
  TParticle     *fParticle;             // this particle
  TVector3      *fInjectPos;            // injected position, unit cm
  std::vector<MyProERunMode>  fRunModes;  // run mode of all sub-det

  ClassDef(MyProEvtHeader,1)

};

#endif

