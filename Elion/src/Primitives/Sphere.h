#pragma once
#include "Primitives/Primitive.h"

namespace Elion
{
	class ELION_API Sphere : public Primitive
	{
	private:

		int m_Lats = 10;
		int m_Longs = 10;

		std::vector<GLfloat> m_Vertices;
		std::vector<GLfloat> m_TexCoords;
		std::vector<GLfloat> m_Normals;
		std::vector<uint> m_Indices;

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