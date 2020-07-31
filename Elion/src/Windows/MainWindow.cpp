#include "MainWindow.h"


namespace Elion
{
	void MainWindow::init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
				{
					ELION_INFO("Window has been created...");
					this->window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED);
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


				this->gl_context = SDL_GL_CreateContext(this->window);

				glewExperimental = GL_TRUE;
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK)
					ELION_ERROR("Glew was uninitialized , check if you installed it correctly!");

				glEnable(GL_DEPTH_TEST); // This one keeps background objects visible
				glDepthFunc(GL_LESS);
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_LIGHTING);

				glEnable(GL_BLEND); // This one helps us to create transparency
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

				glLineWidth(3); // Thicken lines so we can see 'em clearly
				Interface::UserInterface::init(this->window, this->gl_context);
	}

	void MainWindow::render()
	{
		SDL_GL_SwapWindow(this->window);
	}

	void MainWindow::update()
	{
		Interface::UserInterface::render(this->window);
	}


	void MainWindow::clear()
	{
		Interface::UserInterface::clear();
	}
}