#pragma once

#include <chrono>

#include "keyhandler.h"
#include "camera.h"
#include "statemachine.h"
#include "sun.h"
#include "player.h"

using std::chrono::steady_clock;

class Game
{
public:
static int i;
    const int WINDOW_WIDTH;
    const int WINDOW_HEIGHT;
    const int FPS;
    const GLdouble FOVY;
    const GLdouble ZNEAR;
    const GLdouble ZFAR;
    const GLdouble ASPECT_RATIO;

public:
    KeyHandler keyhandler;
    StateMachine stateMachine;

private:
    float dt;
    steady_clock::time_point lastTime;

public:
    Game();
    void start();
    void update();
    void render() const;
};