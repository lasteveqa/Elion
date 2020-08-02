#pragma once
#include "Interface/UIComponent.h"

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
			void init() override;
			void render() override;
			void clear() override;
		};
	}
}