#pragma once
#include "Direction.h"
#include "Rect.h"

class ViewPort
{
private:
	RectI port;
public:
	ViewPort(RectI port);
	int getWidth();
	int getHeight();
	RectI getPort() { return port; }
};

