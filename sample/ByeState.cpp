#include <string>

#include "ByeState.h"

std::shared_ptr<ByeState> ByeState::create()
{
    auto ret = std::make_shared<ByeState>();
    return ret;
}

void ByeState::enter()
{
    printf("   [ByeState] enter\n");
}

void ByeState::update(float delta)
{
    count++;
    printf("   [ByeState] update %d\n", count);
    if (count == 2) {
        owner->printPing("ByeState");
        stateMachine->popState();
    }
}

void ByeState::exit()
{
    printf("   [ByeState] exit\n");
}