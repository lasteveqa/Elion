#include "Interface/ToolBar.h"


namespace Elion
{
	namespace Interface
	{
		void ToolBar::init()
		{

		}

		void ToolBar::render()
		{
			ImGui::SetNextWindowSizeConstraints(ImVec2(200.0f, 200.0f), ImVec2(200.0f, 200.0f));
			ImGui::SetNextWindowPos(ImVec2(10.0f, 40.0f));

			if (ImGui::Begin("Toolbar"))
			{
				if (m_PrimitiveTypes.empty())
					index = -1;
				
					if (ImGui::BeginMenu("Primitive"))
					{


						if (ImGui::MenuItem("Triangle"))
						{

							m_Scene.add_primitive(PrimitiveTypes::TRIANGLE);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::TRIANGLE);
							index++;
						}
						if (ImGui::MenuItem("Plane"))
						{
							m_Scene.add_primitive(PrimitiveTypes::PLANE);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::PLANE);
							index++;
						}
						if (ImGui::MenuItem("Round"))
						{
							m_Scene.add_primitive(PrimitiveTypes::ROUND);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::ROUND);
							index++;
						}

						ImGui::EndMenu();
					}
					if (ImGui::BeginMenu("Mesh"))
					{

						if (ImGui::MenuItem("Cube"))
						{
							m_Scene.add_primitive(PrimitiveTypes::CUBE);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::CUBE);
							index++;
						}

						if (ImGui::MenuItem("Sphere"))
						{
							m_Scene.add_primitive(PrimitiveTypes::SPHERE);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::SPHERE);
							index++;
						}
						ImGui::EndMenu();
					}
					if (ImGui::BeginMenu("Light"))
					{
						if (ImGui::MenuItem("Directional Light"))
						{
						}
						if (ImGui::MenuItem("Spot Light"))
						{
						}
						if (ImGui::MenuItem("Point Light"))
						{
						}
						if (ImGui::MenuItem("Rect Light"))
						{
						}
						if (ImGui::MenuItem("Sky Light"))
						{
						}
						ImGui::EndMenu();
					}

				
					ImGui::End();
				
			}





		}

		void ToolBar::clear()
		{

		}
	}
}