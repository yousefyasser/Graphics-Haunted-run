#include "include/tilemanager.h"
#include <glut.h>

TileManager::TileManager(float tileWidth, float tileHeight, int rows, int cols, float startX, float startZ, float speed)
	: tileWidth(tileWidth), tileHeight(tileHeight), rows(rows), cols(cols), startX(startX), startZ(startZ),
	  SPEED(speed), START_X(startX), START_Z(startZ)
{
	groundMap.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		groundMap[i].resize(cols);
		for (int j = 0; j < cols; j++)
		{
			groundMap[i][j] = true;
		}
	}
}

void TileManager::load()
{
	texture.Load("Textures/ground.bmp");
}

void TileManager::update(float dt)
{
	startZ -= SPEED * dt;
	if(startZ <= START_Z - tileHeight)
	{
		startZ = START_Z;
		generateRow();
	}
}

void TileManager::generateRow()
{
	groundMap.erase(groundMap.begin());
	groundMap.emplace_back(cols, true);
	if (rand() % 100 < 90)
	{
		int hole = rand() % cols;
		groundMap[rows - 1][hole] = false;
	}
}

void TileManager::render() const
{
	float x = startX;
	float z = startZ;
	for (auto row : groundMap)
	{
		for (auto tile : row)
		{
			if (tile)
			{
				renderTile(x, z);
			}
			x += tileWidth;
		}
		z += tileHeight;
		x = startX;
	}
}

void TileManager::renderTile(float x, float z) const
{
	glDisable(GL_LIGHTING);

	glColor3f(0.6, 0.6, 0.6);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.texture[0]);

	glPushMatrix();
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

	glEnable(GL_LIGHTING);

	glColor3f(1, 1, 1);
}

bool TileManager::getTile(int row, int col) const
{
	return groundMap[row][col];
}

bool TileManager::isHole(float x, float z) const
{
	int col = (x - startX) / tileWidth;
	int row = (z - startZ) / tileHeight;
	if (row < 0 || row >= rows || col < 0 || col >= cols)
	{
		return false;
	}
	return !groundMap[row][col];
}