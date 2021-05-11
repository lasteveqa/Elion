#include "Grid/Grid.h"

namespace Elion
{
	void Grid::init()
	{
	/*	float vertices[] = {
	 -0.5f, -0.5f, 0.0f,
	  0.5f, -0.5f, 0.0f,
	  0.5f,  0.5f, 0.0f,
	 -0.5f,  0.5f, 0.0f
		};*/

		

		std::string vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;

            uniform mat4 transform;
            uniform mat4 projection;
            uniform mat4 cameraView;

			void main()
			{
                mat4 MVP = projection * cameraView * transform;
				gl_Position = MVP * vec4(a_Position, 1.0);
                	
			}
		)";


		std::string fragmentSrc = R"(
				#version 430 core

				layout(location = 0) out vec4 color;


                

				void main()
				{
                   
                   color = vec4( 1.0f, 1.0f, 1.0f, 1.0f);

				}
        )";

		generate_grid(60, this->m_Vectices, this->m_Indices);

		this->m_Program = this->shader->load_native_GLSL(vertexSrc, fragmentSrc);

		glCreateBuffers(1, &this->m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
		glBufferData(GL_ARRAY_BUFFER, this->m_Vectices.size() * sizeof(glm::uvec3), glm::value_ptr(this->m_Vectices[0]), GL_STATIC_DRAW);

		glCreateVertexArrays(1, &this->m_VAO);
		glBindVertexArray(this->m_VAO);

		glCreateBuffers(1, &this->m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_Indices.size() * sizeof(glm::uvec3), glm::value_ptr(this->m_Indices[0]), GL_STATIC_DRAW);




		GLint position_attribute = glGetAttribLocation(this->m_Program, "a_Position");
		glEnableVertexAttribArray(position_attribute);
		glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));


		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Grid::update()
	{

	}

	void Grid::draw()
	{
		glUseProgram(this->m_Program);
		glBindVertexArray(this->m_VAO);


		glm::mat4 mat_projection = glm::mat4(1.0f);
		mat_projection = glm::perspective(glm::radians(45.0f), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), 0.1f, 1000.0f);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(-33.0f, 0.0f, -20.0f));
		transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));
		Cam::render();



		GLint Translate = glGetUniformLocation(this->m_Program, "transform");
		//GLint ViewLocation = glGetUniformLocation(this->m_Program, "cameraView");
		GLint ProjectionLocation = glGetUniformLocation(this->m_Program, "projection");

		glUniformMatrix4fv(Translate, 1, GL_FALSE, glm::value_ptr(transform));
		//glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));

		Cam::set_camera("cameraView", this->m_Program);

		

		glDrawElements(GL_LINES, this->m_IndicesSize, GL_UNSIGNED_INT, NULL);
		glUseProgram(0);
		glBindVertexArray(0);
	}


	void Grid::generate_grid(int N, std::vector<glm::vec3>& vertices, std::vector<glm::uvec4>& indices)
	{
		
		for (int j = 0; j <= N; ++j) {
			for (int i = 0; i <= N; ++i) {
				float x = (float)i / (float)N * 60;
				float y = 0;
				float z = (float)j / (float)N * 60;
				vertices.push_back(glm::vec3(x, y, z));
			}
		}

		for (int j = 0; j < N; ++j) {
			for (int i = 0; i < N; ++i) {

				int row1 = j * (N + 1);
				int row2 = (j + 1) * (N + 1);

				indices.push_back(glm::uvec4(row1 + i, row1 + i + 1, row1 + i + 1, row2 + i + 1));
				indices.push_back(glm::uvec4(row2 + i + 1, row2 + i, row2 + i, row1 + i));

			}
		}

		this->m_IndicesSize = (GLuint)indices.size() * 4;
	}
}