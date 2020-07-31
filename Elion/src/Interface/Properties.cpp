#include "Interface/Properties.h"


namespace Elion
{
	namespace Interface
	{
		void Properties::init(SDL_Window* window, SDL_GLContext gl_context)
		{
			
		}

		void Properties::render(SDL_Window* window)
		{
			
			ImGuiIO& io = ImGui::GetIO();
			
			static float color[] = { 0.5f , 0.5f , 0.5f, 1.0f };

			ImGui::SetNextWindowSizeConstraints(ImVec2(300.0f, 200.0f), ImVec2(300.0f, 200.0f));
			ImGui::SetNextWindowPos(ImVec2(10.0f, 250.0f));

			if (ImGui::Begin("Properties"))
			{
				ImGui::Text("Color");
				ImGui::ColorEdit4("", color);

				ImGui::Text("Position");
				ImGui::PushItemWidth(50);
				ImGui::InputFloat("x", &a);
				ImGui::SameLine(100);
				ImGui::InputFloat("y", &a);
				ImGui::SameLine(200);
				ImGui::InputFloat("z", &a);
			
				ImGui::Text("Size");
				ImGui::PushItemWidth(50);
				ImGui::InputFloat("X", &a);
				ImGui::SameLine(100);
				ImGui::InputFloat("Y", &a);
				ImGui::SameLine(200);
				ImGui::InputFloat("Z", &a);

				ImGui::End();
			}
		}

		void Properties::clear()
		{

		}
	}
}