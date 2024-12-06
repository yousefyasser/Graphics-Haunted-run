#pragma once

#include "vector3f.h"
#include <stdio.h>

class BoundingBox {
public:
  Vector3f min;
  Vector3f max;

  BoundingBox();
  BoundingBox(const Vector3f &minPoint, const Vector3f &maxPoint);

  void render() const;
  bool intersects(const BoundingBox &other) const;
  void expandBy(float x, float y, float z);
  void print();
};