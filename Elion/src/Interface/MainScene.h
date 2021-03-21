#pragma once
#include "Interface/UIComponent.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"
#include "Meshes/Mesh.h"
#include "Renderer/OBJFileLoader.h"
namespace Elion
{
	
	namespace Interface
	{
		enum { DEFAULT, ROTATION, TRANSLATION, ORBIT };

		struct Offset
		{
			float X, Y;
	    };

		class MainScene : public UIComponent
		{
		private:

			bool m_Opened = false;
			bool m_OutOfScene = false;
			int m_Xpos = 0, m_Ypos = 0;
			int m_ButtonNumber = 0;

			float pitch = 0.0f;
			float yaw = -90.0f;
			float lastX = SCENE_WIDTH / 2, lastY = SCENE_HEIGHT / 2;
			float Radians = 0.0f;

			const float m_Width = 250.0f;
			const float m_Height = 700.0f;

			const float m_CameraSpeed = 0.1f;

			Offset m_Offset;


			OBJFileLoader obj;

			//Skybox
			std::unique_ptr<Entity> m_Skybox;
			std::vector<std::string> faces;
			SetOfPropeties m_SkyboxProps;
			float m_Pitch, m_Yaw, m_Xoffset, m_Yoffset;
			glm::vec3 m_CameraFront;
			//

			Mesh m_Mesh;

		public:

		    bool rotate_camera();
			bool translate_camera();
			void orbit_camera();

			void calculate_offset();

			bool is_mouse_in_scene();

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