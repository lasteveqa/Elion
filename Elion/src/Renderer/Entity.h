#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexBuffer.h" 

namespace Elion
{
    struct Entity
   {
	   GLuint VBO, VAO, EBO, Texture, Program;
	   Shader shader;
   };

}