#pragma once

#include "camera.h"
#include "statemachine.h"

class Game
{
public:
    const int WINDOW_WIDTH;
    const int WINDOW_HEIGHT;
    const int FPS;
    const float FOVY;
    const float ZNEAR;
    const float ZFAR;
    float dt;
    StateMachine stateMachine;
    Camera camera;

    Game();
    void Game::update(GLdouble fovy, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar);
    void render() const;
};