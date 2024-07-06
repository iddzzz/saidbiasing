#include "SaidBiasingDetectorConstruction.hh"

SaidBiasingDetectorConstruction::SaidBiasingDetectorConstruction(){}

SaidBiasingDetectorConstruction::~SaidBiasingDetectorConstruction(){}

G4VPhysicalVolume *SaidBiasingDetectorConstruction::Construct(){

    G4NistManager *nist = G4NistManager::Instance();

    G4Material *matWorld = nist -> FindOrBuildMaterial("G4_AIR");
    G4Box *solidWorld = new G4Box("solidWorld", 20 * cm, 20 * cm, 20 * cm);
    logicWorld = new G4LogicalVolume(solidWorld, matWorld, "logicWorld");
    physWorld = new G4PVPlacement(
        0,
        G4ThreeVector(0., 0., 0.),
        logicWorld,
        "physWorld",
        0,
        false,
        0,
        true
    );

    G4Material *matWater = nist -> FindOrBuildMaterial("G4_WATER");
    G4Box *solidWater = new G4Box("solidWater", 10 * cm, 10 * cm, 0.75 * cm);
    G4LogicalVolume *logicWater = new G4LogicalVolume(solidWater, matWater, "logicWater");
    physWater1 = new G4PVPlacement(
        0,
        G4ThreeVector(0., 0., -0.75 * cm),
        logicWater,
        "physWater1",
        logicWorld,
        false,
        0,
        true
    );
    physWater2 = new G4PVPlacement(
        0,
        G4ThreeVector(0., 0., 0.75 * cm),
        logicWater,
        "physWater2",
        logicWorld,
        false,
        0,
        true
    );

    return physWorld;
}

void SaidBiasingDetectorConstruction::CreateImportanceStore(){
    G4cout << G4endl << "SaidBiasingDetectorConstruction::CreateImportanceStore" << G4endl;

    G4IStore *istore = G4IStore::GetInstance();
    istore -> AddImportanceGeometryCell(1, *physWorld);
    istore -> AddImportanceGeometryCell(4, *physWater2);
    istore -> AddImportanceGeometryCell(16, *physWater1);

    G4cout << "SaidBiasingDetectorConstruction::CreateImportanceStore finished" << G4endl << G4endl;

}