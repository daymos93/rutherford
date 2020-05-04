/*
 * PrimaryGenerationAction.hh
 *
 *  Created on: 7/5/2016
 *      Author: fn1
 */

#ifndef INCLUDE_PRIMARYGENERATORACTION_HH_
#define INCLUDE_PRIMARYGENERATORACTION_HH_

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class G4ParticleGun;

class PrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{

public:
	PrimaryGeneratorAction();
	virtual ~PrimaryGeneratorAction();
	virtual void GeneratePrimaries (G4Event*);

private:
	G4ParticleGun* fparticleGun;


};




#endif /* INCLUDE_PRIMARYGENERATORACTION_HH_ */
