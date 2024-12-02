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
Model_3DS model_player;
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

	util::setupLights();
	util::setupMaterials();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);
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

	GLfloat lightIntensity[] = {0.7, 0.7, 0.7, 1.0f};
	GLfloat lightPosition[] = {0.0f, 100.0f, 0.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);

	// Draw Ground
	RenderGround();

	// Draw Tree Model
	glPushMatrix();
	glTranslatef(10, 0, 0);
	glScalef(0.7, 0.7, 0.7);
	model_tree.Draw();
	glPopMatrix();

	// Draw house Model
	glPushMatrix();
	glRotatef(90.f, 1, 0, 0);
	model_house.Draw();
	glPopMatrix();

	// Draw key model
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 10.0f);
	glScalef(0.1f, 0.1f, 0.1f);
	model_key.Draw();
	glPopMatrix();

	// Draw player model
	glPushMatrix();
	glTranslatef(15.0f, 2.0f, 0.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	model_player.Draw();
	glPopMatrix();

	// Draw enemy model
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 15.0f);
	glScalef(5.0f, 5.0f, 5.0f);
	model_enemy.Draw();
	glPopMatrix();

	// sky box
	glPushMatrix();

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	glTranslated(50, 0, 0);
	glRotated(90, 1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, tex);
	gluQuadricTexture(qobj, true);
	gluQuadricNormals(qobj, GL_SMOOTH);
	gluSphere(qobj, 100, 100, 100);
	gluDeleteQuadric(qobj);

	glPopMatrix();

	glutSwapBuffers();
}

//=======================================================================
// Keyboard Function
//=======================================================================
void myKeyboard(unsigned char button, int x, int y)
{
	switch (button)
	{
	case 'w':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'r':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case '1':
		// TODO: add first person view when player is implemented
		// game.camera.setFirstPersonView(characterPosition, characterDirection);
		break;
	case '3':
		// TODO: add third person view when player is implemented
		// game.camera.setFirstPersonView(characterPosition, characterDirection, 10.0f, 5.0f);
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

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
	model_player.Load("Models/boy/boy.3DS");
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

	myInit();

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutTimerFunc(0, myUpdate, 0);

	glutMainLoop();
}