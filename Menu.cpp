#include "Menu.h"



Menu::Menu(SDL_Renderer* renderer)
{
	mRenderer = renderer;
	


	texture = IMG_LoadTexture(mRenderer, "assets/Paisagem.jpg");
	std::cout << "Erro Load Menu: " << mRenderer << std::endl;
	std::cout << "Erro Load Menu2: " << renderer << std::endl;
}

Menu::~Menu()
{
}

void Menu::Render()
{
	SDL_Rect* mem = new SDL_Rect();
	mem->x = 0;
	mem->y = 0;
	mem->h = 100;
	mem->w = 200;

	SDL_RenderCopy(mRenderer, texture, mem, mem);
}