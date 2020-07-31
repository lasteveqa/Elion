#pragma once
#include "Interface/UIComponent.h"


namespace Elion
{
	namespace Interface
	{
		class SceneOutliner : public UIComponent
		{

		public:
			void init(SDL_Window* window, SDL_GLContext gl_context);
			void render(SDL_Window* window);
			void clear();
		};
	}
}