
#include "EventAct.hh"

EventAct::EventAct()
{
    G4cout<<"Event generator is created successfully\t\t\t\t\tOK!!!"<<G4endl;
}

EventAct::~EventAct()
{ G4cout<<G4endl;}

void EventAct::BeginOfEventAction(const G4Event *event)
{ }

void EventAct::EndOfEventAction(const G4Event *event)
{
    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
}