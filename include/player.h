#pragma once

#include <chrono>

#include "gameobject.h"
#include <glut.h>

using std::chrono::steady_clock;

class Player : public GameObject
{
public:
  static float PLAYER_Y;
  static float JUMP_SPEED;
  static float JUMP_HEIGHT;
public:
  using GameObject::GameObject;
  
  BoundingBox calculateBoundingBox() override;
  void update(float dt) override;
  void render() const override;
  void load() override;

public:
  int keys = 0;
  void jump();
  void startFalling();
  bool isFalling() const;
  bool isJumping() const;
  bool isInvincible() const;

private:
  bool falling = false;
  bool invincible = false;
  bool jumping = false;
  steady_clock::time_point invincibilityTimer;  
};