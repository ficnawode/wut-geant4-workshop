#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Trd.hh"
#include "G4VisAttributes.hh"

namespace B1
{


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Envelope parameters
  //
  G4double env_sizeXY = 20 * cm, env_sizeZ = 30 * cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

     // Define world volume
        G4double world_size = 1.0 * m;
        G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

        G4Box* solidWorld = new G4Box("World", world_size / 2, world_size / 2, world_size / 2);
        G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
        G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", nullptr, false, 0, true);

        // Define aluminum box
        G4double box_size = 10.0 * cm;
        G4Material* aluminum = nist->FindOrBuildMaterial("G4_Al");

        G4Box* solidBox = new G4Box("AluminumBox", box_size / 2, box_size / 2, box_size / 2);
        G4LogicalVolume* logicBox = new G4LogicalVolume(solidBox, aluminum, "AluminumBox");

        // Place aluminum box at the center of the world
        new G4PVPlacement(0, G4ThreeVector(), logicBox, "AluminumBox", logicWorld, false, 0, true);

        // Visualization attributes
        G4VisAttributes* worldVisAttr = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 0.1)); // Transparent world
        logicWorld->SetVisAttributes(worldVisAttr);

        G4VisAttributes* boxVisAttr = new G4VisAttributes(G4Colour(1.0, 0.1, 0.1)); // Gray aluminum
        logicBox->SetVisAttributes(boxVisAttr);

        return physWorld;
}


}  
