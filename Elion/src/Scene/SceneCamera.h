#pragma once
#include <string>
#include "GL/glew.h"
#include "Renderer/Shader.h"

namespace Elion
{
	class Cam
	{

	private:

		static glm::mat4 CameraMatrix;
		static glm::vec3 Up;
		static glm::vec3 Eye;
		static glm::vec3 Center;

	public:
		

		//glGetUniformLocation and glUniformMatrix4fv
		static void set_camera(const std::string& uniform, GLuint program);
		static void set_camera(const std::string& uniform, Shader& shader);
		//static glm::mat4& zoom_camera(const Projection& projection, float Radians);

		static void render();

		static inline glm::mat4& get_matrix() { return CameraMatrix; }
		static inline glm::vec3& get_up() { return Up; }
		static inline glm::vec3& get_eye() { return Eye; }
		static inline glm::vec3& get_center() { return Center; }
	};
	
}
