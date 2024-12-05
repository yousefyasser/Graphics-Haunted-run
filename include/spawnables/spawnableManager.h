#pragma once

#include "collectable.h"
#include <vector>
#include <memory>

class SpawnableManager {
public:
  const float SPAWN_RATE = 0.2f;

  static void update(float dt, std::vector<std::unique_ptr<Collectable>> &collectables);
  static void render(const std::vector<std::unique_ptr<Collectable>> &collectables);
};
