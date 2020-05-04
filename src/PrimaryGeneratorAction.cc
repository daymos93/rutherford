/*
 * PrimaryGeneratorAction.cc
 *
 *  Created on: 7/5/2016
 *      Author: fn1
 */
#include "PrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "G4PhysicalConstants.hh"
#include "Randomize.hh"


PrimaryGeneratorAction::PrimaryGeneratorAction(): fparticleGun(0)
{
	G4int nparticleGun=1;

	G4ParticleDefinition* particle= G4ParticleTable::GetParticleTable()-> FindParticle("alpha");

	fparticleGun=
			new G4ParticleGun(nparticleGun);

	fparticleGun->SetParticleDefinition(particle);

	fparticleGun->SetParticleEnergy(5.5*MeV);

	fparticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));



	fparticleGun->SetParticlePosition(G4ThreeVector(0,0,-5.5*cm));




};

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete fparticleGun;
};

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* aEvent)
{


	G4double radio, angle, x, y, z;

	G4int nEvent;

	nEvent= aEvent-> GetEventID();

	angle= twopi*rad*G4UniformRand();

	radio= 0.25*cm*G4UniformRand();

	x=radio*sin(angle);

	y=radio*cos(angle);

	z=-5.5*cm;

//	G4cout<< "nEvent="<< nEvent+1 << G4endl;
//	G4cout<< "x=" << x << G4endl;
//	G4cout<< "y=" << y << G4endl;
//	G4cout<< "z=" << z << G4endl;

	fparticleGun->SetParticlePosition(G4ThreeVector(x,y,z));

	fparticleGun->GeneratePrimaryVertex(aEvent);

};
