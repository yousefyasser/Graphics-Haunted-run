#include "include/collisionmanager.h"

bool CollisionManager::checkCollision(const GameObject &obj1, const GameObject &obj2)
{
  return obj1.checkCollision(obj2);
}
