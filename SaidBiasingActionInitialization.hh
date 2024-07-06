#ifndef SAIDBIASINGACTIONINITIALIZATION_HH
#define SAIDBIASINGACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"

#include "SaidBiasingPrimaryGeneratorAction.hh"

class SaidBiasingActionInitialization : public G4VUserActionInitialization 
{
public:
    SaidBiasingActionInitialization();
    ~SaidBiasingActionInitialization();

    virtual void Build() const;
};


#endif 