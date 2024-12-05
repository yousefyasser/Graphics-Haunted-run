#pragma once

#include "spawnable.h"
#include <vector>
#include <memory>

class Collectable : public Spawnable {
public:
  using Spawnable::Spawnable;

  void load() override;
  void update(float dt) override;
  void render() const override;
  static void Collectable::spawn(std::vector<std::unique_ptr<Collectable>> &collectables, float groundSpeed);
};
