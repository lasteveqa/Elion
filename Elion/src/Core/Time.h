#pragma once
#include <Core/Core.h>

namespace Elion
{


	class Time
	{
	private:
		float m_LastTime = SDL_GetTicks();

	public:
		Time() { }
		
		float get_delta()
		{
			double currentTime = SDL_GetTicks();
			double delta = currentTime - m_LastTime;
			m_LastTime = currentTime;

			return delta;
		}

	};


}