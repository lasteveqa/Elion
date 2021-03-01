#include "Triangle.h"


namespace Elion
{
	void Triangle::set_color(const Color& color)
	{
		this->color = color;
	}
	void Triangle::set_position(const Position& position)
	{
		this->position = position;
	}

	void Triangle::set_scale(const Scale& scale)
	{
		this->scale = scale;
	}

	void Triangle::set_rotation(const Rotation& rotation)
	{
		this->rotation = rotation;
	}

	void Triangle::set_projection(const Projection& projection)
	{
		this->projection = projection;
	}


	void Triangle::update()
	{

		if (!VAO)
		{
			float vertices[] = {
			 -0.5f, -0.5f, 0.0f,
			  0.5f, -0.5f, 0.0f,
			  0.0f,  1.0f, 0.0f
			};

			std::string vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;

            uniform mat4 scale;
            uniform mat4 rotate;
            uniform mat4 translate;
            uniform mat4 projection;
            
            out vec4 v_Color;
			void main()
			{
                mat4 MVP = projection * translate * rotate;
				gl_Position = MVP * scale * vec4(a_Position, 1.0);
    
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

			uint32_t indices[] = { 0 , 1 , 2 };

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

	void Triangle::draw()
	{

		glUseProgram(this->program);

		glBindVertexArray(VAO);


		GLint ColorUniform = glGetUniformLocation(program, "UniformColor");

		glUniform4f(ColorUniform, color.R, color.G, color.B, color.A);

	//	mat_camera_view = glm::translate(glm::mat4(1.0f), glm::vec3(this->m_Camera.eye.x, this->m_Camera.eye.y, this->m_Camera.eye.z));
		mat_view = glm::translate(glm::mat4(1.0f), glm::vec3(position.X, position.Y, position.Z));

		mat_camera_view = mat_view * mat_camera_view;

		mat_rotate = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.Radians), glm::vec3(rotation.X, rotation.Y, rotation.Z));
		mat_scale = glm::scale(glm::mat4(1.0f), glm::vec3(scale.X, scale.Y, scale.Z));

		mat_projection = glm::perspective(projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), projection.Near, projection.Far);

		this->ScaleLocation = glGetUniformLocation(program, "scale");
		this->RotateLocation = glGetUniformLocation(program, "rotate");
		this->ViewLocation = glGetUniformLocation(program, "translate");
		this->ProjectionLocation = glGetUniformLocation(program, "projection");

		glUniformMatrix4fv(this->RotateLocation, 1, GL_FALSE, glm::value_ptr(mat_rotate));
		glUniformMatrix4fv(this->ScaleLocation, 1, GL_FALSE, glm::value_ptr(mat_scale));
		glUniformMatrix4fv(this->ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(this->ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));


		glDrawElements(GL_TRIANGLES, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);


		glUseProgram(0);
		glBindVertexArray(0);
	}



	void Triangle::free()
	{
		glDeleteProgram(this->program);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);
	}
}