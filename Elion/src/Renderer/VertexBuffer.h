#pragma once
#include "glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"
#include <iostream>

namespace Elion
{
	


	class ELION_API VertexBuffer
	{
	private:

		GLuint VBO;

	


	public:
		
		VertexBuffer(float* vertices , uint32_t size);
		~VertexBuffer();

		void bind();
		void unbind();

		inline GLuint get_vbo() { return this->VBO; }
		
	};

}