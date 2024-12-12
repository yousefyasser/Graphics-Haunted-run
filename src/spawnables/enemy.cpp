#include "include/spawnables/enemy.h"


void Enemy::update(float dt) {
  Spawnable::update(dt);
  scale += 0.1;

  if (scale > 6.5f) {
    scale = 5.0f;
  }
}

void Enemy::load() {}

void Enemy::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(scale, scale, scale);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}