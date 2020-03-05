#pragma once
#include "GL/glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"

namespace Elion
{
	
	class ELION_API VertexArray
	{
	private:
		static uint32_t VAO;

	public:
		VertexArray();
		~VertexArray();

		void bind();
		void unbind();

		
	};

}