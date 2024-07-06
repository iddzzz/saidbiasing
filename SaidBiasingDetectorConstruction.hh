#ifndef SAIDBIASINGDETECTORCONSTRUCTION_HH
#define SAIDBIASINGDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4IStore.hh"

class SaidBiasingDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        SaidBiasingDetectorConstruction();
        ~SaidBiasingDetectorConstruction();

        virtual G4VPhysicalVolume *Construct();

        void CreateImportanceStore();
        
        G4VPhysicalVolume * GetPhysWorld() const {return physWorld;};
    
    private:
        G4VPhysicalVolume * physWorld, * physWater1, * physWater2;
        G4LogicalVolume *logicWorld;
};

#endif 