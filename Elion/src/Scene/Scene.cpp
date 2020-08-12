#include "Scene/Scene.h"

namespace Elion
{

	std::vector<Primitive*> Scene::m_Primitives;
	std::vector<unsigned int> Scene::m_IndexesOfExceptedPrimitives;

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

	void Scene::set_color(Color& color)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); ++i)
			{
				m_Primitives[i]->set_color(color);
			}
		}
	}


	void Scene::set_size(Size& size)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); ++i)
			{
				m_Primitives[i]->set_size(size);
			}
		}
	}


	void Scene::set_position(Position& position)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); ++i)
			{
				m_Primitives[i]->set_position(position);
			}
		}
	}




	void Scene::update()
	{
		if (!m_Primitives.empty())
		for (std::size_t i = 0; i < m_Primitives.size(); ++i)
		{
				m_Primitives[i]->update();
		}
	}

	void Scene::draw()
	{
		if(!m_Primitives.empty())
		for (std::size_t i = 0; i < m_Primitives.size(); ++i)
		{
			m_Primitives[i]->draw();
		}
	}


	void Scene::set_excepted_primitive(unsigned int index)
	{
		m_IndexesOfExceptedPrimitives.push_back(index);
	}

	void Scene::update_excepted_primitives()
	{
		for (std::size_t i = 0; i < m_IndexesOfExceptedPrimitives.size(); ++i)
		{
				m_Primitives[m_IndexesOfExceptedPrimitives[i]]->update();
		}
	}

	void Scene::draw_excepted_primitives()
	{
		for (std::size_t i = 0; i < m_IndexesOfExceptedPrimitives.size(); ++i)
		{
				m_Primitives[m_IndexesOfExceptedPrimitives[i]]->draw();
		}
	}

	void Scene::clean_all_properties(unsigned int index)
	{
		do {
			m_Primitives[index]->free();
		} while (false);
	}

	void Scene::delete_item_of_primitives(unsigned int index)
	{
		delete m_Primitives[index];
	}
}