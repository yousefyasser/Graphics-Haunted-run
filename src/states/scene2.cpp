#include "include/states/scene2.h"

Scene2::Scene2()
    : camera(0.0f, 15.0f, -26.0f, 0.0f, 12.0f, -21.0f, 0.0f, 1.0f, 0.0f),
      sun(GL_LIGHT1, 50.0f, 50.0f, 50.0f),
      player(Vector3f(0, 5, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0)),
      groundManager(15, 10, 30, 3, -15.0f, -22.5f, 0.0f, 10.0f, "Textures/ground.bmp"),
      wallManagerLeft(10, 30, 10, 3, -15.0f, 0.0f, 22.0f, 10.0f, "Textures/wall.bmp"),
      wallManagerRight(10, 30, 10, 3, -15.0f, 0.0f, -22.5f, 10.0f, "Textures/wall.bmp"),
      spawnableManager(true, true),
      keyMode(0) {}

void Scene2::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);
    camera.fovy = p.fovy;
    camera.aspectRatio = p.aspectRatio;
    camera.zNear = p.zNear;
    camera.zFar = p.zFar;

    player.load();

    enemyModel.Load("Models/enemy/enemy.3ds");
    collectableModel.Load("Models/key/key.3ds");
    groundManager.load();
    wallManagerLeft.load();
    wallManagerRight.load();
}

void Scene2::exit() {}

void Scene2::update(float dt)
{
    sun.update(dt);
    player.update(dt);
    groundManager.update(dt);
    wallManagerLeft.update(dt);
    wallManagerRight.update(dt);
    camera.update(dt, player.position, player.angle);
    spawnableManager.update(dt, collectables, false, collectableModel, groundManager.SPEED);
    spawnableManager.update(dt, enemies, true, enemyModel, groundManager.SPEED);
}

void Scene2::render() const
{
    camera.setup();
    sun.render();
    player.render();
    spawnableManager.render(collectables);
    spawnableManager.render(enemies);
    groundManager.render();
    wallManagerLeft.render();
    wallManagerRight.render();
}