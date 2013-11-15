/*=============================================================================
#       FileName :          MyXDetectorConstruction.cc
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-16   07:37:13
#------------------------------------------------------------------------------
#       Description  
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-16   07:37:13
=============================================================================*/

#include "MyXDetectorConstruction.hh"
#include "MyXDetectorParameter.hh"

#include "G4LogicalVolume.hh"   // Geometry
#include "G4PVPlacement.hh"

#include "G4NistManager.hh"     // Material

#include "G4VisAttributes.hh"   // Visulization
#include "G4Colour.hh"

#include "G4Region.hh"		    // Regions & Cut
#include "G4UserLimits.hh"

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

MyXDetectorConstruction::MyXDetectorConstruction():
  mPS(0),
  mSi(0),
  mBGO(0),
  mVacuum(0),mAir(0),mFe(0),mMylar(0),
  fWorldPhys(0)
{;}


MyXDetectorConstruction::~MyXDetectorConstruction()
{;}

//.....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.......oooOO0OOooo....

G4VPhysicalVolume* MyXDetectorConstruction::Construct(){
  BuildMaterial();          // Define the Materials
  SetupGeometry();
  SetVisualization();
  return fWorldPhys;
}

void MyXDetectorConstruction::BuildMaterial(){
  G4NistManager *nistManager = G4NistManager::Instance();
  nistManager->SetVerbose(1);
	
  mPS = nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  mSi = nistManager->FindOrBuildMaterial("G4_Si");
  G4String	Name;       //G4Material(const G4String& name, ...);
  mBGO = new G4Material(Name = "BGO",7.13*g/cm3,3,solid);
  mBGO->AddElement(nistManager->FindOrBuildElement("Bi"),4);
  mBGO->AddElement(nistManager->FindOrBuildElement("Ge"),3);
  mBGO->AddElement(nistManager->FindOrBuildElement("O"),12);
  const G4int NUMENTRIES = 7;
  G4double ENERGY[NUMENTRIES] =
   {1.553E-9*GeV, 2.013E-9*GeV, 2.100E-9*GeV, 2.219E-9*GeV, 2.400E-9*GeV, 2.498E-9*GeV, 3.11E-9*GeV};
  G4double RINDEXPWO[NUMENTRIES] =
   {2.15, 2.15, 2.15, 2.15, 2.15, 2.15, 2.15};
  G4double ABSORPTIONPWO[NUMENTRIES] = 
   {2.0*m, 2.0*m, 2.0*m, 2.0*m, 2.0*m, 2.0*m, 2.0*m};
  G4double ScintilSlow[NUMENTRIES] =
    {1., 1., 1., 1., 1., 1., 1.};
  G4MaterialPropertiesTable *PWOMPT = new G4MaterialPropertiesTable();
  PWOMPT->AddProperty("RINDEX", ENERGY, RINDEXPWO, NUMENTRIES);
  PWOMPT->AddProperty("ABSLENGTH",ENERGY, ABSORPTIONPWO, NUMENTRIES);
  PWOMPT->AddProperty("SLOWCOMPONENT", ENERGY, ScintilSlow, NUMENTRIES);
  PWOMPT->AddConstProperty("SCINTILLATIONYIELD",50./MeV);
  PWOMPT->AddConstProperty("RESOLUTIONSCALE",0.);
  PWOMPT->AddConstProperty("FASTTIMECONSTANT", 300.*ns);
  PWOMPT->AddConstProperty("SLOWTIMECONSTANT",300.*ns);
  PWOMPT->AddConstProperty("YIELDRATIO",1.);
  mBGO->SetMaterialPropertiesTable(PWOMPT);

  mVacuum = nistManager->FindOrBuildMaterial("G4_AIR");         //???
  mAir = nistManager->FindOrBuildMaterial("G4_AIR");
  mFe = nistManager->FindOrBuildMaterial("G4_Fe");
  mMylar = nistManager->FindOrBuildMaterial("G4_MYLAR");
  // Output List
  G4cout<<*(G4Material::GetMaterialTable())<<G4endl;
}

void MyXDetectorConstruction::SetupGeometry(){
  // The World
  G4VSolid* worldSoli = new G4Orb("world",Diam_World / 2.0 );
  G4LogicalVolume* worldLogi = new G4LogicalVolume(worldSoli,mAir,"world");
  fWorldPhys= new G4PVPlacement(0,G4ThreeVector(),worldLogi,"world",0,false,0,pSurfChk);
  // The sub-detector
  SetupGeometry_SubDetector_1(worldLogi);
  SetupGeometry_SubDetector_2(worldLogi);
}

void MyXDetectorConstruction::SetVisualization(){
  // The World
  fWorldLogi->SetVisAttributes(G4VisAttributes::Invisible);
  //sub_detector_1
  G4VisAttributes* visBGO = new G4VisAttributes(G4Colour(1.0,0.0,0.0));
  fBGOLogi->SetVisAttributes(visBGO);

  //sub_detector_2
  G4VisAttributes* visPS = new G4VisAttributes(G4Colour(1.0,1.0,0.0));
  fPSLogi->SetVisAttributes(visPS);
}

void MyXDetectorConstruction::SetupGeometry_SI(G4LogicalVolume* theWorldLogi){

}

void MyXDetectorConstruction::SetupGeometry_BGO(G4LogicalVolume* theWorldLogi){

}

