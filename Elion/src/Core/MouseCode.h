#pragma once

namespace Elion
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	
}

#define MOUSE_BUTTON_0      ::Elion::Mouse::Button0
#define MOUSE_BUTTON_1      ::Elion::Mouse::Button1
#define MOUSE_BUTTON_2      ::Elion::Mouse::Button2
#define MOUSE_BUTTON_3      ::Elion::Mouse::Button3
#define MOUSE_BUTTON_4      ::Elion::Mouse::Button4
#define MOUSE_BUTTON_5      ::Elion::Mouse::Button5
#define MOUSE_BUTTON_6      ::Elion::Mouse::Button6
#define MOUSE_BUTTON_7      ::Elion::Mouse::Button7
#define MOUSE_BUTTON_LAST   ::Elion::Mouse::ButtonLast
#define MOUSE_BUTTON_LEFT   ::Elion::Mouse::ButtonLeft
#define MOUSE_BUTTON_RIGHT  ::Elion::Mouse::ButtonRight
#define MOUSE_BUTTON_MIDDLE ::Elion::Mouse::ButtonMiddle