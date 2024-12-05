#pragma once

#include "vector3f.h"
#include "stdlib.h"
#include <glut.h>

enum class CameraMode{
    FIRST_PERSON, THIRD_PERSON, FREE_MODE
};

class Camera
{
public:
    CameraMode cameraMode = CameraMode::THIRD_PERSON;
    Vector3f eye, center, up;
    GLdouble fovy, aspectRatio, zNear, zFar;

public:
    Camera(float eyeX = 1.0f, float eyeY = 1.0f, float eyeZ = 1.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f);

    void setup() const;
    void moveX(float d);
    void moveY(float d);
    void moveZ(float d);
    void rotateX(float a);
    void rotateY(float a);
    void rotateZ(float a);
    void setFirstPersonView(const Vector3f &characterPosition, const Vector3f &characterDirection);
    void setThirdPersonView(const Vector3f &characterPosition, const Vector3f &characterDirection, float distance, float height);
    void look() const;

    Vector3f getRelativeCharacterPosition(Vector3f characterPosition);
    Vector3f getRelativeCharacterDir(Vector3f characterAngle);

    void update(float dt, Vector3f playerPosition, Vector3f playerAngle);
    void Camera::toggleCameraMode();
    void Camera::toggleCameraFreeMode();
};