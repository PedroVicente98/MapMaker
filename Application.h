#pragma once
#include "SDL.h"
#include "Window.h"
#include "Settings.h"
#include "SDL_image.h"
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
	//void GetDisplayMode();
	//int GetWidth() { return Width; }
	//int GetHeight() { return Height; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_DisplayMode* DM;
	//int Width;
	//int Height;
};