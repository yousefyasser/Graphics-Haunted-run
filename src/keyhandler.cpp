#include "include/keyhandler.h"
#include "include/game.h"
#include "include/util.h"
#include "include/states/scene1.h"
#include "include/states/scene2.h"

KeyHandler::KeyHandler(Game &game) : game(game) {}

void KeyHandler::keyDown(unsigned char key, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());
    switch (key)
    {
        case 'm':
            scene1.keyMode = (scene1.keyMode + 1) % 2;
            scene1.camera.toggleCameraFreeMode();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }

    if (scene1.keyMode)
    {
        cameraKeyDown(key, x, y);
    }
    else
    {
        playerKeyDown(key, x, y);
    }
}

void KeyHandler::keyUp(unsigned char key, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());
    if (!scene1.keyMode)
    {
        playerKeyUp(key, x, y);
    }
}

void KeyHandler::mouse(int button, int state, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        scene1.camera.toggleCameraMode();
    }
}

void KeyHandler::cameraKeyDown(unsigned char key, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());

    const float d = 1.5f;
    const float a = 1.0f;

    switch (key)
    {
    case 'w':
        scene1.camera.moveY(d);
        break;
    case 's':
        scene1.camera.moveY(-d);
        break;
    case 'd':
        scene1.camera.moveX(-d);
        break;
    case 'a':
        scene1.camera.moveX(d);
        break;
    case 'q':
        scene1.camera.moveZ(d);
        break;
    case 'e':
        scene1.camera.moveZ(-d);
        break;

    case 'i':
        scene1.camera.rotateX(a);
        break;
    case 'k':
        scene1.camera.rotateX(-a);
        break;
    case 'l':
        scene1.camera.rotateY(-a);
        break;
    case 'j':
        scene1.camera.rotateY(a);
        break;
    case 'u':
        scene1.camera.rotateZ(a);
        break;
    case 'o':
        scene1.camera.rotateZ(-a);
        break;
    }
}

void KeyHandler::playerKeyDown(unsigned char key, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());
    switch (key)
    {
    case 'a':
        scene1.player.velocity.x = scene1.player.MAX_SPEED;
        break;
    case 'd':
        scene1.player.velocity.x = -scene1.player.MAX_SPEED;
        break;
    case ' ':
        scene1.player.jump();
        break;
    }
}

void KeyHandler::playerKeyUp(unsigned char key, int x, int y)
{
    Scene1 &scene1 = dynamic_cast<Scene1 &>(game.stateMachine.getCurrentState());
    switch (key)
    {
    case 'a':
    case 'd':
        scene1.player.velocity.x = 0;
        break;
    }
}