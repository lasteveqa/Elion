#pragma once
#include "Interface/UIComponent.h"

namespace Elion
{
	namespace Interface
	{
		class Properties : public UIComponent
		{
		private:
			float* color;
		public:
			void handle_color(float* color);
			void init() override;
			void render() override;
			void clear() override;
		};
	}
}