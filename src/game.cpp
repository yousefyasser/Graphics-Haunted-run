#include "include/game.h"

Game::Game() 
    : WINDOW_WIDTH(800), WINDOW_HEIGHT(600), FPS(60),
      stateMachine({
          {"EmptyState", []() { return std::make_unique<EmptyState>(); }}
      }) {
}

void Game::update() {
    stateMachine.update(1);
}