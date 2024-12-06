#pragma once

#include "spawnable.h"

class Collectable : public Spawnable {
public:
  using Spawnable::Spawnable;

  void load() override;
  void update(float dt) override;
  void render() const override;
};
