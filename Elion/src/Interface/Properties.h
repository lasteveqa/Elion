#pragma once
#include "Interface/UIComponent.h"

namespace Elion
{
	namespace Interface
	{
		class Properties : public UIComponent
		{
		private:
			float a = 1.0f;
		public:
			void init(SDL_Window* window, SDL_GLContext gl_context) override;
			void render(SDL_Window* window) override;
			void clear() override;
		};
	}
}