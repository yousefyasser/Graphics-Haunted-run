#include <cmath>

#include "include/sun.h"
#include "include/util.h"

Sun::Sun(GLenum light, float positionX, float positionY, float positionZ)
{
    this->angle = 0.0f;
    this->light = light;
    this->ambient = {1.0f, 1.0f, 1.0f, 1.0f};
    this->diffuse = {1.0f, 1.0f, 1.0f, 1.0f};
    this->specular = {1.0f, 1.0f, 1.0f, 1.0f};
    this->position = {positionX, positionY, positionZ, 1.0f};
}

void Sun::setup()
{
    glEnable(light);
    glLightfv(light, GL_AMBIENT, ambient.data());
    glLightfv(light, GL_DIFFUSE, diffuse.data());
    glLightfv(light, GL_SPECULAR, specular.data());
    glLightfv(light, GL_POSITION, position.data());
}

void Sun::render() const
{
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 0);
    glTranslatef(position[0], position[1], position[2]);
    glutSolidSphere(1, 100, 100);
    glEnable(GL_LIGHTING);
    glColor3f(1, 1, 1);
    glPopMatrix();
}

void Sun::update(float dt)
{
    angle += dt;

    position[0] = 10.0f * cos(angle);
    position[1] = 10.0f * sin(angle);

    float intensity = (sin(angle) + 1.0f) / 2.0f;
    ambient = {intensity, intensity, intensity, 1.0f};
    diffuse = {intensity, intensity, intensity, 1.0f};
    specular = {intensity, intensity, intensity, 1.0f};

    setup();
}