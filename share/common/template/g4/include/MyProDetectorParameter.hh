/*=============================================================================
#       FileName :          MyProGlobal.hh
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-20   16:06:01
#
#------------------------------------------------------------------------------
#       Description  :
#           declear all const variables here, define in src/MyProGlobal.cc. Any file want to use variables defined here just #include MyProGlobal.hh
#           *   Warning  *      can NOT use these variables here to define longth of array IN any HEADER files
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-20   16:06:01
=============================================================================*/
#ifndef MyProGlobal_H
#define MyProGlobal_H

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....
// World
extern const G4int          Diam_World;


// Plastic Scintllator
    //-----> Frame Structure 


// Silicon Detector
    //-----> Frame Structure 


// BGO Calorimeter
    //-----> Frame Structure 
    //----->   
extern const G4int          PlaneNum_BGO;
extern const G4float    

extern const G4int          BarNum_BGO;
extern const G4ThreeVector  BarSize_BGO;        //(x,y,z)
extern const G4float        BarGap_BGO;         //Gap of 2 Bars in one Layer

// Neutron Detector
    //-----> Frame Structure 



#endif


