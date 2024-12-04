#include "include/collectable.h"

Collectable::Collectable(const Vector3f &initialPosition,
                         const Vector3f &initialAngle)
    : GameObject(initialPosition, initialAngle) {
  boundingBox = calculateBoundingBox();
}

BoundingBox Collectable::calculateBoundingBox() {
  BoundingBox bb;
  bb.min = Vector3f(-0.5f, -0.5f, -0.5f); // TODO: update according to model
  bb.max = Vector3f(0.5f, 0.5f, 0.5f);    // TODO: update according to model
  return bb;
}

void Collectable::update(float dt) {
  // Rotate the collectable
  angle.y += 90.0f * dt;
}

void Collectable::render() const {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glRotatef(angle.y, 0, 1, 0);
  model_collectable.Draw();
  glPopMatrix();
}
