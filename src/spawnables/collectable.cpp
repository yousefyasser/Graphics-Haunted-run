#include "include/spawnables/collectable.h"

void Collectable::load() {}

void Collectable::update(float dt) {
  Spawnable::update(dt);
  angle.y += 90.0f * dt;
}

void Collectable::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(1.0f, 0.5f, 0.5f);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}