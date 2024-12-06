#pragma once

#include "scene.h"
#include "../spawnables/spawnableManager.h"

#include <glut.h>

class Scene1 : public Scene
{
public:
    Scene1();

    void enter(const BaseParams &params) override;
    void exit() override;
    void update(float dt) override;
    void render() const override;

public:
    SpawnableManager spawnableManager;
    Model_3DS collectableModel;
    std::vector<std::unique_ptr<Spawnable>> collectables;
};
