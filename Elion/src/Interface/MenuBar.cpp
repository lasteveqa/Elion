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


