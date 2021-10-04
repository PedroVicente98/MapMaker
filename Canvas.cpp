#include "Canvas.h"

Canvas::Canvas(SDL_Renderer* renderer)
{
	cRenderer = renderer;



	texture = IMG_LoadTexture(cRenderer, "assets/MundoConhecido72.png");
	std::cout << "Erro Load Menu: " << cRenderer << std::endl;
	std::cout << "Erro Load Menu2: " << renderer << std::endl;
}

Canvas::~Canvas()
{
}

void Canvas::Render()
{
	SDL_RenderCopy(cRenderer, texture, NULL, NULL);
}

