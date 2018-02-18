#include "math.h"
#include "MyScene.h"
#include "StlDisplayableObject.h"
#define _USE_MATH_DEFINES
#include <cmath>

void setup()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 400);
	glutCreateWindow("lab 2");
	
	//Tree* tree;
	//tree = new Tree();            
	//objects["tree"] = tree;

	StlDisplayableObject* stlObj = new StlDisplayableObject("./bust.stl");
	objects["cube"] = stlObj;

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

void drawObjects() {
	glColor3f(0.f, 0.f, 0.f);
	for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr)
	{
		itr->second->display();
	}
}

void drawShapes()
{
	glRotatef(0.4f, 0.f, 1.f, 0.f);
	drawObjects();
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
	glTranslatef(0.f, 0.f, -15.f);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	// Create light components.
	GLfloat ambientLight[] = { 1.0f, 0.0f, 0.0f };
	GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat position[] = { 10.0f, 10.0f, 10.0f, 1.0f };

	// Assign created components to GL_LIGHT0.
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
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