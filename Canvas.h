#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"
#include <iostream>


class Canvas{
public:
    Canvas(SDL_Renderer* renderer);
	~Canvas();
	void Render();

private:
	SDL_Renderer* cRenderer;
	SDL_Texture* texture;
};