#pragma once
#include "../State.h"
#include "Hello.h"

class HelloChildState : public State<Hello*>
{
public:
    static std::shared_ptr<HelloChildState> create();
    virtual void enter() override;
    virtual void update(float delta) override;
    virtual void exit() override;
    
private:
    int count = 0;
};
