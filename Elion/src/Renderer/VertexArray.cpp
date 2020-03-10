#include "VertexArray.h"

namespace Elion
{
	

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);
	}


	void VertexArray::bind()
	{
		glBindVertexArray(this->VAO);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}


	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &this->VAO);
	}

}