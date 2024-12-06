#include "include/spawnables/enemy.h"

void Enemy::load() {}

void Enemy::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(5.0f, 5.0f, 5.0f);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}