#pragma once
#include "Core/Core.h"
#include "Light/Light.h"

namespace Elion
{
	class Sun : public Light
	{
	public:
		void init() override;
		void update(const std::string& filename) override;
		void draw() override;
		void free() override;
	};
}