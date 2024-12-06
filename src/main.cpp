#include "include/TextureBuilder.h"
#include "include/Model_3DS.h"
#include "include/GLTexture.h"
#include <glut.h>

#include "include/game.h"
#include "include/util.h"
#include "include/states/scene1.h"

Game game;

//=======================================================================
// OpengGL Configuration Function
//=======================================================================
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	util::setupMaterials();

	game.start();
}

//=======================================================================
// Display Function
//=======================================================================
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game.render();

	glutSwapBuffers();
}

//=======================================================================
// Keyboard Function
//=======================================================================
void myKeyboard(unsigned char button, int x, int y)
{
	game.keyhandler.keyDown(button, x, y);

	glutPostRedisplay();
}

void myKeyboardUp(unsigned char button, int x, int y)
{
	game.keyhandler.keyUp(button, x, y);

	glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y)
{
	game.keyhandler.mouse(button, state, x, y);

	glutPostRedisplay();
}

void myUpdate(int value)
{
	game.update();

	glutPostRedisplay();
	glutTimerFunc(1000 / game.FPS, myUpdate, 0);
}

//=======================================================================
// Main Function
//=======================================================================
void main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA | GLUT_DEPTH);

	glutInitWindowSize(game.WINDOW_WIDTH, game.WINDOW_HEIGHT);

	glutInitWindowPosition(100, 150);

	glutCreateWindow("Hunted Run");

	glutDisplayFunc(myDisplay);

	glutKeyboardFunc(myKeyboard);
	glutKeyboardUpFunc(myKeyboardUp);

	glutMouseFunc(myMouse);

	myInit();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutTimerFunc(0, myUpdate, 0);

	glutMainLoop();
}