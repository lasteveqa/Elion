#include "Quad.h"

namespace Elion
{

	void Quad::set_color(const Color& color)
	{
		this->color = color;
	}

	void Quad::set_position(const Position& position)
	{
		this->position = position;
	}

	void Quad::set_scale(const Scale& scale)
	{
		this->scale = scale;
	}

	void Quad::set_rotation(const Rotation& rotation)
	{
		this->rotation = rotation;
	}



	void Quad::set_projection(const Projection& projection)
	{
		this->projection = projection;
	}


	void Quad::update()
	{
	

		if (!VAO)
		{

			float vertices[] = {
		 -0.5f, -0.5f, 0.0f, 
		  0.5f, -0.5f, 0.0f, 
		  0.5f,  0.5f, 0.0f,
		 -0.5f,  0.5f, 0.0f
			};



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


                uniform vec4 UniformColor;

				void main()
				{
                   
                   color = UniformColor;

				}
        )";




			uint32_t indices[] = { 0 , 1 , 2 , 2 , 3 , 0 };

			this->SizeIndices = sizeof(indices);

			this->program = this->shader->load_native_GLSL(vertexSrc, fragmentSrc);

			glCreateBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glCreateVertexArrays(1, &VAO);
			glBindVertexArray(VAO);


			glCreateBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->SizeIndices * sizeof(float), indices, GL_STATIC_DRAW);



			GLint position_attribute = glGetAttribLocation(program, "a_Position");
			glEnableVertexAttribArray(position_attribute);
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));


			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}
			


	}

	void Quad::draw()
	{
		glUseProgram(this->program);
		
		glBindVertexArray(VAO);


		GLint ColorUniform = glGetUniformLocation(program, "UniformColor");

		glUniform4f(ColorUniform, color.R, color.G, color.B, color.A);

		mat_projection = glm::mat4(1.0f);
		mat_projection = glm::perspective(projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), projection.Near, projection.Far);

		transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(position.X, position.Y, position.Z));
		transform = glm::scale(transform, glm::vec3(scale.X, scale.Y, scale.Z));
		transform = glm::rotate(transform, glm::radians(rotation.Radians), glm::vec3(rotation.X, rotation.Y, rotation.Z));

		/*mat_camera_view = glm::mat4(1.0f);
		mat_camera_view = glm::lookAt(glm::vec3(this->m_Camera.eye.x, this->m_Camera.eye.y, this->m_Camera.eye.z + 1.0f),
			glm::vec3(this->m_Camera.center.x, this->m_Camera.center.y, this->m_Camera.center.z),
			glm::vec3(this->m_Camera.up.x, this->m_Camera.up.y, this->m_Camera.up.z));*/



		this->Translate = glGetUniformLocation(program, "transform");
		this->ViewLocation = glGetUniformLocation(program, "cameraView");
		this->ProjectionLocation = glGetUniformLocation(program, "projection");

		glUniformMatrix4fv(this->Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(this->ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(this->ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));
		

		glDrawElements(GL_TRIANGLES, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);


		glUseProgram(0);
		glBindVertexArray(0);
	}




	void Quad::free()
	{
		glDeleteProgram(this->program);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);

	}
}