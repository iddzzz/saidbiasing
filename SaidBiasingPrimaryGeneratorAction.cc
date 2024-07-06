#include "SaidBiasingPrimaryGeneratorAction.hh"

SaidBiasingPrimaryGeneratorAction::SaidBiasingPrimaryGeneratorAction(/* args */)
{
    fParticleGun = new G4ParticleGun(1);
}

SaidBiasingPrimaryGeneratorAction::~SaidBiasingPrimaryGeneratorAction()
{
    delete fParticleGun;
}

void SaidBiasingPrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent){
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "e-";
    G4ParticleDefinition *particle = particleTable -> FindParticle(particleName);

    G4ThreeVector pos(0., 0., -2 * cm);
    G4ThreeVector mom(0., 0., 1);

    fParticleGun -> SetParticlePosition(pos);
    fParticleGun -> SetParticleMomentumDirection(mom);
    fParticleGun -> SetParticleMomentum(10. * MeV);
    fParticleGun -> SetParticleDefinition(particle);

    fParticleGun -> GeneratePrimaryVertex(anEvent);
}