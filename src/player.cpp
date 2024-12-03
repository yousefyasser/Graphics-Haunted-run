#include "include/player.h"

// Initialize bounding box after construction
Player::Player(const Vector3f &initialPosition) : GameObject(initialPosition)
{
  boundingBox = calculateBoundingBox();
}

BoundingBox Player::calculateBoundingBox()
{
  // Define player's bounding box based on its dimensions
  return BoundingBox(
      Vector3f(position.x - 0.05, position.y, position.z - 0.05),
      Vector3f(position.x + 0.05, position.y + 0.2, position.z + 0.05));
}