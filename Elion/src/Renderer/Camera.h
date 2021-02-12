#pragma once
#include "GL/glew.h"
#include "Core/Log.h"
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include <iostream>
#include <string>

namespace Elion
{
		
	
	class ELION_API Camera
	{

	private:

		static Shader* shader;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

	public:

		static GLuint matrix_GLSL(const char* vertex_file_path, const char* fragment_file_path);

		static Shader* init_shader();
		static GLint set_uniform_location(GLuint program ,const std::string& matrix_name);
		static glm::mat4 set_rotation(float rotation, float x, float y, float z);
		static glm::mat4 set_scaling(float x, float y, float z);
		static glm::mat4 set_translation(float x, float y, float z);
		static glm::mat4 set_projection(float radians, float width, float height, float _near, float _far);

		static glm::mat4& rotate(glm::mat4 matrix , float rotation, float x, float y, float z);
		static glm::mat4& translate(glm::mat4 matrix, float x, float y, float z);
		static glm::mat4& scale(glm::mat4 matrix, float x, float y, float z);
		static glm::mat4& projection(glm::mat4 matrix, float radians, float width, float height, float _near, float _far);

		static void upload_matrices(GLint matrix_location, glm::mat4 matrix_transfromed);

		const glm::mat4& get_projection_matrix() const { return this->m_ProjectionMatrix; }
		const glm::mat4& get_view_matrix() const { return this->m_ViewMatrix; }
		const glm::mat4& get_view_projection_matrix() const { return this->m_ViewProjectionMatrix; }

	};

}

#define MatrixGLSL(...) Elion::Camera::matrix_GLSL(__VA_ARGS__)
//#define GLSL(...) Elion::Camera::LoadGLSL(__VA_ARGS__)

#define setShaderID(...) Elion::Camera::set_shader(__VA_ARGS__)
#define setMatrixName(...) Elion::Camera::set_matrix_name(__VA_ARGS__)

#define setMatrixRotation(...) Elion::Camera::set_rotation(__VA_ARGS__)
#define MatrixRotate(...) Elion::Camera::rotate(__VA_ARGS__)

#define setMatrixTranslation(...) Elion::Camera::set_translation(__VA_ARGS__)
#define MatrixTranslate(...) Elion::Camera::translate(__VA_ARGS__)

#define setMatrixProjection(...) Elion::Camera::set_projection(__VA_ARGS__)

#define MatrixScale(...) Elion::Camera::scale(__VA_ARGS__)

#define UpdateMatrices() Elion::Camera::update()

#define ReleaseMatrices() Elion::Camera::release_matrices()



