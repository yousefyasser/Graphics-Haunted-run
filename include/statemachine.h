#pragma once

#include <unordered_map>
#include <functional>
#include <string>
#include <memory>

#include "states/basestate.h"
#include "states/emptystate.h"

class StateMachine
{
public:
    StateMachine(std::unordered_map<std::string, std::function<std::unique_ptr<BaseState>()>> states);
    ~StateMachine();
    void change(std::string stateName, void *enterParams);
    void update(float dt);
    void render() const;

private:
    std::unique_ptr<BaseState> current;
    std::unordered_map<std::string, std::function<std::unique_ptr<BaseState>()>> states;
};