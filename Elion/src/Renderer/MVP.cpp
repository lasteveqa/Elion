#include "MVP.h"


namespace Elion
{

	void MVP::set_rotate(const MatrixProperties& mp, const VCoord& c)
	{
		this->model = glm::rotate(this->model, glm::radians(mp.Radians), glm::vec3(c.X, c.Y, c.Z));

		std::cout << mp.Radians << std::endl;
		std::cout << c.X << std::endl;
		std::cout << c.Y << std::endl;
		std::cout << c.Z << std::endl;
	}

	void MVP::set_translate(const VCoord& c)
	{
		this->view = glm::translate(view, glm::vec3(c.X, c.Y, c.Z));
	}

	void MVP::set_perspective(const MatrixProperties& mp)
	{
		this->projection = glm::perspective(glm::radians(mp.Radians), mp.W_Window / mp.H_Window, mp.Near, mp.Far);
	}

	void MVP::matrix_name(std::string matrix_name)
	{
		this->Name.push_back(matrix_name);
		is_valid_matrix_name();

	}


	void MVP::upload_uniform_mat4(GLuint program)
	{
		
			/*GLint model_location = glGetUniformLocation(program, "model");
			glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(this->model));

			GLint view_location = glGetUniformLocation(program, "view");
			glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(this->view));

			GLint projection_location = glGetUniformLocation(program, "projection");
			glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(this->projection));*/
		
	}


	void MVP::clear()
	{

	}


	void MVP::matrix_name_output()
	{
		for (std::size_t i = 0; i < this->Name.size(); i++)
		{
			std::cout << Name[i] << std::endl;
			
		}
	}

	void MVP::matrix_matrices_output()
	{
		

	}

	// Returns false if it has additional same name item
	// true if all is clear
	void MVP::is_valid_matrix_name()
	{
		std::vector<std::string > names;
		std::vector<std::string> duplicates;

		names = this->Name;

		if (!names.empty())
		{

			std::sort(names.begin(), names.end());

			for (std::size_t i = 1; i < names.size(); i++)
			{
				if (names[i - 1] == names[i])
					duplicates.push_back(names[i]);
			}

			if (duplicates.empty())
			{
				std::cout << "No Duplicate words" << std::endl;
			}

			else
			{
				for (std::size_t i = 0; i < duplicates.size(); i++)
				{
					this->Name.pop_back();
				}

			}
		}
	}
	
}