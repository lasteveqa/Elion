#include "Core/Window.h"


namespace Elion
{

	


	Window::Window(const WindowProperties& props) : wprops(props)
	{
	
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			ELION_INFO("Window has been created...");
			this->window = SDL_CreateWindow(props.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, props.Width, props.Height, this->flag);
		}

		if (this->window != nullptr)
		{
			Renderer::init(this->window);
			ELION_INFO("Renderer has been created...");
		}
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);


		gl_context = SDL_GL_CreateContext(this->window);
    }

	





	Window::~Window()
	{
		SDL_DestroyWindow(this->window);
		Renderer::clear();
	}
}