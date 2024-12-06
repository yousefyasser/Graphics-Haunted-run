#pragma once



class Game;
class KeyHandler
{
public:
    KeyHandler(Game &game);
    void keyDown(unsigned char key, int x, int y);
    void keyUp(unsigned char key, int x, int y);
    void mouse(int key, int state, int x, int y);
    void specialKeyDown(int key, int x, int y);
    void specialKeyUp(int key, int x, int y);

private:
    Game &game;

    void cameraKeyDown(unsigned char key, int x, int y);
    void playerKeyDown(unsigned char key, int x, int y);
    void playerKeyUp(unsigned char key, int x, int y);
};