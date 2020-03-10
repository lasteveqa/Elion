#pragma once
#include "GL/glew.h"
#include "Core/Core.h"
#include "SDL/SDL.h"
#include "Renderer/Shader.h"

namespace Elion
{
	struct VertexAttributes
	{
		uint Position, Color;

	};


	class ELION_API OpenGL_API
	{
	private:
		VertexAttributes va;


	public:
		OpenGL_API(uint program)
		{
			OpenGL_Program::set_program(program);
		}
		

		void init();

		inline uint get_vertex_attribute_position() const { return this->va.Position; }
		inline uint get_vertex_attribute_color() const { return this->va.Color; }

	};

}
