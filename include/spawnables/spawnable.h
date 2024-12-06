#pragma once

#include "../gameobject.h"

class Spawnable: public GameObject {
public:
  using GameObject::GameObject;

  void update(float dt) override;
};
