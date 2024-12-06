#include "include/gameobject.h"

GameObject::GameObject() {}

GameObject::GameObject(const Vector3f &initialPosition, const Vector3f &initialVelocity, const Vector3f &initialAngle)
    : position(initialPosition), velocity(initialVelocity), angle(initialAngle) {
      boundingBox = calculateBoundingBox();
    }

GameObject::GameObject(const Vector3f &initialPosition)
    : position(initialPosition) {
      boundingBox = calculateBoundingBox();
    }

GameObject::GameObject(const Vector3f &initialPosition,
                       const Vector3f &initialAngle)
    : position(initialPosition), angle(initialAngle) {
      boundingBox = calculateBoundingBox();
    }

BoundingBox GameObject::calculateBoundingBox()
{
  return BoundingBox(
      Vector3f(position.x - 1, position.y - 5, position.z - 0.05f),
      Vector3f(position.x + 1, position.y + 5, position.z + 0.05f));
}

void GameObject::setModel(const Model_3DS &newModel){
  this->model = newModel;
}

void GameObject::setPosition(const Vector3f &newPosition)
{
  this->position = newPosition;
  boundingBox = calculateBoundingBox();
}

Vector3f GameObject::getPosition() { return position; }

void GameObject::print()
{
  printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
  boundingBox.print();
}

bool GameObject::checkCollision(const GameObject &other) const
{
  return boundingBox.intersects(other.boundingBox);
}
