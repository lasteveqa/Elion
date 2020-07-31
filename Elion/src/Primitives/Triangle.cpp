#include "Triangle.h"


namespace Elion
{
	Triangle::Triangle()
	{
		
	}

	void Triangle::set_color(const Color& color)
	{
		this->color = color;
		this->changes = true;
	}
	void Triangle::set_position(const Position& position)
	{
		this->position = position;
	}

	void Triangle::set_size(const Size& size)
	{
		this->size = size;
	}


	bool Triangle::is_set()
	{
		return this->changes;
	}


	void Triangle::update()
	{
		if (changes)
		{
			float vertices[] = {
			 -0.5f, -0.5f, 0.0f, this->color.R , this->color.G , this->color.B , this->color.A,
			  0.5f, -0.5f, 0.0f, this->color.R , this->color.G , this->color.B , this->color.A,
			  0.0f,  1.0f, 0.0f, this->color.R , this->color.G , this->color.B , this->color.A
			};

			std::string vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 translate;
            
            out vec4 v_Color;
			void main()
			{
                v_Color = a_Color;
				gl_Position = translate *  vec4(a_Position, 1.0);	
    
			}
		)";

			std::string fragmentSrc = R"(
			#version 430 core
			
			layout(location = 0) out vec4 color;

            in vec4 v_Color;

			void main()
			{
				color = v_Color;
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
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(0 * sizeof(float)));

			GLint color_attribute = glGetAttribLocation(program, "a_Color");
			glEnableVertexAttribArray(color_attribute);
			glVertexAttribPointer(color_attribute, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));


			this->changes = false;


		}
	}

	void Triangle::draw()
	{
		

		glUseProgram(this->program);
		
		glBindVertexArray(VAO);

		glm::mat4 scale = glm::mat4(1.0f);

		scale = Elion::Camera::scale(scale, size.X, size.Y, size.Z);


		glm::mat4 move_matrix = glm::mat4(1.0f);
		move_matrix = glm::translate(move_matrix, glm::vec3(position.X, position.Y, position.Z)) * scale;
		this->location = glGetUniformLocation(program, "translate");
		glUniformMatrix4fv(this->location, 1, GL_FALSE, glm::value_ptr(move_matrix));

		glDrawElements(GL_TRIANGLES, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);

		glUseProgram(0);
		glBindVertexArray(0);
		
	}
}