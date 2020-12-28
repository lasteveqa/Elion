#pragma once

#include <iostream>
#include "Core/Core.h"
#include "SDL.h"
#include <functional>
#include "Core/KeyCodes.h"

namespace Elion
{
	
	struct KeyPressedEvent
	{
		SDL_Keycode Keycode;
		std::size_t RepeatCount;

		KeyPressedEvent(SDL_Keycode keycode = 0) : Keycode(keycode) {}
	};


	class ELION_API Event
	{

	private:
		
		KeyPressedEvent m_KeyPressedEvent;

	public:
		Event() { this->m_KeyPressedEvent = KeyPressedEvent(); }
		

		SDL_Keycode get_keycode() { return this->m_KeyPressedEvent.Keycode; }

		inline std::size_t& get_repeat_count() { return this->m_KeyPressedEvent.RepeatCount; }

	};

	extern SDL_Event sdl_event;

	
}



