#pragma once

#include "spawnable.h"

class Enemy : public Spawnable {
public:
  using Spawnable::Spawnable;

  void load() override;
  void update(float dt) override;
  void render() const override;

private:
  float scale = 5.0f;
};