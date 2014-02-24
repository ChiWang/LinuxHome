/*
 *  $Id: MyProEvtHit.h, 2014-02-24 10:02:57 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/02/2014
*/

#ifndef MyProEvtHit_H
#define MyProEvtHit_H

#include "TObject.h"

class MyProEvtHit : public TObject{
/*
 *  The Hit at here not has the same concept as G4Hit. Event Hit class used to store the information of every single minimum detector unit correspond to one event inject into detector.
 *  But, this hit will also be used in the Sensitive Detector. Every sensitive detector correspond to a single sub-detector should set this class as a data member in their concrete SimuHit class which inherited from G4VHit.
 *  This is class will also be used while data analysis for real data.
 *
 */
public:
  MyProEvtHit();
  ~MyProEvtHit();
//  const MyProEvtHit& operator=(const MyProEvtHit &right);
  int GetUID() const        {return fUID;}
  void SetUID(int id)       {fUID = id;}
  double GetEnergy() const  {return fEnergy;}
  void SetEnergy(double e)  {fEnergy = e;}
  double GetTime() const    {return fTime;}
  void SetTime(double t)    {fTime = t;}
  double GetPosition(short i) const  {return fPosition[i];}
  void UpdateThisStep(double e, double x, double y, double z, double t=0);  // this function is only invoked from MyProSimSubDetSD::ProcessHits()
  void PrintHit() const;

protected:
  int       fUID;           // ID of minimum detector unit. For instance, we can set fUID =  layerID*1000 + barID*10 +sideID
  double    fEnergy;        // unit MeV
  double    fPosition[3];   // unit cm
  double    fTime;          // unit mSec

  ClassDef(MyProEvtHit,1)
};

#endif

