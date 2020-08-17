#pragma once
#include "Interface/UIComponent.h"
#include <map>

namespace Elion
{
	namespace Interface
	{
		
		class SceneOutliner : public UIComponent
		{
		private:
			bool m_Clicked = false;

			void draw_no_stencil();
			void draw_stencil();
			void draw_scaled_version_fo_primitives();


		public:
			void init();
			void render();
			void clear();
		};
	}
}