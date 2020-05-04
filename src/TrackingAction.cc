#include "TrackingAction.hh"
#include "G4Alpha.hh"
#include "G4RunManager.hh"


TrackingAction::TrackingAction():fdetector(0),frun(0)
{
}

TrackingAction::~TrackingAction()
{
}

void TrackingAction::PostUserTrackingAction(const G4Track* track)
{
	fdetector=(DetectorConstruction*)G4RunManager::GetRunManager()->GetUserDetectorConstruction();

	frun=(RunAction*)G4RunManager::GetRunManager()->GetUserRunAction();

	G4int CopyNum;


	if ((track->GetDynamicParticle()->GetDefinition()==G4Alpha::AlphaDefinition()) &&
			(track->GetTouchableHandle()->GetVolume()->GetLogicalVolume()->GetName()
					==fdetector->GetVolume()->GetName()))
	{

		CopyNum = track->GetTouchableHandle()->GetVolume()->GetCopyNo();

		G4cout << " Volumen " << CopyNum << G4endl;

		frun->AddParticle(CopyNum);

	};

}
