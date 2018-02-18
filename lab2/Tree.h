#ifndef ___Tree__
#define ___Tree__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include <cmath>
#include <string>

using namespace std;

class Tree : public DisplayableObject       // a Tree is a DisplayableObject
{
public:
	Tree();                                 // constructor
	~Tree() { };                            // destructor
	void display();                         // overloaded virtual display function
private:
	void branch();                          // draw branch function
};
#endif