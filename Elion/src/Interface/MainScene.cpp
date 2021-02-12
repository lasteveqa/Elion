#include "Interface/MainScene.h"

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

			this->m_Skybox = std::make_unique<PObject>();
			this->m_Skybox->Program = this->m_Skybox->shader->load_GLSL("Shaders/skybox.vs", "Shaders/skybox.fs");
			
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

			
			this->m_CameraFront = glm::vec4(1.0f);
		}

		void MainScene::render()
		{

			glViewport(SCENE_XPOSITION, SCENE_YPOSITION, SCENE_WIDTH, SCENE_HEIGHT);

			SDL_GetMouseState(&m_Xpos, &m_Ypos);
	
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

			rotate_skybox();
			glm::mat4 mat_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f),
				m_CameraFront,
				glm::vec3(0.0f, 1.0f, 0.0f));


			glm::mat4 mat_projection = glm::perspective(this->m_SkyboxProps.projection.Radians, (GLfloat)(m_Wprops.size().Width / m_Wprops.size().Height), this->m_SkyboxProps.projection.Near, this->m_SkyboxProps.projection.Far);



			GLint view_location = glGetUniformLocation(this->m_Skybox->Program, "view");
			GLint projecton_location = glGetUniformLocation(this->m_Skybox->Program, "projection");

			glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(mat_view));
			glUniformMatrix4fv(projecton_location, 1, GL_FALSE, glm::value_ptr(mat_projection));

		
			glDrawArrays(GL_TRIANGLES, 0, 36);

			glDepthMask(GL_TRUE);

			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glUseProgram(0);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS);
		

			
			
			///////////////// Skybox

			if (!m_PrimitiveTypes.empty() && !this->m_SetOfProperties.empty())
			{
				
				rotate_world();
				translate_world();


				//Render Options
				options();
				//
			}


			
			m_Scene.update();
			m_Scene.draw();

		}

		void MainScene::rotate_world()
		{
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
			{
				for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
				{
				this->m_SetOfProperties[i].rotation.Z = 0.0f;

				
				  if (xoffset < 0)
				  {
					  this->m_SetOfProperties[i].rotation.X -= 0.01f;
					if (this->m_SetOfProperties[i].rotation.Radians > 0)
					{
						this->m_SetOfProperties[i].rotation.Radians = 0;
					}
					this->m_SetOfProperties[i].rotation.Y = 1.0f;
					this->m_SetOfProperties[i].rotation.Radians -= this->m_CameraSpeed;
				  }

				  if (xoffset > 0)
				  {
					  this->m_SetOfProperties[i].rotation.X -= 0.01f;
					  if (this->m_SetOfProperties[i].rotation.Radians < 0)
					  {
						  this->m_SetOfProperties[i].rotation.Radians = 0;
					  }
					  this->m_SetOfProperties[i].rotation.Y = 1.0f;
					  this->m_SetOfProperties[i].rotation.Radians += this->m_CameraSpeed;
				  }

				  if (yoffset < 0)
				  {
					  this->m_SetOfProperties[i].rotation.Y -= 0.01f;
					  if (this->m_SetOfProperties[i].rotation.Radians > 0)
					  {
						  this->m_SetOfProperties[i].rotation.Radians = 0;
					  }
					  this->m_SetOfProperties[i].rotation.X = 1.0f;
					  this->m_SetOfProperties[i].rotation.Radians -= this->m_CameraSpeed;
				  }

				  if (xoffset > 0)
				  {
					  this->m_SetOfProperties[i].rotation.Y -= 0.01f;
					  if (this->m_SetOfProperties[i].rotation.Radians < 0)
					  {
						  this->m_SetOfProperties[i].rotation.Radians = 0;
					  }
					  this->m_SetOfProperties[i].rotation.X = 1.0f;
					  this->m_SetOfProperties[i].rotation.Radians += this->m_CameraSpeed;
				  }
				}
				this->m_ButtonNumber = ROTATION;
			}
				
		}

	void MainScene::translate_world()
	{
		
		const Uint8* state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_W] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				this->m_SetOfProperties[i].position.Z += this->m_CameraSpeed;
			}
			this->m_ButtonNumber = TRANSLATION;
		}
	    if (state[SDL_SCANCODE_S] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	    {
		    for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
		    {
				this->m_SetOfProperties[i].position.Z -= this->m_CameraSpeed;
		    }
		this->m_ButtonNumber = TRANSLATION;
	    }

		if (state[SDL_SCANCODE_A] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				this->m_SetOfProperties[i].position.X += this->m_CameraSpeed;
			}
			this->m_ButtonNumber = TRANSLATION;
		}
		if (state[SDL_SCANCODE_D] && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			for (std::size_t i = 0; i < this->m_SetOfProperties.size(); ++i)
			{
				this->m_SetOfProperties[i].position.X -= this->m_CameraSpeed;
			}
			this->m_ButtonNumber = TRANSLATION;
		}

		
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

		xoffset = this->m_Xpos - this->lastX;
		yoffset = this->lastY - this->m_Ypos;

		this->lastX = this->m_Xpos;
		this->lastY = this->m_Ypos;

		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{

			xoffset *= this->m_CameraSpeed;
			yoffset *= this->m_CameraSpeed;

			yaw += xoffset;
			pitch += yoffset;

			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;

			glm::vec3 direction = glm::vec3(1.0f);
			direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			direction.y = sin(glm::radians(pitch));
			direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			this->m_CameraFront = glm::normalize(direction);


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

	void MainScene::clear()
	{

	}


   }

	
}