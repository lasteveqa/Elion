#include "Interface/MenuBar.h"

namespace Elion
{
	namespace Interface
	{
		void MenuBar::init()
		{

		}

		void MenuBar::render()
		{
			if (ImGui::BeginMainMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("New"))
					{
						
					}
					if (ImGui::MenuItem("Open"))
					{

					}
					if (ImGui::MenuItem("Save"))
					{

					}
					if (ImGui::MenuItem("Exit"))
					{
						sdl_event.type = SDL_QUIT;
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
				if (ImGui::BeginMenu("Settings"))
				{
					if (ImGui::MenuItem("OpenGL version"))
					{
						if (ImGui::MenuItem("OpenGL version"))
						{

						}
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Help"))
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


