#include "include/states/emptystate.h"

EmptyState::EmptyState() : BaseState() {}
EmptyState::~EmptyState() {}
void EmptyState::render() const {
}
void EmptyState::update(float dt) {}
void EmptyState::enter(void *params) {}
void EmptyState::exit() {}