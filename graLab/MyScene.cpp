#include "MyScene.h"
#include "math.h"
#define _USE_MATH_DEFINES

#include <cmath>

void setup()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 400);
	glutCreateWindow("lab 2");
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
	glLoadIdentity();     // reset matrix
	gluPerspective(45.0, aspect, 1, 1000);
	glMatrixMode(GL_MODELVIEW); // return matrix mode to modelling and viewing
}

void drawCylinder() 
{
	float height = 10.f;
	int radius = 5;
	float resolution = .25f * M_PI;
	float x, z;

	float red = 0.f;

	glBegin(GL_QUAD_STRIP);
	for (float i = 0.f; i <= 2 * M_PI; i += resolution) {
		glColor4f(red, 0.f, 0.f, 1.f);
		red += i / (4.f * M_PI);
		x = radius * cos(i);
		z = radius * sin(i);

		glVertex3f(x, height, z);
		glVertex3f(x, 0.f, z);
	}

	glVertex3f(radius, height, 0.f);
	glVertex3f(radius, 0.f, 0.f);

	glEnd();
}

void drawShapes()
{
	glRotatef(0.4f, .3f, 1.f, 0.f);
	drawCylinder();
	glutPostRedisplay();
}

float num = 0;
float num2 = 0;

void draw()
{
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawShapes();
	checkGLError();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // Initialise GL environment
	setup();                        // Call additional initialisation commands
	glutDisplayFunc(draw);          // Register scene to render contents of draw() function
	checkGLError();                 // Check any OpenGL errors in initialisation
	glutReshapeFunc(reshape); 
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -50.f);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
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