#include "include/states/scene1.h"

Scene1::Scene1(): Scene(), spawnableManager(false, true) {}

void Scene1::enter(const BaseParams &params)
{
    Scene::enter(params);
    collectableModel.Load("Models/key/key.3ds");
}

void Scene1::exit() {}

void Scene1::update(float dt)
{
    Scene::update(dt);
    spawnableManager.update(dt, collectables, false, collectableModel, groundManager.SPEED);

    if (!player.isFalling() && player.position.y == Player::PLAYER_Y && groundManager.isHole(player.position.x, player.position.z))
    {
        player.startFalling();
    }

    if (!player.isInvincible())
    {
        int index = spawnableManager.isColliding(player, collectables);
        if (index == -1)
            return;

        player.startInvincibility();
        player.keys++;
        spawnableManager.removeColliding(index, collectables);
    }
}

void Scene1::render() const
{
    Scene::render();
    spawnableManager.render(collectables);
}