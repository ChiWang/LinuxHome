/*
 *  $Id: MyProDetectorConstruction.h, 2014-02-15 23:20:46 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
*/ 

#ifndef MyProDetectorConstruction_H
#define MyProDetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class MyProDetectorConstruction : public G4VUserDetectorConstruction{
 public:
  MyProDetectorConstruction();
  virtual ~MyProDetectorConstruction();

  virtual G4VPhysicalVolume* Construct();

 private:
  void BuildMaterial();
  void SetupGeometry();
  void SetVisualization();
  G4VPhysicalVolume*      fWorldPhys;                 //PhysicalVolume for Construct() SetupGeometry() and SetVisualization()
  static G4bool           pSurfChk;                   //If set true, active checking for overlaps with existing volume

  // Special
  //___________________________________________________Material for Construct() and BuildMaterial()
  G4Material*     mPS;        //Plastic Scintillator
  G4Material*     mSi;
  G4Material*     mBGO;
  G4Material*     mVacuum;
  G4Material*     mAir;
  G4Material*     mFe;
  G4Material*     mMylar;
  //___________________________________________________LogivalVolume for Construct() and SetVisualization()
  G4LogicalVolume*  fWorldLogi;
  G4LogicalVolume*  fBGOLogi;
  G4LogicalVolume*  fPSLogi;    //Plastic scintillator

  void SetupGeometry_SubDetector_1(G4LogicalVolume* theWorldLogical);
  void SetupGeometry_SubDetector_2(G4LogicalVolume* theWorldLogical);
};

#endif


