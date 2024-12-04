#include <iostream>

#include "include/states/scene1.h"

Scene1::Scene1()
    : camera(0.0f, 15.0f, -26.0f, 0.0f, 12.0f, -21.0f, 0.0f, 1.0f, 0.0f),
      sun(GL_LIGHT1),
      player(Vector3f(0, 5, 0), Vector3f(0, 0, 0), Vector3f(0, 0, 0)),
      tileManager(10, 10, 20, 3, -15, -15) {}

void Scene1::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);
    camera.fovy = p.fovy;
    camera.aspectRatio = p.aspectRatio;
    camera.zNear = p.zNear;
    camera.zFar = p.zFar;

    player.load();
    tileManager.load();
}

void Scene1::exit() {}

void Scene1::update(float dt)
{
    sun.update(dt);
    player.update(dt);
    tileManager.update(dt);
}

void Scene1::render() const
{
    camera.setup();
    sun.render();
    player.render();
    tileManager.render();
}