#pragma once
#include "Renderer/Texture.h"
#include "Primitives/Primitive.h"
#include "Primitives/Quad.h"
namespace Elion {

	

	class ELION_API Tileset
	{

	private:
		Texture* texture;

		std::vector<std::shared_ptr<Primitive>> m_vecQuads;
	public:

		bool load(const std::string& tileset);
	};


}

