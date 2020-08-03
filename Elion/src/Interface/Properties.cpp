#include "Interface/Properties.h"


namespace Elion
{
	namespace Interface
	{
		void Properties::init()
		{
			
		}

		void Properties::render()
		{
			
			ImGuiIO& io = ImGui::GetIO();
			
			static float color[] = { this->m_Color.R , this->m_Color.G , this->m_Color.B , this->m_Color.A };

			ImGui::SetNextWindowSizeConstraints(ImVec2(300.0f, 200.0f), ImVec2(300.0f, 200.0f));
			ImGui::SetNextWindowPos(ImVec2(10.0f, 250.0f));

			if (ImGui::Begin("Properties"))
			{
				ImGui::Text("Color");
				ImGui::ColorEdit4("", color);

				ImGui::Text("Position");
				ImGui::PushItemWidth(50);
				ImGui::InputFloat("x", &this->m_Position.X);
				ImGui::SameLine(100);
				ImGui::InputFloat("y", &this->m_Position.Y);
				ImGui::SameLine(200);
				ImGui::InputFloat("z", &this->m_Position.Z);
			
				ImGui::Text("Size");
				ImGui::PushItemWidth(50);
				ImGui::InputFloat("X", &this->m_Size.X);
				ImGui::SameLine(100);
				ImGui::InputFloat("Y", &this->m_Size.Y);
				ImGui::SameLine(200);
				ImGui::InputFloat("Z", &this->m_Size.Z);

				ImGui::End();
			}

			Scene::set_properties(this->m_Color, this->m_Size, this->m_Position);
		}

		void Properties::clear()
		{

		}
	}
}