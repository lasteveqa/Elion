#pragma once
#include "Core/Core.h"
#include "SDL.h"
namespace Elion
{


	class Input
	{
	private:
		static std::unique_ptr<Input> input_Instance;

	public:

		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool is_key_pressed(SDL_Keycode key) { return key; }


		static std::unique_ptr<Input>& Instance()
		{
			
			return input_Instance;
		}
		
		
	};

}
