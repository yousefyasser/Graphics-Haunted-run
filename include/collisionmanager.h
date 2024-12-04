#pragma once

#include "gameobject.h"

class CollisionManager
{
public:
  static bool checkCollision(const GameObject &obj1, const GameObject &obj2);
};
