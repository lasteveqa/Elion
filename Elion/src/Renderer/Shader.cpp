#include "Shader.h"


namespace Elion
{
	//Shader::Shader(const char* s_vertexShader, const char* s_fragmentShader)
	//{
	//	

	//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);




	//	//Compile Vertex Shader
	//	char const* VertexSourcePointer = s_vertexShader;
	//	glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
	//	glCompileShader(vertexShader);


	//	//Compile Fragment Shader
	//	char const* FragmentSourcePointer = s_fragmentShader;
	//	glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
	//	glCompileShader(fragmentShader);

	//	//Check for shader's errors
	//	shaderCompilerCheck(vertexShader);
	//	shaderCompilerCheck(fragmentShader);

	//	//LINK PROGRAM
	//	GLuint ProgramID = glCreateProgram();
	//	glAttachShader(ProgramID, vertexShader);
	//	glAttachShader(ProgramID, fragmentShader);
	//	glLinkProgram(ProgramID);




	//	//delete
	//	glDetachShader(ProgramID, vertexShader);
	//	glDetachShader(ProgramID, fragmentShader);

	//	glDeleteShader(vertexShader);
	//	glDeleteShader(fragmentShader);

	//	shaderLinkCheck(ProgramID);


	//	this->Program = ProgramID;

	//	glDeleteProgram(ProgramID);
	//}	

	uint Shader::load_shader(const char* vertex_file_path, const char* fragment_file_path)
	{
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string VertexShaderCode;
		std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
		if (VertexShaderStream.is_open()) {
			std::stringstream ss;
			ss << VertexShaderStream.rdbuf();
			VertexShaderCode = ss.str();
			VertexShaderStream.close();
		}
		else
		{
			std::cout << "Impossible to open! Make sure you put path correctly" << std::endl;
		}




		std::string FragmentShaderCode;
		std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
		if (FragmentShaderStream.is_open()) {
			std::stringstream sstr;
			sstr << FragmentShaderStream.rdbuf();
			FragmentShaderCode = sstr.str();
			FragmentShaderStream.close();
		}




		GLint Result = GL_FALSE;
		int InfoLogLength;


		// Compile Vertex Shader
		std::cout << "Compile vertex shader : " << vertex_file_path << std::endl;
		char const* VertexSourcePointer = VertexShaderCode.c_str();
		glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
		glCompileShader(vertexShader);

		// Check Vertex Shader
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(vertexShader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			std::cout << &VertexShaderErrorMessage[0] << std::endl;
		}


		// Compile Fragment Shader
		std::cout << "Compile fragment shader : " << fragment_file_path << std::endl;
		char const* FragmentSourcePointer = FragmentShaderCode.c_str();
		glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
		glCompileShader(fragmentShader);

		// Check Fragment Shader
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(fragmentShader, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			std::cout << &FragmentShaderErrorMessage[0] << std::endl;
		}


		// Link the program
		std::cout << "Linking program..." << std::endl;
		GLuint ProgramID = glCreateProgram();

		//this->mvp = MVP(ProgramID);

		glAttachShader(ProgramID, vertexShader);
		glAttachShader(ProgramID, fragmentShader);
		glLinkProgram(ProgramID);

		// Check the program
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);


		glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);


		if (InfoLogLength > 0) {
			std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			std::cout << &ProgramErrorMessage[0] << std::endl;
		}

		glDetachShader(ProgramID, vertexShader);
		glDetachShader(ProgramID, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	

		return ProgramID;

		glDeleteProgram(ProgramID);
		
	}




	void Shader::shaderCompilerCheck(uint ID)
	{
		GLint comp;
		glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);

		if (comp == GL_FALSE) {
			ELION_ERROR("Shader Compilation FAILED");
			GLchar messages[256];
			glGetShaderInfoLog(ID, sizeof(messages), 0, &messages[0]);
			ELION_ERROR(messages);
		}
	}



	void Shader::shaderLinkCheck(uint ID) {
		GLint linkStatus, validateStatus;
		glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);


		if (linkStatus == GL_FALSE) {
			ELION_ERROR("Shader Linking FAILED");
			GLchar messages[256];
			glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
			ELION_ERROR(messages);
		}

		glValidateProgram(ID);
		glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);

		if (linkStatus == GL_FALSE) {
			ELION_ERROR("Shader Validation FAILED");
			GLchar messages[256];
			glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
			ELION_ERROR(messages);
		}
	}

	void Shader::set_mvp(MVP* mvp)
	{
		this->p_mvp = mvp;
	}

	bool Shader::is_mvp_set()
	{
		if (this->p_mvp)
		{
			return GL_TRUE;
		}
		else
		{
			ELION_ERROR("First you need to set MVP class for working with matrices!");
			ELION_TRACE("You can do it in Shader constructor or just call function set_mvp()");

			return GL_FALSE;
		}



	}

	void Shader::begin_mvp_loop()
	{
		//static MVP* mvp = new MVP();
	}


	void Shader::matrix_name(std::string matrix_name)
	{
		this->p_mvp->matrix_name(matrix_name);
	}

	void Shader::matrix_rotate(const MatrixProperties& mp , const VCoord& c)
	{
		this->p_mvp->set_rotate(mp , c);
	}

	void Shader::matrix_translate(const VCoord& c)
	{
		this->p_mvp->set_translate(c);
	}

	void Shader::matrix_perspective(const MatrixProperties& mp)
	{
		this->p_mvp->set_perspective(mp);
	}

	void Shader::upload_uniform_mat4(GLuint program)
	{

		glm::mat4 model = glm::rotate(model, glm::radians(15.0f), glm::vec3(1.0f, 1.0f, 0.0f));


		glm::mat4 view = glm::translate(view, glm::vec3(0.0f, -0.4f, -4.0f));


		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		GLint model_location = glGetUniformLocation(program, "model");
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

		GLint view_location = glGetUniformLocation(program, "view");
		glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

		GLint projection_location = glGetUniformLocation(program, "projection");
		glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));
	//	this->p_mvp->upload_uniform_mat4(program);
	}




	void Shader::mvp_func(GLuint program)
	{
		glm::mat4 model = glm::rotate(model, glm::radians(15.0f), glm::vec3(1.0f, 1.0f, 0.0f));


		glm::mat4 view = glm::translate(view, glm::vec3(0.0f, -0.4f, -4.0f));


		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


		GLint m_location = glGetUniformLocation(program, "model");
		glUniformMatrix4fv(m_location, 1, GL_FALSE, glm::value_ptr(model));

		GLint v_location = glGetUniformLocation(program, "view");
		glUniformMatrix4fv(v_location, 1, GL_FALSE, glm::value_ptr(view));

		GLint p_location = glGetUniformLocation(program, "projection");
		glUniformMatrix4fv(p_location, 1, GL_FALSE, glm::value_ptr(projection));
	}


	
	//FINISH MVP MATRIX RIGHT HERE
}