#include "Cube.h"


namespace Elion
{

	void Cube::set_color(const Color& color)
	{
		this->m_Props.color = color;
	}

	void Cube::set_position(const Position& position)
	{
		this->m_Props.position = position;
	}

	void Cube::set_scale(const Scale& scale)
	{
		this->m_Props.scale = scale;
	}


	void Cube::set_rotation(const Rotation& rotation)
	{
		this->m_Props.rotation = rotation;
	}

	


	void Cube::set_projection(const Projection& projection)
	{
		this->m_Props.projection = projection;
	}



	void Cube::update()
	{



		if (!entity.VAO)
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
                FragPos = vec4(transform * vec4(a_Position, 1.0f));
                Normal = normalize(vec4(a_Position, 1.0f));

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
               float ambientStrength = 0.1;
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
		        3, 4, 7, 7, 2, 3,
		        7, 4, 5, 5, 6, 7

				};

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


	void Cube::draw()
	{

		glUseProgram(this->entity.Program);

		
		glBindVertexArray(entity.VAO);

		GLint ColorUniform = glGetUniformLocation(entity.Program, "UniformColor");

		glUniform4f(ColorUniform, m_Props.color.R, m_Props.color.G, m_Props.color.B, m_Props.color.A);

		
			GLint LightUniform = glGetUniformLocation(entity.Program, "LightColor");

			glUniform4f(LightUniform, 1.0f, 1.0f, 1.0f, 1.0f);

			GLint LightPosUniform = glGetUniformLocation(entity.Program, "LightPos");

			glUniform3f(LightPosUniform, -8.0f, 8.0f, -8.0f);
		
			mat_projection = glm::mat4(1.0f);
			mat_projection = glm::perspective(glm::radians(m_Props.projection.Radians), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

			transform = glm::mat4(1.0f);
			transform = glm::translate(transform, glm::vec3(m_Props.position.X, m_Props.position.Y, m_Props.position.Z));
			transform = glm::rotate(transform, glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));
			transform = glm::scale(transform, glm::vec3(m_Props.scale.X, m_Props.scale.Y, m_Props.scale.Z));

			Cam::render();
	
		GLint Translate = glGetUniformLocation(entity.Program, "transform");
		GLint ProjectionLocation = glGetUniformLocation(entity.Program, "projection");

		glUniformMatrix4fv(Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));

		//Setting Camera
		Cam::set_camera("cameraView", this->entity.Program);

		glDrawElements(GL_TRIANGLE_STRIP, this->SizeIndices, GL_UNSIGNED_SHORT, NULL);
		glDrawElements(GL_TRIANGLE_STRIP, this->SizeIndices, GL_UNSIGNED_INT, (void*)0);


		glUseProgram(0);
		glBindVertexArray(0);
	}


	void Cube::free()
	{
		glUseProgram(0);
		glBindVertexArray(0);

		glDeleteProgram(this->entity.Program);
		glDeleteBuffers(1, &entity.VBO);
		glDeleteBuffers(1, &entity.EBO);
		glDeleteVertexArrays(1, &entity.VAO);

	}

}