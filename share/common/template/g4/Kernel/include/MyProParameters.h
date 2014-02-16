/*
 *  $Id: MyProParameters.h, 2014-02-16 22:37:37 chi $
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
  const int     kWorldR=100;

  namespace SubDet1{
    const G4ThreeVector  SubDet_1Size(20,30,40);        //(x,y,z)
    const int     kPlaneNum=20;
    const int     kBarNum=10;
  }

  namespace SubDet2{
  }

}

#endif


