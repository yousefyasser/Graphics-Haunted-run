#include "include/spawnables/key.h"

void Key::load() {
    model.Load("Models/key/key.3ds");
}

void Key::update(float dt) {}

void Key::render() const {
    glPushMatrix();
    model.Draw();
    glPopMatrix();
}
