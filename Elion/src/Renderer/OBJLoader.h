#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include "glew.h"
#include "Core/Log.h"
#include "Core/Core.h"


namespace Elion
{
	




   class ELION_API OBJLoader
	{

	private:

	   std::vector<float> p_vertices;
	   std::vector<float> t_vertices;
	   std::vector<float> n_vertices;
	   
	   std::vector<uint> face;


	   std::string position_vertices_output;
	   std::string texture_vertices_output;
	   std::string normal_vertices_output;
	   std::string face_output;

	   std::vector<float> v_parser(std::string file_output);
	   std::vector<uint> f_parser(std::string file_output);
	  

	public:

		OBJLoader() {}

		OBJLoader(const char* filename);

		bool loadOBJ(const char* filename);
		

		inline std::vector<float> get_p_vertices() { return this->p_vertices; }
		inline std::vector<uint> get_face() { return this->face; }

	};
	




	
}