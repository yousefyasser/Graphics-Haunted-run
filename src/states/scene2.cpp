#include "include/states/scene2.h"
#include "SoundManager.h"

extern SoundManager soundManager;

Scene2::Scene2() : Scene(), spawnableManager(true, false) {}

void Scene2::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);

    Scene::enter(params);

    player.keys = 7;
    enemyModel.Load("Models/enemy/enemy.3ds");
    start = std::chrono::high_resolution_clock::now();
}

void Scene2::exit() {}

void Scene2::update(float dt)
{
    Scene::update(dt);
    elapsed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start);
    spawnableManager.update(dt, enemies, true, enemyModel, groundManager.SPEED);

    if (!player.isFalling() && player.position.y == Player::PLAYER_Y && groundManager.isHole(player.position.x, player.position.z))
    {
        player.startFalling();
        player.keys--;
        soundManager.playSound("fall");
    }

    int pos = spawnableManager.isColliding(player, enemies);
    if (pos == -1)
        return;
    soundManager.playSound("scream");
    player.keys--;
    player.startInvincibility();
    spawnableManager.removeColliding(pos, enemies);
}

void Scene2::render() const
{
    Scene::render();
    renderTime();
    spawnableManager.render(enemies);
}

void Scene2::renderTime() const
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glColor3f(6.0f, 6.0f, 6.0f);
    util::drawText(700.0f, 720 - 40.0f, 0.0f, "Time: " + std::to_string(int(COUNTDOWN - elapsed.count())));

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);
}