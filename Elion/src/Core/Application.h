#pragma once
#include "Core.h"
#include "Core/Window.h"
#include "SDL/SDL.h"
#include "Time.h"
#include "Events/ApplicationEvent.h"
namespace Elion
{
	

	class ELION_API Application
	{
	private:

		bool running = true;

	public:

		bool is_running() { return this->running; }

		void set_running(bool enable) { this->running = enable; }

		void init();
		void Run();

		

	

		

		bool on_window_stop(WindowCloseEvent& e);

		void OnEvent(Event& e);

		
	    void update();

		/*void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);*/
		
		Application();
		~Application();

		
	};

}
