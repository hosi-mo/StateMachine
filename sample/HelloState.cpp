#include "HelloState.h"
#include "HelloChildState.h"
#include "ByeState.h"

std::shared_ptr<HelloState> HelloState::create()
{
    auto ret = std::make_shared<HelloState>();
    return ret;
}

void HelloState::enter()
{
    printf("   [HelloState] enter\n");
}

void HelloState::update(float delta)
{
    count++;
    printf("   [HelloState] update %d\n", count);
    if (count == 2) {
        stateMachine->pushState(HelloChildState::create());
    }
    if (4 <= count) {
        stateMachine->changeState(ByeState::create());
    }
}

void HelloState::exit()
{
    printf("   [HelloState] exit\n");
}