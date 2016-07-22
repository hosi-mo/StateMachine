#pragma once
#include "StateMachine.h"

template <class T> class State
{
public:
    virtual void enter();
    virtual void update(float delta);
    virtual void exit();
    void setStateMachine(StateMachine<T>* s);
    void setOwner(T s);
    StateMachine<T>* stateMachine;
    T owner;
};

#include "StatePrivate.h"