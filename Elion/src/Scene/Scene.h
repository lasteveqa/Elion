#pragma once

#include "Core/Core.h"
#include "glew.h"
#include "Primitives/Triangle.h"
#include "Primitives/Quad.h"

namespace Elion
{
	class Scene
	{
	private:
		float Width = 700.0f;
		float Height = 700.0f;
		
		std::vector<GLuint> m_VecVAO;

		GLuint VAO;

		static Triangle m_triangle;
		static Quad m_quad;

		static std::vector<Primitive*> m_Primitives;

	public:
		static void add_primitive(PrimitiveTypes pt);
		static void set_properties(Color& color, Size& size, Position& position);
		static void draw();


	};
}