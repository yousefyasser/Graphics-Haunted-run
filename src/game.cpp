#include <chrono>

#include "include/game.h"

Game::Game()
    : WINDOW_WIDTH(1280), WINDOW_HEIGHT(720), FPS(60),
      FOVY(45.0), ZNEAR(0.1), ZFAR(1000), dt(0.0f),
      camera(20, 5, 20, 0, 0, 0, 0, 1, 0),
      stateMachine({{"TestState", []()
                     { return std::make_unique<EmptyState>(); }}})
{
  stateMachine.change("TestState", nullptr);
}

void Game::update(GLdouble aspectRatio)
{
  static auto lastTime = std::chrono::high_resolution_clock::now();
  auto currentTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> elapsed = currentTime - lastTime;
  dt = elapsed.count();
  lastTime = currentTime;

  stateMachine.update(dt);
  camera.setup(FOVY, aspectRatio, ZNEAR, ZFAR);
}

void Game::render() const
{
  stateMachine.render();
}