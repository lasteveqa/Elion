#pragma once
#include "GL/glew.h"
#include "Core/Log.h"
#include "Core/Core.h"
#include <string>

namespace Elion
{
	class ELION_API Shader
	{
	
		

	public:

		static GLuint load_shader(const char* s_vertexShader, const char* s_fragmentShader);
	 
	};


}
