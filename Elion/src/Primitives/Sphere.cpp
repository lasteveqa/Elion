#include "Sphere.h"


namespace Elion
{

	void Sphere::set_color(const Color& color)
	{
		this->color = color;
	}

	void Sphere::set_position(const Position& position)
	{
		this->position = position;
	}

	void Sphere::set_scale(const Scale& scale)
	{
		this->scale = scale;
	}


	void Sphere::set_rotation(const Rotation& rotation)
	{
		this->rotation = rotation;
	}




	void Sphere::set_projection(const Projection& projection)
	{
		this->projection = projection;
	}



	void Sphere::update()
	{
		if (!VAO)
		{

			

			//this->PrimitiveMeshLoader.loadOBJ("img/sphere.obj");

			std::string vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;

            uniform mat4 transform;
            uniform mat4 projection;
            uniform mat4 cameraView;

			void main()
			{
                mat4 MVP = projection * cameraView  * transform;
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

			this->program = this->shader->load_native_GLSL(vertexSrc, fragmentSrc);

			//for (std::size_t i = 0; i < PrimitiveMeshLoader.get_face().size(); i+=3)
			//{
				//this->m_Indices.push_back(PrimitiveMeshLoader.get_face()[i]);
		    //}

			

			/*glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, this->PrimitiveMeshLoader.get_p_vertices().size() * sizeof(GLfloat), this->PrimitiveMeshLoader.get_p_vertices().data(), GL_STATIC_DRAW);

			GLint position_attribute = glGetAttribLocation(program, "a_Position");
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(position_attribute);



		glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(uint), m_Indices.data(), GL_STATIC_DRAW);*/

		}
	}


	void Sphere::draw()
	{

		glUseProgram(this->program);


		glBindVertexArray(VAO);

		GLint ColorUniform = glGetUniformLocation(program, "UniformColor");

		glUniform4f(ColorUniform, color.R, color.G, color.B, color.A);

		mat_projection = glm::mat4(1.0f);
		mat_projection = glm::perspective(glm::radians(projection.Radians), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), projection.Near, projection.Far);

		transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(position.X, position.Y, position.Z));
		transform = glm::scale(transform, glm::vec3(scale.X, scale.Y, scale.Z));
		transform = glm::rotate(transform, glm::radians(rotation.Radians), glm::vec3(rotation.X, rotation.Y, rotation.Z));
		

		Cam::render();

		this->Translate = glGetUniformLocation(program, "transform");
		this->ProjectionLocation = glGetUniformLocation(program, "projection");

		glUniformMatrix4fv(this->Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(this->ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));

		//Setting Camera
		Cam::set_camera("cameraView", this->program);
		glDrawElements(GL_LINE_LOOP, this->m_Indices.size(), GL_UNSIGNED_INT, 0);


		glUseProgram(0);
		glBindVertexArray(0);
	}


	void Sphere::free()
	{
		glUseProgram(0);
		glBindVertexArray(0);

		glDeleteProgram(this->program);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);

	}

}