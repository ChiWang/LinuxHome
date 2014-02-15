/*
 *  $Id: MyProParameters.h, 2014-02-15 23:24:12 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    declear all const variables here
 *    *   Warning  *      can NOT use these variables here to define longth of array IN any HEADER files
*/

#ifndef MyProParameters_H
#define MyProParameters_H
#include "G4ThreeVector.hh"

//-------------------------------------------------------------------
namespace MyProParameters{
  const G4ThreeVector kWorldSize(100,200,20);
  const G4int     kWorldR=100;

  namespace SubDet_1{
    const G4ThreeVector  SubDet_1Size(20,30,40);        //(x,y,z)
    const G4int     kPlaneNum=20;
    const G4int     kBarNum=10;
  }

  namespace SubDet_2{
  }

}

#endif


