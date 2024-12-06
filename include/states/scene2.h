#pragma once

#include "scene.h"
#include "../spawnables/spawnableManager.h"

#include <glut.h>

class Scene2 : public Scene
{
public:
    Scene2();
    void enter(const BaseParams& params) override;
    void exit() override;
    void update(float dt) override;
    void render() const override;

public:
    SpawnableManager spawnableManager;
    Model_3DS enemyModel;
    std::vector<std::unique_ptr<Spawnable>> enemies;
};