#pragma once
#include "glew.h"
#include "SDL.h"

namespace Elion
{


	
	class Renderer
	{

	private:
		static SDL_Renderer* renderer;


	public:
		static void init(SDL_Window* window);

		static inline SDL_Renderer* get_renderer() { return renderer; }

		static void clear();
		void on_window_resize(unsigned int width, unsigned int height);

		static void render();

		static void update(SDL_Window* window);

		
	};


}