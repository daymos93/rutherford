/*
 * DetectorConstruction.hh
 *
 *  Created on: 7/5/2016
 *      Author: fn1
 */

#ifndef INCLUDE_DETECTORCONSTRUCTION_HH_
#define INCLUDE_DETECTORCONSTRUCTION_HH_
#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"

class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction

{
public:
	DetectorConstruction();
	virtual ~DetectorConstruction();
	virtual G4VPhysicalVolume* Construct();

	G4LogicalVolume* GetVolume(){return detectorVolumen;}

private:

	G4LogicalVolume* detectorVolumen;
};




#endif /* INCLUDE_DETECTORCONSTRUCTION_HH_ */
