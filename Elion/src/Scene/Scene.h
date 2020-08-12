#pragma once

#include "Core/Core.h"
#include "glew.h"
#include "Primitives/Triangle.h"
#include "Primitives/Quad.h"

namespace Elion
{
	class Scene
	{
	private:
		float Width = 700.0f;
		float Height = 700.0f;
		
		std::vector<GLuint> m_VecVAO;

		static std::vector<unsigned int> m_IndexesOfExceptedPrimitives;

		static std::vector<Primitive*> m_Primitives;


	public:
		//Add new primitive
		static void add_primitive(PrimitiveTypes pt);

		//Add properties to existing primitives

		static void set_color(Color& color);
		static void set_size(Size& size);
		static void set_position(Position& position);
		static void update();
		static void draw();

		// Set index of excepted primitive
		static void set_excepted_primitive(unsigned int index);

		//Update for excepted
		static void update_excepted_primitives();
		//Draw indexes of excepted primitives
		static  void draw_excepted_primitives();
		//Clean all properties current item of primitives
		static void clean_all_properties(unsigned int index);
		//Delete primitives item by index
		static void delete_item_of_primitives(unsigned int index);

		static std::vector<Primitive*> get_primitives() { return m_Primitives; }

		


	};
}