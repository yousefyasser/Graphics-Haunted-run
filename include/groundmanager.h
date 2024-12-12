#pragma once

#include "GLTexture.h"
#include <vector>

#include "tilemanager.h"

class GroundManager : public TileManager
{
public:
    using TileManager::TileManager;
    using TileManager::load;
    using TileManager::render;
    using TileManager::getTile;

    void update(float dt) override;
    bool isHole(float x, float z) const;

private:
    void updateMap() override;
    void renderTile(float z, float x) const override;
    void renderHole(float z, float x) const override;
    float colors[3] = {0.0f, 0.0f, 0.0f};

private:
    bool toggleUpdateMap;
};