#include "include/gameobject.h"

GameObject::GameObject() {}

GameObject::GameObject(const Vector3f &initialPosition)
    : position(initialPosition) {}

GameObject::GameObject(const Vector3f &initialPosition,
                       const Vector3f &initialAngle)
    : position(initialPosition), angle(initialAngle) {}

void GameObject::setPosition(const Vector3f &newPosition) {
  this->position = newPosition;
  boundingBox = calculateBoundingBox();
}

Vector3f GameObject::getPosition() { return position; }

void GameObject::print() {
  printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
  boundingBox.print();
}

bool GameObject::checkCollision(const GameObject *other) {
  return boundingBox.intersects(other->boundingBox);
}
