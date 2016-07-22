#pragma once
#include <vector>

template <class T> class State;
template<class T>
class StateMachine
{
    typedef T type;
public:
    static std::shared_ptr<StateMachine<T>> create(T owner);
    void update(float delta);
    void changeState(std::shared_ptr<State<T>> state);
    void pushState(std::shared_ptr<State<T>> state);
    void popState();
    bool isEmpty();
    T owner;
    
protected:
    std::vector<std::shared_ptr<State<T>>> _stack;
    std::shared_ptr<State<T>> _current = nullptr;
    std::shared_ptr<State<T>> _previous = nullptr;
};
#include "StateMachinePrivate.h"
