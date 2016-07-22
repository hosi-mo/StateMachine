#include <string>

#include "../StateMachine.h"
#include "Hello.h"
#include "HelloState.h"

void Hello::start()
{
    auto stateMachine = StateMachine<Hello*>::create(this);
    stateMachine->pushState(HelloState::create());
    while (!stateMachine->isEmpty()) {
      stateMachine->update(0.f);
    }
}

void Hello::printPing(std::string ping)
{
    printf("\n---[Ping] from %s\n", ping.c_str());
}

int main()
{
  auto hello = new Hello();
  hello->start();
  delete hello;
}