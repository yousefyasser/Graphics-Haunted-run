#pragma once

#include "../util.h"
#include "../player.h"
#include "enemy.h"
#include "collectable.h"
#include <vector>
#include <memory>
#include <map>

class SpawnableManager {
  public:
    const float ENEMY_SPAWN_RATE = 10.0f;
    const float COLLECTABLE_SPAWN_RATE = 5.0f;

    float enemy_last_spawned_at = 0.0f;
    float collectable_last_spawned_at = 0.0f;

    bool enemies, collectables;

  public:
    SpawnableManager(bool enemies, bool collectables);

    void update(float dt, std::vector<std::unique_ptr<Spawnable>> &collectables, bool isEnemy, const Model_3DS &model, float groundSpeed);
    void render(const std::vector<std::unique_ptr<Spawnable>> &spawnables) const;
    int isColliding(Player &player, const std::vector<std::unique_ptr<Spawnable>> &spawnables);
    void removeColliding(int index, std::vector<std::unique_ptr<Spawnable>> &spawnables);

  private:
    void SpawnableManager::spawn(std::vector<std::unique_ptr<Spawnable>> &collectables, bool isEnemy, const Model_3DS &model, float groundSpeed);
};
