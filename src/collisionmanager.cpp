#include "include/collisionmanager.h"

bool CollisionManager::checkCollision(GameObject &obj1, GameObject &obj2)
{
  obj1.boundingBox = obj1.calculateBoundingBox();
  obj2.boundingBox = obj2.calculateBoundingBox();
  return obj1.checkCollision(obj2);
}
