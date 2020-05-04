/*
 * TrackingAction.hh
 *
 *  Created on: 26/5/2016
 *      Author: fn1
 */

#ifndef INCLUDE_TRACKINGACTION_HH_
#define INCLUDE_TRACKINGACTION_HH_


#include "G4UserTrackingAction.hh"
#include "DetectorConstruction.hh"
#include "RunAction.hh"


class TrackingAction : public G4UserTrackingAction

{
public:
	TrackingAction();
	virtual ~TrackingAction();

	virtual void PostUserTrackingAction(const G4Track* track);

private:

	DetectorConstruction* fdetector;

	RunAction* frun;

};





#endif /* INCLUDE_TRACKINGACTION_HH_ */
