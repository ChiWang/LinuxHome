/*
 *  $Id: MyProEvent.h, 2014-02-24 11:50:51 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/02/2014
*/

#inlcude "TObject.h"

class TClonesArray;
class MyProEvtHeader;
class MyProEvtHit;

class MyProEvent : public TObject{
public:
  MyProEvent();
  ~MyProEvent();
  TClonesArray* GetHitCollection() const;
  void UpdateHit(short SubDet_ID, int UID, double e, double x, double y, double z, double t=-1);
  void Reset();

private:
  MyProEvtHeader    *fEvtHeader;
  // here is just an example of one sub-det. If there are many sub-dets, use:
  //TClonesArray      *fSubDet1Hits;     //->
  TClonesArray      *fHits;     //->

};
