#include "Interface/UIComponent.h"

namespace Elion
{
	namespace Interface
	{
		std::vector<PrimitiveTypes> UIComponent::m_PrimitiveTypes;
		std::vector<SetOfPropeties> UIComponent::m_SetOfProperties;
		Color UIComponent::m_Color;
		Size UIComponent::m_Size;
		Position UIComponent::m_Position;
		Rotation UIComponent::m_Rotation;
		Projection UIComponent::m_Projection;
		Scene UIComponent::m_Scene;

		int UIComponent::index = 0;

		int UIComponent::m_Update = 1;
	}
}