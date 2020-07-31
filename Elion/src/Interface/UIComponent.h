#pragma once
#include "Core/Core.h"
#include "imgui.h"
#include "imgui/examples/imgui_impl_sdl.h"
#include "imgui/examples/imgui_impl_opengl3.h"
#include "Core/WindowProperties.h"

namespace Elion
{
	namespace Interface
	{
		class UIComponent
		{
		protected:
			WindowProperties m_Wprops;

		public:
			virtual void init(SDL_Window* window, SDL_GLContext gl_context){}
			virtual void render(SDL_Window* window){}
			virtual void clear(){}
		};
	}
}