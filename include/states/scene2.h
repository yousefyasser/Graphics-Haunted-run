#pragma once

#include <chrono>

#include "scene.h"
#include "../spawnables/spawnableManager.h"

#include <glut.h>

using std::chrono::steady_clock;

class Scene2 : public Scene
{
public:
    const float COUNTDOWN = 60.0f;
    Scene2();
    void enter(const BaseParams& params) override;
    void exit() override;
    void update(float dt) override;
    void render() const override;

public:
    SpawnableManager spawnableManager;
    Model_3DS enemyModel;
    std::vector<std::unique_ptr<Spawnable>> enemies;
    steady_clock::time_point start;
    std::chrono::seconds elapsed;

private:
    void renderTime() const;
};