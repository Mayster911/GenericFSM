#include "GenericFSM.h"

GenericFSM::Transition::Transition(State* from, Event* on, State* to)
{
    From = from;
    On = on;
    To = to;
}
