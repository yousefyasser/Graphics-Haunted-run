#pragma once

#include "collectable.h"
#include <vector>
#include <memory>

class SpawnableManager {
  public:
    const float SPAWN_RATE = 5.0f;
    float last_spawned_at = 0.0f;

  public:
    void update(float dt, std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed);
    void render(const std::vector<std::unique_ptr<Collectable>> &collectables) const;

  private:
    void SpawnableManager::spawn(std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed);
};
