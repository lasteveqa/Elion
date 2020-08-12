#include "UserInterface.h"

namespace Elion
{
	namespace Interface
	{
		MenuBar UserInterface::m_MenuBar;
		ToolBar UserInterface::m_ToolBar;
		Properties UserInterface::m_Properties;
		SceneOutliner UserInterface::m_SceneOutliner;

		void UserInterface::init(SDL_Window* window, SDL_GLContext gl_context)
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();

			ImGui::StyleColorsDark();

			ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
			ImGui_ImplOpenGL3_Init("#version 430 core");

			m_MenuBar.init();
			m_ToolBar.init();
			m_Properties.init();
			m_SceneOutliner.init();
		}

		void UserInterface::begin(SDL_Window* window)
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplSDL2_NewFrame(window);
			ImGui::NewFrame();
		}

		void UserInterface::end()
		{
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

		void UserInterface::render(SDL_Window* window)
		{
			begin(window);

			m_MenuBar.render();
			m_ToolBar.render();
			m_Properties.render();
			m_SceneOutliner.render();

			glDisable(GL_STENCIL_TEST);
			// Non-stencil primitives here
			Scene::update();
			Scene::draw();

			end();
		}

		void UserInterface::clear()
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplSDL2_Shutdown();
		}
	}
}