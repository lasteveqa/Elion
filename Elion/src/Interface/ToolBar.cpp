#include "Interface/ToolBar.h"


namespace Elion
{
	namespace Interface
	{
		void ToolBar::init(SDL_Window* window, SDL_GLContext gl_context)
		{

		}

		void ToolBar::render(SDL_Window* window)
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
						this->TriangleSelected = true;
					
					}
					if (ImGui::MenuItem("Quad"))
					{
						this->QuadSelected = true;
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

			if (this->TriangleSelected)
			{
				Scene::draw_triangle();
				this->TriangleSelected = false;
			}

			if (this->QuadSelected)
			{
				Scene::draw_quad();
				this->QuadSelected = false;
			}
			
			



		}

		void ToolBar::clear()
		{

		}
	}
}