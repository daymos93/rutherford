/*
 * DetectorConstruction.cc
 *
 *  Created on: 7/5/2016
 *      Author: fn1
 */
#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Tubs.hh"
#include "G4PhysicalConstants.hh"
#include "G4RotationMatrix.hh"


DetectorConstruction::DetectorConstruction():detectorVolumen(0)
{
};

DetectorConstruction::~DetectorConstruction()
{
};

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	//WORLD

	G4Box* solidWorld=
			new G4Box("world",20*cm,20*cm,20*cm);

	G4NistManager* material=
            G4NistManager::Instance();

    G4Material* vacuum=
    		material->FindOrBuildMaterial("G4_Galactic");

    G4LogicalVolume* logicalWorld=
    		new G4LogicalVolume(solidWorld,vacuum, "world");

    G4VPhysicalVolume* physicalWorld=
    		new G4PVPlacement (0,G4ThreeVector(0,0,0),logicalWorld, "world",0,false,0,true);

    //00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

    //GOLD_TARGET

    G4Box* solidTarget=
    		new G4Box("target",0.5*cm,0.5*cm,1*um);

    G4Material* gold=
    		material->FindOrBuildMaterial("G4_Au");

    G4LogicalVolume* logicalTarget=
        		new G4LogicalVolume(solidTarget,gold, "target");

    G4VPhysicalVolume* physicalTarget=
        		new G4PVPlacement (0,G4ThreeVector(0,0,0),logicalTarget, "target",logicalWorld,false,0,true);

    G4VisAttributes* targetColor=
                new G4VisAttributes(G4Colour(1,1,0));

    logicalTarget->SetVisAttributes(targetColor);

    //0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

    //DETECTORS

    G4Tubs* solidDetector=
    		new G4Tubs ("detector",0,0.5*cm,0.05*cm,0,twopi);

    G4Material* air=
        		material->FindOrBuildMaterial("G4_Pb");

    G4LogicalVolume* logicalDetector=
           		new G4LogicalVolume(solidDetector,air, "detector");

    G4VisAttributes* detectorColor=
                    new G4VisAttributes(G4Colour(1,0,0));

    logicalDetector->SetVisAttributes(detectorColor);

    for (int nDetector = 0; nDetector < 72 ; ++nDetector) {

    	G4double phi= nDetector*5*deg;

    	G4double radio= 11.60*cm;

    	G4ThreeVector position= G4ThreeVector(sin(phi),0,cos(phi));

    	              position=position*radio;

    	G4RotationMatrix* rotation=
    			new G4RotationMatrix ();

    	rotation->rotateY(-phi);

    	G4VPhysicalVolume* physicalDetector=
    	            		new G4PVPlacement (rotation,position,logicalDetector, "detector",logicalWorld,false,nDetector,true);

	}


    //000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

    detectorVolumen=logicalDetector;


 return physicalWorld;


} ;







