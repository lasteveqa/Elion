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
				ImGui::TextColored(ImVec4(1, 1, 0, 1), "Items");

				ImGui::BeginChild("Scrolling");
				
				if (!m_PrimitiveTypes.empty())
				{
					for (std::size_t i = 0; i < m_PrimitiveTypes.size(); ++i)
					{
					 std::string str_index = "";

					 if (m_PrimitiveTypes.size() != m_SetOfProperties.size())
					 {
						 m_SetOfProperties.push_back(SetOfPropeties());
					 }
					 
						 if (m_PrimitiveTypes[i] == PrimitiveTypes::TRIANGLE)
						 {
							 str_index = std::to_string(i) + ": Triangle";
							 if (ImGui::Selectable(str_index.c_str()))
							 {
								 index = i;
							 }
						 }

						 else if (m_PrimitiveTypes[i] == PrimitiveTypes::QUAD)
						 {

							 str_index = std::to_string(i) + ": Quad";
							 if (ImGui::Selectable(str_index.c_str()))
							 {
								 index = i;
							 }

						 }

						 else if (m_PrimitiveTypes[i] == PrimitiveTypes::ROUND)
						 {
							 str_index = std::to_string(i) + ": Round";

							 if (ImGui::Selectable(str_index.c_str()))
							 {
								 index = i;
							 }
						 }


						 else if (m_PrimitiveTypes[i] == PrimitiveTypes::CUBE)
						 {
							 str_index = std::to_string(i) + ": Cube";
							 if (ImGui::Selectable(str_index.c_str()))
							 {
								 index = i;
							 }
						 }

					}
					
					if (!m_SetOfProperties.empty())
					{				
							m_Scene.set_item_position(m_SetOfProperties[index].position, index);
							m_Scene.set_item_color(m_SetOfProperties[index].color, index);
							m_Scene.set_item_scale(m_SetOfProperties[index].scale, index);
							m_Scene.set_item_projection(m_SetOfProperties[index].projection, index);
							m_Scene.set_item_rotation(m_SetOfProperties[index].rotation, index);
					}
				}

			    ImGui::EndChild();				

				ImGui::End();
			}


		}




	}

}