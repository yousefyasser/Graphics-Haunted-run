#include "include/spawnables/collectable.h"

void Collectable::load() {}

void Collectable::update(float dt) {
  Spawnable::update(dt);
  angle.y += 90.0f * dt;
}

void Collectable::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(scale[0], scale[1], scale[2]);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}