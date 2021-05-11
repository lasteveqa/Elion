#include "Light/Sun.h"

namespace Elion
{

	

	void Sun::init()
	{

	}

	void Sun::update(const std::string& filename)
	{
		if (!program)
		{
			model = Model(filename);
			program = shader.load_GLSL("Shaders/sunlight.vs", "Shaders/sunlight.fs");

		}
	}

	void Sun::draw()
	{



		glm::vec3 diffuseColor = glm::vec3(0.5f); // decrease the influence
		glm::vec3 ambientColor = diffuseColor * glm::vec3(0.4f); // low influence

		glUniform3fv(glGetUniformLocation(program, "viewPos"), 1, glm::value_ptr(Cam::get_eye()));

		glUniform3fv(glGetUniformLocation(program, "light.position"), 1, &glm::vec3(-64.0f, 64.0f, -64.0f)[0]);
		glUniform3fv(glGetUniformLocation(program, "light.direction"), 1, glm::value_ptr(Cam::get_center()));
		glUniform3fv(glGetUniformLocation(program, "light.ambient"), 1, glm::value_ptr(ambientColor));
		glUniform3fv(glGetUniformLocation(program, "light.diffuse"), 1, glm::value_ptr(diffuseColor));
		glUniform3fv(glGetUniformLocation(program, "light.specular"), 1, &glm::vec3(0.5f, 0.5f, 0.5f)[0]);

		glUniform1f(glGetUniformLocation(program, "light.cutOff"), glm::radians(12.5f));
		glUniform1f(glGetUniformLocation(program, "light.outerCutOff"), glm::radians(17.5f));
		glUniform1f(glGetUniformLocation(program, "light.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(program, "light.linear"), 0.09f);
		glUniform1f(glGetUniformLocation(program, "light.quadratic"), 0.032f);

		glUniform1i(glGetUniformLocation(program, "material.diffuse"), 0);
		glUniform1i(glGetUniformLocation(program, "material.specular"), 1);
		glUniform1f(glGetUniformLocation(program, "material.shininess"), 32.0f);
	

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), 0.1f, 100.0f);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));

		Cam::render();

		glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		glUniformMatrix4fv(glGetUniformLocation(program, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

		Cam::set_camera("view", program);
		model.Draw(shader);
		glUseProgram(0);
	}


	void Sun::free()
	{
		//glDeleteProgram(program);
	}
}