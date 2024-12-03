#pragma once

#include "camera.h"
#include "statemachine.h"
#include "sun.h"
#include "player.h"

class Game
{
public:
    const int WINDOW_WIDTH;
    const int WINDOW_HEIGHT;
    const int FPS;
    const GLdouble FOVY;
    const GLdouble ZNEAR;
    const GLdouble ZFAR;
    const GLdouble ASPECT_RATIO;

    float dt;
    StateMachine stateMachine;
    Camera camera;
    Sun sun;
    Player player;

    Game();
    void update();
    void render() const;
};