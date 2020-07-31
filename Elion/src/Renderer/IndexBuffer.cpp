#include "IndexBuffer.h"


namespace Elion
{
	


	IndexBuffer::IndexBuffer(uint32_t* indices , uint32_t size) : m_Indices(indices) , m_Size(size)
	{
		glCreateBuffers(1, &this->m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(uint32_t), indices, GL_STATIC_DRAW);

	}


	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
	}
	
	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}


	void IndexBuffer::draw()
	{
			glDrawElements(GL_TRIANGLES, this->m_Size, GL_UNSIGNED_INT, (void*)0);
	}

}