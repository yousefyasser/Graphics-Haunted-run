#pragma once

#include "boundingBox.h"
#include "vector3f.h"

class GameObject {
public:
  Vector3f position;
  Vector3f angle;
  BoundingBox boundingBox;

  GameObject();
  GameObject(const Vector3f &initialPosition);
  GameObject(const Vector3f &initialPosition, const Vector3f &initialAngle);

  void setPosition(const Vector3f &newPosition);
  Vector3f getPosition();
  void print();
  virtual BoundingBox calculateBoundingBox() = 0;
  virtual bool checkCollision(const GameObject *other);
  virtual void update(float dt) = 0;
  virtual void render() const = 0;
};
