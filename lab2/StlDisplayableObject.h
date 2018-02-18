#pragma once
#include "DisplayableObject.h"
#include "parse_stl.h"
#include <string>

class StlDisplayableObject :
	public DisplayableObject
{
public:
	StlDisplayableObject(std::string);
	~StlDisplayableObject();
	void display();
private:
	std::vector<stl::triangle> triangles;
};

