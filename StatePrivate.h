#ifndef StatePrivate_h
#define StatePrivate_h

template<typename T>
void State<T>::enter()
{
}

template<typename T>
void State<T>::update(float delta)
{
}

template<typename T>
void State<T>::exit()
{
}

template<typename T>
void State<T>::setStateMachine(StateMachine<T>* s)
{
    stateMachine = s;
}

template<typename T>
void State<T>::setOwner(T s)
{
    owner = s;
}

#endif