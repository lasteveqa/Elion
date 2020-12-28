#include "Primitives/Round.h"


namespace Elion
{
	Round::Round()
	{


	}

	void Round::set_color(const Color& color)
	{
		this->color = color;
	}

	void Round::set_position(const Position& position)
	{
		this->position = position;
	}

	void Round::set_size(const Size& size)
	{
		this->size = size;
	}

	void Round::set_rotation(const Rotation& rotation)
	{
		this->rotation = rotation;
	}

	void Round::set_projection(const Projection& projection)
	{
		this->projection = projection;
	}


	void Round::update()
	{
		if (!VAO)
		{
			for (int i = 0; i < 100; ++i)
			{
			
				vertices.push_back(std::cos(i * this->m_DoublePI / 100) * this->m_Radius);
				vertices.push_back(std::sin(i * this->m_DoublePI / 100) * this->m_Radius);
				vertices.push_back(0.0f);
			}



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
				gl_Position = MVP * scale * vec4(a_Position, 1.0) ;
                	
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


			this->program = this->shader->load_native_GLSL(vertexSrc, fragmentSrc);

			glCreateBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

			glCreateVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			GLint position_attribute = glGetAttribLocation(program, "a_Position");
			glEnableVertexAttribArray(position_attribute);
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));




			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}

	}

	void Round::draw()
	{

		glUseProgram(this->program);

		glBindVertexArray(VAO);

		this->mat_rotate = glm::mat4(1.0f);
		this->mat_scale = glm::mat4(1.0f);
		this->mat_view = glm::mat4(1.0f);
		this->mat_projection = glm::mat4(1.0f);
		this->mat_model = glm::mat4(1.0f);

		GLint ColorUniform = glGetUniformLocation(program, "UniformColor");

		glUniform4f(ColorUniform, color.R, color.G, color.B, color.A);


		//Position and view
		mat_view = glm::translate(glm::mat4(1.0f), glm::vec3(position.X, position.Y, -8.0f));
		mat_model = glm::translate(glm::mat4(1.0f), glm::vec3(position.X, position.Y, position.Z));

		mat_view = mat_model * mat_view;

		mat_rotate = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.Radians), glm::vec3(rotation.X, rotation.Y, rotation.Z));
		mat_scale = glm::scale(glm::mat4(1.0f), glm::vec3(size.X, size.Y, size.Z));

		mat_projection = glm::perspective(projection.Radians, (GLfloat)(projection.Width / projection.Height), projection.Near, projection.Far);

		this->ScaleLocation = glGetUniformLocation(program, "scale");
		this->RotateLocation = glGetUniformLocation(program, "rotate");
		this->ViewLocation = glGetUniformLocation(program, "translate");
		this->ProjectionLocation = glGetUniformLocation(program, "projection");

		glUniformMatrix4fv(this->RotateLocation, 1, GL_FALSE, glm::value_ptr(mat_rotate));
		glUniformMatrix4fv(this->ScaleLocation, 1, GL_FALSE, glm::value_ptr(mat_scale));
		glUniformMatrix4fv(this->ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_view));
		glUniformMatrix4fv(this->ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));


		glDrawArrays(GL_TRIANGLE_FAN, 0 , this->vertices.size());


		glUseProgram(0);
		glBindVertexArray(0);


	}




	void Round::free()
	{
		glDeleteProgram(this->program);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);

	}
}