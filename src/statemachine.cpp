#include <cassert>

#include "include/statemachine.h"

StateMachine::StateMachine(std::unordered_map<StateType, std::function<std::unique_ptr<BaseState>()>> states)
    : states(states), current(std::make_unique<EmptyState>()), currentStateType(StateType::Empty) {}

void StateMachine::change(StateType stateName, void *enterParams)
{
    assert(states.find(stateName) != states.end());
    current->exit();
    current = states[stateName]();
    currentStateType = stateName;
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

StateType StateMachine::getCurrentStateType() const
{
    return currentStateType;
}