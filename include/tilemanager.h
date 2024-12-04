#pragma once

#include "GLTexture.h"
#include <vector>

class TileManager
{
public:
    TileManager(float tileWidth, float tileHeight, int rows, int cols,
                float minX, float minZ, float maxX, float maxZ);
    void load();
    void update(float dt);
    void render() const;

private:
    GLTexture texture;
    std::vector<std::vector<bool>> groundMap;
    float tileWidth;
    float tileHeight;
    int rows;
    int cols;
    float minX;
    float minZ;
    float maxX;
    float maxZ;

private:
    void renderTile(float x, float z) const;
};