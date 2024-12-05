#pragma once

#include "GLTexture.h"
#include <vector>

class TileManager
{
public:
    TileManager(float tileWidth, float tileHeight, int rows, int cols, float startX, float startZ, float speed);
    void load();
    void update(float dt);
    void render() const;
    bool getTile(int row, int col) const;
    bool isHole(float x, float z) const;

    const float SPEED;

private:
    GLTexture texture;
    std::vector<std::vector<bool>> groundMap;

private:
    float tileWidth;
    float tileHeight;
    int rows;
    int cols;
    float startX;
    float startZ;

private:
    const float START_X;
    const float START_Z;

private:
    void generateRow();
    void renderTile(float x, float z) const;
};