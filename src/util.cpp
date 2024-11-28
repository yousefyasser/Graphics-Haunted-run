#include <cmath>
#include <glut.h>

#include "include/util.h"

void util::setupLights()
{
    GLfloat ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {50};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat lightIntensity[] = {1.0f, 1.0f, 1, 1.0f};
    GLfloat lightPosition[] = {-5.0f, 2.0f, -3.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void util::setupCamera(int width, int height, Camera &camera)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, width / height, 0.001, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.look();
}

void util::drawText(float x, float y, float z, const char *text)
{
    glRasterPos3f(x, y, z);
    for (const char *c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void util::drawText(float x, float y, const char *text)
{
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void util::drawText(float x, float y, float z, std::string text) {
    util::drawText(x, y, z, text.c_str());
}

void util::drawText(float x, float y, std::string text) {
    util::drawText(x, y, text.c_str());
}