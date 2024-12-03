#pragma once

#include "gameobject.h"

class Player : public GameObject
{
public:
  using GameObject::GameObject;

  Player(const Vector3f &initialPosition);

  BoundingBox calculateBoundingBox() override;
};