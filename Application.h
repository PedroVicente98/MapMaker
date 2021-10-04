#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"
#include "Window.h"
#include "Settings.h"
#include <iostream>

class Application
{
public:
	Application();
	~Application();
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEnvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }


private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_DisplayMode* DM;

};