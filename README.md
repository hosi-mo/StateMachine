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
void HelloState::enter()
{
}

void HelloState::update(float delta)
{
    //stateMachine->pushState(ByeState::create()); //push
    //stateMachine->changeState(ByeState::create());//change
    //stateMachine->popState(); //pop 
}

void HelloState::exit()
{
}
```

```
void ByeState::enter()
{
    owner->printPing();//easy to access Parent
}

void ByeState::update(float delta)
{
}

void ByeState::exit()
{
}
```

## Demo
```
cd sample
g++ -std=c++11 hello.cpp HelloState.cpp HelloChildState.cpp ByeState.cpp -o main
./main
```

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

[MIT](https://github.com/hosi-mo/StateMachine/blob/master/LICENSE)

## Author

[hosi-mo](http://hosimo.net/about)