#include "Light/Sun.h"

namespace Elion
{

	

	void Sun::init()
	{

	}

	void Sun::update()
	{

	}

	void Sun::draw(Entity& entity)
	{
		glUniform1i(glGetUniformLocation(entity.Program, "foo"), true);


		glUniform3fv(glGetUniformLocation(entity.Program, "viewPos"), 1, glm::value_ptr(Cam::get_eye()));

		
		glm::vec3 diffuseColor = glm::vec3(0.7f); // decrease the influence
		glm::vec3 ambientColor = diffuseColor * glm::vec3(0.4f); // low influence

		glUniform3fv(glGetUniformLocation(entity.Program, "light.position"), 1, &glm::vec3(-64.0f, 64.0f, -64.0f)[0]);
		glUniform3fv(glGetUniformLocation(entity.Program, "light.direction"), 1, &glm::vec3(0.0f, 0.0f, 0.0f)[0]);
		glUniform3fv(glGetUniformLocation(entity.Program, "light.ambient"), 1, glm::value_ptr(ambientColor));
		glUniform3fv(glGetUniformLocation(entity.Program, "light.diffuse"), 1, glm::value_ptr(diffuseColor));
		glUniform3fv(glGetUniformLocation(entity.Program, "light.specular"), 1, &glm::vec3(0.5f, 0.5f, 0.5f)[0]);

		glUniform1f(glGetUniformLocation(entity.Program, "light.cutOff"), glm::radians(12.5f));
		glUniform1f(glGetUniformLocation(entity.Program, "light.outerCutOff"), glm::radians(17.5f));
		glUniform1f(glGetUniformLocation(entity.Program, "light.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(entity.Program, "light.linear"), 0.09f);
		glUniform1f(glGetUniformLocation(entity.Program, "light.quadratic"), 0.032f);

		glUniform1i(glGetUniformLocation(entity.Program, "material.diffuse"), 0);
		glUniform1i(glGetUniformLocation(entity.Program, "material.specular"), 1);

		glUniform3fv(glGetUniformLocation(entity.Program, "material.vambient"), 1, &glm::vec3(0.19225, 0.19225, 0.19225)[0]);
		glUniform3fv(glGetUniformLocation(entity.Program, "material.vdiffuse"), 1, &glm::vec3(0.50754, 0.50754, 0.50754)[0]);
		glUniform3fv(glGetUniformLocation(entity.Program, "material.vspecular"), 1, &glm::vec3(0.508273, 0.508273, 0.508273)[0]);

		glUniform1f(glGetUniformLocation(entity.Program, "material.shininess"), 32.0f);
	
	}


	void Sun::free()
	{
		//glDeleteProgram(program);
	}
}