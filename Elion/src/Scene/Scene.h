#pragma once

#include "Core/Core.h"
#include "glew.h"
#include "Events/KeyEvent.h"

#include "Primitives/Triangle.h"
#include "Primitives/Plane.h"
#include "Primitives/Round.h"
#include "Primitives/Cube.h"
#include "Primitives/Sphere.h"

namespace Elion
{
	
	class Scene
	{
	private:

		std::vector<std::unique_ptr<Primitive>> m_Primitives;


	public:
		Scene();
		//Primitives
		void add_primitive(PrimitiveTypes pt);
		std::vector<std::unique_ptr<Primitive>>& get_primitives() { return this->m_Primitives; }
		void set_item_color(const Color& color , int index);
		void set_item_scale(const Scale& scale, int index);
		void set_item_position(const Position& position, int index);
		void set_item_rotation(const Rotation& rotation, int index);
		void set_item_projection(const Projection& projection, int index);

		void delete_item(int& index);
		//

		void update();
		void draw();



		


	};
}