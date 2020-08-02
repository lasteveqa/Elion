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
			void init() override;
			void render() override;
			void clear() override;
		};
	}
}