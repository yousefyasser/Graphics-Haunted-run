#include <chrono>

#include "include/game.h"
#include "include/util.h"
#include "include/states/scene1.h"
#include "include/states/scene2.h"

Game::Game()
    : WINDOW_WIDTH(1280), WINDOW_HEIGHT(720), FPS(60), dt(0.0f),
      ASPECT_RATIO((GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT),
      FOVY(45.0), ZNEAR(0.1), ZFAR(1000),
      keyhandler(*this),
      stateMachine({
          {StateType::Empty, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<EmptyState>(); }},
          {StateType::Scene1, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<Scene1>(); }},
          {StateType::Scene2, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<Scene2>(); }},
      })
{
}

void Game::update()
{
  auto currentTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> elapsed = currentTime - lastTime;
  lastTime = currentTime;
  dt = elapsed.count();

  stateMachine.update(dt);

  if (stateMachine.getCurrentStateType() == StateType::Scene1)
  {
    auto &scene1 = dynamic_cast<Scene1 &>(stateMachine.getCurrentState());
    if (scene1.player.keys == 7)
    {
      stateMachine.change(StateType::Scene2, Scene2::EnterParams{
                                                 FOVY,
                                                 ASPECT_RATIO,
                                                 ZNEAR,
                                                 ZFAR,
                                             });
    }
  }
}

void Game::render() const
{
  stateMachine.render();
}

void Game::start()
{
  stateMachine.change(StateType::Scene1, Scene1::EnterParams{
                                              FOVY,
                                              ASPECT_RATIO,
                                              ZNEAR,
                                              ZFAR,
                                         });
  lastTime = std::chrono::high_resolution_clock::now();
}