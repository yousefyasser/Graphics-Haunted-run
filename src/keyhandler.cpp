#include "include/keyhandler.h"
#include "include/game.h"
#include "include/util.h"
#include "include/states/scene1.h"
#include "include/states/scene2.h"

KeyHandler::KeyHandler(Game &game) : game(game) {}

void KeyHandler::keyDown(unsigned char key, int x, int y)
{
    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:

        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        switch (key)
        {
        case 'm':
            scene.keyMode = (scene.keyMode + 1) % 2;
            scene.camera.toggleCameraFreeMode();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }

        if (scene.keyMode)
        {
            cameraKeyDown(key, x, y);
        }
        else
        {
            playerKeyDown(key, x, y);
        }
        break;
    }
}

void KeyHandler::keyUp(unsigned char key, int x, int y)
{
    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:
        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        if (!scene.keyMode)
        {
            playerKeyUp(key, x, y);
        }
        break;
    }
}

void KeyHandler::mouse(int button, int state, int x, int y)
{
    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:
        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            scene.camera.toggleCameraMode();
        }
        break;
    }
}

void KeyHandler::cameraKeyDown(unsigned char key, int x, int y)
{
    Camera *camera = nullptr;
    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:
        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        camera = &scene.camera;
    }

    if (camera == nullptr)
        return;

    const float d = 1.5f;
    const float a = 1.0f;

    switch (key)
    {
    case 'w':
        camera->moveY(d);
        break;
    case 's':
        camera->moveY(-d);
        break;
    case 'd':
        camera->moveX(-d);
        break;
    case 'a':
        camera->moveX(d);
        break;
    case 'q':
        camera->moveZ(d);
        break;
    case 'e':
        camera->moveZ(-d);
        break;

    case 'i':
        camera->rotateX(a);
        break;
    case 'k':
        camera->rotateX(-a);
        break;
    case 'l':
        camera->rotateY(-a);
        break;
    case 'j':
        camera->rotateY(a);
        break;
    case 'u':
        camera->rotateZ(a);
        break;
    case 'o':
        camera->rotateZ(-a);
        break;
    }
}

void KeyHandler::playerKeyDown(unsigned char key, int x, int y)
{
    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:
        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        switch (key)
        {
        case 'a':
            scene.player.velocity.x = scene.player.MAX_SPEED;
            break;
        case 'd':
            scene.player.velocity.x = -scene.player.MAX_SPEED;
            break;
        case ' ':
            scene.player.jump();
            break;
        }
        break;
    }
}

void KeyHandler::playerKeyUp(unsigned char key, int x, int y)
{

    switch (game.stateMachine.getCurrentStateType())
    {
    case StateType::Scene1:
    case StateType::Scene2:
        Scene &scene = dynamic_cast<Scene &>(game.stateMachine.getCurrentState());
        switch (key)
        {
        case 'a':
        case 'd':
            scene.player.velocity.x = 0;
            break;
        }
        break;
    }
}