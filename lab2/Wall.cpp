#include "Wall.h"

void Wall::display()
{
	// Draws an exciting chequered Wall
	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);

	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
							   		 	   
	float black[]    = { 0.0f, 0.0f, 0.0f, 1.0f };
	float white[]    = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

	for (int col = -10; col < 10; col++)
	{
		for (int row = -10; row < 10; row++)
		{
			//checkerboard pattern, alternate rows and cols (XOR)
			if (!(col%2) != !(row%2)) glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
			else					  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, black);

			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(scale[0] * col + scale[0], scale[2] * row + scale[2], -10.0f );
			glVertex3f(scale[0] * col + scale[0], scale[2] * row,			 -10.0f);
			glVertex3f(scale[0] * col,			  scale[2] * row,			 -10.0f);
			glVertex3f(scale[0] * col,			  scale[2] * row + scale[2], -10.0f);
		}
	}
	glEnd();
	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();
}