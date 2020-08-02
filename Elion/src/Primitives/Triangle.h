#pragma once
#include "Primitives/Primitive.h"

namespace Elion
{
	class ELION_API Triangle : public Primitive
	{

	private:

	public:

		Triangle();

		void set_color(const Color& color) override;
		void set_position(const Position& position) override;
		void set_size(const Size& size) override;
		void update() override;
		void draw() override;

		bool free_vao();
	};

}

