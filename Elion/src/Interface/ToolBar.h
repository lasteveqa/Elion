#pragma once
#include "Interface/UIComponent.h"

namespace Elion
{

	namespace Interface
	{
		
		class ToolBar : public UIComponent
		{

		public:
			void init() override;
			void render() override;
			void clear() override;
		};
	}
}