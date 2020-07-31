#pragma once
#include "glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"
#include <iostream>
#include "Renderer/Attributes.h"

namespace Elion
{
	


	class ELION_API VertexBuffer
	{
	private:

		GLuint VBO;

	
		std::vector<Attribute> attributeElements;

	public:
		
		VertexBuffer(float* vertices , uint32_t size);
		~VertexBuffer();

		void bind();
		void unbind();


		void set_vertex_attribute(const Attribute& attr)
		{
			this->attributeElements.push_back(attr);
		}

		inline GLuint get_vbo() { return this->VBO; }
		
		static std::shared_ptr<VertexBuffer> create(float* vertices, uint32_t size)
		{
			return std::make_shared<VertexBuffer>(vertices, size);
		}
	};

}