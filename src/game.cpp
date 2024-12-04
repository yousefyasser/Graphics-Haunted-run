#include <chrono>

#include "include/game.h"

Game::Game()
    : WINDOW_WIDTH(1280), WINDOW_HEIGHT(720), FPS(60), dt(0.0f),
      ASPECT_RATIO((GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT), 
      FOVY(45.0), ZNEAR(0.1), ZFAR(1000), keyMode(0),
      keyhandler(*this),
      sun(GL_LIGHT1), 
      player(Vector3f(1, 1, 1)), 
      camera(0.0f, 15.0f, -26.0f, 0.0f, 12.0f, -21.0f, 0.0f, 1.0f, 0.0f), 
      stateMachine({{StateType::Empty, []()
                     { return std::make_unique<EmptyState>(); }}})
{
  stateMachine.change(StateType::Empty, nullptr);
  lastTime = std::chrono::high_resolution_clock::now();
}

void Game::update()
{
  auto currentTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> elapsed = currentTime - lastTime;
  lastTime = currentTime;
  dt = elapsed.count();

  camera.setup(FOVY, ASPECT_RATIO, ZNEAR, ZFAR);
  sun.update(dt);
  stateMachine.update(dt);
  player.update(dt);
}

void Game::render() const
{
  sun.render();
  stateMachine.render();
  player.render();
}