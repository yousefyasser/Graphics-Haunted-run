#include "include/states/scene.h"

Scene::Scene()
    : camera(0.0f, 15.0f, -26.0f, 0.0f, 12.0f, -21.0f, 0.0f, 1.0f, 0.0f),
      sun(GL_LIGHT1, 40.0f, 40.0f, 0.0f),
      player(Vector3f(0, Player::PLAYER_Y, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0)),
      groundManager(15, 5, 40, 3, -15.0f, -22.5f, 0.0f, 10.0f, "Textures/ground.bmp"),
      wallManagerLeft(10, 30, 10, 3, -15.0f, 0.0f, 22.5f, 10.0f, "Textures/wall.bmp"),
      wallManagerRight(10, 30, 10, 3, -15.0f, 0.0f, -22.5f, 10.0f, "Textures/wall.bmp"),
      fl1(GL_LIGHT2, 23, 5, 15), fl2(GL_LIGHT3, -23, 5, 15),
      keyMode(0) {}

void Scene::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);

    camera.fovy = p.fovy;
    camera.aspectRatio = p.aspectRatio;
    camera.zNear = p.zNear;
    camera.zFar = p.zFar;

    player.load();
    groundManager.load();
    wallManagerLeft.load();
    wallManagerRight.load();
}

void Scene::exit() {}

void Scene::update(float dt)
{
    sun.update(dt);
    fl1.update(dt);
    fl2.update(dt);
    player.update(dt);
    groundManager.update(dt);
    wallManagerLeft.update(dt);
    wallManagerRight.update(dt);
    camera.update(dt, player.position, player.angle);
}

void Scene::render() const
{
    camera.setup();
    sun.render();
    fl1.render();
    fl2.render();
    player.render();
    groundManager.render();
    wallManagerLeft.render();
    wallManagerRight.render();
}