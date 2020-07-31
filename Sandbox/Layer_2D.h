#pragma once
#ifndef __LAYER_2D__
#define __LAYER_2D__
#include <Elion.h>
#include <stdlib.h>
class Layer_2D : public Elion::Layer
{
private:
	Elion::Time m_time;

	std::shared_ptr<Elion::VertexArray> m_vao;
	std::shared_ptr<Elion::IndexBuffer> m_ebo;
	std::shared_ptr<Elion::VertexBuffer> m_vbo;

	std::shared_ptr<Elion::Shader> m_shader;

	float velocity;
	glm::vec3 position;

	GLuint m_program;

	GLint location_transform;
	Elion::Movement mv;

	Elion::Texture tx;

	std::vector<std::shared_ptr<Elion::Primitive>> shapes;


	Elion::ParticleSystem m_ParticleSystem;
	Elion::Particle m_Particle;
	
public:
	Layer_2D(){}


	float RandomNumber(float Min, float Max);

	void init() override;
	void update() override;
	void render() override;
	void clear() override;
};

#endif;

