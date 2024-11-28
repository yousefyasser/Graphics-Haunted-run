#include "include/game.h"

Game::Game()
    : WINDOW_WIDTH(1280), WINDOW_HEIGHT(720), FPS(60),
      FOVY(45.0), ZNEAR(0.1), ZFAR(1000), dt(0.0f),
      camera(20, 5, 20, 0, 0, 0, 0, 1, 0),
      stateMachine({{"EmptyState", []()
                     { return std::make_unique<EmptyState>(); }}})
{
}