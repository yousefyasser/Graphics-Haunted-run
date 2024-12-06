#include "include/states/scene2.h"

Scene2::Scene2(): Scene(), spawnableManager(true, false) {}

void Scene2::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);

    Scene::enter(params);

    player.keys = 7;
    enemyModel.Load("Models/enemy/enemy.3ds");
}

void Scene2::exit() {}

void Scene2::update(float dt)
{
    spawnableManager.update(dt, enemies, true, enemyModel, groundManager.SPEED);

    if (!player.isFalling() && groundManager.isHole(player.position.x, player.position.z))
    {
        player.startFalling();
    }
}

void Scene2::render() const
{
    Scene::render();
    spawnableManager.render(enemies);
}