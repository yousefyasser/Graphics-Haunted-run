#include "include/keyhandler.h"
#include "include/game.h"
#include "include/util.h"

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

void KeyHandler::keyUp(unsigned char key, int x, int y){
    if(!game.keyMode){
        playerKeyUp(key, x, y);
    }
}

void KeyHandler::cameraKeyDown(unsigned char key, int x, int y){
    Vector3f characterDirection = game.camera.getRelativeCharacterDir(game.player.angle);
    Vector3f characterPosition = game.camera.getRelativeCharacterPosition(game.player.position);

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
            game.camera.setFirstPersonView(characterPosition, characterDirection);
            break;
        case '3':
            game.camera.setThirdPersonView(characterPosition, characterDirection, 20.0f, 15.0f);
            break;
    }
}

void KeyHandler::playerKeyDown(unsigned char key, int x, int y){
    switch(key){
        case 'a':
            game.player.velocity.x = game.player.MAX_SPEED;
            break;
        case 'd':
            game.player.velocity.x = -game.player.MAX_SPEED;
            break;
    }
}

void KeyHandler::playerKeyUp(unsigned char key, int x, int y){
    switch(key){
        case 'a':
        case 'd':
            game.player.velocity.x = 0;
            break;
    }
}