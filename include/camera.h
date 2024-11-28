#pragma once

#include "vector3f.h"
#define DEG2RAD(a) (a * 0.0174532925)

class Camera {
public:
    Vector3f eye, center, up;
    Camera(float eyeX = 1.0f, float eyeY = 1.0f, float eyeZ = 1.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);
    void moveX(float d);
    void moveY(float d);
    void moveZ(float d);
    void rotateX(float a);
    void rotateY(float a);
    void rotateZ(float a);
    void look();
};