#pragma once
#include "GL/glew.h"
#include "Core/Log.h"
#include "Core/Core.h"
#include <string>
#include "Renderer/OpenGL_Program.h"
namespace Elion
{
	class ELION_API Shader
	{
	
		

	public:
		Shader(const char* s_vertexShader, const char* s_fragmentShader);

		static GLuint load_shader(const char* s_vertexShader, const char* s_fragmentShader);
	 
	};


}
