#include "Viewport.h"




int ViewPort::getHeight() {
	return port.height;
}

ViewPort::ViewPort(RectI port)
{
	this->port = port;

}

int ViewPort::getWidth() {
	return port.width;
}

