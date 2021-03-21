#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include "glew.h"
#include "Renderer/FileLoader.h"

namespace Elion
{
	
   class OBJFileLoader : public FileLoader
	{

	private:

	   std::vector<glm::fvec3> p_vertices;
	   std::vector<glm::fvec2> t_vertices;
	   std::vector<glm::fvec3> n_vertices;

	   std::vector<FileVertex> vertices;

	   std::vector<GLint> vertex_position_indicies;
	   std::vector<GLint> vertex_texcoord_indicies;
	   std::vector<GLint> vertex_normal_indicies;
	   
	   std::vector<unsigned int> face;

	 
	  

	public:

		OBJFileLoader();

		~OBJFileLoader()
		{
			glUseProgram(0);
			glBindVertexArray(0);

			glDeleteProgram(Program);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);
			glDeleteVertexArrays(1, &VAO);
		}

		OBJFileLoader(const char* filename);

		bool loadOBJ(const char* filename);

		void update();

		void draw();

		std::vector<glm::fvec3> v_parser3(std::string file_output);
		std::vector<glm::fvec2> v_parser2(std::string file_output);
		void f_parser(std::string file_output);

		/*inline std::vector<float> get_p_vertices() { return this->p_vertices; }
		inline std::vector<float> get_t_vertices() { return this->t_vertices; }
		inline std::vector<float> get_n_vertices() { return this->n_vertices; }*/

		//inline std::vector<uint> get_face() { return this->face; }

	};
	




	
}