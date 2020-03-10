#include "OpenGL_API.h"

namespace Elion
{
	
	void OpenGL_API::init()
	{
		this->va.Position = glGetAttribLocation(OpenGL_Program::get_program(), "a_Position");
		glEnableVertexAttribArray(this->va.Position);
		glVertexAttribPointer(this->va.Position, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);



		this->va.Color = glGetAttribLocation(OpenGL_Program::get_program(), "a_Color");
		glEnableVertexAttribArray(this->va.Color);
		glVertexAttribPointer(this->va.Color, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	}
}