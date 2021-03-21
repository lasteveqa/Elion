#include "MainWindow.h"


namespace Elion
{
	SDL_Window* sdl_window;
	void MainWindow::init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
				{
					ELION_INFO("Window has been created...");
					sdl_window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED);
				}

				if (sdl_window != nullptr)
				{
				Renderer::init(sdl_window);
					ELION_INFO("Renderer has been created...");
				}
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);


				this->gl_context = SDL_GL_CreateContext(sdl_window);

				glewExperimental = GL_TRUE;
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK)
					ELION_ERROR("Glew was uninitialized , check if you installed it correctly!");

				//Global opengl state
				glEnable(GL_DEPTH_TEST); // This one keeps background objects visible
				glDepthFunc(GL_LESS);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_LIGHTING);

				//Transparency
				//glEnable(GL_BLEND); // This one helps us to create transparency
				//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			
				//glLineWidth(2); // Thicken lines so we can see 'em clearly

				Interface::UserInterface::init(sdl_window, this->gl_context);
				
	}

	void MainWindow::render()
	{
		Interface::UserInterface::render(sdl_window);

		SDL_GL_SwapWindow(sdl_window);
	}

	void MainWindow::events()
	{

	}

	void MainWindow::update()
	{
	}


	void MainWindow::clear()
	{
		Interface::UserInterface::clear();
	}
}