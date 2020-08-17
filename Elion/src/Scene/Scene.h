#pragma once

#include "Core/Core.h"
#include "glew.h"
#include "Primitives/Triangle.h"
#include "Primitives/Quad.h"
#include "Scene/Selected.h"

namespace Elion
{
	class Scene
	{
	private:
		float Width = 700.0f;
		float Height = 700.0f;
		
		std::vector<GLuint> m_VecVAO;


		static std::vector<Primitive*> m_Primitives;


	public:
		//Add new primitive
		static void add_primitive(PrimitiveTypes pt);
		
		static void set_color(Color& color);
		static void set_size(Size& size);
		static void set_position(Position& position);
		static void update();
		static void draw();

		//Clean all properties current item of primitives
		static void clean_all_properties(unsigned int index);
		//Delete primitives item by index
		static void delete_item_of_primitives(unsigned int index);

		static std::vector<Primitive*> get_primitives() { return m_Primitives; }

		


	};
}