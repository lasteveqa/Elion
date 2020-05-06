#pragma once
#include "GL/glew.h"
#include "Core/Core.h"
#include "SDL/SDL.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexIndices.h"
#include "Renderer/OBJLoader.h"
#include "Renderer/Attributes.h"

namespace Elion
{


	class ELION_API OpenGL_API
	{
	private:

		
	

	public:
		
		static std::shared_ptr<VertexArray> vao() 
		{
			std::shared_ptr<VertexArray> _vao;
			return _vao; 
		}
		static std::shared_ptr<VertexBuffer> vbo() 
		{ 
			std::shared_ptr<VertexBuffer> _vbo;
			return _vbo; 
		}
		static std::shared_ptr<VertexIndices> ebo()
		{
			std::shared_ptr<VertexIndices> _ebo;
			return _ebo;
		}
		
	};

}
