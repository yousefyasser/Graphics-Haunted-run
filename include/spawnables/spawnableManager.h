#pragma once

#include "../util.h"
#include "enemy.h"
#include "collectable.h"
#include <vector>
#include <memory>

class SpawnableManager {
  public:
    const float ENEMY_SPAWN_RATE = 10.0f;
    const float COLLECTABLE_SPAWN_RATE = 5.0f;
    float enemy_last_spawned_at = 0.0f;
    float collectable_last_spawned_at = 0.0f;

  public:
    void update(float dt, std::vector<std::unique_ptr<Spawnable>> &collectables, float groundSpeed);
    void render(const std::vector<std::unique_ptr<Spawnable>> &spawnables) const;

  private:
    void SpawnableManager::spawn(std::vector<std::unique_ptr<Spawnable>> &collectables, float groundSpeed);
};
