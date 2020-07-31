#include "MenuBar.h"


namespace Elion
{
	namespace Interface
	{
		void MenuBar::init(SDL_Window* window, SDL_GLContext gl_context)
		{

		}

		void MenuBar::render(SDL_Window* window)
		{

			
			if (ImGui::BeginMainMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("New"))
					{
						//Do something
					}
					if (ImGui::MenuItem("Open"))
					{
						//Do something
					}
					if (ImGui::MenuItem("Save"))
					{
						//Do something
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Edit"))
				{
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("View"))
				{
					ImGui::EndMenu();
				}
				ImGui::EndMainMenuBar();
			}

		}

		void MenuBar::clear()
		{

		}
	}
}