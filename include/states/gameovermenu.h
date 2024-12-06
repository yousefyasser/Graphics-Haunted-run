#pragma once

#include "basestate.h"

class GameOverMenu : public BaseState
{
public:
    struct EnterParams : public BaseState::BaseParams
    {
        int score;
        int timeRemaining;

        EnterParams(int score, int timeRemaining)
            : score(score), timeRemaining(timeRemaining) {}
    };

public:
    GameOverMenu();
    void enter(const BaseParams &params) override;
    void update(float dt) override;
    void render() const override;
    void exit() override;

private:
    int score;
    int timeRemaining;
};