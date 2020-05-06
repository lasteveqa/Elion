#pragma once
#include "GL/glew.h"
#include "Core/Core.h"
#include "SDL.h"
#include "Core/Log.h"
#include "Renderer/Renderer.h"
#include <iostream>
namespace Elion
{

	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Elion",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		
		}

	};



	class ELION_API Window
	{
	private:
	
		SDL_Window* window = nullptr;
		const int flag = SDL_WINDOW_OPENGL;
		bool b_vsync = false;
		SDL_GLContext gl_context;
		WindowProperties wprops;
		
		
	public:
		Window(const WindowProperties& props);
		
		void set_width(unsigned int width) { wprops.Width = width; }
		void set_height(unsigned int height) { wprops.Height = height; }

		inline unsigned int get_width() const { return wprops.Width; }
		inline unsigned int get_height() const { return wprops.Height; }

		inline SDL_Window* get_window() { return this->window; }

		~Window();
			
			inline void set_vsync(bool enabled) { this->b_vsync = enabled; }
			inline bool is_set_vsync() { return this->b_vsync; }

		
	};

}