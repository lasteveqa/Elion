#include "Interface/MainScene.h"

namespace Elion
{
	namespace Interface
	{

		void MainScene::init()
		{

		}

		void MainScene::render()
		{
			
			glViewport(SCENE_XPOSITION, SCENE_YPOSITION, SCENE_WIDTH, SCENE_HEIGHT);
			/*
			glm::mat4 pMat4;  // your matrix

			double dArray[16] = { 0.0 };

			const float* pSource = (const float*)glm::value_ptr(pMat4);
			for (int i = 0; i < 16; ++i)
				dArray[i] = pSource[i];
			*/

			if (!m_PrimitiveTypes.empty() && !this->m_SetOfProperties.empty())
			{
				rotate();
				//move_camera();
			}


			m_Scene.draw();
			m_Scene.update();

		}

		void MainScene::rotate()
		{
			static bool ctrl_clicked = false;
			static bool mouse_button_clicked = false;
			int X, Y = 0;
			static float resultX, resultY = 0;
			const Uint8* state = SDL_GetKeyboardState(NULL);



			if (state[SDL_SCANCODE_W])
				for (std::size_t i = 0; i < this->m_Scene.get_primitives().size(); ++i)
				{
					this->m_SetOfProperties[i].position.Z -= 0.01f;
				}

			if (state[SDL_SCANCODE_S])
				for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
				{
					this->m_SetOfProperties[i].position.Z += 0.01f;
				}

			if (state[SDL_SCANCODE_LCTRL])
				ctrl_clicked = true;

			if (state[SDL_SCANCODE_RCTRL])
				ctrl_clicked = true;

			switch (sdl_event.type)
			{

			
				
				
			

			case SDL_MOUSEBUTTONDOWN:
				if (sdl_event.button.button == SDL_BUTTON_RIGHT && ctrl_clicked)
				{
					mouse_button_clicked = true;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				ctrl_clicked = false;
				mouse_button_clicked = false;
				break;

			case SDL_MOUSEMOTION:

				if (mouse_button_clicked)
				{

					SDL_GetMouseState(&X, &Y);
					if (X > m_Wprops.size().Width / 2)
					{
						this->m_SetOfProperties[index].rotation.Radians += 0.1f;
						resultX = this->m_SetOfProperties[index].rotation.Radians;
					}
					if (Y > m_Wprops.size().Height / 2)
					{
						this->m_SetOfProperties[index].rotation.Radians += 0.1f;
						resultY = this->m_SetOfProperties[index].rotation.Radians;
					}
					if (X < m_Wprops.size().Width / 2)
					{
						this->m_SetOfProperties[index].rotation.Radians -= 0.1f;
						resultX = this->m_SetOfProperties[index].rotation.Radians;
					}

					if (Y < m_Wprops.size().Height / 2)
					{
						this->m_SetOfProperties[index].rotation.Radians -= 0.1f;
						resultY = this->m_SetOfProperties[index].rotation.Radians;
					}

					this->m_SetOfProperties[index].rotation.X = resultX;
					this->m_SetOfProperties[index].rotation.Y = resultY;
				}

				break;

			}


		}


		void MainScene::move_camera()
		{
			switch (sdl_event.type)
			{
			case SDL_KEYDOWN:
				switch (sdl_event.key.keysym.sym)
				{
				case SDLK_w:
					for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
					{
						this->m_SetOfProperties[i].position.Z -= 1.0f;
					}
					break;

				case SDLK_s:
					for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
					{
						this->m_SetOfProperties[i].position.Z += 1.0f;
					}
					break;
				}
				break;
			}
		}

		void MainScene::clear()
		{

		}

	}
}