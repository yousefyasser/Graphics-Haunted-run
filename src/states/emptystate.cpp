#include "include/states/emptystate.h"

EmptyState::EmptyState() : BaseState() {}
void EmptyState::render() const {}
void EmptyState::update(float dt) {}
void EmptyState::enter(const BaseParams& params) {}
void EmptyState::exit() {}