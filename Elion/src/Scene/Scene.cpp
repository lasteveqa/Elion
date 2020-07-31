#include "Scene/Scene.h"

namespace Elion
{
	Triangle Scene::m_triangle;
	Quad Scene::m_quad;

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

	bool Scene::is_TrianglePicked(bool is_picked)
	{
		return false;
	}
}