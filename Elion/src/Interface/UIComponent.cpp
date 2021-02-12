#include "Interface/UIComponent.h"

namespace Elion
{
	namespace Interface
	{
		std::vector<PrimitiveTypes> UIComponent::m_PrimitiveTypes;
		std::vector<SetOfPropeties> UIComponent::m_SetOfProperties;

		Scene UIComponent::m_Scene;

		int UIComponent::index = -1;

		int UIComponent::m_Update = 1;
	}
}