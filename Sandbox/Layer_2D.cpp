#include "Layer_2D.h"





void Layer_2D::init()
{
	this->position = glm::normalize(this->position);
	this->velocity = 1.0f;

	

	// Init here
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };


	float vertices[] = {
		     -0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 0.0f , 0.0f,  0.0f, 0.0f ,
			  0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 0.0f , 0.0f , 1.0f , 0.0f,
			  0.25f,  0.25f, 0.0f, 0.0f, 0.0f, 0.0f , 0.0f ,  1.0f , 1.0f,
			 -0.25f,  0.25f, 0.0f, 0.0f, 0.0f, 0.0f , 0.0f ,  0.0f , 1.0f
	};

	unsigned int indices[6] = {
		0, 1, 2, 2, 3, 0
	};
	this->shapes.push_back(std::make_shared<Elion::Triangle>());

	this->shapes.push_back(std::make_shared<Elion::Quad>());

	
												  
	this->m_program = Elion::Camera::matrix_GLSL("glsl/vertex_shader.glsl", "glsl/fragment_shader.glsl");
	this->m_vao = std::make_shared<Elion::VertexArray>();
									 			  

	
									 
									 
	std::shared_ptr<Elion::VertexBuffer> vbo = std::shared_ptr<Elion::VertexBuffer>(Elion::VertexBuffer::create(vertices, sizeof(vertices)));
									 
	std::shared_ptr<Elion::IndexBuffer> ebo = std::shared_ptr<Elion::IndexBuffer>(Elion::IndexBuffer::create(indices, sizeof(indices)));

	vbo->set_vertex_attribute(Elion::Attribute("aPos", 3, GL_FALSE, 9, 0, this->m_program));
	vbo->set_vertex_attribute(Elion::Attribute("aColor", 4, GL_FALSE, 9, 3, this->m_program));
	vbo->set_vertex_attribute(Elion::Attribute("TexCoord", 2, GL_FALSE, 9, 7, this->m_program));
	this->m_vao->add_vertex_buffer(vbo);
	this->m_vao->set_index_buffer(ebo);

	
		this->shapes[0]->set_color(Elion::Color(1.0f, 1.0f, 0.0f , 1.0f));
		this->shapes[1]->set_color(Elion::Color(0.0f, 0.0f, 1.0f , 0.5f));
	
		tx.load_from_file("img/characters.png");

		

		this->shapes[0]->set_size(Elion::Size(0.5f, 0.5f, 0.0f));
		this->shapes[1]->set_size(Elion::Size(1.5f * 0.0720, 1.5f * 0.128, 0.0f));

	
		
	
}

void Layer_2D::update()
{
	
	

	for (std::size_t i = 0; i < this->shapes.size(); i++)
	{
		this->shapes[i]->update();
	}

}

void Layer_2D::render()
{

	

	static auto start = std::chrono::high_resolution_clock::now();

	auto t_now = std::chrono::high_resolution_clock::now();
	float times = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - start).count();
	times *= 2;
	
	GLint myUniformLocation;



	glUseProgram(m_program);




	this->m_vao->bind();
	this->location_transform = Elion::Camera::set_uniform_location(this->m_program, "transform");

	this->tx.bind();
	glm::mat4 scale = glm::mat4(1.0f);
	glm::mat4 rotate = glm::mat4(1.0f);

	
	
	scale = Elion::Camera::scale(scale, 0.0720 * 1.5, 0.1280f * 1.5, 0.0f);
	
	glm::mat4 transform = glm::mat4(1.0f);

	float fps = m_time.get_ticks() / 1000.0f;

	rotate = Elion::Camera::rotate(rotate, 180.0f, 1.0f, 0.0f, 0.0f);
		const uint8_t* state = SDL_GetKeyboardState(NULL);
		myUniformLocation = glGetUniformLocation(this->m_program, "AnimationNumber");
		if (state[SDL_SCANCODE_A])
		{
			this->mv.set_Xpos(this->mv.x_pos() - this->velocity * fps);
			glUniform1i(myUniformLocation, 1);
		}
		if (state[SDL_SCANCODE_S])
		{
			this->mv.set_Ypos(this->mv.y_pos() - this->velocity * fps);
			glUniform1i(myUniformLocation, 0);
		}
		if (state[SDL_SCANCODE_W])
		{
			this->mv.set_Ypos(this->mv.y_pos() + this->velocity * fps);
			glUniform1i(myUniformLocation, 3);
		}
		if (state[SDL_SCANCODE_D])
		{
			this->mv.set_Xpos(this->mv.x_pos() + this->velocity * fps);
			glUniform1i(myUniformLocation, 2);
		}
		
	
	transform = Elion::Camera::translate(transform, this->mv.x_pos(), this->mv.y_pos(), 0.2f) *scale * rotate;
	Elion::Camera::upload_matrices(location_transform, transform);
	this->m_vao->draw();

	srand(time(NULL));

	glUseProgram(0);
	this->m_vao->unbind();
	
	
	this->shapes[0]->set_position(Elion::Position(0.011f * velocity, 0.011f, 0.3f));
	this->shapes[1]->set_position(Elion::Position(0.011f, 0.011f * velocity, 0.1f));

	for (std::size_t i = 0; i < this->shapes.size(); i++)
	{
		this->shapes[i]->draw();
	}

	if (state[SDL_SCANCODE_H])
	{
		/*float x = Elion::Input::get_mouse_Xposition();
		float y = Elion::Input::get_mouse_Yposition();
		auto width = GLCore::Application::Get().GetWindow().GetWidth();
		auto height = GLCore::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);*/
	}



	

	m_time.start();
	
}


void Layer_2D::clear()
{

}

float Layer_2D::RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}