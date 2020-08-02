#pragma once
#include "GL/glew.h"
#include "Core/Core.h"
#include "SDL.h"
#include "Core/Log.h"
#include <iostream>
#include "Renderer/Renderer.h"
#include "Interface/UserInterface.h"

namespace Elion
{

	class Window
	{
	private:


	public:
		

		virtual void init(){}
		virtual void render(){}
		virtual void update(){}
		virtual void clear(){}
	};



	class WindowSwitcher
	{
	private:
		Window* window;

	public:
		void set_window(Window* window)
		{
			this->window = nullptr;

			this->window = window;

			this->window->init();
		}

		void update()
		{
			if (this->window != nullptr)
			{
				this->window->update();
			}
		}


		void render()
		{
			if (this->window != nullptr)
			{
				this->window->render();
			}
		}



		void clear()
		{
			this->window->clear();
			this->window = nullptr;
		}


		~WindowSwitcher()
		{
			this->window->clear();
			this->window = nullptr;
		}
	};

}