#include "Tree.h"

Tree::Tree()
{
}

// define display function (to be called by MyScene)
void Tree::display()
{
	// Project from Object Space to World Space
	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]);   // position
	glScalef(scale[0], scale[1], scale[2]); // scale
	glRotatef(rotation[1], 0.f, 1.f, 0.f);  // set orientation (Y)
	glRotatef(rotation[2], 0.f, 0.f, 1.f);  // set orientation (Z)
	glRotatef(rotation[0], 1.f, 0.f, 0.f);  // set orientation (X)
	char curr;
	float angle = 90.f;
	string sequence = "f^f&f^f&f-f-f-f&f";

	for (unsigned int i = 0; i < sequence.size(); i++)
	{
		curr = sequence[i];             // for each char in sequence
		switch (curr) {                  // check current char command
		case 'f':                   // draw branch, move forward
			branch();
			break;
		case '+':                   // yaw clockwise
			glRotatef(-angle, 0.f, 0.f, 1.f);
			break;
		case '-':                   // yaw counter-clockwise
			glRotatef(angle, 0.f, 0.f, 1.f);
			break;
		case '^':                   // pitch clockwise
			glRotatef(-angle, 1.f, 0.f, 0.f);
			break;
		case '&':                   // pitch counter-clockwise
			glRotatef(angle, 1.f, 0.f, 0.f);
			break;
		case '<':                   // roll clockwise
			glRotatef(-angle, 0.f, 1.f, 0.f);
			break;
		case '>':                   //roll counter-clockwise
			glRotatef(angle, 0.f, 1.f, 0.f);
			break;
		case '|':                   // roll upside-down
			glRotatef(180.f, 0.f, 1.f, 0.f);
			break;
		}
	}
	glPopMatrix();

}

void Tree::branch()
{
	float res = 0.025f*M_PI;                  // resolution (in radians: equivalent to 18 degrees)
	float r = 0.15f;                        // ratio of radius to height
	float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
	float t = 0.f;                          // initialise angle as 0
	float red = 0.f;
	do
	{                                     // create branch with multiple QUADS
		glBegin(GL_QUADS);
		glColor4f(red, 0.f, 0.f, 1.f);
		red = t / (2.f * M_PI);

		// Create first points
		glVertex3f(x, 0.f, z);          // bottom
		glVertex3f(x, 1.f, z);          // top
										// Iterate around circle
		t += res;                       // add increment to angle
		x = r*cos(t);                   // move x and z around circle
		z = r*sin(t);
		// Close quad
		glVertex3f(x, 1.f, z);          // top
		glVertex3f(x, 0.f, z);          // bottom
		glEnd();
	} while (t <= 2 * M_PI);                // full rotation around circle

	glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
}