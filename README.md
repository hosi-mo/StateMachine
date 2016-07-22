Simple State Machine
====

A simple State Machine using C++11. Easy to Access parent class.

## A Quick Look
```
void Hello::start()
{
    auto stateMachine = StateMachine<Hello*>::create(this);
    stateMachine->pushState(std::make_shared<HelloState>());
    while (!stateMachine->isEmpty()) {
        stateMachine->update(0.f);
    }
}

void Hello::printPing()
{
    printf("Ping");
}
```

```
void Hello::start()
{
    auto stateMachine = StateMachine<Hello*>::create(this);
    stateMachine->pushState(HelloState::create());
    while (!stateMachine->isEmpty()) {
        stateMachine->update(0.f);
    }
}

void Hello::printPing()
{
    printf("Ping");
}

void HelloState::enter()
{
    owner->printPing();
}

void HelloState::update(float delta)
{
    stateMachine->changeState(ByeState::create());
}

void HelloState::exit()
{
}
```

## Demo
```
[StateMachine] push
[HelloState] enter
[HelloState] update 1
[HelloState] update 2

[StateMachine] push
[HelloChildState] enter
[HelloChildState] update 1
[HelloChildState] update 2
[HelloChildState] update 3
[HelloChildState] update 4
[HelloChildState] update 5

---[Ping] from HelloChildState

[StateMachine] pop
[HelloChildState] exit
[HelloState] update 3
[HelloState] update 4

[StateMachine] change
[HelloState] exit
[ByeState] enter
[ByeState] update 1
[ByeState] update 2

---[Ping] from ByeState

[StateMachine] pop
[ByeState] exit
```

## Licence

[MIT](https://github.com/hosi-mo/tool/blob/master/LICENCE)

## Author

[hosi-mo](http:://hosimo.net)