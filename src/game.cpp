#include <chrono>

#include "include/game.h"
#include "include/util.h"
#include "include/states/scene1.h"
#include "include/states/scene2.h"
#include "include/states/gameovermenu.h"

Game::Game()
    : WINDOW_WIDTH(1280), WINDOW_HEIGHT(720), FPS(60), dt(0.0f),
      ASPECT_RATIO((GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT),
      FOVY(45.0), ZNEAR(0.1), ZFAR(100),
      keyhandler(*this),
      stateMachine({
          {StateType::Empty, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<EmptyState>(); }},
          {StateType::Scene1, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<Scene1>(); }},
          {
              StateType::Scene2,
              []() -> std::unique_ptr<BaseState>
              { return std::make_unique<Scene2>(); },
          },
          {StateType::GameOverMenu, []() -> std::unique_ptr<BaseState>
           { return std::make_unique<GameOverMenu>(); }},
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
  else if (stateMachine.getCurrentStateType() == StateType::Scene2)
  {
    auto &scene2 = dynamic_cast<Scene2 &>(stateMachine.getCurrentState());
    if (scene2.player.keys == 0)
    {
      stateMachine.change(StateType::GameOverMenu, GameOverMenu::EnterParams{
                                                       0,
                                                       int(scene2.COUNTDOWN - scene2.elapsed.count()),
                                                   });
    }
    else if (scene2.elapsed.count() >= scene2.COUNTDOWN)
    {
      stateMachine.change(StateType::GameOverMenu, GameOverMenu::EnterParams{
                                                       scene2.player.keys * 10,
                                                       0,
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
  stateMachine.change(StateType::Scene2, Scene2::EnterParams{
                                             FOVY,
                                             ASPECT_RATIO,
                                             ZNEAR,
                                             ZFAR,
                                         });
  lastTime = std::chrono::high_resolution_clock::now();
}