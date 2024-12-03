#include "include/gameobject.h"

class Player : public GameObject {
public:
  // Inherit constructors from GameObject
  using GameObject::GameObject;

  // Initialize bounding box after construction
  Player(const Vector3f &initialPosition) : GameObject(initialPosition) {
    boundingBox = calculateBoundingBox();
  }

  BoundingBox calculateBoundingBox() override {
    // Define player's bounding box based on its dimensions
    return BoundingBox(
        Vector3f(position.x - 0.05, position.y, position.z - 0.05),
        Vector3f(position.x + 0.05, position.y + 0.2, position.z + 0.05));
  }
};