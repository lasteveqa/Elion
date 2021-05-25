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



		if (!entity.Program)
		{
			model = Model("img/cube.obj");

			entity.Program = entity.shader.load_GLSL("Shaders/primitive.vs", "Shaders/primitive.fs");

			
			this->light = std::make_unique<Sun>();
		}
	}


	void Cube::draw()
	{

		glUseProgram(this->entity.Program);

		

		Cam::render();

		light->draw(entity);

			glm::mat4 projection = glm::mat4(1.0f);
			projection = glm::perspective(glm::radians(m_Props.projection.Radians), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

			glm::mat4 transform = glm::mat4(1.0f);
			transform = glm::translate(transform, glm::vec3(m_Props.position.X, m_Props.position.Y, m_Props.position.Z));
			transform = glm::rotate(transform, glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));
			transform = glm::scale(transform, glm::vec3(m_Props.scale.X, m_Props.scale.Y, m_Props.scale.Z));

			glUniformMatrix4fv(glGetUniformLocation(entity.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glUniformMatrix4fv(glGetUniformLocation(entity.Program, "transform"), 1, GL_FALSE, glm::value_ptr(transform));


		//Setting Camera
		Cam::set_camera("view", this->entity.Program);

		model.Draw(entity.shader);

		glUseProgram(0);
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