#pragma once

#include "gameobject.h"
#include <glut.h>

class Player : public GameObject
{
public:
  using GameObject::GameObject;

  Player(const Vector3f &initialPosition, const Vector3f &initialVelocity, const Vector3f &initialAngle);
  
  void update(float dt) override;
  void render() const override;
  void load() override;
};