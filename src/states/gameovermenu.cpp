#include "include/states/gameovermenu.h"
#include "include/util.h"

#include <string>
#include <glut.h>

GameOverMenu::GameOverMenu() {}

void GameOverMenu::enter(const BaseParams &params)
{
    auto enterParams = dynamic_cast<const EnterParams&>(params);
    score = enterParams.score;
    timeRemaining = enterParams.timeRemaining;
}

void GameOverMenu::exit() {}

void GameOverMenu::update(float dt) {}

void GameOverMenu::render() const
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);

    if (score <= 0)
    {
        glColor3f(6.0f, 0.0f, 0.0f);
        util::drawText(500.0f, 720 - 200.0f, 0.0f, "Game Over!, Time Remaining: " + std::to_string(timeRemaining));
    }
    else
    {
        glColor3f(0.0f, 6.0f, 0.0f);
        util::drawText(500.0f, 720 - 200.0f, 0.0f, "You Win!, Score: " + std::to_string(score));
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);
}