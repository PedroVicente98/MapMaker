#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"


class Menu {
public:
	Menu(SDL_Window* window;);
	~Menu();

private:
	SDL_Renderer* renderer;
};