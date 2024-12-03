#pragma once

#include <unordered_map>
#include <functional>
#include <string>
#include <memory>

#include "states/basestate.h"
#include "states/emptystate.h"

enum class StateType
{
    Empty,
    StartMenu,
    Scene1,
    Scene2,
    GameOverMenu,
};

class StateMachine
{
public:
    StateMachine(std::unordered_map<StateType, std::function<std::unique_ptr<BaseState>()>> states);
    void change(StateType stateName, void *enterParams);
    void update(float dt);
    void render() const;
    StateType getCurrentStateType() const; 

private:
    StateType currentStateType;
    std::unique_ptr<BaseState> current;
    std::unordered_map<StateType, std::function<std::unique_ptr<BaseState>()>> states;
};