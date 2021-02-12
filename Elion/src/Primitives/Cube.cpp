#include "Cube.h"


namespace Elion
{

	void Cube::set_color(const Color& color)
	{
		this->color = color;
	}

	void Cube::set_position(const Position& position)
	{
		this->position = position;
	}

	void Cube::set_scale(const Scale& scale)
	{
		this->scale = scale;
	}


	void Cube::set_rotation(const Rotation& rotation)
	{
		this->rotation = rotation;
	}


	void Cube::set_projection(const Projection& projection)
	{
		this->projection = projection;
	}



	void Cube::update()
	{



		if (!VAO)
		{


			float vertices[] = {
				 1.0,  1.0,  1.0,
				 1.0, -1.0,  1.0,
				  1.0, -1.0, -1.0,
				   1.0,  1.0, -1.0,
				   -1.0,  1.0, -1.0,
					-1.0,  1.0,  1.0,
				      -1.0, -1.0,  1.0,
	                   -1.0, -1.0, -1.0,
			};


			std::string vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;

            uniform mat4 transform;
            uniform mat4 projection;
            uniform mat4 cameraView;

            out vec4 Normal;
            out vec4 FragPos;

			void main()
			{
                mat4 MVP = projection * cameraView * transform;
				gl_Position = MVP * vec4(a_Position, 1.0);
                FragPos = vec4(a_Position, 1.0f);
                Normal = vec4(a_Position, 1.0f);

			}
		)";


			std::string fragmentSrc = R"(
				#version 430 core

               struct Material {
                 vec4 ambient;
                 vec4 diffuse;
                 vec4 specular;
                 float shininess;
                   }; 
  
                uniform Material material;

				layout(location = 0) out vec4 color;

                uniform vec4 UniformColor;
                uniform vec4 LightColor;
                uniform vec3 LightPos;

                in vec4 FragPos;
                in vec4 Normal;

				void main()
				{
               float ambientStrength = 0.2;
               vec4 ambient = ambientStrength * LightColor;

               vec4 norm = normalize(Normal);

               vec4 lightDir = normalize(vec4(LightPos, 0.0f) - FragPos);

               float diff = max(dot(norm, lightDir), 0.0);

               vec4 diffuse = diff * LightColor;

               vec4 result = (ambient + diffuse) * UniformColor;


                   color = result;

				}
        )";


		// v6----- v5
	//   /|      /|
	//  v1------v0|
	//  | |     | |
	//  | |v7---|-|v4
	//  |/      |/
	//  v2------v3

			uint32_t indices[] = { 
				0, 1, 2, 2, 3, 0,
		0, 3, 4, 4, 5, 0,
		0, 5, 6, 6, 1, 0,
		1, 6, 7, 7, 2, 1,
		7, 4, 3, 3, 2, 7,
		7, 4, 5, 5, 6, 7

				};

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


	void Cube::draw()
	{

		glUseProgram(this->program);

		glBindVertexArray(VAO);

		GLint ColorUniform = glGetUniformLocation(program, "UniformColor");

		glUniform4f(ColorUniform, color.R, color.G, color.B, color.A);

		
			GLint LightUniform = glGetUniformLocation(program, "LightColor");

			glUniform4f(LightUniform, 1.0f, 1.0f, 1.0f, 1.0f);

			GLint LightPosUniform = glGetUniformLocation(program, "LightPos");

			glUniform3f(LightPosUniform, 1.0f, 1.0f, 8.0f);
		
			mat_projection = glm::mat4(1.0f);
			mat_projection = glm::perspective(projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), projection.Near, projection.Far);

			transform = glm::mat4(1.0f);
			transform = glm::translate(transform, glm::vec3(position.X, position.Y, position.Z));
			transform = glm::rotate(transform, glm::radians(rotation.Radians), glm::vec3(rotation.X, rotation.Y, rotation.Z));
			transform = glm::scale(transform, glm::vec3(scale.X, scale.Y, scale.Z));

			mat_camera_view = glm::mat4(1.0f);
			mat_camera_view = glm::lookAt(glm::vec3(this->m_Camera.first.X, this->m_Camera.first.Y, this->m_Camera.first.Z + 8.0f),
				glm::vec3(this->m_Camera.second.X, this->m_Camera.second.Y, this->m_Camera.second.Z),
				glm::vec3(0.0f, 1.0f, 0.0f));

	

		this->Translate = glGetUniformLocation(program, "transform");
		this->ViewLocation = glGetUniformLocation(program, "cameraView");
		this->ProjectionLocation = glGetUniformLocation(program, "projection");

		glUniformMatrix4fv(this->Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(this->ViewLocation, 1, GL_FALSE, glm::value_ptr(mat_camera_view));
		glUniformMatrix4fv(this->ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));

		glDrawElements(GL_TRIANGLE_STRIP, this->SizeIndices, GL_UNSIGNED_SHORT, NULL);
		glDrawElements(GL_TRIANGLE_STRIP, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);


		glUseProgram(0);
		glBindVertexArray(0);
	}


	void Cube::free()
	{
		glUseProgram(0);
		glBindVertexArray(0);

		glDeleteProgram(this->program);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);

	}

}