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
			entity.Program = entity.shader.load_GLSL("Shaders/obj.vs", "Shaders/obj.fs");

			light = std::make_unique<Sun>();
			light->update("img/sphere.obj");
		}
	}


	void Sphere::draw()
	{
		light->draw();
		

		//Light
		glUseProgram(entity.Program);
		//glm::vec3 lightPos(-8.0f, 8.0f, -8.0f);

		glm::vec4 UniformColor = glm::vec4(m_Props.color.R, m_Props.color.G, m_Props.color.B, m_Props.color.A);

		//glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // decrease the influence
		//glm::vec3 ambientColor = diffuseColor * glm::vec3(0.4f); // low influence

		//glUniform3fv(glGetUniformLocation(entity.Program, "viewPos"), 1, glm::value_ptr(Cam::get_eye()));

		//glUniform3fv(glGetUniformLocation(entity.Program, "light.position"), 1, glm::value_ptr(lightPos));
		//glUniform3fv(glGetUniformLocation(entity.Program, "light.ambient"), 1, glm::value_ptr(ambientColor));
		//glUniform3fv(glGetUniformLocation(entity.Program, "light.diffuse"), 1, glm::value_ptr(diffuseColor));
		//glUniform3fv(glGetUniformLocation(entity.Program, "light.specular"), 1, &glm::vec3(0.5f, 0.5f, 0.5f)[0]);

		//glUniform3fv(glGetUniformLocation(entity.Program, "material.ambient"), 1, &glm::vec3(0.9f, 0.9f, 0.9f)[0]);
		//glUniform3fv(glGetUniformLocation(entity.Program, "material.diffuse"), 1, &glm::vec3(0.5f, 0.5f, 0.5f)[0]);
		//glUniform3fv(glGetUniformLocation(entity.Program, "material.specular"), 1, &glm::vec3(0.5f, 0.5f, 0.5f)[0]);
		//glUniform3fv(glGetUniformLocation(entity.Program, "material.shininess"), 1, &glm::vec3(32.0f, 32.0f, 32.0f)[0]);

		glUniform3fv(glGetUniformLocation(entity.Program, "UniformColor"), 1, glm::value_ptr(UniformColor));

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(m_Props.projection.Radians), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), m_Props.projection.Near, m_Props.projection.Far);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(m_Props.position.X, m_Props.position.Y, m_Props.position.Z));
		transform = glm::rotate(transform, glm::radians(m_Props.rotation.Radians), glm::vec3(m_Props.rotation.X, m_Props.rotation.Y, m_Props.rotation.Z));
		transform = glm::scale(transform, glm::vec3(m_Props.scale.X, m_Props.scale.Y, m_Props.scale.Z));

		Cam::render();

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