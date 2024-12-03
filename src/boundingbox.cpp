#include "include/vector3f.h"
#include <stdio.h>

// class to define bounding box
class BoundingBox {
public:
  Vector3f min; // Minimum point of the box
  Vector3f max; // Maximum point of the box

  // default constructor
  BoundingBox() {}

  // constructor with min and max points
  BoundingBox(const Vector3f &minPoint, const Vector3f &maxPoint) {
    this->min = minPoint;
    this->max = maxPoint;
  }

  // Check if this bounding box intersects with another
  bool intersects(const BoundingBox &other) const {
    return (min.x <= other.max.x && max.x >= other.min.x) &&
           (min.y <= other.max.y && max.y >= other.min.y) &&
           (min.z <= other.max.z && max.z >= other.min.z);
  }

  // Expand bounding box by a specific object's dimensions
  void expandBy(float x, float y, float z) {
    min.x -= x;
    min.y -= y;
    min.z -= z;
    max.x += x;
    max.y += y;
    max.z += z;
  }

  // print the bounding box
  void print() {
    printf("Min: (%f, %f, %f)\n", min.x, min.y, min.z);
    printf("Max: (%f, %f, %f)\n", max.x, max.y, max.z);
  }
};