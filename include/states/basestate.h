#pragma once

class BaseState {
public:
    BaseState();
    virtual ~BaseState();
    virtual void enter(void* params) = 0;
    virtual void exit() = 0;
    virtual void update(float dt) = 0;
    virtual void render() const = 0;
};