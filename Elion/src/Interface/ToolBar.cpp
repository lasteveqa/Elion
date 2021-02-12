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
						if (ImGui::MenuItem("Quad"))
						{
							m_Scene.add_primitive(PrimitiveTypes::QUAD);
							m_PrimitiveTypes.emplace_back(PrimitiveTypes::QUAD);
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
						ImGui::EndMenu();
					}
					if (ImGui::BeginMenu("Texture"))
					{
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