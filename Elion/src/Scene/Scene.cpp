#include "Scene/Scene.h"

namespace Elion
{
	Triangle Scene::m_triangle;
	Quad Scene::m_quad;

	std::vector<Primitive*> Scene::m_Primitives;

	void Scene::add_primitive(PrimitiveTypes pt)
	{
		switch (pt)
		{
		case PrimitiveTypes::TRIANGLE:
			m_Primitives.push_back(new Triangle());
			break;
		case PrimitiveTypes::QUAD:
			m_Primitives.push_back(new Quad());
			break;
		}
	}

	void Scene::set_properties(Color& color, Size& size, Position& position)
	{
		if (!m_Primitives.empty())
		{
			m_Primitives[m_Primitives.size() - 1]->set_color(color);
			m_Primitives[m_Primitives.size() - 1]->set_size(size);
			m_Primitives[m_Primitives.size() - 1]->set_position(position);
		}
	}



	void Scene::draw()
	{
		if(!m_Primitives.empty())
		for (std::size_t i = 0; i < m_Primitives.size(); i++)
		{
			
			m_Primitives[i]->update();
			m_Primitives[i]->draw();
		}
	}
}