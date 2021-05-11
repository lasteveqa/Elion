#include "Plane.h"

namespace Elion
{

	void Plane::set_color(const Color& color)
	{
		this->m_Props.color = color;
	}

	void Plane::set_position(const Position& position)
	{
		this->m_Props.position = position;
	}

	void Plane::set_scale(const Scale& scale)
	{
		this->m_Props.scale = scale;
	}

	void Plane::set_rotation(const Rotation& rotation)
	{
		this->m_Props.rotation = rotation;
	}



	void Plane::set_projection(const Projection& projection)
	{
		this->m_Props.projection = projection;
	}


	void Plane::update()
	{
	

		if (!entity.VAO)
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

			this->entity.Program = this->entity.shader.load_native_GLSL(vertexSrc, fragmentSrc);

			glCreateBuffers(1, &entity.VBO);
			glBindBuffer(GL_ARRAY_BUFFER, entity.VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glCreateVertexArrays(1, &entity.VAO);
			glBindVertexArray(entity.VAO);


			glCreateBuffers(1, &entity.EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity.EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->SizeIndices * sizeof(float), indices, GL_STATIC_DRAW);



			GLint position_attribute = glGetAttribLocation(entity.Program, "a_Position");
			glEnableVertexAttribArray(position_attribute);
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));


			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}
			


	}

	void Plane::draw()
	{
		glUseProgram(this->entity.Program);
		
		glBindVertexArray(entity.VAO);


		GLint ColorUniform = glGetUniformLocation(entity.Program, "UniformColor");

		glUniform4f(ColorUniform, m_Props.color.R, m_Props.color.G, m_Props.color.B, m_Props.color.A);

		mat_projection = glm::mat4(1.0f);
		mat_projection = glm::perspective(m_Props.projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

		transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(m_Props.position.X, m_Props.position.Y, m_Props.position.Z));
		transform = glm::scale(transform, glm::vec3(m_Props.scale.X, m_Props.scale.Y, m_Props.scale.Z));
		transform = glm::rotate(transform, glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));

		/*mat_camera_view = glm::mat4(1.0f);
		mat_camera_view = glm::lookAt(glm::vec3(this->m_Camera.eye.x, this->m_Camera.eye.y, this->m_Camera.eye.z + 1.0f),
			glm::vec3(this->m_Camera.center.x, this->m_Camera.center.y, this->m_Camera.center.z),
			glm::vec3(this->m_Camera.up.x, this->m_Camera.up.y, this->m_Camera.up.z));*/



		GLint Translate = glGetUniformLocation(entity.Program, "transform");
		GLint ViewLocation = glGetUniformLocation(entity.Program, "cameraView");
		GLint ProjectionLocation = glGetUniformLocation(entity.Program, "projection");

		glUniformMatrix4fv(Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));
		

		glDrawElements(GL_TRIANGLES, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);


		glUseProgram(0);
		glBindVertexArray(0);
	}




	void Plane::free()
	{
		glDeleteProgram(this->entity.Program);
		glDeleteBuffers(1, &entity.VBO);
		glDeleteBuffers(1, &entity.EBO);
		glDeleteVertexArrays(1, &entity.VAO);

	}
}