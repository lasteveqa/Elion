#include "VertexIndices.h"


namespace Elion
{

	VertexIndices::VertexIndices(std::vector<uint> indices) : Indices(indices)
	{
		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices.size() * sizeof(uint), &this->Indices[0], GL_STATIC_DRAW);
	}


	void VertexIndices::bind()
	{
		if (!this->Indices.empty())
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	}

	void VertexIndices::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}


	void VertexIndices::draw()
	{
		if(!this->Indices.empty())
		glDrawElements(GL_TRIANGLES, this->Indices.size(), GL_UNSIGNED_INT, (void*)0);
	}

}