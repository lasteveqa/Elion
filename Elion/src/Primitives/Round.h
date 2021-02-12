#pragma once
#include "Primitives/Primitive.h"
#include <cmath>

namespace Elion
{
	class ELION_API Round : public Primitive
	{

	private:

		float m_Radius = 1.0f;
		const float m_DoublePI = 3.141592 * 2;

		std::vector<GLfloat> vertices;

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
