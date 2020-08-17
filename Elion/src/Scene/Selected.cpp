#include "Scene/Selected.h"

namespace Elion
{
	std::vector<unsigned int> Selected::m_SelectedIndexesOfPrimitives;

	void Selected::set(unsigned int selectedIndex)
	{
		
		   if(!m_SelectedIndexesOfPrimitives.empty())
				m_SelectedIndexesOfPrimitives.erase(m_SelectedIndexesOfPrimitives.begin());
		

			m_SelectedIndexesOfPrimitives.push_back(selectedIndex);
		
	}


	void Selected::remove(unsigned int selectedIndex)
	{
		m_SelectedIndexesOfPrimitives.erase(m_SelectedIndexesOfPrimitives.begin() + selectedIndex);
	}

	void Selected::draw(std::vector<Primitive*> primitives)
	{
		for (std::vector<unsigned int>::iterator it = m_SelectedIndexesOfPrimitives.begin(); it != m_SelectedIndexesOfPrimitives.end(); ++it)
		{
			primitives[*it]->draw();
		}
	}


	void Selected::except_selected(unsigned int primitiveIndex)
	{
		for (std::vector<unsigned int>::iterator it = m_SelectedIndexesOfPrimitives.begin(); it != m_SelectedIndexesOfPrimitives.end(); ++it)
		{
			if (primitiveIndex == m_SelectedIndexesOfPrimitives[*it])
				continue;
		}
	}

}