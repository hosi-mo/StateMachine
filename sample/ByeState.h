#pragma once
#include "../State.h"
#include "Hello.h"

class ByeState : public State<Hello*>
{
public:
    static std::shared_ptr<ByeState> create();
    virtual void enter() override;
    virtual void update(float delta) override;
    virtual void exit() override;
    
private:
    int count = 0;
};
