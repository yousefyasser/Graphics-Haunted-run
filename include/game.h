#pragma once

#include <chrono>

#include "camera.h"
#include "statemachine.h"
#include "sun.h"
#include "player.h"

using std::chrono::steady_clock;

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

public:
    StateMachine stateMachine;
    Camera camera;
    Sun sun;
    Player player;

private:
    float dt;
    steady_clock::time_point lastTime;

public:
    Game();
    void update();
    void render() const;
};