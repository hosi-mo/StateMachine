#include <string>
#include "HelloChildState.h"

std::shared_ptr<HelloChildState> HelloChildState::create()
{
    auto ret = std::make_shared<HelloChildState>();
    return ret;
}

void HelloChildState::enter()
{
    printf("      [HelloChildState] enter\n");
}

void HelloChildState::update(float delta)
{
    count++;
    printf("      [HelloChildState] update %d\n", count);
    if (5 <= count) {
        owner->printPing("HelloChildState");
        stateMachine->popState();
    }
}

void HelloChildState::exit()
{
    printf("      [HelloChildState] exit\n");
}