#include "include/keyhandler.h"
#include "include/game.h"

KeyHandler::KeyHandler(Game &game): game(game){}

void KeyHandler::keyDown(unsigned char key, int x, int y){
    switch (key)
	{
        case 'm':
            game.keyMode = (game.keyMode + 1) % 2;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
	}

    if(game.keyMode){
        cameraKeyDown(key, x, y);
    }else {
        playerKeyDown(key, x, y);
    }
}

void KeyHandler::cameraKeyDown(unsigned char key, int x, int y){
    switch(key) {
        case 'w':
            game.camera.moveY(1.0f);
            break;
        case 's':
            game.camera.moveY(-1.0f);
            break;
        case 'd':
            game.camera.moveX(-1.0f);
            break;
        case 'a':
            game.camera.moveX(1.0f);
            break;
        case 'q':
            game.camera.moveZ(1.0f);
            break;
        case 'e':
            game.camera.moveZ(-1.0f);
            break;

        case 'i':
            game.camera.rotateX(1.0f);
            break;
        case 'k':
            game.camera.rotateX(-1.0f);
            break;
        case 'l':
            game.camera.rotateY(-1.0f);
            break;
        case 'j':
            game.camera.rotateY(1.0f);
            break;
        case 'u':
            game.camera.rotateZ(1.0f);
            break;
        case 'o':
            game.camera.rotateZ(-1.0f);
            break;

        case '1':
            game.camera.setFirstPersonView(game.player.position, game.player.angle);
            break;
        case '3':
            game.camera.setThirdPersonView(game.player.position, game.player.angle, 10.0f, 5.0f);
            break;
    }
}

void KeyHandler::playerKeyDown(unsigned char key, int x, int y){
    switch(key){
        case 'a':
            // TODO: move player left
            break;
        case 'd':
            // TODO: move player right
            break;
    }
}