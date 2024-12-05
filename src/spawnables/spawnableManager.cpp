#include "include/spawnables/spawnableManager.h"

void SpawnableManager::update(float dt, std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed){
    bool collectableOutOfBound = false;
    last_spawned_at += dt;

    if(last_spawned_at >= SPAWN_RATE){
        spawn(collectables, groundSpeed);
        last_spawned_at = 0.0f;
    }

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

void SpawnableManager::render(const std::vector<std::unique_ptr<Collectable>> &collectables) const {
    for(const auto& collectable: collectables){
        collectable->render();
    }
}

void SpawnableManager::spawn(std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed)
{
  Vector3f pos(0, 3, 100), vel(0, 0, -groundSpeed), angle(0, 0, 0);

  auto newCollectable = std::make_unique<Collectable>(pos, vel, angle);
  newCollectable->load();
  collectables.push_back(std::move(newCollectable));
}
