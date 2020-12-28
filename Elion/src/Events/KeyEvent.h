#pragma once
#include "Core/Core.h"
#include "Events/Event.h"


namespace Elion
{
	class KeyEvent
	{
	private:
		KeyCodes m_Key;
	public:


		//Using SDL functions//////////////////
		template<typename T, typename ... Args>
		void set_key_down(SDL_Keycode key, std::function<T>& f(Args... args));

		template<typename T, typename ... Args>
		void set_key_down(const std::string& key, std::function<T>& f(Args... args));

		template<typename T, typename ... Args>
		void set_key_up(SDL_Keycode key, std::function<T>& f(Args... args));

		/////////////////////////////////////////////////////////////////////

		void set_key(KeyCodes k);


	};
}