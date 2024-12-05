#pragma once

#include "../gameobject.h"

class Spawnable: public GameObject {
public:
  using GameObject::GameObject;

  const float SPAWN_RATE = 0.2f;
};
