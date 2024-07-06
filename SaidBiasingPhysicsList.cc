#include "SaidBiasingPhysicsList.hh"

SaidBiasingPhysicsList::SaidBiasingPhysicsList(SaidBiasingDetectorConstruction * det)
{   
    detector = det;

    physicsEM = new G4EmStandardPhysics_option4();
    physicsDecay = new G4DecayPhysics();
    physicsRadDecay = new G4RadioactiveDecayPhysics();
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
    RegisterPhysics(new G4EmStandardPhysics_option4());
}

SaidBiasingPhysicsList::~SaidBiasingPhysicsList()
{
}

// void SaidBiasingPhysicsList::ConstructParticle(){
//     physicsDecay -> ConstructParticle();
//     physicsRadDecay -> ConstructParticle();
//     physicsEM -> ConstructParticle();
// }

// void SaidBiasingPhysicsList::ConstructProcess(){
//     AddTransportation();
//     // physicsDecay -> ConstructProcess();
//     // physicsRadDecay -> ConstructProcess();
//     // physicsEM -> ConstructProcess();
//     AddBiasingProcess();
    
//     G4Decay* theDecayProcess = new G4Decay();
//     G4RadioactiveDecay * theRadDecayProcess = new G4RadioactiveDecay();
//     auto particleIterator=GetParticleIterator();
//     particleIterator->reset();
//     while( (*particleIterator)() ){
//         G4ParticleDefinition* particle = particleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         if (theDecayProcess->IsApplicable(*particle)) { 
//         pmanager->AddProcess(theDecayProcess);
//         pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
//         pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
//         }
//         if (theRadDecayProcess->IsApplicable(*particle)) { 
//         pmanager ->AddProcess(theRadDecayProcess);
//         // pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
//         // pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
//         }
//     }

// }

void SaidBiasingPhysicsList::AddBiasingProcess(){
    G4cout << G4endl << "SaidBiasingPhysicsList::AddBiasingProcess" << G4endl;

    G4IStore* iStore = G4IStore::GetInstance();
    G4GeometrySampler fGeomSampler(detector -> GetPhysWorld(),"e-");
    fGeomSampler.SetParallel(false);

    static G4bool first = true;
    if(first) {
        fGeomSampler.PrepareImportanceSampling(iStore, 0);

        fGeomSampler.Configure();
        if(fGeomSampler.IsConfigured()){
            G4cout << " GeomSampler Configured!!! " << G4endl;
        }
        first = false;
    }

    #ifdef G4MULTITHREADED 
    if(!G4Threading::IsMasterThread()) fGeomSampler.AddProcess();
    #else
    G4cout << " Running in singlethreaded mode!!! " << G4endl;
    #endif

    G4cout << "SaidBiasingPhysicsList::AddBiasingProcess finished" << G4endl << G4endl;
}