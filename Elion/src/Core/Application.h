#pragma once
#include "Core/Core.h"
#include "Time.h"
#include "Events/Event.h"
#include "Windows/MainWindow.h"
namespace Elion
{
	

	class ELION_API Application
	{
	private:

		bool running = true;
	
		WindowSwitcher m_WindowSwitcher;
	public:

		bool is_running() { return this->running; }

		void set_running(bool enable) { this->running = enable; }

		void init();

		void begin_render();
		void end_render();

		void run();

		void OnEvent(Event& e);

		
	    void update();

		
		Application();
		~Application();

		
	};

}
