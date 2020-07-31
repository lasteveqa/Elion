#include "ParticleSystem.h"


namespace Elion
{
	void ParticleSystem::init(const Camera& camera)
	{
		if (!m_QuadVA)
		{
			float vertices[] = {
				 -0.5f, -0.5f, 0.0f,
				  0.5f, -0.5f, 0.0f,
				  0.5f,  0.5f, 0.0f,
				 -0.5f,  0.5f, 0.0f
			};

			glCreateVertexArrays(1, &m_QuadVA);
			glBindVertexArray(m_QuadVA);

			GLuint quadVB, quadIB;
			glCreateBuffers(1, &quadVB);
			glBindBuffer(GL_ARRAY_BUFFER, quadVB);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glEnableVertexArrayAttrib(quadVB, 0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

			uint32_t indices[] = {
				0, 1, 2, 2, 3, 0
			};

			glCreateBuffers(1, &quadIB);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadIB);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			this->m_program = MatrixGLSL("glsl/vertex_shader.glsl", "glsl/fragment_shader.glsl");
			this->m_ViewProjection = glGetUniformLocation(this->m_program, "u_ViewProj");
			this->m_Transform = glGetUniformLocation(this->m_program, "u_Transform");
			this->m_Color = glGetUniformLocation(this->m_program, "u_Color");
		}

		glUseProgram(this->m_program);
		glUniformMatrix4fv(this->m_ViewProjection, 1, GL_FALSE, glm::value_ptr(camera.get_view_projection_matrix()));

		for (auto& particle : m_ParticlePool)
		{
			if (!particle.Active)
				continue;

			// Fade away particles
			float life = particle.LifeRemaining / particle.LifeTime;
			glm::vec4 color = glm::lerp(particle.ColorEnd, particle.ColorBegin, life);

			float size = glm::lerp(particle.SizeEnd, particle.SizeBegin, life);

			// Render
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), { particle.Position.x, particle.Position.y, 0.0f })
				* glm::rotate(glm::mat4(1.0f), particle.Rotation, { 0.0f, 0.0f, 1.0f })
				* glm::scale(glm::mat4(1.0f), { size, size, 1.0f });
			glUniformMatrix4fv(this->m_Transform, 1, GL_FALSE, glm::value_ptr(transform));
			glUniform4fv(m_Color, 1, glm::value_ptr(color));
			glBindVertexArray(m_QuadVA);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		}
	}
	void ParticleSystem::Emit(const Particle& part)
	{
		Particle& particle = m_ParticlePool[m_PoolIndex];
		particle.Active = true;
		particle.Position = part.Position;
		particle.Rotation = Random::Float() * 2.0f * glm::pi<float>();

		// Velocity
		particle.Velocity = part.Velocity;
		particle.Velocity.x += part.VelocityVariation.x * (Random::Float() - 0.5f);
		particle.Velocity.y += part.VelocityVariation.y * (Random::Float() - 0.5f);

		// Color
		particle.ColorBegin = part.ColorBegin;
		particle.ColorEnd = part.ColorEnd;

		particle.LifeTime = part.LifeTime;
		particle.LifeRemaining = part.LifeTime;
		particle.SizeBegin = part.SizeBegin + part.SizeVariation * (Random::Float() - 0.5f);
		particle.SizeEnd = part.SizeEnd;

		m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
	}
}