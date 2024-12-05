#include "tilemanager.h"

class WallManager : public TileManager
{
public:
    using TileManager::TileManager;
    using TileManager::load;
    using TileManager::update;
    using TileManager::render;
    using TileManager::getTile;
    using TileManager::updateMap;

private:
    void renderTile(float z, float y) const override;
};