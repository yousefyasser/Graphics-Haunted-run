#include "include/states/scene2.h"

Scene2::Scene2() : Scene(), spawnableManager(true, false) {}

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
    Scene::update(dt);
    spawnableManager.update(dt, enemies, true, enemyModel, groundManager.SPEED);

    if (!player.isFalling() && player.position.y == Player::PLAYER_Y && groundManager.isHole(player.position.x, player.position.z))
    {
        player.startFalling();
    }

    int pos = spawnableManager.isColliding(player, enemies);
    if (pos == -1)
        return;

    player.keys--;
    player.startInvincibility();
    spawnableManager.removeColliding(pos, enemies);
}

void Scene2::render() const
{
    Scene::render();
    spawnableManager.render(enemies);
}