#pragma once

#include "camera.h"
#include "statemachine.h"

class Game
{
public:
    Game();
    void update();
    void render() const;

    const int WINDOW_WIDTH, WINDOW_HEIGHT, FPS;
    const float FOVY, ZNEAR, ZFAR;

    float dt;
    StateMachine stateMachine;
    Camera camera;
};