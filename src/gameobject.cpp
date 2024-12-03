#include "include/gameobject.h"

GameObject::GameObject() { this->position = Vector3f(); }

// Constructor with position
GameObject::GameObject(const Vector3f &initialPosition) {
  this->position = initialPosition;
  // boundingBox = calculateBoundingBox(); // I cant call a virtual function
  // here gotta call it down
}

// set position
void GameObject::setPosition(const Vector3f &newPosition) {
  this->position = newPosition;
  boundingBox = calculateBoundingBox();
}

// get position
Vector3f GameObject::getPosition() { return position; }

// print GameObject
void GameObject::print() {
  printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
  boundingBox.print();
}

// Check collision with another object
bool GameObject::checkCollision(const GameObject *other) {
  return boundingBox.intersects(other->boundingBox);
}