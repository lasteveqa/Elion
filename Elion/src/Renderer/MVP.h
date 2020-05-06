#pragma once
#include "GL/glew.h"
#include "Core/Core.h"
#include "Core/Log.h"
#include <iostream>
#include <string>
#include <algorithm>

namespace Elion
{
	struct VCoord
	{
		float X, Y, Z;
		VCoord(float x, float y, float z) : X(x), Y(y), Z(z) {}
	};

	struct MatrixProperties
	{
		float Radians;
		float W_Window, H_Window, Near, Far;
		MatrixProperties(float radians) : Radians(radians) {}
		MatrixProperties(float radians, float widthWindow, float heightWindow, float _near, float _far) :
			Radians(radians),
			W_Window(widthWindow),
			H_Window(heightWindow),
			Near(_near),
			Far(_far)
		{}
	};

	class ELION_API MVP
	{
	protected:



		std::vector<GLint> matrix_locations;

		GLuint Program = NULL;

		std::vector<std::string> Name;


		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;

	public:


		void set_rotate(const MatrixProperties& mp , const VCoord& c);
		void set_translate(const VCoord& c);
		void set_perspective(const MatrixProperties& mp);

		void matrix_name(std::string matrix_name);


		void upload_uniform_mat4(GLuint program);

		void matrix_name_output();

		void is_valid_matrix_name();

		const glm::mat4& get_model() const { return this->model; }
		const glm::mat4& get_view() const { return this->view; }
		const glm::mat4& get_projection() const { return this->projection; }



		void matrix_matrices_output();

		inline std::vector<std::string> get_names() { return this->Name; }
		

		void clear();
	};

}