#include "Interface/MainScene.h"
#include "Windows/MainWindow.h"
namespace Elion
{
	namespace Interface
	{

		void MainScene::init()
		{

			float cubeVertices[] = {
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
			};

			this->m_Skybox = std::make_unique<Entity>();
			this->m_Skybox->Program = m_Skybox->shader->load_GLSL("Shaders/skybox.vs", "Shaders/skybox.fs");
			
			glCreateBuffers(1, &this->m_Skybox->VBO);
			glBindBuffer(GL_ARRAY_BUFFER, this->m_Skybox->VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

			glCreateVertexArrays(1, &this->m_Skybox->VAO);
			glBindVertexArray(this->m_Skybox->VAO);
			

			std::vector<std::string> faces
			{
				"img/right.jpg",
					"img/left.jpg",
					"img/top.jpg",
					"img/bottom.jpg",
					"img/front.jpg",
					"img/back.jpg"
			};

			this->m_Skybox->Texture = load_cubemap(faces);

			GLint position_attribute = glGetAttribLocation(this->m_Skybox->Program, "aPos");
			glEnableVertexAttribArray(position_attribute);
			glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));

			this->m_Mesh.init();
			this->obj.loadOBJ("img/sphere.obj");
		}

		void MainScene::render()
		{

			glViewport(SCENE_XPOSITION, SCENE_YPOSITION, SCENE_WIDTH, SCENE_HEIGHT);

			SDL_GetMouseState(&m_Xpos, &m_Ypos);
			calculate_offset();
	
			/*
			glm::mat4 pMat4;  // your matrix

			double dArray[16] = { 0.0 };

			const float* pSource = (const float*)glm::value_ptr(pMat4);
			for (int i = 0; i < 16; ++i)
				dArray[i] = pSource[i];
			*/

			///////////////// Skybox
			glDepthFunc(GL_LEQUAL);
			glUseProgram(this->m_Skybox->Program);
			glBindVertexArray(this->m_Skybox->VAO);
			glBindTexture(GL_TEXTURE_CUBE_MAP, this->m_Skybox->Texture);

			
			glm::mat4 transform = glm::mat4(1.0f);
			transform = glm::translate(transform, glm::vec3(Cam::get_eye().x, Cam::get_eye().y, Cam::get_eye().z));
			transform = glm::scale(transform, glm::vec3(m_SkyboxProps.scale.X, m_SkyboxProps.scale.Y, m_SkyboxProps.scale.Z));
			transform = glm::rotate(transform, glm::radians(m_SkyboxProps.rotation.Radians), glm::vec3(m_SkyboxProps.rotation.X, m_SkyboxProps.rotation.Y, m_SkyboxProps.rotation.Z));
			


			glm::mat4 mat_projection = glm::perspective(this->m_SkyboxProps.projection.Radians, (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), this->m_SkyboxProps.projection.Near, this->m_SkyboxProps.projection.Far);

			//Cam::render();

			

			//GLint view_location = glGetUniformLocation(this->m_Skybox->Program, "view");
			GLint projecton_location = glGetUniformLocation(this->m_Skybox->Program, "projection");
			GLint transform_location = glGetUniformLocation(this->m_Skybox->Program, "transform");

			//glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(mat_view));
			glUniformMatrix4fv(projecton_location, 1, GL_FALSE, glm::value_ptr(mat_projection));
			glUniformMatrix4fv(transform_location, 1, GL_FALSE, glm::value_ptr(transform));

			//Setting camera
			Cam::set_camera("view", this->m_Skybox->Program);
		
			glDrawArrays(GL_TRIANGLES, 0, 36);

			glDepthMask(GL_TRUE);

			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glUseProgram(0);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS);
		
			///////////////// Skybox

			

			//if (is_mouse_in_scene())
			//{
			
				rotate_skybox();

			

				if (!m_PrimitiveTypes.empty() && !this->m_SetOfProperties.empty())
				{
				

					if (rotate_camera() && translate_camera())
					{
						orbit_camera();
					}

					//Render Options
					options();
					//
				}

			//}
				

				obj.update();
				obj.draw();
			
			m_Scene.update();
			m_Scene.draw();


