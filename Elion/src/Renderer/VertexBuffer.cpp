#include "VertexBuffer.h"
namespace Elion
{
	uint32_t VertexBuffer::VBO;


	VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
	{
		
		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	


	void VertexBuffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	}

	void VertexBuffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &this->VBO);
	}

}