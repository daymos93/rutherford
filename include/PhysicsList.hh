/*
 * PhysicsList.hh
 *
 *  Created on: 7/5/2016
 *      Author: fn1
 */

#ifndef INCLUDE_PHYSICSLIST_HH_
#define INCLUDE_PHYSICSLIST_HH_
#include "G4VUserPhysicsList.hh"

class PhysicsList: public G4VUserPhysicsList

{
	public:
       PhysicsList();
       virtual ~PhysicsList();
       virtual void ConstructParticle();
       virtual void ConstructProcess();
       virtual void SetCuts();

	private:
       G4double cutforGamma;
       G4double cutforElectron;
       G4double cutforPositron;

};




#endif /* INCLUDE_PHYSICSLIST_HH_ */
