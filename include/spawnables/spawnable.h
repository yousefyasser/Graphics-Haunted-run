#pragma once

#include "../gameobject.h"

class Spawnable: public GameObject {
public:
  using GameObject::GameObject;

  static void spawn();
};
