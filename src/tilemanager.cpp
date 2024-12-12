#include "include/tilemanager.h"
#include <glut.h>

TileManager::TileManager(float tileWidth, float tileHeight, int rows, int cols,
						 float startMainAxis, float startSecondaryAxis, float constantAxis,
						 float speed, char *texturePath)
	: tileWidth(tileWidth), tileHeight(tileHeight), rows(rows), cols(cols),
	  startMainAxis(startMainAxis), startSecondaryAxis(startSecondaryAxis), constantAxis(constantAxis),
	  tileMap(rows, std::vector<bool>(cols, true)),
	  SPEED(speed), START_MAIN_AXIS(startMainAxis), START_SECONDARY_AXIS(startSecondaryAxis),
	  TEXTURE_PATH(texturePath) {}

void TileManager::load()
{
	texture.Load(const_cast<char *>(TEXTURE_PATH));
}

void TileManager::render() const
{
	float mainAxis = startMainAxis;
	float secondaryAxis = startSecondaryAxis;
	for (auto row : tileMap)
	{
		for (auto tile : row)
		{
			if (tile)
			{
				renderTile(mainAxis, secondaryAxis);
			} else {
				renderHole(mainAxis, secondaryAxis);
			}
			secondaryAxis += tileWidth;
		}
		mainAxis += tileHeight;
		secondaryAxis = startSecondaryAxis;
	}
}

void TileManager::update(float dt)
{
	startMainAxis -= SPEED * dt;
	if (startMainAxis <= START_MAIN_AXIS - tileHeight)
	{
		startMainAxis = START_MAIN_AXIS;
		updateMap();
	}
}

bool TileManager::getTile(int row, int col) const
{
	return tileMap[row][col];
}

float TileManager::getConstantAxis() const
{
	return constantAxis;
}