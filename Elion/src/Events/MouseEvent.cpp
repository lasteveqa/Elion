#include "MouseEvent.h"

namespace Elion
{
	void MouseEvent::mouse_click(const int btn)
	{
		
	}

	void MouseEvent::mouse_hover()
	{

	}

	void MouseEvent::mouse_hold()
	{

	}

	const bool MouseEvent::is_clicked() const
	{
		return this->m_Clicked;
	}

	const bool MouseEvent::is_hovered() const
	{
		return this->m_Hovered;
	}

}