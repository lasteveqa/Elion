#include "Interface/SceneOutliner.h"


namespace Elion
{
	namespace Interface
	{
		void SceneOutliner::init()
		{
			glEnable(GL_STENCIL_TEST);
		}

		void SceneOutliner::render()
		{
			ImGui::SetNextWindowSizeConstraints(ImVec2(350.0f, 400.0f), ImVec2(350.0f, 400.0f));
			ImGui::SetNextWindowPos(ImVec2(this->m_Wprops.size().Width - 360.0f, 40.0f));


			if (ImGui::Begin("Scene Outliner"))
			{

				ImGui::TextColored(ImVec4(1, 1, 0, 1), "Items");

				if (ImGui::BeginChild("Scrolling"))
				{
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

					for (std::size_t i = 0; i < m_PrimitiveTypes.size(); i++)
					{
						glStencilFunc(GL_ALWAYS, 1, 0xFF);
						glStencilMask(0xFF);

						if (ImGui::IsItemClicked())
						{
							Selected::set(i);
						}

						Selected::draw(Scene::get_primitives());

						glStencilFunc(GL_NOTEQUAL, 0, 0xFF);
						glStencilMask(0x00);
						glDisable(GL_DEPTH_TEST);

						Scene::get_primitives()[i]->set_size(Size(1.01f, 1.01f, 1.01f));
						glColorMask(255, 255, 0, 255);

						Selected::draw(Scene::get_primitives());
						glColorMask(255, 255, 255, 0);
						glStencilMask(0xFF);
						glStencilFunc(GL_KEEP, 2, 0xFF);
						glEnable(GL_DEPTH_TEST);
					}
					ImGui::EndChild();
				}

				ImGui::End();
			}


		



		}

		void SceneOutliner::draw_no_stencil()
		{

		}


		void SceneOutliner::draw_stencil()
		{
			glEnable(GL_STENCIL_TEST);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			//Stencil Primitives here
		}


		void SceneOutliner::draw_scaled_version_fo_primitives()
		{
			glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
			glDisable(GL_DEPTH_TEST);

			// draw scaled of stencil primitives here

			glEnable(GL_DEPTH_TEST);
		}

		void SceneOutliner::clear()
		{

		}
	}
}