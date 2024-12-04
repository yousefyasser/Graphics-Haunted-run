#pragma once

#include "Model_3DS.h"
#include "gameobject.h"
#include <glut.h>

class Player : public GameObject
{
public:
  Model_3DS model_player;

  using GameObject::GameObject;

  Player(const Vector3f &initialPosition, const Vector3f &initialVelocity, const Vector3f &initialAngle);

  BoundingBox calculateBoundingBox() override;
  
  void update(float dt) override;
  void render() const override;
};