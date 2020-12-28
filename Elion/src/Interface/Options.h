#pragma once
#include "Interface/UIComponent.h"

namespace Elion
{
	namespace Interface
	{
		class Options : public UIComponent
		{
		private:
			bool m_IsClicked = false;
			bool m_Opened = false;
			int x = 0, y = 0;
			const float m_Width = 250.0f;
			const float m_Height = 700.0f;
		public:
			void init() override;
			void render() override;
			void clear() override;

			bool& is_opened();
		};
	}
}
