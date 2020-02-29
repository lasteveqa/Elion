#pragma once

#include "Event.h"
#include "Elion/Core/MouseCode.h"
namespace Elion
{


	class MouseMovedEvent : public Event
	{
	private:
		float x_position, y_position;

	public:
		MouseMovedEvent(float x , float y) : x_position(x) , y_position(y) {}

		inline float get_x_position() const { return this->x_position; }
		inline float get_y_position() const { return this->y_position; }


		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};





	class MouseScrolledEvent : public Event
	{
	private:
		float x_offset, y_offset;

	public:
		MouseScrolledEvent(float x, float y) : x_offset(x), y_offset(y) {}


		inline float get_x_offset() const { return this->x_offset; }
		inline float get_y_offset() const { return this->y_offset; }

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};





	class MouseButtonEvent : public Event
	{
	protected:

		MouseCode button;

		MouseButtonEvent(MouseCode button) : button(button) {}

	public:

		inline MouseCode get_button() const { return this->button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	};





	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(MouseCode button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};






	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseCode button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}