#pragma once

#include "GLTexture.h"
#include <vector>

class TileManager
{
public:
    TileManager(float tileWidth, float tileHeight, int rows, int cols,
                float startMainAxis, float startSecondaryAxis, float constantAxis,
                float speed, char *texturePath);
    virtual void load();
    virtual void update(float dt);
    virtual void render() const;
    bool getTile(int row, int col) const;
    float getConstantAxis() const;

    const float SPEED;

protected:
    virtual void updateMap() {}
    virtual void renderTile(float mainAxis, float secondaryAxis) const = 0;
    virtual void renderHole(float mainAxis, float secondaryAxis) const = 0;

protected:
    GLTexture texture;
    std::vector<std::vector<bool>> tileMap;

protected:
    float tileWidth;
    float tileHeight;
    int rows;
    int cols;
    float startMainAxis;
    float startSecondaryAxis;
    float constantAxis;

public:
    const float START_MAIN_AXIS;
    const float START_SECONDARY_AXIS;
    char *TEXTURE_PATH;
};