#include "SaidBiasingActionInitialization.hh"

SaidBiasingActionInitialization::SaidBiasingActionInitialization(/* args */)
{
}

SaidBiasingActionInitialization::~SaidBiasingActionInitialization()
{
}

void SaidBiasingActionInitialization::Build() const {
    SaidBiasingPrimaryGeneratorAction *generator = new SaidBiasingPrimaryGeneratorAction();
    SetUserAction(generator);
}