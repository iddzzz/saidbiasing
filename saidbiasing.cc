#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"

#include "FTFP_BERT.hh"
#include "G4VModularPhysicsList.hh"
#include "G4GeometrySampler.hh"
#include "G4ImportanceBiasing.hh"

#include "SaidBiasingDetectorConstruction.hh"
#include "SaidBiasingActionInitialization.hh"
#include "SaidBiasingPhysicsList.hh"


int main(int argc, char** argv){

    G4UIExecutive *ui = 0;
    if (argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }
    

    G4RunManager *runManager = new G4RunManager();
    SaidBiasingDetectorConstruction * detector = new SaidBiasingDetectorConstruction();
    runManager -> SetUserInitialization(detector);
    // G4VModularPhysicsList *physicsList = new SaidBiasingPhysicsList(detector);
    SaidBiasingPhysicsList *physicsList = new SaidBiasingPhysicsList(detector);
    G4GeometrySampler mgs(detector -> GetPhysWorld(), "e-");
    // G4GeometrySampler mgs2(detector -> GetPhysWorld(), "gamma");
    physicsList -> RegisterPhysics(new G4ImportanceBiasing(&mgs));
    // physicsList -> RegisterPhysics(new G4ImportanceBiasing(&mgs2));
    runManager -> SetUserInitialization(physicsList);
    // runManager -> SetUserInitialization(new FTFP_BERT);
    // runManager -> SetUserInitialization(new SaidBiasingPhysicsList(detector));
    runManager -> SetUserInitialization(new SaidBiasingActionInitialization());
    runManager -> Initialize();

    detector -> CreateImportanceStore();

    G4VisManager *visManager = new G4VisExecutive;
    visManager -> Initialize();


    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    if (!ui) {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager -> ApplyCommand(command + fileName);
    } else {
        UImanager -> ApplyCommand("/control/execute vis.mac");
        ui -> SessionStart();
        delete ui;
    }


    delete visManager;
    return 0;
}