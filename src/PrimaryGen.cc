
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen()
{
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen()
{ }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent)
{
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleEnergy(0.662*MeV);
    gun->SetParticlePosition(G4ThreeVector(0,-10*mm,0.));
    gun->SetParticleMomentumDirection(G4ThreeVector(0, 1, 0));
    gun->GeneratePrimaryVertex(anEvent);
}