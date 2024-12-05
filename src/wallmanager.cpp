#include "include/wallmanager.h"
#include <glut.h>

void WallManager::renderTile(float z, float y) const
{
	glDisable(GL_LIGHTING);

	glColor3f(0.627, 0.125, 0.941);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.texture[0]);

	glPushMatrix();
	glTranslatef(constantAxis, 0, 0);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, y, z);
	glTexCoord2f(1, 0);
	glVertex3f(0, y + tileWidth, z);
	glTexCoord2f(1, 1);
	glVertex3f(0, y + tileWidth, z + tileHeight);
	glTexCoord2f(0, 1);
	glVertex3f(0, y, z + tileHeight);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);

	glColor3f(1, 1, 1);
}