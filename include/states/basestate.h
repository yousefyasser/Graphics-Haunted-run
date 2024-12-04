#pragma once

#include <memory>

class BaseState {
public:
    struct BaseParams {
        virtual ~BaseParams() = default;
    };

public:
    BaseState();
    virtual ~BaseState() = default;
    virtual void enter(const BaseParams& params) = 0;
    virtual void exit() = 0;
    virtual void update(float dt) = 0;
    virtual void render() const = 0;
};