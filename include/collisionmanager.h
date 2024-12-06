#pragma once

#include "gameobject.h"

class CollisionManager
{
public:
  static bool checkCollision(GameObject &obj1, GameObject &obj2);
};
