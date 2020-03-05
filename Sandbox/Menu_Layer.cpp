#include "Menu_Layer.h"


Menu_Layer::Menu_Layer()
{
	
}

void Menu_Layer::init()
{
	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f,           1.0f, 1.0f, 1.0f,
		 1.0f,  0.5f, -0.5f,          0.0f, 1.0f, 0.0f,
		 0.5f, 1.0f,   0.0f,          1.0f, 0.0f, 1.0f
	};

	

	


	const char* vertexSrc = R"(
			#version 430 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

	const char* fragmentSrc = R"(
			#version 430 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";
	

	this->program = Elion::Shader::load_shader(vertexSrc, fragmentSrc);

	this->m_VertexBuffer = Elion::create_ref<Elion::VertexBuffer>(vertices, sizeof(vertices));
	this->m_VertexArray = Elion::create_ref<Elion::VertexArray>();

	//glGenBuffers(1, &this->vbo);
	//glGenVertexArrays(1, &this->vao);

	//glBindVertexArray(this->vao);
	//glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	this->positionAttribute = glGetAttribLocation(program, "a_Position");
	glEnableVertexAttribArray(this->positionAttribute);
	glVertexAttribPointer(this->positionAttribute, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);



	this->colorAttribute = glGetAttribLocation(program, "a_Color");
	glEnableVertexAttribArray(this->colorAttribute);
	glVertexAttribPointer(this->colorAttribute, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));


	

}

void Menu_Layer::update()
{
	
}

void Menu_Layer::render()
{
	glUseProgram(this->program);
	//glBindVertexArray(this->vao);
	this->m_VertexArray->bind();
	//modelViewProjection(0.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Menu_Layer::clear()
{
	glDeleteProgram(program);
	//glDeleteBuffers(1, &this->vbo);
	//glDeleteVertexArrays(1, &this->vao);
}