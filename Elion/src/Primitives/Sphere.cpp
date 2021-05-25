#include "Primitives/Sphere.h"


namespace Elion
{
	void Sphere::set_color(const Color& color)
	{
		m_Props.color = color;
	}

	void Sphere::set_position(const Position& position)
	{
		m_Props.position = position;
	}

	void Sphere::set_scale(const Scale& scale)
	{
		m_Props.scale = scale;
	}

	void Sphere::set_rotation(const Rotation& rotation)
	{
		m_Props.rotation = rotation;
	}

	void Sphere::set_projection(const Projection& projection)
	{
		m_Props.projection = projection;
	}


	void Sphere::update()
	{
		if (!entity.Program)
		{

			model = Model("img/sphere.obj");
			entity.Program = entity.shader.load_GLSL("Shaders/primitive.vs", "Shaders/primitive.fs");

			light = std::make_unique<Sun>();
			//light->update("img/sphere.obj");
		}
	}


	void Sphere::draw()
	{
		
		

		//Light
		
		
		glUseProgram(entity.Program);

		Cam::render();
		
		//light->draw(entity);


		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(m_Props.projection.Radians), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(m_Props.position.X, m_Props.position.Y - 1.0f, m_Props.position.Z));
		transform = glm::rotate(transform, glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));
		transform = glm::scale(transform, glm::vec3(m_Props.scale.X * 0.015, m_Props.scale.Y * 0.015, m_Props.scale.Z * 0.015));

		glUniformMatrix4fv(glGetUniformLocation(entity.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		glUniformMatrix4fv(glGetUniformLocation(entity.Program, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

		Cam::set_camera("view", entity.Program);
		model.Draw(entity.shader);
		glUseProgram(0);
		
		
	}


	void Sphere::free()
	{
		glUseProgram(0); 
		glBindVertexArray(0);
		glDeleteProgram(this->entity.Program);
	}
}