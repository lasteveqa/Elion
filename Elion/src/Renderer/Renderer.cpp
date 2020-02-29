#include "Renderer.h"
namespace Elion
{
	SDL_Renderer* Renderer::renderer;


	void Renderer::init(SDL_Window* window)
	{
		
			renderer = SDL_CreateRenderer(window, -1, 0);
		
	}


	void Renderer::render()
	{
	
	}

	void Renderer::clear()
	{
		SDL_RenderClear(renderer);
		SDL_DestroyRenderer(renderer);
	}



}