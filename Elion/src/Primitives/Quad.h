#pragma once
#include "Primitives/Primitive.h"

namespace Elion
{
	class ELION_API Quad : public Primitive
	{

	private:


	public:
		Quad();

		void set_color(const Color& color) override;
		void set_position(const Position& position) override;
		void set_size(const Size& size) override;
		void update() override;
		void draw() override;


		void free() override;
	};

}
