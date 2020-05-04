/*
 * RunAction.hh
 *
 *  Created on: 26/5/2016
 *      Author: fn1
 */

#ifndef INCLUDE_RUNACTION_HH_
#define INCLUDE_RUNACTION_HH_
#include "G4UserRunAction.hh"
#include "vector"
using namespace std;


class RunAction : public G4UserRunAction

{
public:

	RunAction();
	virtual ~RunAction();

	virtual void BeginOfRunAction (const G4Run*);
	virtual void EndOfRunAction (const G4Run*);

	inline void AddParticle (int index)
	{
		nparticle[index]++;
	}

private:

	vector <G4int> nparticle;


};



#endif /* INCLUDE_RUNACTION_HH_ */
