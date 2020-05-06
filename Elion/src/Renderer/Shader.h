#pragma once
#include "GL/glew.h"
#include "Core/Log.h"
#include "Core/Core.h"
#include "Renderer/MVP.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



namespace Elion
{

	class ELION_API Shader : public MVP
	{
	private:
		
		MVP* p_mvp;
	public:
		Shader(MVP *mvp) : p_mvp(mvp){}

		GLuint load_shader(const char* vertex_file_path, const char* fragment_file_path);

		void shaderLinkCheck(uint ID);
		void shaderCompilerCheck(uint ID);
        
		void set_mvp(MVP* mvp);
		
		void upload_uniform_mat4(GLuint program);

		void matrix_name(std::string matrix_name);
		void matrix_rotate(const MatrixProperties& mp , const VCoord& c);
		void matrix_translate(const VCoord& c);
		void matrix_perspective(const MatrixProperties& mp);


		void matrix_name_output()
		{
			p_mvp->matrix_name_output();
		}
		
		void matrix_matrices_output()
		{
			this->p_mvp->matrix_matrices_output();
		}

		bool is_mvp_set();

	
	 
		void mvp_func(GLuint program);


		void begin_mvp_loop();
		void end_mvp_loop();
	};


}


#define BEGIN_MVP_LOOP Elion::Shader::begin_mvp_loop
#define END_MVP_LOOP Elion::Shader::end_mvp_loop