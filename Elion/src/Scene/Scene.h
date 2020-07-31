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

	public:
		static void draw_triangle();
		static void draw_quad();

		static bool is_TrianglePicked(bool is_picked);
	};
}