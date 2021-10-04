#include "Menu.h"



Menu::Menu(SDL_Renderer* renderer)
{
	mRenderer = renderer;
	


	texture = IMG_LoadTexture(mRenderer, "assets/MundoConhecido72.png");
	std::cout << "Erro Load Menu: " << mRenderer << std::endl;
	std::cout << "Erro Load Menu2: " << renderer << std::endl;
}

Menu::~Menu()
{
}

void Menu::Render()
{
	SDL_RenderCopy(mRenderer, texture, NULL, NULL);
}