#pragma once
#include "GL/glew.h"
#include "Core/Log.h"
#include "Core/Core.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/compatibility.hpp"


namespace Elion
{



	class ELION_API Shader
	{

	public:
		GLuint ID;
		Shader(){}
		Shader(const char* vertex_file_path, const char* fragment_file_path);

		 GLuint load_GLSL(const char* vertex_file_path, const char* fragment_file_path);
		 void GLSL(const char* vertex_file_path, const char* fragment_file_path);
		 GLuint load_native_GLSL(const std::string& vertex_shader, const std::string& fragment_shader);


		 void bind() { glUseProgram(this->ID); }
		 void unbind() { glUseProgram(0); }

		 void set_mat4(const std::string& name, const glm::mat4& matrix) const;

		void shaderLinkCheck(uint ID);
		void shaderCompilerCheck(uint ID);

		void set_uniform_location(GLint location, glm::mat4 matrix);
		
	
		GLint get_uniform_location(GLuint program, const std::string& name);

		void set_uniform1i(GLuint program ,const std::string& name , float value);


		GLuint get_program() { return ID; }


		~Shader(){}
	};


}

