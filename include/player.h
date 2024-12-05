#pragma once

#include "gameobject.h"
#include <glut.h>

class Player : public GameObject
{
public:
  using GameObject::GameObject;
  
  void update(float dt) override;
  void render() const override;
  void load() override;
};