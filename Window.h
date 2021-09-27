#ifndef Window_H
#define Window_H
#include "SDL.h"
class Window
{
public:
	static Window* Instance()
	{
		return w_Instance = (w_Instance != nullptr) ? w_Instance : new Window();
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool isRunning() { return m_IsRunning; };
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
	Window(){}
	static Window* w_Instance;
	bool m_IsRunning;

	SDL_DisplayMode DM;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};


#endif // !Window_H

