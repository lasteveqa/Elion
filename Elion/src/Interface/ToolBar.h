#pragma once
#include "Interface/UIComponent.h"
#include "Scene/Scene.h"

namespace Elion
{

	namespace Interface
	{
		
		class ToolBar : public UIComponent
		{
		private:
			bool TriangleSelected = false;
			bool QuadSelected = false;

		public:
			void init(SDL_Window* window, SDL_GLContext gl_context) override;
			void render(SDL_Window* window) override;
			void clear() override;
		};
	}
}