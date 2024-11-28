#include "include/states/emptystate.h"

EmptyState::EmptyState() : BaseState() {}
void EmptyState::render() {}
void EmptyState::update(float dt) {}
void EmptyState::enter(void *params) {}
void EmptyState::exit() {}