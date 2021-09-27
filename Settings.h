#pragma once
#include <SDL_video.h>
class Settings
{
public:
	Settings();
	~Settings();
	void GetResolution();
	int GetWidth();
	int GetHeight();

private:
	int Width;
	int Height;
};
