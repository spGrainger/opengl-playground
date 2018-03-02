#include "math.h"
#include "MyScene.h"
#define _USE_MATH_DEFINES
#include <cmath>

#include "Wall.h"

void setup()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 400);
	glutCreateWindow("lab 2");
	
	Wall* wall = new Wall();
	objects["wall"] = wall;
}

void reshape(int _width, int _height)
{
	printf("reshape!\n");
	// update global dimension variables
	int width = _width;
	int height = _height;
	// calculate new aspect ratio
	GLdouble aspect = static_cast<GLdouble>(width) / static_cast<GLdouble>(height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();			// reset matrix
	gluPerspective(45.0, aspect, 1, 1000);
	glMatrixMode(GL_MODELVIEW); // return matrix mode to modelling and viewing
}

void drawObjects() {
	for (std::map <std::string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr)
	{
		itr->second->display();
	}
}

void drawShapes()
{
	//glRotatef(0.4f, 0.f, 1.f, 0.f);

	drawObjects();
	glutPostRedisplay();
}

float num = 0;
float num2 = 0;

void draw()
{
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.3f, 0.3f, 0.5f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawShapes();
	checkGLError();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	setup();
	glutDisplayFunc(draw);
	checkGLError();
	glutReshapeFunc(reshape);
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -15.f);

	GLfloat diffuse[]  = { 1.f, 1.f, 1.f, 1.f };
	GLfloat specular[] = { 1.f, 1.f, 1.f, 1.f };
	GLfloat ambient[]  = { 0.f, 0.f, 0.f, 1.f };
	GLfloat position[] = { -10.f, 10.f, 0.f, 1.0f };

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glutMainLoop();                 // Begin rendering sequence
	return 0;
}

void checkGLError()
{
	int e = 0;                      // Error count
	GLenum error = glGetError();    // Get first glError
	while (GL_NO_ERROR != error)    // Loop until no errors found
	{
		e++;
		printf("GL Error %i: %s\n", e, gluErrorString(error)); // Display error string
		error = glGetError();                                  // Get next glError
	}
}