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

				if (ImGui::BeginChild("Scrolling"))
				{
					for (std::size_t i = 0; i < m_PrimitiveTypes.size(); ++i)
					{
						
						switch (m_PrimitiveTypes[i])
						{
						case PrimitiveTypes::TRIANGLE:
							ImGui::Text("Triangle", m_PrimitiveTypes.size());
							//add_object_to_list("Triangle");

							break;

						case PrimitiveTypes::QUAD:
							ImGui::Text("Quad", m_PrimitiveTypes.size());
							//add_object_to_list("Quad");

							break;

						case PrimitiveTypes::ROUND:
							ImGui::Text("Round", m_PrimitiveTypes.size());
							break;
						}


						if (ImGui::IsItemClicked())
						{
							m_StencilTest = Stencil::ON;
						}

						switch (m_StencilTest)
						{
						case Stencil::ON:

							//glEnable(GL_STENCIL_TEST);

							//glStencilFunc(GL_ALWAYS, 1, 0xFF);
							////Scene::clean_all_properties(i);
							//Scene::set_excepted_primitive(i);
							//Scene::update_excepted_primitives();
							//Scene::draw_excepted_primitives();

							//glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
							//glDisable(GL_DEPTH_TEST);

							//Scene::clean_all_properties(i);
							//Scene::get_primitives()[i]->set_size(Size(1.03f, 1.03f, 0.0f));
							//Scene::get_primitives()[i]->set_color(Color(1.0f, 0.0f, 1.0f, 1.0f));
							//Scene::update_excepted_primitives();
							//Scene::draw_excepted_primitives();

							//glEnable(GL_DEPTH_TEST);
							//break;

						case Stencil::OFF:

							break;
						}
						
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