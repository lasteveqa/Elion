#include "Scene/SceneCamera.h"


namespace Elion
{
	glm::mat4 Cam::CameraMatrix;
	glm::vec3 Cam::Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Cam::Eye = glm::vec3(8.0f, 8.0f, 8.0f);
	glm::vec3 Cam::Center = glm::vec3(-8.0f, -8.0f, -8.0f);

	void Cam::render()
	{
		glm::vec3 cameraPos = glm::vec3(Eye.x, Eye.y, Eye.z);
		glm::vec3 cameraTarget = glm::vec3(Center.x, Center.y, Center.z);
		glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
		glm::vec3 up = glm::vec3(Up.x, Up.y, Up.z);
		glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
		glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
		
	    CameraMatrix = glm::lookAt(cameraPos, cameraPos + cameraTarget, up);
	}

	void Cam::set_camera(const std::string& uniform, GLuint program)
	{
		GLint CameraLocation = glGetUniformLocation(program, uniform.c_str());
		glUniformMatrix4fv(CameraLocation, 1, GL_FALSE, glm::value_ptr(CameraMatrix));
	}

	void Cam::set_camera(const std::string& uniform, Shader& shader)
	{
		GLint CameraLocation = glGetUniformLocation(shader.ID, uniform.c_str());
		glUniformMatrix4fv(CameraLocation, 1, GL_FALSE, glm::value_ptr(CameraMatrix));
	}
	
}