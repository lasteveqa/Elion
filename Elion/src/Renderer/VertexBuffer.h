#pragma once
#include "glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"

namespace Elion
{
	class ELION_API VertexBuffer
	{
	private:
		uint32_t VBO;

	public:
		VertexBuffer(float* vertices, uint32_t size);
		~VertexBuffer();

		void bind();
		void unbind();

		
	};

}