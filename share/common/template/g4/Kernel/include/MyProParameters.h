/*
 *  $Id: MyProParameters.h, 2014-02-21 19:34:38 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    declear all const variables here
 *    *   Warning  *      can NOT use these variables here to define longth of array IN any HEADER files
*/

#ifndef MyProParameters_H
#define MyProParameters_H
#include "TVector3.h"

//-------------------------------------------------------------------
namespace MyProParameters{
  // the unit of any size is cm
  const short   kSubDetNo = 4;
  namespace SubDet{
    const TVector3  kDetectorSize(20,30,80);
    const TVector3  kPlaneSize(20,30,10)
    const TVector3  kBarSize(20,30,10)
    const short     kPlaneNo    = 7;     // one plane has 2 layers (x and y)
    const short     kBarNo      = 10;
    const short     kRefBarNo   = 2;
    const short     kSideNo     = 2;
    const short     kDyNo       = 3;
  }

}

#endif


