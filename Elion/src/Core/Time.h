#pragma once


namespace Elion
{


	class Time
	{
	public:
		Time(float time = 0.0f)
			: time(time)
		{
		}

		operator float() const { return time; }

		float GetSeconds() const { return time; }
		float GetMilliseconds() const { return time * 1000.0f; }

	private:
		float time;


	};


}