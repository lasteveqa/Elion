#pragma once
#include "Core/Core.h"
#include "Light/Light.h"

namespace Elion
{
	class Sun : public Light
	{
	public:
		void init() override;
		void update() override;
		void draw() override;
	};
}