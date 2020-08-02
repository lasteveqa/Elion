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
				//auto style = ImGui::GetStyle();
				
				if (ImGui::BeginMenu("Primitive"))
				{
					if (ImGui::MenuItem("Triangle"))
					{
						
						Scene::add_primitive(PrimitiveTypes::TRIANGLE);
						m_PrimitiveTypes.push_back(PrimitiveTypes::TRIANGLE);
					
					}
					if (ImGui::MenuItem("Quad"))
					{
						Scene::add_primitive(PrimitiveTypes::QUAD);
						m_PrimitiveTypes.push_back(PrimitiveTypes::QUAD);
					}
					if (ImGui::MenuItem("Round"))
					{
						
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Mesh"))
				{
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Texture"))
				{
					ImGui::EndMenu();
				}
				ImGui::End();
			}

		/*	if (this->TriangleSelected)
			{
				Scene::draw_triangle();
				
			}
			
			if (this->QuadSelected)
			{
				Scene::draw_quad();
				
			}*/
			
			Scene::draw();



		}

		void ToolBar::clear()
		{

		}
	}
}