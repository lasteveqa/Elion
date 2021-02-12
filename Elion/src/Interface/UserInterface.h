#pragma once
#include "Core/Core.h"
#include "Interface/MenuBar.h"
#include "Interface/ToolBar.h"
#include "Interface/Properties.h"
#include "Interface/SceneOutliner.h"
#include "Interface/MainScene.h"
namespace Elion
{

	namespace Interface
	{
		class UserInterface
		{

		private:

			static MenuBar m_MenuBar;
			static ToolBar m_ToolBar;
			static Properties m_Properties;
			static SceneOutliner m_SceneOutliner;
			static MainScene m_MainScene;
			
		public:

			static void init(SDL_Window* window , SDL_GLContext gl_context);
			static void begin(SDL_Window* window);
			static void end();
			static void render(SDL_Window* window);
			static void events();
			static void clear();
		};

	}

}

