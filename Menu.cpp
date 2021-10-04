#include "Menu.h"


Menu::Menu(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* texture;
	texture = IMG_LoadTexture(renderer, "assets/MundoConhecido72.png");
	std::cout << "Erro Load: " << SDL_GetError() << std::endl;
	SDL_RenderCopy(renderer, texture, NULL, NULL);

}

Menu::~Menu()
{
}
