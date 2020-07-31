#include "Interface/SceneOutliner.h"


namespace Elion
{
	namespace Interface
	{
		void SceneOutliner::init(SDL_Window* window, SDL_GLContext gl_context)
		{

		}

		void SceneOutliner::render(SDL_Window* window)
		{
			ImGui::SetNextWindowSizeConstraints(ImVec2(350.0f, 400.0f), ImVec2(350.0f, 400.0f));
			ImGui::SetNextWindowPos(ImVec2(this->m_Wprops.size().Width - 360.0f, 40.0f));

			if (ImGui::Begin("Scene Outliner"))
			{
				//auto style = ImGui::GetStyle();

				ImGui::TextColored(ImVec4(1, 1, 0, 1), "Items");

				ImGui::BeginChild("Scrolling");
				for (int n = 0; n < 50; n++)
				{
					ImGui::Text("%04d: Some text", n);
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