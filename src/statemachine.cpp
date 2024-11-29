#include <cassert>

#include "include/statemachine.h"

StateMachine::StateMachine(std::unordered_map<std::string, std::function<std::unique_ptr<BaseState>()>> states)
    : states(states), current(std::make_unique<EmptyState>()) {}

void StateMachine::change(std::string stateName, void *enterParams)
{
    assert(states.find(stateName) != states.end());
    current->exit();
    current = states[stateName]();
    current->enter(enterParams);
}

void StateMachine::update(float dt)
{
    current->update(dt);
}

void StateMachine::render() const
{
    current->render();
}