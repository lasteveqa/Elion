#pragma once
#include "Core/Core.h"
#include "glew.h"
namespace Elion
{

	class ELION_API VertexIndices
	{
	private:
		uint EBO;
		std::vector<uint> Indices;

	public:
		VertexIndices(){}
		VertexIndices(std::vector<uint> indices);

		void bind();
		void unbind();
		void draw();
	};

}
