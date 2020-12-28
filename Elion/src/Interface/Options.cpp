#include "Options.h"

namespace Elion
{
	namespace Interface
	{
		void Options::init()
		{

		}

		void Options::render()
		{
			SDL_GetMouseState(&x, &y);
			//std::cout << index << std::endl;
			if (is_opened() && !m_SetOfProperties.empty())
			{
				ImGui::SetNextWindowSizeConstraints(ImVec2(this->m_Width, this->m_Height), ImVec2(this->m_Width, this->m_Height));
				if (ImGui::Begin("Options"))
				{
					if (ImGui::Selectable("Delete"))
					{

						m_Scene.delete_item(index);
						m_PrimitiveTypes.erase(m_PrimitiveTypes.begin() + index);
						m_SetOfProperties.erase(m_SetOfProperties.begin() + index);
						index = 0;
						is_opened() = this->m_IsClicked;
					}
					is_opened() = this->m_IsClicked;
					ImGui::End();
				}
			}
		}


		bool& Options::is_opened()
		{
			const Uint8* keys = SDL_GetKeyboardState(NULL);
			if ((!keys[SDL_SCANCODE_LCTRL] && !keys[SDL_SCANCODE_RCTRL]) && (!keys[SDL_SCANCODE_LSHIFT] && !keys[SDL_SCANCODE_RSHIFT]) && (!keys[SDL_SCANCODE_LALT] && !keys[SDL_SCANCODE_RALT]))
			{
				switch (sdl_event.type)
				{
				case SDL_MOUSEBUTTONDOWN:
					switch (sdl_event.button.button)
					{
					case SDL_BUTTON_RIGHT:

						ImGui::SetNextWindowPos(ImVec2(x, y));
						this->m_Opened = true;
						this->m_IsClicked = true;

						break;

					case SDL_BUTTON_LEFT:
						if (!ImGui::IsMouseHoveringRect(ImVec2(x, y), ImVec2(x + this->m_Width, y + this->m_Height)))
							this->m_IsClicked = false;

						break;
					}
					break;

				case SDL_MOUSEBUTTONUP:
					switch (sdl_event.button.button)
					{
					case SDL_BUTTON_RIGHT:
						break;
					}
					break;

				}
			}
			return this->m_Opened;
		}

		

		void Options::clear()
		{

		}
	}
}