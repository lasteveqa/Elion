#include "OBJLoader.h"


namespace Elion {

	OBJLoader::OBJLoader(const char* filename)
	{
		

	}



	bool OBJLoader::loadOBJ(const char* filename)
	{
		std::fstream file(filename, std::ios::in);

		std::string  line;

		if (!file.is_open()) return GL_FALSE;

		while (!file.eof())
		{
			std::getline(file, line);

			if (line[0] == 'v' && line[1] == ' ')
			{
				this->position_vertices_output += line + "\n";
			}

			else if (line[0] == 'v' && line[1] == 't')
			{
				this->texture_vertices_output += line + "\n";
			}

			else if (line[0] == 'v' && line[1] == 'n')
			{
				this->normal_vertices_output += line + "\n";
			}

			else if (line[0] == 'f')
			{
				this->face_output += line + "\n";
			}
		}

		this->p_vertices = this->v_parser(this->position_vertices_output);
		this->t_vertices = this->v_parser(this->texture_vertices_output);
		this->n_vertices = this->v_parser(this->normal_vertices_output);
		this->face = this->f_parser(this->face_output);
		


		
		return GL_TRUE;
	}

	std::vector<float> OBJLoader::v_parser(std::string file_output)
	{
		std::stringstream ss;
		
		ss << file_output;

		std::string word;

		std::vector<float> vec;

		float found;

		while (!ss.eof())
		{
			ss >> word;

			if (std::stringstream(word) >> found)
			{
				
				vec.push_back(found);

			}
			
			word = "";

		}
		return vec;
		
	}

	std::vector<uint> OBJLoader::f_parser(std::string file_output)
	{
		std::stringstream ss;

		ss << file_output;

		std::string word;

		std::vector<uint> vec;


		//Three types of indices
		uint v_index;
		uint vt_index;
		uint vn_index;

		while (!ss.eof())
		{
			ss >> word;
			
			word.erase(std::remove(word.begin(), word.end(), 'f'), word.end());

			std::replace(word.begin(), word.end(), '/' , ' ');
			
			if (std::stringstream(word) >> v_index >> vt_index >> vn_index)
			{
				vec.push_back(v_index);
				vec.push_back(vt_index);
				vec.push_back(vn_index);
			}
			
			word = "";

		}
		return vec;
	}



}