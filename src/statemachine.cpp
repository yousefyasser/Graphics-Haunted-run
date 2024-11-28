#include "include/statemachine.h"

StateMachine::StateMachine(std::unordered_map<std::string, std::function<std::unique_ptr<BaseState>()>> states)
    : states(states), empty(std::make_unique<EmptyState>()), current(empty.get()) {}

void StateMachine::change(std::string stateName, void* enterParams) {
    current->exit();
    current.reset(states[stateName]().release());
	current->enter(enterParams);
}

void StateMachine::update(float dt) {
    current->update(dt);
}

void StateMachine::render() {
    current->render();
}