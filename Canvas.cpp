#include "Canvas.h"

Canvas::Canvas(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Canvas::~Canvas()
{
}

