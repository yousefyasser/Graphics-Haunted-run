#pragma once

#include "boundingBox.h"
#include "vector3f.h"
#include "Model_3DS.h"

class GameObject {
public:
  const float MAX_SPEED = 0.5f;

  Model_3DS model;
  Vector3f velocity;
  Vector3f position;
  Vector3f angle;
  BoundingBox boundingBox;

  GameObject();
  GameObject(const Vector3f &initialPosition, const Vector3f &initialVelocity, const Vector3f &initialAngle);
  GameObject(const Vector3f &initialPosition);
  GameObject(const Vector3f &initialPosition, const Vector3f &initialAngle);
  
  void setModel(const Model_3DS &model);
  void setPosition(const Vector3f &newPosition);
  Vector3f getPosition();
  void print();

  virtual void load() = 0;
  virtual BoundingBox calculateBoundingBox();
  virtual bool checkCollision(const GameObject &other) const;
  virtual void update(float dt) = 0;
  virtual void render() const = 0;
};
