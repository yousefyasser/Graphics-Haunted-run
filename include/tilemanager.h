#pragma once

#include "GLTexture.h"
#include <vector>

class TileManager
{
public:
    TileManager(float tileWidth, float tileHeight, int rows, int cols, float startX, float startZ);
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
    float startX;
    float startZ;

private:
    void renderTile(float x, float z) const;
};