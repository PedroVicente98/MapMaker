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
	bool Init();
};