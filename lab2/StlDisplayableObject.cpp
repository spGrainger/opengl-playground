#include "StlDisplayableObject.h"

StlDisplayableObject::StlDisplayableObject(std::string fileName)
{
	triangles = stl::parse_stl(fileName);
}

StlDisplayableObject::~StlDisplayableObject()
{
}

void StlDisplayableObject::display()
{
	glPushMatrix();
	glScalef(.05f, .05f, .05f);
	glTranslatef(0.f, -100.f, 0.f);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLES);

	glColor3f(0.1f, 0.1f, 0.1f);

	for (stl::triangle t : triangles)
	{
		glNormal3f(t.normal.x, t.normal.y, t.normal.z);
		glVertex3f(t.v1.x, t.v1.y, t.v1.z);
		glVertex3f(t.v2.x, t.v2.y, t.v2.z);
		glVertex3f(t.v3.x, t.v3.y, t.v3.z);
	}
	glEnd();
	glPopMatrix();

}
