#pragma once

#include "spawnable.h"

class Enemy : public Spawnable {
public:
  using Spawnable::Spawnable;

  void load() override;
  void render() const override;
};