			this->m_Mesh.draw();

			
		}

		bool MainScene::rotate_camera()
		{
	
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
			{

				this->m_ButtonNumber = ROTATION;

			}

				return true;
		}

	bool MainScene::translate_camera()
	{
		
		const Uint8* state = SDL_GetKeyboardState(NULL);

	

		if (state[SDL_SCANCODE_W] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				Cam::get_eye() +=  this->m_CameraSpeed * Cam::get_center() / 10.0f;
			}
			return true;
			this->m_ButtonNumber = TRANSLATION;
		}
	    if (state[SDL_SCANCODE_S] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	    {
		    for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
		    {
				Cam::get_eye() += -this->m_CameraSpeed * Cam::get_center() / 10.0f;
		    }
			return true;
		this->m_ButtonNumber = TRANSLATION;
	    }

		if (state[SDL_SCANCODE_A] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				glm::vec3 strafeDirection = glm::cross(Cam::get_center(), Cam::get_up());
				Cam::get_eye() += -this->m_CameraSpeed * strafeDirection / 10.0f;
			}
			return true;
			this->m_ButtonNumber = TRANSLATION;
		}
		if (state[SDL_SCANCODE_D] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				glm::vec3 strafeDirection = glm::cross(Cam::get_center(), Cam::get_up());
				Cam::get_eye() += this->m_CameraSpeed * strafeDirection / 10.0f;
			}
			return true;
			this->m_ButtonNumber = TRANSLATION;
		}

		return false;
	}


	void MainScene::orbit_camera()
	{

	}


	void MainScene::options()
	{
		
		if (is_options_opened() && !m_SetOfProperties.empty())
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
					this->m_Opened = false;
				}
				this->m_Opened = is_options_opened();
				ImGui::End();
			}
		}

	}


	bool MainScene::is_options_opened()
	{

		static int x = 0, y = 0;

		switch (sdl_event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			this->m_ButtonNumber = DEFAULT;
			break;

		case SDL_MOUSEBUTTONUP:
			switch (sdl_event.button.button)
			{
			case SDL_BUTTON_RIGHT:
				ImGui::SetNextWindowPos(ImVec2(m_Xpos, m_Ypos));


				if ((m_Xpos > SCENE_XPOSITION && m_Xpos < SCENE_XPOSITION + SCENE_WIDTH) &&
					(m_Ypos > 20.0f && m_Ypos < 20.0f + SCENE_HEIGHT) && this->m_ButtonNumber == DEFAULT)
				{
					this->m_Opened = true;
				}

				x = this->m_Xpos;
				y = this->m_Ypos;

				break;

			case SDL_BUTTON_LEFT:
				if (!ImGui::IsMouseHoveringRect(ImVec2(x, y), ImVec2(x + this->m_Width, y + this->m_Height)) && this->m_Opened)
					this->m_Opened = false;
				
				break;
			}


			break;

		}
		return this->m_Opened;
	}



	void MainScene::rotate_skybox()
	{
		
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{

			/*float xoffset = this->m_Offset.X * this->m_CameraSpeed;
			float yoffset = this->m_Offset.Y * this->m_CameraSpeed;

			yaw += xoffset;
			pitch += yoffset;

			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;*/
			
		  /* glm::vec3 direction = glm::vec3(1.0f);
			direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			direction.y = sin(glm::radians(pitch));
			direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			Cam::get_center() = direction;*/

			if (!this->m_OutOfScene)
			{
				glm::vec3 toRotateAround = glm::cross(Cam::get_center(), Cam::get_up());

				glm::mat3 rotator = glm::rotate(-m_Offset.X * this->m_CameraSpeed / 100.0f, Cam::get_up()) * glm::rotate(m_Offset.Y * this->m_CameraSpeed / 100.0f, toRotateAround);

				Cam::get_center() = rotator * Cam::get_center();
			}


			this->m_OutOfScene = false;

			if (this->m_Xpos <= SCENE_XPOSITION)
			{
				SDL_WarpMouseInWindow(sdl_window, SCENE_XPOSITION + SCENE_WIDTH - 5, this->m_Ypos);
				this->m_OutOfScene = true;
			}
			if (this->m_Xpos >= SCENE_XPOSITION + SCENE_WIDTH)
			{
				SDL_WarpMouseInWindow(sdl_window, SCENE_XPOSITION + 5, this->m_Ypos);
				this->m_OutOfScene = true;
			}

			if (this->m_Ypos <= 20)
			{
				SDL_WarpMouseInWindow(sdl_window, this->m_Xpos, SCENE_HEIGHT - 100);
				this->m_OutOfScene = true;
			}
			if (this->m_Ypos >= SCENE_HEIGHT - 100)
			{
				SDL_WarpMouseInWindow(sdl_window, this->m_Xpos, 25);
				this->m_OutOfScene = true;
			}
				
		}
	}


	unsigned int MainScene::load_cubemap(std::vector<std::string> faces)
	{
		unsigned int textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

		int width, height, nrChannels;
		for (unsigned int i = 0; i < faces.size(); i++)
		{
			unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
					0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
				);
				stbi_image_free(data);
			}
			else
			{
				std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
				stbi_image_free(data);
			}
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return textureID;
	}


	bool MainScene::is_mouse_in_scene()
	{
		if ((this->m_Xpos >= SCENE_XPOSITION && this->m_Xpos <= SCENE_XPOSITION + SCENE_WIDTH) &&
			(this->m_Ypos >= 0 && this->m_Ypos <= 0 + SCENE_HEIGHT))
		{
			return true;
		}

		return false;
	}



	void MainScene::calculate_offset()
	{
		m_Offset.X = this->m_Xpos - this->lastX;
		m_Offset.Y = this->lastY - this->m_Ypos;

		this->lastX = this->m_Xpos;
		this->lastY = this->m_Ypos;
	}

	void MainScene::clear()
	{

	}


   }

	
}