#pragma once

#include "Event.h"
namespace Elion
{
	

  
	 
	class WindowCloseEvent : public Event
	{

	public:
		


	};

	class AppTickEvent : public Event
	{

	public:
		AppTickEvent() = default;


	};


	class AppUpdateEvent : public Event
	{
	public:

		AppUpdateEvent() = default;


	};

	class AppRenderEvent : public Event
	{
	public:

		AppRenderEvent() = default;

		

	};




	class ApplicationEvent
	{

	};
}