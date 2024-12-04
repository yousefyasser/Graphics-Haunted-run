#include "TextureBuilder.h"
#include "Model_3DS.h"
#include "GLTexture.h"
#include <glut.h>

#include "include/game.h"
#include "include/util.h"

Game game;

GLuint tex;
char title[] = "3D Model Loader Sample";

// 3D Projection Options
GLdouble fovy = game.FOVY;
GLdouble aspectRatio = game.ASPECT_RATIO;
GLdouble zNear = game.ZNEAR;
GLdouble zFar = game.ZFAR;

// Model Variables
Model_3DS model_house;
Model_3DS model_tree;
Model_3DS model_key;
Model_3DS model_enemy;

// Textures
GLTexture tex_ground;

//=======================================================================
// OpengGL Configuration Function
//=======================================================================
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	game.camera.setup(fovy, aspectRatio, zNear, zFar);
	//*******************************************************************************************//
	// EYE (ex, ey, ez): defines the location of the camera.									 //
	// Center (cx, cy, cz):	 denotes the direction where the camera is aiming at.				 //
	// UP (ux, uy, uz):  denotes the upward orientation of the camera.							 //
	//*******************************************************************************************//

	// util::setupLights();
	game.sun.setup();
	util::setupMaterials();
}

//=======================================================================
// Render Ground Function
//=======================================================================
void RenderGround()
{
	glDisable(GL_LIGHTING); // Disable lighting

	glColor3f(0.6, 0.6, 0.6); // Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D); // Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]); // Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0); // Set quad normal direction.
	glTexCoord2f(0, 0);	 // Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
	glVertex3f(-20, 0, -20);
	glTexCoord2f(5, 0);
	glVertex3f(20, 0, -20);
	glTexCoord2f(5, 5);
	glVertex3f(20, 0, 20);
	glTexCoord2f(0, 5);
	glVertex3f(-20, 0, 20);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING); // Enable lighting again for other entites coming throung the pipeline.

	glColor3f(1, 1, 1); // Set material back to white instead of grey used for the ground texture.
}

//=======================================================================
// Display Function
//=======================================================================
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw Ground
	RenderGround();

	// Draw Tree Model
	// glPushMatrix();
	// glTranslatef(10, 0, 0);
	// glScalef(0.7, 0.7, 0.7);
	// model_tree.Draw();
	// glPopMatrix();

	// Draw house Model
	// glPushMatrix();
	// glRotatef(90.f, 1, 0, 0);
	// model_house.Draw();
	// glPopMatrix();

	// Draw key model
	// glPushMatrix();
	// glTranslatef(0.0f, 2.0f, 10.0f);
	// glScalef(0.1f, 0.1f, 0.1f);
	// model_key.Draw();
	// glPopMatrix();

	// Draw enemy model
	// glPushMatrix();
	// glTranslatef(0.0f, 1.0f, 15.0f);
	// glScalef(5.0f, 5.0f, 5.0f);
	// model_enemy.Draw();
	// glPopMatrix();

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

void myUpdate(int value)
{
	game.update();

	glutPostRedisplay();
	glutTimerFunc(1000 / game.FPS, myUpdate, 0);
}

//=======================================================================
// Assets Loading Function
//=======================================================================
void LoadAssets()
{
	// Loading Model files
	model_house.Load("Models/house/house.3DS");
	model_tree.Load("Models/tree/Tree1.3ds");
	model_key.Load("Models/key/key9albe.3DS");
	game.player.model_player.Load("Models/boy/boy.3DS");
	model_enemy.Load("Models/enemy/enemy.3ds");

	// Loading texture files
	tex_ground.Load("Textures/ground.bmp");
	loadBMP(&tex, "Textures/blu-sky-3.bmp", true);
}

//=======================================================================
// Main Function
//=======================================================================
void main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(game.WINDOW_WIDTH, game.WINDOW_HEIGHT);

	glutInitWindowPosition(100, 150);

	glutCreateWindow(title);

	glutDisplayFunc(myDisplay);

	glutKeyboardFunc(myKeyboard);
	glutKeyboardUpFunc(myKeyboardUp);

	myInit();

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutTimerFunc(0, myUpdate, 0);

	glutMainLoop();
}