#pragma once

#include "vector3f.h"
#include "boundingBox.h"

class GameObject {
public:
    Vector3f position;
    Vector3f angle;
    BoundingBox boundingBox;

    GameObject();
    GameObject(const Vector3f &initialPosition);

    void setPosition(const Vector3f &newPosition);
    Vector3f getPosition();
    void print();
    virtual BoundingBox calculateBoundingBox() = 0;
    virtual bool checkCollision(const GameObject *other);
    virtual void update(float dt) = 0;
    virtual void render() = 0;
};