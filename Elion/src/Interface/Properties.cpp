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

			


			ImGui::SetNextWindowSizeConstraints(ImVec2(500.0f, 300.0f), ImVec2(500.0f, 300.0f));
			ImGui::SetNextWindowPos(ImVec2(10.0f, 250.0f));

			if (ImGui::Begin("Properties"))
			{
				if (!m_SetOfProperties.empty() && !m_PrimitiveTypes.empty())
				{
					float color[] = { this->m_SetOfProperties[index].color.R , this->m_SetOfProperties[index].color.G , this->m_SetOfProperties[index].color.B , this->m_SetOfProperties[index].color.A };

					ImGui::Text("Color");
					ImGui::ColorEdit4("", color, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputRGB);

					ImGui::Text("Position");
					ImGui::PushItemWidth(50);
					ImGui::InputFloat("x", &this->m_SetOfProperties[index].position.X);
					ImGui::SameLine(100);
					ImGui::InputFloat("y", &this->m_SetOfProperties[index].position.Y);
					ImGui::SameLine(200);
					ImGui::InputFloat("z", &this->m_SetOfProperties[index].position.Z);


					ImGui::Text("Size");
					ImGui::PushItemWidth(50);
					ImGui::InputFloat("X", &this->m_SetOfProperties[index].scale.X);
					ImGui::SameLine(100);
					ImGui::InputFloat("Y", &this->m_SetOfProperties[index].scale.Y);
					ImGui::SameLine(200);
					ImGui::InputFloat("Z", &this->m_SetOfProperties[index].scale.Z);


					ImGui::Text("Rotation");
					ImGui::PushItemWidth(50);
					ImGui::InputFloat("Rad", &this->m_SetOfProperties[index].rotation.Radians);
					ImGui::SameLine(100);
					ImGui::InputFloat("Xpos", &this->m_SetOfProperties[index].rotation.X);
					ImGui::SameLine(200);
					ImGui::InputFloat("Ypos", &this->m_SetOfProperties[index].rotation.Y);
					ImGui::SameLine(300);
					ImGui::InputFloat("Zpos", &this->m_SetOfProperties[index].rotation.Z);


					ImGui::Text("Projection");
					ImGui::PushItemWidth(60);
					ImGui::InputFloat("Rp", &this->m_SetOfProperties[index].projection.Radians);
					ImGui::SameLine(100);
					ImGui::InputFloat("W", &this->m_SetOfProperties[index].projection.Width);
					ImGui::SameLine(200);
					ImGui::InputFloat("H", &this->m_SetOfProperties[index].projection.Height);
					ImGui::SameLine(300);
					ImGui::InputFloat("Near", &this->m_SetOfProperties[index].projection.Near);
					ImGui::SameLine(400);
					ImGui::InputFloat("Far", &this->m_SetOfProperties[index].projection.Far);

					handle_color(color);

				}
					ImGui::End();
			}
		}

		void Properties::clear()
		{

		}


		void Properties::handle_color(float* color)
		{
				m_SetOfProperties[index].color.R = color[0];
				m_SetOfProperties[index].color.G = color[1];
				m_SetOfProperties[index].color.B = color[2];
				m_SetOfProperties[index].color.A = color[3];
		}
	}
}