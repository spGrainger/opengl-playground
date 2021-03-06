#ifndef ___MyScene__
#define ___MyScene__

#ifdef __APPLE__                        // if OS X
#include <glut/glut.h>                  // include freeglut libraries
#else                                   // if Windows
#include <gl/glut.h>                    // include freeglut libraries
#endif

#include "Tree.h"

#include <string>
#include <map>

#include <stdio.h>
map<string, DisplayableObject*> objects;

void setup();
void draw();
int main(int argc, char **argv);
void checkGLError();                        // Prints any OpenGL errors to console


#endif