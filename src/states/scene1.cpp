#include "include/states/scene1.h"

Scene1::Scene1()
    : camera(0.0f, 15.0f, -26.0f, 0.0f, 12.0f, -21.0f, 0.0f, 1.0f, 0.0f),
      sun(GL_LIGHT1),
      player(Vector3f(0, 5, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0)),
      groundManager(15, 10, 20, 3, -15, -22.5f, 0.0f, 10.0f, "Textures/ground.bmp"),
      wallManager(20, 30, 20, 3, -15, -22.5f, 5.0f, 10.0f, "Textures/wall.bmp"),
      keyMode(0) {}

void Scene1::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);
    camera.fovy = p.fovy;
    camera.aspectRatio = p.aspectRatio;
    camera.zNear = p.zNear;
    camera.zFar = p.zFar;

    player.load();
    groundManager.load();
    wallManager.load();
}

void Scene1::exit() {}

void Scene1::update(float dt)
{
    sun.update(dt);
    player.update(dt);
    groundManager.update(dt);
    wallManager.update(dt);
    camera.update(dt, player.position, player.angle);
}

void Scene1::render() const
{
    camera.setup();
    sun.render();
    player.render();
    groundManager.render();
    wallManager.render();
}