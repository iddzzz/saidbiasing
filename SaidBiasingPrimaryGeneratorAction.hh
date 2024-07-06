#ifndef SAIDBIASINGPRIMARYGENERATORACTION_HH
#define SAIDBIASINGPRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

class SaidBiasingPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun *fParticleGun;
public:
    SaidBiasingPrimaryGeneratorAction();
    ~SaidBiasingPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);
};




#endif 