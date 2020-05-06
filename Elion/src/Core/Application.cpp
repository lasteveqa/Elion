
#include "Application.h"

namespace Elion 
{
	

	Application::Application()
	{
		
		Log::init();
	}

    void Application::init()
	{
		
	}

	void Application::Run()
	{
		
		Renderer::render();
	}

	void Application::update()
	{
		
	}


	Application::~Application()
	{
		//window->clear();
	
	}
}