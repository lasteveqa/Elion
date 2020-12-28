#pragma once
#include "Interface/UIComponent.h"

namespace Elion
{

	namespace Interface
	{

		class MainScene : public UIComponent
		{
		private:

		public:

			void rotate();
			void move_camera();

			void init() override;
			void render() override;
			void clear() override;
		};
	}
}