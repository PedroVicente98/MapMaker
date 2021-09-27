#include "Settings.h"





void Settings::GetResolution()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	Width = DM.w;
	Height = DM.h;
}

int Settings::GetWidth()
{
	return Width;
}

int Settings::GetHeight()
{
	return Height;
}

Settings::Settings()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	Width = DM.w;
	Height = DM.h;
}

Settings::~Settings()
{
}
