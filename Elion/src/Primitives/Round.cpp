#include "Primitives/Round.h"


namespace Elion
{

	void Round::set_color(const Color& color)
	{
		this->m_Props.color = color;
	}

	void Round::set_position(const Position& position)
	{
		this->m_Props.position = position;
	}

	void Round::set_scale(const Scale& scale)
	{
		this->m_Props.scale = scale;
	}

	void Round::set_rotation(const Rotation& rotation)
	{
		this->m_Props.rotation = rotation;
	}


	void Round::set_projection(const Projection& projection)
	{
		this->m_Props.projection = projection;
	}


	void Round::update()
	{
		if (!entity.VAO)
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


			this->entity.Program = this->entity.shader.load_native_GLSL(vertexSrc, fragmentSrc);

			glCreateBuffers(1, &entity.VBO);
			glBindBuffer(GL_ARRAY_BUFFER, entity.VBO);
			glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

			glCreateVertexArrays(1, &entity.VAO);
			glBindVertexArray(entity.VAO);



			GLint position_attribute = glGetAttribLocation(entity.Program, "a_Position");
			glEnableVertexAttribArray(position_attribute);
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));




			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}

	}

	void Round::draw()
	{

		glUseProgram(this->entity.Program);

		glBindVertexArray(entity.VAO);

		GLint ColorUniform = glGetUniformLocation(entity.Program, "UniformColor");

		glUniform4f(ColorUniform, m_Props.color.R, m_Props.color.G, m_Props.color.B, m_Props.color.A);

		mat_view = glm::mat4(1.0f);
		//Position and view
		//mat_camera_view = glm::translate(glm::mat4(1.0f), glm::vec3(this->m_Camera.eye.x, this->m_Camera.eye.y, this->m_Camera.eye.z));
		mat_view = glm::translate(glm::mat4(1.0f), glm::vec3(m_Props.position.X, m_Props.position.Y, m_Props.position.Z));

		mat_camera_view = mat_view * mat_camera_view;

		mat_rotate = glm::rotate(glm::mat4(1.0f), glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));
		mat_scale = glm::scale(glm::mat4(1.0f), glm::vec3(m_Props.scale.X, m_Props.scale.Y, m_Props.scale.Z));

		mat_projection = glm::perspective(m_Props.projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

		GLint ScaleLocation = glGetUniformLocation(entity.Program, "scale");
		GLint RotateLocation = glGetUniformLocation(entity.Program, "rotate");
		GLint ViewLocation = glGetUniformLocation(entity.Program, "translate");
		GLint ProjectionLocation = glGetUniformLocation(entity.Program, "projection");

		glUniformMatrix4fv(RotateLocation, 1, GL_FALSE, glm::value_ptr(mat_rotate));
		glUniformMatrix4fv(ScaleLocation, 1, GL_FALSE, glm::value_ptr(mat_scale));
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));


		glDrawArrays(GL_LINE_LOOP, 0 , this->vertices.size());


		glUseProgram(0);
		glBindVertexArray(0);


	}




	void Round::free()
	{
		this->vertices.clear();
		glDeleteProgram(this->entity.Program);
		glDeleteBuffers(1, &entity.VBO);
		glDeleteVertexArrays(1, &entity.VAO);

	}
}