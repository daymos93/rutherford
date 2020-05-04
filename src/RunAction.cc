/*
 * RunAction.cc
 *
 *  Created on: 26/5/2016
 *      Author: fn1
 */

#include "RunAction.hh"
#include "fstream"
#include "globals.hh"

RunAction::RunAction()
{
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction (const G4Run*)
{

	for (G4int i = 0; i < 72; ++i) {

		nparticle.push_back(0);

	}
}

void RunAction::EndOfRunAction (const G4Run*)
{


	ofstream outfile("datos.txt");

	outfile<< "angle        " << "particle" << endl;

	outfile<< "0        " << nparticle[0]<< endl;

	G4int detectors=nparticle.size();

    for (G4int i= 1; i < detectors/2; ++i) {

    outfile<< i*5 <<"        "<< nparticle[i]+nparticle[detectors-i]<<endl;

    };


    outfile<< "180        "<<nparticle[detectors/2]<<endl;

    outfile.close();

}
