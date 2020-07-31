#pragma once
#include "Core/Core.h"
#include "SDL.h"
#include "glm/glm.hpp"

namespace Elion
{


	class Input
	{
	private:
		static std::unique_ptr<Input> input_Instance;

		static float x;
		static float y;

	public:

		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool is_key_pressed(SDL_Keycode key) { return key; }

		inline static float get_mouse_Xposition()  { return x; }
		inline static float get_mouse_Yposition() { return y; }


		static std::unique_ptr<Input>& Instance()
		{
			
			return input_Instance;
		}
		
		
	};

}
