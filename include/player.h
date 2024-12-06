#pragma once

#include <chrono>

#include "gameobject.h"
#include <glut.h>

using std::chrono::steady_clock;

class Player : public GameObject
{
public:
  static float PLAYER_Y;
public:
  using GameObject::GameObject;
  
  void update(float dt) override;
  void render() const override;
  void load() override;

public:
  int keys;
  void startFalling();
  bool isFalling() const;
  bool isInvincible() const;

private:
  bool falling = false;
  bool invincible = false;
  steady_clock::time_point invincibilityTimer;  
};