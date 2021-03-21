#include "OBJFileLoader.h"


namespace Elion {

	OBJFileLoader::OBJFileLoader(const char* filename)
	{
		

	}

	OBJFileLoader::OBJFileLoader()
	{
		
	}



	bool OBJFileLoader::loadOBJ(const char* filename)
	{
		std::fstream file(filename, std::ios::in);

		std::string  line;

		std::string position_vertices_output;
		std::string texture_vertices_output;
		std::string normal_vertices_output;
		std::string face_output;

		if (!file.is_open()) return GL_FALSE;

		while (!file.eof())
		{
			std::getline(file, line);

			

			if (line[0] == 'v' && line[1] == ' ')
			{
				position_vertices_output += line + "\n";
			}

			else if (line[0] == 'v' && line[1] == 't')
			{
				texture_vertices_output += line + "\n";
			}

			else if (line[0] == 'v' && line[1] == 'n')
			{
				normal_vertices_output += line + "\n";
			}

			else if (line[0] == 'f')
			{
				face_output += line + "\n";
			}

			//

		}

		this->p_vertices = this->v_parser3(position_vertices_output);
		this->t_vertices = this->v_parser2(texture_vertices_output);
		this->n_vertices = this->v_parser3(normal_vertices_output);
		this->f_parser(face_output);
		


		
		return GL_TRUE;
	}

	std::vector<glm::fvec3> OBJFileLoader::v_parser3(std::string file_output)
	{
		std::stringstream ss;
		
		ss << file_output;

		std::string word;

		std::vector<glm::vec3> vec;

		float foundX;
		float foundY;
		float foundZ;

		while (!ss.eof())
		{
			ss >> word;

			if (std::stringstream(word) >> foundX >> foundY >> foundZ)
			{
				
				vec.push_back(glm::vec3(foundX , foundY, foundZ));

			}
			
			word = "";

		}

		return vec;
		
	}

	std::vector<glm::fvec2> OBJFileLoader::v_parser2(std::string file_output)
	{
		std::stringstream ss;

		ss << file_output;

		std::string word;

		std::vector<glm::vec2> vec;

		float foundX;
		float foundY;
		float foundZ;

		while (!ss.eof())
		{
			ss >> word;

			if (std::stringstream(word) >> foundX >> foundY)
			{

				vec.push_back(glm::vec2(foundX, foundY));

			}

			word = "";

		}

		return vec;

	}

	void OBJFileLoader::f_parser(std::string file_output)
	{
		std::stringstream ss;

		ss << file_output;

		std::string word;


		//Three types of indices
		GLint v_index = 0;
		GLint vt_index = 0;
		GLint vn_index = 0;

		

		while (!ss.eof())
		{
			ss >> word;
			
			word.erase(std::remove(word.begin(), word.end(), 'f'), word.end());

			std::replace(word.begin(), word.end(), '/' , ' ');
			
			if (std::stringstream(word) >> v_index >> vt_index >> vn_index)
			{
				
				vertex_position_indicies.push_back(v_index);
				vertex_texcoord_indicies.push_back(vt_index);
				vertex_normal_indicies.push_back(vn_index);
		
				
			}
			
			word = "";

			

		}
	}


	void OBJFileLoader::update()
	{
		if (!VAO)
		{

			Program = shader->load_GLSL("Shaders/obj.vs", "Shaders/obj.fs");

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);

			
	
			vertices.resize(1984 , FileVertex());

			std::cout << vertices.size();

			for (size_t i = 0; i < vertices.size(); ++i)
			{
				vertices[i].VPosition = p_vertices[vertex_position_indicies[i] - 1];
				vertices[i].TexCoords = t_vertices[vertex_texcoord_indicies[i] - 1];
				vertices[i].Normal = n_vertices[vertex_normal_indicies[i] - 1];
			}
			
		     glBufferData(GL_ARRAY_BUFFER, sizeof(FileVertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, idx.size() * sizeof(unsigned int), idx.data(), GL_STATIC_DRAW);
		
			GLint position_attribute = glGetAttribLocation(Program, "a_Position");
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(FileVertex), (GLvoid*)offsetof(FileVertex, VPosition));
			glEnableVertexAttribArray(position_attribute);
			//Texcoord
			GLint texture_attribute = glGetAttribLocation(Program, "a_Texture");
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(FileVertex), (GLvoid*)offsetof(FileVertex, TexCoords));
			glEnableVertexAttribArray(texture_attribute);
			//Normal
			GLint normal_attribute = glGetAttribLocation(Program, "a_Normal");
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(FileVertex), (GLvoid*)offsetof(FileVertex, Normal));
			glEnableVertexAttribArray(normal_attribute);

			
			if (texture.load_from_file("img/lightning.png"))
				std::cout << "LMAL";

			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}


	void OBJFileLoader::draw()
	{
		glUseProgram(Program);
		glBindVertexArray(VAO);
		glActiveTexture(GL_TEXTURE0);
		texture.bind();

		GLint texture_sampler = glGetUniformLocation(Program, "texture_diffuse");
		glUniform1i(texture_sampler, 0);

		//glBindTexture(GL_TEXTURE_2D, Texture);

		GLint ColorUniform = glGetUniformLocation(Program, "UniformColor");

		glUniform4f(ColorUniform, 1.0f, 1.0f, 1.0f, 1.0f);

		glm::mat4 mat_projection = glm::mat4(1.0f);
		mat_projection = glm::perspective(glm::radians(45.0f), (GLfloat)(SCENE_WIDTH / SCENE_HEIGHT), 0.1f, 1000.0f);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));

		Cam::render();

		GLint Translate = glGetUniformLocation(Program, "transform");
		GLint ProjectionLocation = glGetUniformLocation(Program, "projection");

		glUniformMatrix4fv(Translate, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(mat_projection));

		//Setting Camera
		Cam::set_camera("cameraView", Program);

		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		//glDrawElements(GL_LINE_LOOP, idx.size(), GL_UNSIGNED_INT, (void*)0);
		texture.unbind();

		glBindVertexArray(0);
		glUseProgram(0);
	}
}