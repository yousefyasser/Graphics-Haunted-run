#pragma once

#include "statemachine.h"

class Game
{
public:
    Game();
    void update();
    void render() const;
    const int WINDOW_WIDTH, WINDOW_HEIGHT, FPS;
    StateMachine stateMachine;
};