#include "Renderer/ModelLoader.h"

namespace Elion
{
	ModelLoader::ModelLoader(const std::string &path)
	{

	

		this->m_Model = Model(path);

		this->m_Program = this->m_Shader.load_GLSL("Shaders/test.vs", "Shaders/test.fs");
		
	}


	void ModelLoader::draw()
	{
		glUseProgram(this->m_Program);

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), 0.1f, 1000.0f);
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));

		Cam::render();
		
	

		
		glUniformMatrix4fv(glGetUniformLocation(this->m_Program, "projection"), 1, GL_FALSE, &projection[0][0]);

		
		glUniformMatrix4fv(glGetUniformLocation(this->m_Program, "transform"), 1, GL_FALSE, &transform[0][0]);

		
		Cam::set_camera("view", this->m_Program);
		m_Model.Draw(this->m_Shader);
		glUseProgram(0);

	
	}

	
}