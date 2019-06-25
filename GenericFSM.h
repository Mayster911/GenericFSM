#ifndef GENERICFSM_H
#define GENERICFSM_H

namespace GenericFSM
{
    class State
    {
        public:
            State();
            bool operator ==(const State &b) const;
            bool operator !=(const State &b) const;
        protected:
        private:
    };

    class Event
    {
        public:
            Event();
            bool operator ==(const Event &b) const;
            bool operator !=(const Event &b) const;
        protected:
        private:
    };

    class Transition
    {
        public:
            Transition(State* from, Event* on, State* to);
            State* GetFrom()     { return From; }
            Event* GetOn()       { return On; }
            State* GetTo()       { return To; }
        protected:
        private:
            State* From;
            Event* On;
            State* To;
    };

    class FSM
    {
        public:
            FSM(State* startState);
            unsigned int GetCountOfTransitions() { return CountOfTransitions; }
            GenericFSM::State* GetCurrentState() { return CurrentState; }
            void AddTransition(State* from, Event* on, State* to);
            void RaiseEvent(Event* event);
        protected:
        private:
            unsigned int            CountOfTransitions;
            GenericFSM::State*       			CurrentState;
            GenericFSM::Transition**           	Transitions;
    };
}

#endif // GENERICFSM_H
