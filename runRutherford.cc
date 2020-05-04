#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "TrackingAction.hh"
#include "RunAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
G4RunManager* runManager=
		new G4RunManager;

runManager->SetUserInitialization(
		new DetectorConstruction);

runManager->SetUserInitialization(
		new PhysicsList);

runManager->SetUserAction(new PrimaryGeneratorAction);

runManager->SetUserAction(new TrackingAction);

runManager->SetUserAction(new RunAction);

runManager->Initialize();

G4UIExecutive* UI=
		new G4UIExecutive (argc,argv);

G4VisManager* VisManager=
		new G4VisExecutive ();

VisManager->Initialize();

G4UImanager* UImanager=
		G4UImanager::GetUIpointer();

UImanager->ApplyCommand("/control/execute vis.mac");
//UImanager->ApplyCommand("/control/execute run.mac");

UI->SessionStart();

delete UI;

delete VisManager;

delete UImanager;

delete runManager;

return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
