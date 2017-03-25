

#ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "Run.hh"

class EventAct : public G4UserEventAction
{
public:
    EventAct();
    ~EventAct();
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
private:

};

#endif //CPROJECT_EVENTACT_HH
