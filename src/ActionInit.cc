
#include "ActionInit.hh"

ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
    SetUserAction(new PrimaryGen());
    SetUserAction(new RunGen());

    EventAct* eventAction = new EventAct;
    SetUserAction(eventAction);}