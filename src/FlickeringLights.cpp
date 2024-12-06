#include "include/FlickeringLights.h"
#include <cstdlib>
#include <ctime>

FlickeringLights::FlickeringLights(GLenum light, float positionX, float positionY, float positionZ)
{
    this->duration = 0.0f;
    this->light = light;
    this->ambient = {1.0f, 1.0f, 1.0f, 1.0f};
    this->diffuse = {1.0f, 1.0f, 1.0f, 1.0f};
    this->specular = {1.0f, 1.0f, 1.0f, 1.0f};
    this->position = {positionX, positionY, positionZ, 1.0f};
}

void FlickeringLights::setup() {
    glEnable(light);
    glLightfv(light, GL_AMBIENT, ambient.data());
    glLightfv(light, GL_DIFFUSE, diffuse.data());
    glLightfv(light, GL_SPECULAR, specular.data());
    glLightfv(light, GL_POSITION, position.data());
}

void FlickeringLights::update(float dt) {
    duration += dt;
    if (duration < 0.5)
        return;
    duration = 0;
    float intensity = (std::rand() % 100) / 200.0f;
    this->ambient = {intensity, intensity, intensity, 1.0f};
    this->diffuse = {intensity, intensity, intensity, 1.0f};
    this->specular = {intensity, intensity, intensity, 1.0f};

    setup();
}

void FlickeringLights::render() const {
    glPushMatrix();
    glTranslatef(position[0], position[1], position[2]);
    glColor3f(1.0f, ambient[1], ambient[2]);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();
}