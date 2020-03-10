#include "Menu_Layer.h"


Menu_Layer::Menu_Layer()
{
	
}

void Menu_Layer::init()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,           1.0f, 1.0f, 1.0f,
		 1.0f,  0.5f, -0.5f,          0.0f, 1.0f, 0.0f,
		 0.5f, 1.0f,   0.0f,          1.0f, 0.0f, 1.0f
	};

	float vertices2[] = {
		-1.0f, -0.5f, 1.0f,           1.0f, 1.0f, 1.0f,
		 0.0f,  0.5f, -0.5f,          0.0f, 1.0f, 0.0f,
		 0.0f, 1.0f,   0.0f,          1.0f, 0.0f, 1.0f
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
	
	Elion::OpenGL_API opengl_api(Elion::Shader::load_shader(vertexSrc, fragmentSrc));

	this->m_VertexBuffer = Elion::create_ref<Elion::VertexBuffer>(vertices, sizeof(vertices));
	this->m_VertexArray = Elion::create_ref<Elion::VertexArray>();

	this->m_VertexBuffer2 = Elion::create_ref<Elion::VertexBuffer>(vertices2, sizeof(vertices2));
	this->m_VertexArray2 = Elion::create_ref<Elion::VertexArray>();

	opengl_api.init();

}

void Menu_Layer::update()
{
	
}

void Menu_Layer::render()
{
	glUseProgram(Elion::OpenGL_Program::get_program());
	this->m_VertexArray2->unbind();
	this->m_VertexArray->bind();
	//modelViewProjection(0.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	this->m_VertexArray->unbind();
	glUseProgram(0);
	glUseProgram(Elion::OpenGL_Program::get_program());
	this->m_VertexArray2->bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glUseProgram(0);
}

void Menu_Layer::clear()
{
	//glDeleteBuffers(1, &this->vbo);
	//glDeleteVertexArrays(1, &this->vao);
}