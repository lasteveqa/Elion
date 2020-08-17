#pragma once
#include "Primitives/Primitive.h"

namespace Elion
{
	class Selected
	{
	private:
		static std::vector<unsigned int> m_SelectedIndexesOfPrimitives;
	public:
		static void set(unsigned int selectedIndex);

		static void remove(unsigned int selectedIndex);

		static void draw(std::vector<Primitive*> primitives);

		static void except_selected(unsigned int primitiveIndex);
	};
}