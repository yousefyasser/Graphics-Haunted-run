#include "include/collisionmanager.h"

bool CollisionManager::checkCollision(GameObject *obj1, GameObject *obj2)
{
  return obj1->checkCollision(obj2);
}
