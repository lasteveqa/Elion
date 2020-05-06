#pragma once
#include "GL/glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"
#include "Renderer/VertexBuffer.h"
namespace Elion
{
	
	class ELION_API VertexArray
	{
	private:

		uint VAO;
	

	public:
		VertexArray();
		~VertexArray();

		void bind();
		void unbind();

	
		void bind_vertex_buffers();
		void unbind_vertex_buffers();

		inline GLuint get_vao() { return this->VAO; }

		
	};

}