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
			bool m_SelectedItem = false;

			void draw_no_stencil();
			void draw_stencil();
			void draw_scaled_version_fo_primitives();

			enum class Stencil
			{
				OFF = 0,
				ON = 1
			};

			Stencil m_StencilTest;

		public:
			void init();
			void render();
			void clear();
		};
	}
}