#include "PrimaryGeneratorAction.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace example
{

    PrimaryGeneratorAction::PrimaryGeneratorAction()
    {
        fParticleSource = new G4GeneralParticleSource();
    }

    PrimaryGeneratorAction::~PrimaryGeneratorAction()
    {
        delete fParticleSource;
    }

    void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
    {
        fParticleSource->GeneratePrimaryVertex(event);
    }

}
