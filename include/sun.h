#pragma once

#include <array>
#include <glut.h>

class Sun
{
private:
    float angle;
    GLenum light;
    std::array<GLfloat, 4> ambient;
    std::array<GLfloat, 4> diffuse;
    std::array<GLfloat, 4> specular;
    std::array<GLfloat, 4> position;
    const std::array<GLfloat, 3> INITIAL_POSITION;

public:
    Sun(GLenum light,
        float positionX = 0.0f,
        float positionY = 0.0f,
        float positionZ = 0.0f);
    void setup();
    void render() const;
    void update(float dt);
};