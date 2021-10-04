#include "Menu.h"

Menu::Menu(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Menu::~Menu()
{
}
