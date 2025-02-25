#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;
class G4Box;

namespace example
{

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued
/// in front of the phantom across 80% of the (X,Y) phantom size.

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override;

    // method from the base class
    void GeneratePrimaries(G4Event*) override;

    // method to access particle gun
    const G4GeneralParticleSource* GetParticleGun() const { return fParticleSource; }

  private:
    G4GeneralParticleSource* fParticleSource= nullptr;  // pointer a to G4 gun class
    G4Box* fEnvelopeBox = nullptr;
};

}

