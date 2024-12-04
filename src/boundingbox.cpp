#include "include/boundingbox.h"

BoundingBox::BoundingBox() {}

BoundingBox::BoundingBox(const Vector3f &minPoint, const Vector3f &maxPoint) {
  this->min = minPoint;
  this->max = maxPoint;
}

bool BoundingBox::intersects(const BoundingBox &other) const {
  return (min.x <= other.max.x && max.x >= other.min.x) &&
          (min.y <= other.max.y && max.y >= other.min.y) &&
          (min.z <= other.max.z && max.z >= other.min.z);
}

void BoundingBox::expandBy(float x, float y, float z) {
  min.x -= x;
  min.y -= y;
  min.z -= z;
  max.x += x;
  max.y += y;
  max.z += z;
}

void BoundingBox::print() {
  printf("Min: (%f, %f, %f)\n", min.x, min.y, min.z);
  printf("Max: (%f, %f, %f)\n", max.x, max.y, max.z);
}