#pragma once
#include "Windows/Window.h"
#include "Scene/Scene.h"

namespace Elion
{
	class MainWindow : public Window
	{

	private:
		const char* WindowName = "Elion Test";
		const float Width = 1366.0f;
		const float Height = 768.0f;
		SDL_Window* window;
		bool b_vsync = false;
		SDL_GLContext gl_context;

		//Interface::UserInterface m_UI;
	public:
		void init() override;
		void render() override;
		void update() override;
		void clear() override;


		inline float get_width() { return this->Width; }
		inline float get_height() { return this->Height; }

		inline SDL_Window* get_window() { return this->window; }
		inline SDL_GLContext get_GLcontext() { return this->gl_context; }
	};

}

