/*=====================================================================
 *   File:   MyProParameters.h
 *   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    20/06/2014
 *---------------------------------------------------------------------
 *   Description:
 *      declear all const variables here
 *      *   Warning  *      can NOT use these variables here to define longth of array IN any HEADER files
 *
 *---------------------------------------------------------------------
 *   History:
 *                           Last update:  25/01/2014   17:04:56
=====================================================================*/

#ifndef MyProParameters_H
#define MyProParameters_H

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....


namespace MyProParameters{
  const G4ThreeVector kWorldSize=(100,200,20);
  const G4int     kWorldR=100;

  namespace SubDet_1{
    const G4ThreeVector  SubDet_1Size=(20,30,40);        //(x,y,z)
    const G4int     kPlaneNum=20;
    const G4int     kBarNum=10;
  }

  namespace SubDet_2{
  }

}

#endif


