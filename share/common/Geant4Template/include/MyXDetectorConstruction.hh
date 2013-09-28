/*=============================================================================
#       FileName :          MyXDetectorConstruction.hh
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-20   20:25:19
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-20   20:25:19
=============================================================================*/

#ifndef MyXDetectorConstruction_H
#define MyXDetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class MyXDetectorConstruction : public G4VUserDetectorConstruction{
 public:
  MyXDetectorConstruction();
  virtual ~MyXDetectorConstruction();

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


