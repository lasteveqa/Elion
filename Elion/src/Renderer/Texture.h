#pragma once
#include "glew.h"
#include "Core/Core.h"
#include <string>
#include <iostream>

#include "stb-master/stb_image.h"

namespace Elion
{
	struct TileProps
	{
		uint32_t Xpos = 32;
		uint32_t Ypos = 32;
	    int Width = 32;
		int Height = 32;
    };

	class ELION_API Texture
	{

	private:
		TileProps tile;
		
		GLuint m_TextureID , m_DataFormat;
		int m_Width, m_Height;
	public:
		Texture();
		~Texture();
		
		bool load_from_file(const std::string& filename);

		void bind();
		void unbind();
	};


}
