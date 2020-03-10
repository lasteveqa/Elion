#include "Shader.h"


namespace Elion
{
	Shader::Shader(const char* s_vertexShader, const char* s_fragmentShader)
	{
		glewInit();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);




		//Compile Vertex Shader
		char const* VertexSourcePointer = s_vertexShader;
		glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
		glCompileShader(vertexShader);


		//Compile Fragment Shader
		char const* FragmentSourcePointer = s_fragmentShader;
		glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
		glCompileShader(fragmentShader);



		//LINK PROGRAM
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, vertexShader);
		glAttachShader(ProgramID, fragmentShader);
		glLinkProgram(ProgramID);




		//delete
		glDetachShader(ProgramID, vertexShader);
		glDetachShader(ProgramID, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


		OpenGL_Program::set_program(ProgramID);
	}	


	GLuint Shader::load_shader(const char* s_vertexShader, const char* s_fragmentShader)
	{
		glewInit();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		
		

		//Compile Vertex Shader
		char const* VertexSourcePointer = s_vertexShader;
		glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
		glCompileShader(vertexShader);


		//Compile Fragment Shader
		char const* FragmentSourcePointer = s_fragmentShader;
		glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
		glCompileShader(fragmentShader);



		//LINK PROGRAM
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, vertexShader);
		glAttachShader(ProgramID, fragmentShader);
		glLinkProgram(ProgramID);




		//delete
		glDetachShader(ProgramID, vertexShader);
		glDetachShader(ProgramID, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


		return ProgramID;
	}
}