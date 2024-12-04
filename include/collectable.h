#pragma once

#include "Model_3DS.h"
#include "gameobject.h"
#include <glut.h>
#include <glut.h>

class Collectable : public GameObject {
public:
  Model_3DS model_collectable; // 3D model of the collectable

  using GameObject::GameObject;

  Collectable(const Vector3f &initialPosition, const Vector3f &initialAngle);

  BoundingBox calculateBoundingBox() override;

  void update(float dt) override;
  void render() const override;
};
