#include "Scene/Scene.h"

namespace Elion
{


	Scene::Scene()
	{
	}


	void Scene::add_primitive(PrimitiveTypes pt)
	{
		switch (pt)
		{
		case PrimitiveTypes::TRIANGLE:
			m_Primitives.push_back(std::make_unique<Triangle>());
			break;

		case PrimitiveTypes::QUAD:
			m_Primitives.push_back(std::make_unique<Quad>());
			break;

		case PrimitiveTypes::ROUND:
			m_Primitives.push_back(std::make_unique<Round>());
			break;

		case PrimitiveTypes::CUBE:
			m_Primitives.push_back(std::make_unique<Cube>());
			break;

		case PrimitiveTypes::SPHERE:
			m_Primitives.push_back(std::make_unique<Sphere>());
			break;
		}
	}

	void Scene::set_color(Color& color)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); i++)
			{
				m_Primitives[i]->set_color(color);
			}
		}
	}



	void Scene::set_scale(Scale& size)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); i++)
			{
				m_Primitives[i]->set_scale(size);
			}
		}
	}


	void Scene::set_position(Position& position)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); i++)
			{
				m_Primitives[i]->set_position(position);
			}
		}
	}



	void Scene::set_rotation(Rotation& rotation)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); i++)
			{
				m_Primitives[i]->set_rotation(rotation);
			}
		}
	}




	void Scene::set_projection(Projection& projection)
	{
		if (!m_Primitives.empty())
		{
			for (std::size_t i = 0; i < m_Primitives.size(); i++)
			{
				m_Primitives[i]->set_projection(projection);
			}
		}
	}



	void Scene::set_item_color(const Color& color, int index)
	{
		m_Primitives[index]->set_color(color);
	}

	void Scene::set_item_scale(const Scale& scale, int index)
	{
		m_Primitives[index]->set_scale(scale);
	}

	void Scene::set_item_position(const Position& position, int index)
	{
		m_Primitives[index]->set_position(position);
	}

	void Scene::set_item_rotation(const Rotation& rotation, int index)
	{
		m_Primitives[index]->set_rotation(rotation);
	}

	void Scene::set_item_projection(const Projection& projection, int index)
	{
		m_Primitives[index]->set_projection(projection);
	}


	void Scene::delete_item(int& index)
	{
		m_Primitives[index]->free();

		m_Primitives.erase(m_Primitives.begin() + index);
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
			if (!m_Primitives.empty())
				for (std::size_t i = 0; i < m_Primitives.size(); ++i)
				{
					m_Primitives[i]->draw();
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
	}
}