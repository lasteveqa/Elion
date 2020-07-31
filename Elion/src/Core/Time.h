#pragma once
#include <Core/Core.h>

namespace Elion
{


	class Time
	{


	private:

		Uint32 m_StartTicks;

		Uint32 m_PausedTicks;

		bool m_Paused;
		bool m_Started;

	public:
		
		Time()
		{
			m_StartTicks = 0;
			m_PausedTicks = 0;

			m_Paused = false;
			m_Started = false;
		}

		void start()
		{
			m_Started = true;

			m_Paused = false;

			m_StartTicks = SDL_GetTicks();

			m_PausedTicks = 0;
		}
		void stop()
		{
			m_Started = false;

			m_Paused = false;

			m_StartTicks = 0;

			m_PausedTicks = 0;
		}
		void pause()
		{
			if (m_Started && !m_Paused)
			{

				m_Paused = true;

				m_PausedTicks = SDL_GetTicks() - m_StartTicks;
				m_StartTicks = 0;
			}
		}
		void unpause()
		{
			if (m_Started && m_Paused)
			{
				m_Paused = false;

				m_StartTicks = SDL_GetTicks() - m_PausedTicks;

				m_PausedTicks = 0;
			}
		}

		Uint32 get_ticks()
		{
			Uint32 time = 0;

			if (m_Started)
			{
				if (m_Paused)
				{
	
					time = m_PausedTicks;
				}
				else
				{
					time = SDL_GetTicks() - m_StartTicks;
				}
			}

			return time;
		}

		bool is_paused()
		{
			return m_Paused;
		}


	};


}