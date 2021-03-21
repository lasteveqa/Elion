#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Scene/SceneCamera.h"
#include "Renderer/Texture.h"

namespace Elion
{
	struct FileVertex
	{
		glm::vec3 VPosition;
		glm::vec2 TexCoords;
		glm::vec3 Normal;	
	};


	class FileLoader
	{
	protected:


		GLuint VAO, VBO, EBO, Program;

		std::shared_ptr<Shader> shader;

		Texture texture;
	};
}