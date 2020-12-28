#pragma once
#include "Core/Core.h"
#include "Events/Event.h"
namespace Elion 
{
	class MouseEvent
	{
	private:
		bool m_Clicked = false;
		bool m_Hovered = false;
	public:
		void mouse_click(const int btn);
		void mouse_hover();
		void mouse_hold();
		const bool is_hovered() const;
		const bool is_clicked() const;
	};
}