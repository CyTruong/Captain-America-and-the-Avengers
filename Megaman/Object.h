#pragma once

#include "CollisionRect.h"
// Object use in map collision 
class Object
{
public:
	Object(std::string name, std::string type, int x, int y, int id, int width, int height, RectF body)
		:
		name(name),
		type(type),
		x(x),
		y(y),
		id(id),
		width(width),
		height(height),
		body(body)
	{
	}
	Object() {

	}
	int x;
	int y;
	int width;
	int height;
	int id;
	std::string name;
	RectF body;
	std::string type;
};