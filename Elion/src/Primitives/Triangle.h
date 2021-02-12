#pragma once
#include "Primitives/Primitive.h"

namespace Elion
{
	class ELION_API Triangle : public Primitive
	{

	private:

	public:

		void set_color(const Color& color) override;
		void set_position(const Position& position) override;
		void set_scale(const Scale& scale) override;
		void set_rotation(const Rotation& rotation) override;
		void set_projection(const Projection& projection) override;

		void update() override;
		void draw() override;

		void free() override;
	};

}

