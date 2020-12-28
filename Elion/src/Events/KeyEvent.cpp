#include "Events/KeyEvent.h"


namespace Elion
{
	template<typename T , typename ... Args>
	void KeyEvent::set_key_down(SDL_Keycode key , std::function<T>& f(Args... args))
	{
		if (sdl_event.type == SDL_KEYDOWN)
		{
			if (sdl_event.key.keysym.sym == key)
				f();
		}
	}

	template<typename T, typename ... Args>
	void KeyEvent::set_key_down(const std::string& key, std::function<T>& f(Args... args))
	{
		if (sdl_event.type == SDL_KEYDOWN)
		{
			if(key == "K")
			if (sdl_event.key.keysym.sym == SDLK_k)
				f();
		}
	}

	template<typename T, typename ... Args>
	void KeyEvent::set_key_up(SDL_Keycode key, std::function<T>& f(Args... args))
	{
		if (sdl_event.type == SDL_KEYUP)
		{
			if (sdl_event.key.keysym.sym == key)
				f();
		}
	}



	void KeyEvent::set_key(KeyCodes k)
	{
		if (sdl_event.type == SDL_KEYDOWN)
		{
			if (sdl_event.key.keysym.sym == SDLK_a)
				std::cout << "A pressed" << std::endl;
		}
	}
}