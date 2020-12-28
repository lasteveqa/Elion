#include "Texture.h"


namespace Elion
{
	Texture::Texture()
	{
	}

	bool Texture::load_from_file(const std::string& filename)
	{
		int channels;
		unsigned char* data = stbi_load(filename.c_str(), &tile.Width, &tile.Height, &channels, 0);

		glGenTextures(1, &m_TextureID);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		switch (channels)
		{
		case 3:
			this->m_DataFormat = GL_RGB;
			break;

		case 4:
			this->m_DataFormat = GL_RGBA;
			break;

		default:
			std::cout << "Undefined m_DataFormat in Texture.cpp" << std::endl;
			break;
		}
		
		glTexImage2D(GL_TEXTURE_2D, 0, this->m_DataFormat, tile.Width, tile.Height, 0, this->m_DataFormat, GL_UNSIGNED_BYTE, NULL);
		glTextureSubImage2D(this->m_TextureID, 0, 0, 0, tile.Width, tile.Height, this->m_DataFormat, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
		glEnable(GL_BLEND);
		stbi_image_free(data);

		return true;
	}


	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}

	void Texture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_TextureID);
	}
}