#include "Camera.h"


namespace Elion
{
	Shader* Camera::shader;
	
	Shader* Camera::init_shader()
	{
		shader = new Shader();
		return shader;
	}

	GLuint Camera::matrix_GLSL(const char* vertex_file_path, const char* fragment_file_path)
	{
		return shader->load_GLSL(vertex_file_path, fragment_file_path);
	}

	GLint Camera::set_uniform_location(GLuint program, const std::string& matrix_name)
	{
		GLint location = shader->get_uniform_location(program, matrix_name);

		return location;
	}


	glm::mat4 Camera::set_rotation(float rotation, float x, float y, float z)
	{
		glm::mat4 matrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(x, y, z));

		return matrix;
	}

	glm::mat4 Camera::set_scaling(float x, float y, float z)
	{
		glm::mat4 matrix = glm::scale(glm::mat4(1.0f), glm::vec3(x, y, z));

		return matrix;
	}

	glm::mat4 Camera::set_translation(float x, float y, float z)
	{
		glm::mat4 matrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));

		return matrix;
	}

	glm::mat4 Camera::set_projection(float radians ,float width , float height , float _near , float _far)
	{
		glm::mat4 matrix = glm::perspective(glm::radians(radians), width / height, _near, _far);

		return matrix;
	}

	glm::mat4& Camera::rotate(glm::mat4 matrix, float rotation, float x, float y, float z)
	{
		matrix = glm::rotate(matrix, glm::radians(rotation), glm::vec3(x, y, z));

		return matrix;
	}

	glm::mat4& Camera::translate(glm::mat4 matrix, float x, float y, float z)
	{
		matrix = glm::translate(matrix, glm::vec3(x, y, z));

		return matrix;
	}

	glm::mat4& Camera::scale(glm::mat4 matrix, float x, float y, float z)
	{
		matrix = glm::scale(matrix, glm::vec3(x, y, z));

		return matrix;
	}


	void Camera::upload_matrices(GLint matrix_location, glm::mat4 matrix_transfromed)
	{
		shader->set_uniform_location(matrix_location, matrix_transfromed);
	}


}