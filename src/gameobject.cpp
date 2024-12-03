#include "include/vector3f.h"
#include "include/boundingbox.h"

class GameObject {
public:
  Vector3f position;
  BoundingBox boundingBox;

  // Default constructor
  GameObject() { this->position = Vector3f(); }

  // Constructor with position
  GameObject(const Vector3f &initialPosition) {
    this->position = initialPosition;
    // boundingBox = calculateBoundingBox(); // I cant call a virtual function
    // here gotta call it down
  }

  // set position
  void setPosition(const Vector3f &newPosition) {
    this->position = newPosition;
    boundingBox = calculateBoundingBox();
  }

  // get position
  Vector3f getPosition() { return position; }

  // print GameObject
  void print() {
    printf("Position: (%f, %f, %f)\n", position.x, position.y, position.z);
    boundingBox.print();
  }

  // Pure virtual function to calculate bounding box
  virtual BoundingBox calculateBoundingBox() = 0;

  // Check collision with another object
  virtual bool checkCollision(const GameObject *other) {
    return boundingBox.intersects(other->boundingBox);
  }
};