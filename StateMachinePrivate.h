#ifndef StateMachinePrivate_h
#define StateMachinePrivate_h

template<typename T> std::shared_ptr<StateMachine<T>> StateMachine<T>::create(T owner)
{
    auto ret = std::make_shared<StateMachine>();
    ret->owner = owner;
    return ret;
}

template<typename T> void StateMachine<T>::update(float delta)
{
    if (_current != nullptr) {
        _current->update(delta);
    }
}

template<typename T> void StateMachine<T>::changeState(std::shared_ptr<State<T>> state)
{
    printf("\n[StateMachine] change\n");
    _previous = _current;
    if (_previous != nullptr) {
        _previous->exit();
        _previous = nullptr;
    }
    _current = state;
    _current->setStateMachine(this);
    _current->setOwner(owner);
    _current->enter();
}

template<typename T> void StateMachine<T>::pushState(std::shared_ptr<State<T>> state)
{
    printf("\n[StateMachine] push\n");
    if (_current != nullptr) {
        _stack.push_back(_current);
    }
    _current = state;
    _current->setStateMachine(this);
    _current->setOwner(owner);
    _current->enter();
}

template<typename T> void StateMachine<T>::popState()
{
    printf("\n[StateMachine] pop\n");
    _previous = _current;
    if (_previous != nullptr) {
        _previous->exit();
        _previous = nullptr;
    }
    
    if (!_stack.empty()) {
        auto next = _stack.back();
        _current = next;
        _stack.pop_back();
    } else {
        _current = nullptr;    
    }
}
template<typename T> bool StateMachine<T>::isEmpty()
{
    if (_stack.empty() && _current == nullptr) {
        return true;
    }
    return false;
}

#endif
