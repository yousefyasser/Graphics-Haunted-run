#include "include/groundmanager.h"
#include <glut.h>

void GroundManager::updateMap()
{
	toggleUpdateMap = !toggleUpdateMap;

	tileMap.erase(tileMap.begin());
	tileMap.emplace_back(cols, true);

	if (toggleUpdateMap) return;

	if (rand() % 100 < 90)
	{
		int hole = rand() % cols;
		tileMap[rows - 2][hole] = false;
	}
}

void GroundManager::renderTile(float z, float x) const
{
	glColor3f(0.6, 0.6, 0.6);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.texture[0]);

	glPushMatrix();
	glTranslatef(0, constantAxis, 0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(x, 0, z);
	glTexCoord2f(1, 0);
	glVertex3f(x + tileWidth, 0, z);
	glTexCoord2f(1, 1);
	glVertex3f(x + tileWidth, 0, z + tileHeight);
	glTexCoord2f(0, 1);
	glVertex3f(x, 0, z + tileHeight);
	glEnd();
	glPopMatrix();

	glColor3f(1, 1, 1);
}

void GroundManager::renderHole(float z, float x) const
{
	glDisable(GL_LIGHTING);

	glColor3f(0.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, constantAxis, 0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(x, 0, z);
	glVertex3f(x + tileWidth, 0, z);
	glVertex3f(x + tileWidth, 0, z + tileHeight);
	glVertex3f(x, 0, z + tileHeight);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);

	glColor3f(1, 1, 1);
}

bool GroundManager::isHole(float x, float z) const
{
	int col = (x - startSecondaryAxis) / tileWidth;
	int row = (z - startMainAxis) / tileHeight;
	if (row < 0 || row >= rows || col < 0 || col >= cols)
	{
		return false;
	}
	return !tileMap[row][col];
}