#include <stdlib.h>
#include "GenericFSM.h"

GenericFSM::FSM::FSM(State* startState)
{
	CurrentState = startState;
}

void GenericFSM::FSM::AddTransition(State* from, Event* on, State* to)
{
    if (CountOfTransitions == 0)
    {
        Transitions = (Transition**)malloc(sizeof(Transition*) * 1);
        if (Transitions != NULL)
        {
            CountOfTransitions++;
            Transitions[0] = new Transition(from, on, to);
        }
    }
    else
    {
        Transition** tmp = (Transition**)realloc(Transitions, sizeof(Transition*) * (CountOfTransitions + 1));
        if (tmp != NULL)
        {
            Transitions = tmp;
            CountOfTransitions++;
            Transitions[CountOfTransitions - 1] = new Transition(from, on, to);
        }
    }
}

void GenericFSM::FSM::RaiseEvent(Event* event)
{
    for (unsigned int i=0; i<CountOfTransitions; i++)
    {
        GenericFSM::Transition* t = Transitions[i];
        GenericFSM::State* fromState = t->GetFrom();
        GenericFSM::Event* onEvent   = t->GetOn();
        GenericFSM::State* current = CurrentState;
        if (fromState == current && onEvent == event)
        {
            CurrentState = t->GetTo();
            return;
        }
    }
}
