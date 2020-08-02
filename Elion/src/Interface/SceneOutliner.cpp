#include "Interface/SceneOutliner.h"


namespace Elion
{
	namespace Interface
	{
		void SceneOutliner::init()
		{

		}

		void SceneOutliner::render()
		{
			ImGui::SetNextWindowSizeConstraints(ImVec2(350.0f, 400.0f), ImVec2(350.0f, 400.0f));
			ImGui::SetNextWindowPos(ImVec2(this->m_Wprops.size().Width - 360.0f, 40.0f));

			if (ImGui::Begin("Scene Outliner"))
			{
				//auto style = ImGui::GetStyle();

				ImGui::TextColored(ImVec4(1, 1, 0, 1), "Items");

				ImGui::BeginChild("Scrolling");
				for (std::size_t i = 0; i < m_PrimitiveTypes.size(); i++)
				{
					switch (m_PrimitiveTypes[i])
					{
					case PrimitiveTypes::TRIANGLE:
						ImGui::Text("Triangle", m_PrimitiveTypes.size());
						break;

					case PrimitiveTypes::QUAD:
						ImGui::Text("Quad", m_PrimitiveTypes.size());
						break;

					case PrimitiveTypes::ROUND:
						ImGui::Text("Round", m_PrimitiveTypes.size());
						break;
					}
					
				}

				ImGui::EndChild();

				ImGui::End();
			}


		}

		void SceneOutliner::clear()
		{

		}
	}
}