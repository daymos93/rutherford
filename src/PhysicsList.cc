#include "PhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4ParticleTypes.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4KleinNishinaModel.hh"
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4hMultipleScattering.hh"
#include "G4hIonisation.hh"
#include "G4eplusAnnihilation.hh"
#include "G4VMultipleScattering.hh"
#include "G4ionIonisation.hh"
#include "G4SystemOfUnits.hh"



PhysicsList::PhysicsList()
{
	cutforElectron=1*um;

	cutforGamma=1*um;

	cutforPositron=1*um;

};

PhysicsList::~PhysicsList()
{
};

void PhysicsList::ConstructParticle()
{

	G4Gamma::GammaDefinition();

	G4Proton::ProtonDefinition();

	G4Electron::ElectronDefinition();

	G4Alpha::AlphaDefinition();

	G4Positron::PositronDefinition();

	G4GenericIon::GenericIonDefinition();

	G4He3::He3Definition();


}

void PhysicsList::ConstructProcess()
{

	AddTransportation();

	G4PhysicsListHelper* pH= G4PhysicsListHelper::GetPhysicsListHelper();

	theParticleIterator->reset();

	while ((*theParticleIterator)()){

		G4ParticleDefinition* particle= theParticleIterator->value();

		G4String particleName= particle->GetParticleName();

	if (particleName ==  "gamma"){

		pH->RegisterProcess(new G4PhotoElectricEffect,particle);

		G4ComptonScattering* cs=

				new G4ComptonScattering();

		cs->SetEmModel(new G4KleinNishinaModel);

		pH->RegisterProcess(cs, particle);

        pH->RegisterProcess(new G4GammaConversion, particle);

	} else if (particleName ==  "proton"){

		pH->RegisterProcess(new G4hMultipleScattering,particle);

		pH->RegisterProcess(new G4hIonisation,particle);

	} else if (particleName ==  "e-"){

		pH->RegisterProcess(new G4eMultipleScattering,particle);

		pH->RegisterProcess(new G4eIonisation,particle);

		pH->RegisterProcess(new G4eBremsstrahlung,particle);

	} else if (particleName ==  "alpha" || particleName ==  "he3" || particleName ==  "GenericIon"){

		pH->RegisterProcess(new G4hMultipleScattering,particle);

		pH->RegisterProcess(new G4ionIonisation,particle);

	} else if (particleName ==  "e+"){

		pH->RegisterProcess(new G4eMultipleScattering,particle);

		pH->RegisterProcess(new G4eIonisation,particle);

		pH->RegisterProcess(new G4eBremsstrahlung,particle);

		pH->RegisterProcess(new G4eplusAnnihilation,particle);

	}

	}
}

void PhysicsList::SetCuts()
{
SetCutValue(cutforGamma,"Gamma");

SetCutValue(cutforElectron,"Electron");

SetCutValue(cutforPositron,"Positron");
}

