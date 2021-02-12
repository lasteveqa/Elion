#pragma once
#include "Interface/UIComponent.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"

namespace Elion
{
	
	namespace Interface
	{
		enum { DEFAULT, ROTATION, TRANSLATION, ORBIT };

	

		class MainScene : public UIComponent
		{
		private:

			bool m_Opened = false;
			int m_Xpos = 0, m_Ypos = 0;
			int m_ButtonNumber = 0;

			float pitch = 0.0f;
			float yaw = -90.0f;
			float xoffset = 0.0f;
			float yoffset = 0.0f;
			float lastX = SCENE_WIDTH / 2, lastY = SCENE_HEIGHT / 2;
			bool firstMouse = true;

			const float m_Width = 250.0f;
			const float m_Height = 700.0f;

			float m_CameraSpeed = 0.16f;

			//Skybox
			std::unique_ptr<PObject> m_Skybox;
			std::vector<std::string> faces;
			SetOfPropeties m_SkyboxProps;
			float m_Pitch, m_Yaw, m_Xoffset, m_Yoffset;
			glm::vec3 m_CameraFront;
			//

		public:

			void rotate_world();
			void translate_world();

			//skybox
			unsigned int load_cubemap(std::vector<std::string> faces);
		
			void rotate_skybox();
			//

			void init() override;
			void render() override;
			void clear() override;

			//Options
			void options();
			bool is_options_opened();
			//
		};
	}
}