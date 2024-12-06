#pragma once

#include "GLTexture.h"
#include <vector>

#include "tilemanager.h"

class GroundManager : public TileManager
{
public:
    using TileManager::TileManager;
    using TileManager::load;
    using TileManager::update;
    using TileManager::render;
    using TileManager::getTile;

    bool isHole(float x, float z) const;

private:
    void updateMap() override;

private:
    void renderTile(float z, float x) const override;
    void renderHole(float z, float x) const override;
};