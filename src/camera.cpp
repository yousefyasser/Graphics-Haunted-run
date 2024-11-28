#include "include/vector3f.h"
#include "include/camera.h"

#include <cmath>
#include <glut.h>

Camera::Camera(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) : eye(eyeX, eyeY, eyeZ), center(centerX, centerY, centerZ), up(upX, upY, upZ) {}

Camera::~Camera() {}

void Camera::moveX(float d)
{
    Vector3f right = up.cross(center - eye).unit();
    eye = eye + right * d;
    center = center + right * d;
}

void Camera::moveY(float d)
{
    eye = eye + up.unit() * d;
    center = center + up.unit() * d;
}

void Camera::moveZ(float d)
{
    Vector3f view = (center - eye).unit();
    eye = eye + view * d;
    center = center + view * d;
}

void Camera::rotateX(float a)
{
    Vector3f view = (center - eye).unit();
    Vector3f right = up.cross(view).unit();
    view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
    up = view.cross(right);
    center = eye + view;
}

void Camera::rotateY(float a)
{
    Vector3f view = (center - eye).unit();
    Vector3f right = up.cross(view).unit();
    view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
    right = view.cross(up);
    center = eye + view;
}

void Camera::rotateZ(float a)
{
    Vector3f view = (center - eye).unit();
    float cosA = cos(DEG2RAD(a));
    float sinA = sin(DEG2RAD(a));
    up = up * cosA + view.cross(up) * sinA + view * (view.dot(up) * (1 - cosA));
    center = eye + view;
}

void Camera::look()
{
    gluLookAt(
        eye.x, eye.y, eye.z,
        center.x, center.y, center.z,
        up.x, up.y, up.z);
}