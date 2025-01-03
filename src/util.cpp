#include <cmath>
#include <glut.h>

#include "include/util.h"

float util::DEG2RAD(float a) { return a * 0.017453292; }

void util::setupLights()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);
}

void util::setupMaterials()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);

	// Sich will be assigneet Material Properties whd by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// Set Material's Shine value (0->128)
	GLfloat shininess[] = {96.0f};
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
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

void util::drawText(float x, float y, float z, std::string text)
{
	util::drawText(x, y, z, text.c_str());
}

void util::drawText(float x, float y, std::string text)
{
	util::drawText(x, y, text.c_str());
}

template<typename Base, typename T>
inline bool util::instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}