
#include "Application.h"

namespace Elion 
{
	SDL_Event sdl_event;

	Application::Application()
	{
		Log::init();
		this->m_WindowSwitcher.set_window(new MainWindow());
	}

    void Application::init()
	{
		
	}

	void Application::run()
	{
		while (is_running())
		{
			begin_render();

			while (SDL_PollEvent(&sdl_event))
			{
				ImGui_ImplSDL2_ProcessEvent(&sdl_event);

				switch (sdl_event.type)
				{
				case SDL_QUIT:
					set_running(false);
					break;
				case SDL_KEYDOWN:

					break;

				case SDL_KEYUP:

					break;
				}

			}
			this->m_WindowSwitcher.update();
			this->m_WindowSwitcher.render();
		
			update();
			end_render();
		}
	}

	void Application::begin_render()
	{
		glClearStencil(0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Application::end_render()
	{
		Renderer::render();
	}

	void Application::update()
	{
		
	}


	Application::~Application()
	{
	}
}