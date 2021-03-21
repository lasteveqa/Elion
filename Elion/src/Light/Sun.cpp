#include "Light/Sun.h"

namespace Elion
{

	

	void Sun::init()
	{

	}

	void Sun::update()
	{
		/*u_Entity = std::make_unique<Entity>();
		u_Entity->Program = u_Entity->shader->load_GLSL("Shaders/sunlight.vs", "Shaders/sunlight.fs");

		glCreateBuffers(1, &u_Entity->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, u_Entity->VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

		glCreateVertexArrays(1, &u_Entity->VAO);
		glBindVertexArray(u_Entity->VAO);


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
		glVertexAttribPointer(position_attribute, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));*/

	}

	void Sun::draw()
	{

	}
}