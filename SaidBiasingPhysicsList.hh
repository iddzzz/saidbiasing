#ifndef SAIDBIASINGPHYSICSLIST_HH
#define SAIDBIASINGPHYSICSLIST_HH

#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"

#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include "G4IStore.hh"
#include "G4GeometrySampler.hh"

#include "SaidBiasingDetectorConstruction.hh"

#include "G4RadioactiveDecay.hh"


class SaidBiasingPhysicsList : public G4VModularPhysicsList
{
private:
    G4RadioactiveDecayPhysics * physicsRadDecay;
    G4EmStandardPhysics_option4 * physicsEM;
    G4DecayPhysics * physicsDecay;

    SaidBiasingDetectorConstruction *detector;
public:
    SaidBiasingPhysicsList(SaidBiasingDetectorConstruction *);
    ~SaidBiasingPhysicsList();

    void AddBiasingProcess();

protected:
    // virtual void ConstructParticle();
    // virtual void ConstructProcess();
};

#endif 