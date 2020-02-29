#pragma once

#include <iostream>
#include "Core/Core.h"
#include <string>
#include"SDL.h"
#include <functional>


namespace Elion
{
	



	struct KeyPressedEvent
	{
		SDL_Keycode Keycode;
		std::size_t RepeatCount;
		
		KeyPressedEvent(SDL_Keycode keycode = 0 ) : Keycode(keycode) {}
	};

	





	
	


	class ELION_API Event
	{

	private:
		
		SDL_Event sdl_event;
		//SDL_EventType e;
		KeyPressedEvent kpevent;

	public:

		
		Event() { this->kpevent = KeyPressedEvent(); }
		
		SDL_Event& event() { return this->sdl_event; }

		//SDL_EventType get_event_type() { return this->e; }
		SDL_Keycode get_keycode() { return this->kpevent.Keycode; }
		inline std::size_t& get_repeat_count() { return this->kpevent.RepeatCount; }



		void set_key_pressed_event(const KeyPressedEvent& kpevent , bool repeat , std::function<void()> func)
		{
			
				if (event().key.keysym.sym == kpevent.Keycode && event().key.repeat == repeat)
				
					func();

		}


		
		
	};



	
	

	
}

