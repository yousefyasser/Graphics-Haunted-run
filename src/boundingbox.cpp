#include "include/boundingbox.h"

#include <iostream>
#include <glut.h>

BoundingBox::BoundingBox() {}

BoundingBox::BoundingBox(const Vector3f &minPoint, const Vector3f &maxPoint) {
  this->min = minPoint;
  this->max = maxPoint;
}

bool BoundingBox::intersects(const BoundingBox &other) const {

  bool ret = (min.x <= other.max.x && max.x >= other.min.x) &&
          (min.y <= other.max.y && max.y >= other.min.y) &&
          (min.z <= other.max.z && max.z >= other.min.z);

  return ret;
}

void BoundingBox::expandBy(float x, float y, float z) {
  min.x -= x;
  min.y -= y;
  min.z -= z;
  max.x += x;
  max.y += y;
  max.z += z;
}

void BoundingBox::render() const {
  glBegin(GL_LINES);

  // Draw lines for the edges of the bounding box
  glVertex3f(min.x, min.y, min.z); glVertex3f(max.x, min.y, min.z);
  glVertex3f(min.x, min.y, min.z); glVertex3f(min.x, max.y, min.z);
  glVertex3f(min.x, min.y, min.z); glVertex3f(min.x, min.y, max.z);

  glVertex3f(max.x, max.y, max.z); glVertex3f(min.x, max.y, max.z);
  glVertex3f(max.x, max.y, max.z); glVertex3f(max.x, min.y, max.z);
  glVertex3f(max.x, max.y, max.z); glVertex3f(max.x, max.y, min.z);

  glVertex3f(min.x, max.y, min.z); glVertex3f(max.x, max.y, min.z);
  glVertex3f(min.x, max.y, min.z); glVertex3f(min.x, max.y, max.z);

  glVertex3f(max.x, min.y, min.z); glVertex3f(max.x, max.y, min.z);
  glVertex3f(max.x, min.y, min.z); glVertex3f(max.x, min.y, max.z);

  glVertex3f(min.x, min.y, max.z); glVertex3f(max.x, min.y, max.z);
  glVertex3f(min.x, min.y, max.z); glVertex3f(min.x, max.y, max.z);

  glEnd();
}

void BoundingBox::print() {
  printf("Min: (%f, %f, %f)\n", min.x, min.y, min.z);
  printf("Max: (%f, %f, %f)\n", max.x, max.y, max.z);
}