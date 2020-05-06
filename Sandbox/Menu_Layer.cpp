#include "Menu_Layer.h"


Menu_Layer::Menu_Layer()
{
	
}

void Menu_Layer::init()
{

	

	std::cout << glGetString(GL_VERSION) << std::endl;

	Elion::OBJLoader obj;
	obj.loadOBJ("untitled.obj");

	std::vector<unsigned int> faces = obj.get_face();

	std::vector<unsigned int> indices;

	for (std::size_t i = 0; i < faces.size(); i += 3)
	{
		indices.push_back(faces[i]);
	}

	this->shader = std::make_shared<Elion::Shader>(new Elion::MVP());

	this->program = this->shader->load_shader("glsl/vertex_shader.glsl", "glsl/fragment_shader.glsl");

	this->_vao = std::make_shared<Elion::VertexArray>();
	this->_vbo = std::make_shared<Elion::VertexBuffer>(&obj.get_p_vertices()[0], sizeof(obj.get_p_vertices()));

	this->_ebo = std::make_shared<Elion::VertexIndices>(indices);

	Elion::Attributes attrbs = Elion::Attributes({ { "aPos" , 3 , GL_FALSE , 3 , 0 , this->program} });

	//this->shader->set_mvp(new Elion::MVP());

}

void Menu_Layer::update()
{
}

void Menu_Layer::render()
{
	glUseProgram(this->program);
	this->_vao->bind();


	if (this->shader->is_mvp_set())
	{
		
		this->shader->matrix_name("model");
		this->shader->matrix_name("view");
		this->shader->matrix_name("projection");
		
		this->shader->matrix_rotate(Elion::MatrixProperties(15.0f) , Elion::VCoord(1.0f, 1.0f, 0.0f));
		this->shader->matrix_translate(Elion::VCoord(0.0f, -0.4f, -4.0f));
		this->shader->matrix_perspective(Elion::MatrixProperties(45.0f, 800.0f, 600.0f, 0.1f, 100.0f));

		this->shader->upload_uniform_mat4(this->program);
		
	}

	//shader->mvp_func(this->program);
	this->_ebo->draw();

	//this->shader->s_mvp()->clear();

	glUseProgram(0);
	this->_vao->unbind();
}

void Menu_Layer::clear()
{
}