/*
 *  $Id: MyProEvtHit.cc, 2014-02-24 10:11:13 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 19/02/2014
*/ 

#include <iostream>
#include "MyProEvtHit.h"

ClassImp(MyProEvtHit)

MyProEvtHit::MyProEvtHit()
 :fUID(0),
  fEnergy(0),
  fTime(0)
{
  for (int i=0;i<3;++i) fPosition[i] = 0;
}

MyProEvtHit::~MyProEvtHit(){
}

/*-------------------------------------------------------------------
const MyProEvtHit& MyProEvtHit::operator=(const MyProEvtHit &right){
  fUID = right.fUID;
  fEnergy = right.fEnergy;
  for (int i=0;i<3++i)  fPosition[i] = right.fPosition[i];
  fTime = right.fTime;
}
*/

//-------------------------------------------------------------------
void MyProEvtHit::UpdateThisStep(double e, double x, double y, double z, double t){
  double totE = e + fEnergy;
  double nX = (x*e + fPosition[0]*fEnergy)/totE;
  double nY = (y*e + fPosition[1]*fEnergy)/totE;
  double nZ = (z*e + fPosition[2]*fEnergy)/totE;
  fPosition[0] = nX;
  fPosition[1] = nY;
  fPosition[2] = nZ;
  fEnergy = totE;
  fTime = t;    // only save the time of the last G4Hit in this minimum unit.
}

//-------------------------------------------------------------------
void DmpEvtBgoHit::PrintHit() const{
  std::cout<<fUID<<"\t"<<fEnergy<<"\t("<<fPosition[0]<<","<<fPosition[1]<<","<<fPosition[2]<<")"<<std::endl;
}
