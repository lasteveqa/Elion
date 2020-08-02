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

	void Scene::create_triangle()
	{
		m_Primitives.push_back(new Triangle());
	}

	void Scene::create_quad()
	{
		m_Primitives.push_back(new Quad());
	}

	void Scene::draw_triangle()
	{
		
			m_triangle.set_color(Color(1.0f, 1.0f, 1.0f));
			m_triangle.set_size(Size(0.5f, 0.5f, 0.0f));
			m_triangle.set_position(Position(0.0f, 0.0f, 0.0f));

			m_triangle.draw();

			m_triangle.update();
		

		
	}


	void Scene::draw_quad()
	{
		
			m_quad.set_color(Color(1.0f, 1.0f, 1.0f));
			m_quad.set_position(Position(0.0f, 0.0f, 0.0f));
			m_quad.set_size(Size(0.5f, 0.5f, 0.0f));

			m_quad.update();
		

		m_quad.draw();
	}

	void Scene::delete_triangle()
	{
		m_triangle.free_vao();
	}

	bool Scene::is_TrianglePicked(bool is_picked)
	{
		return false;
	}

	void Scene::draw()
	{
		if(!m_Primitives.empty())
		for (std::size_t i = 0; i < m_Primitives.size(); i++)
		{
			m_Primitives[i]->set_color(Color(1.0f, 1.0f, 1.0f));
			m_Primitives[i]->set_position(Position(0.0f, 0.0f, 0.0f));
			m_Primitives[i]->set_size(Size(0.5f, 0.5f, 0.0f));
			m_Primitives[i]->update();
			m_Primitives[i]->draw();
		}
	}
}