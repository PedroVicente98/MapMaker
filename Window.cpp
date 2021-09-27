#include "Window.h"
#include <iostream>

Window* Window::w_Instance = nullptr;

bool Window::Init()
{
#pragma region COMENTS
/*
	SDL_DisplayMode dm;

	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
	{
		SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
		return 1;
	}

	int w, h;
	w = dm.w;
	h = dm.h;
*/
//SDL_SetWindowDisplayMode(m_Window, NULL);
#pragma endregion

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}
	m_Window = SDL_CreateWindow("D&D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (m_Window == nullptr)
	{
		SDL_Log("Failed to initialize Window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr)
	{
		SDL_Log("Failed to initialize Renderer: %s", SDL_GetError());
		return false;
	}
	return m_IsRunning = true;
}

bool Window::Clean()
{
	return false;
}

void Window::Quit()
{
	m_IsRunning = false;
}

void Window::Update()
{
	SDL_Log("D&D Window Running!!");
}

void Window::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);
	SDL_RenderPresent(m_Renderer);
}

void Window::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}
}
