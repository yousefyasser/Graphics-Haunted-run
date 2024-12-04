#pragma once

#include "basestate.h"

class EmptyState: public BaseState
{
public:
    EmptyState();
    virtual void render() const override;
    virtual void update(float dt) override;
    virtual void enter(const BaseParams& params) override;
    virtual void exit() override;
};