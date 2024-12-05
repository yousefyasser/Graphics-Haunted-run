#include "include/spawnables/collectable.h"

void Collectable::load() {
    model.Load("Models/key/key.3ds");
}

void Collectable::update(float dt) {
  angle.y += 90.0f * dt;
  position += velocity * dt;
}

void Collectable::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(0.5f, 0.5f, 0.5f);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}

void Collectable::spawn(std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed)
{
  Vector3f pos(0, 3, 100), vel(0, 0, -groundSpeed), angle(0, 0, 0);

  auto newCollectable = std::make_unique<Collectable>(pos, vel, angle);
  newCollectable->load();
  collectables.push_back(std::move(newCollectable));
}