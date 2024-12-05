#include "include/spawnables/spawnableManager.h"

void SpawnableManager::update(float dt, std::vector<std::unique_ptr<Collectable>> &collectables){
    bool collectableOutOfBound = false;

    for(auto& collectable: collectables){
        collectable->update(dt);
        
        if(collectable->position.z <= -10){
            collectableOutOfBound = true;
        }
    }

    if(collectableOutOfBound){
        collectables.erase(collectables.begin());
    }
}

void SpawnableManager::render(const std::vector<std::unique_ptr<Collectable>> &collectables){
    for(const auto& collectable: collectables){
        collectable->render();
    }
}
