#include "Viewport.h"

//Utilize this class for creating and rendering to individual viewports inside the window
Viewport::Viewport(std::string viewName, int x, int y, int width, int height)
{
	viewport.x = x;
	viewport.y = y;
	viewport.w = width;
	viewport.h = height;
}

Viewport::~Viewport()
{
}
