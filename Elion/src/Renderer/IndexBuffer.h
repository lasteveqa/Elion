#pragma once
#include "Core/Core.h"
#include "glew.h"
namespace Elion
{

	class ELION_API IndexBuffer
	{
	private:

		GLuint m_EBO;
	
		uint32_t* m_Indices;
		int m_Size;

	public:

		IndexBuffer(){}
		IndexBuffer(uint32_t* indices , uint32_t size);

		void bind();
		void unbind();
		void draw();

		static std::shared_ptr<IndexBuffer> create(uint32_t* indices, uint32_t size)
		{
			return std::make_shared<IndexBuffer>(indices, size);
		}
	};

}
