#include "include/states/scene2.h"
#include "SoundManager.h"

extern SoundManager soundManager;

Scene2::Scene2() : Scene(), spawnableManager(true, true) {}

void Scene2::enter(const BaseParams &params)
{
    const EnterParams &p = dynamic_cast<const EnterParams &>(params);
    Scene::enter(params);

    wallManagerLeft.TEXTURE_PATH = "Textures/wall3.bmp";
    wallManagerRight.TEXTURE_PATH = "Textures/wall3.bmp";
    groundManager.TEXTURE_PATH = "Textures/soil.bmp";
    wallManagerLeft.load();
    wallManagerRight.load();
    groundManager.load();

    player.keys = 7;
    enemyModel.Load("Models/enemy/enemy.3ds");
    keyModel.Load("Models/coin/coin.3ds");
    start = std::chrono::high_resolution_clock::now();
}

void Scene2::exit() {}

void Scene2::update(float dt)
{
    Scene::update(dt);
    elapsed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start);
    spawnableManager.update(dt, enemies, 2, enemyModel, groundManager.SPEED);
    spawnableManager.update(dt, collectables, 1, keyModel, groundManager.SPEED);

    if (!player.isFalling() && player.position.y == Player::PLAYER_Y && groundManager.isHole(player.position.x, player.position.z))
    {
        player.startFalling();
        player.startInvincibility();
        player.keys--;
        soundManager.playSound("fall");
    }

    int index = spawnableManager.isColliding(player, collectables);
    if (index != -1)
    {

        soundManager.playSound("key_collect");
        player.keys++;
        spawnableManager.removeColliding(index, collectables);
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
    spawnableManager.render(collectables);
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