#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Scene/SceneCamera.h"
namespace Elion
{
	class Grid
	{
	private:

		GLuint m_VBO, m_VAO, m_EBO, m_Program;
		std::shared_ptr<Shader> shader;


		std::vector<glm::vec3> m_Vectices;
		std::vector<glm::uvec4> m_Indices;

		int m_IndicesSize = 0;

	public:
		void init();
		void update();
		void draw();

		void generate_grid(int N, std::vector<glm::vec3>& vertices, std::vector<glm::uvec4>& indices);

		float f(float x, float y)
		{
			return sin(x * 2.0f * 3.141526f) * sin(y * 2.0f * 3.141526f) * 0.1f;
		}

		~Grid() {
			glUseProgram(0);
			glBindVertexArray(0);

			glDeleteProgram(this->m_Program);
			glDeleteBuffers(1, &this->m_VBO);
			glDeleteVertexArrays(1, &this->m_VAO);
		}
	};
}