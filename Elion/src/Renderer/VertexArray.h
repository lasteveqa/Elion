#pragma once
#include "GL/glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"

namespace Elion
{
	
	class ELION_API VertexArray
	{
	private:
		uint32_t VAO;

	public:
		VertexArray();
		~VertexArray();

		void bind();
		void unbind();

		
	};

}