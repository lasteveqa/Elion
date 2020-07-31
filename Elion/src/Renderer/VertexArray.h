#pragma once
#include "GL/glew.h"
#include "SDL/SDL.h"
#include "Core/Core.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
namespace Elion
{
	
	class ELION_API VertexArray
	{
	private:

		uint VAO;
	
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	public:
		VertexArray();
		~VertexArray();

		void bind();
		void unbind();

		void add_vertex_buffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
		{
			this->m_VertexBuffers.push_back(vertexBuffer);
		}

		void set_index_buffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
		{
			
			this->m_IndexBuffer = indexBuffer;
		}

		void draw()
		{
			this->m_IndexBuffer->draw();
		}

		inline GLuint get_vao() { return this->VAO; }

		
	};

}