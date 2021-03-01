#pragma once

#include "Core/Core.h"
#include "glew.h"
#include "Primitives/Triangle.h"
#include "Primitives/Quad.h"
#include "Primitives/Round.h"
#include "Primitives/Cube.h"
#include "Events/KeyEvent.h"

namespace Elion
{
	
	class Scene
	{
	private:
		float Width = 700.0f;
		float Height = 700.0f;
		
		std::vector<GLuint> m_VecVAO;


		std::vector<std::unique_ptr<Primitive>> m_Primitives;




	public:
		Scene();
		//Add new primitive
		void add_primitive(PrimitiveTypes pt);
		
		void set_color(Color& color);
		void set_scale(Scale& size);
		void set_position(Position& position);
		void set_rotation(Rotation& rotation);
		void set_projection(Projection& projection);

		//
		void set_item_color(const Color& color , int index);
		void set_item_scale(const Scale& scale, int index);
		void set_item_position(const Position& position, int index);
		void set_item_rotation(const Rotation& rotation, int index);
		void set_item_projection(const Projection& projection, int index);

		void delete_item(int& index);

		void update();
		void draw();

		//Clean all properties current item of primitives
		void clean_all_properties(unsigned int index);
		//Delete primitives item by index
		void delete_item_of_primitives(unsigned int index);


		std::vector<std::unique_ptr<Primitive>>& get_primitives() { return this->m_Primitives; }

		


	};
}