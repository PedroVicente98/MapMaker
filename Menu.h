#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"
#include <iostream>


class Menu {
public:
	Menu(SDL_Renderer* renderer);
	~Menu();
	void Render();

private:
	SDL_Renderer* mRenderer;
	SDL_Texture* texture;
};