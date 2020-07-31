#pragma once
#include "Core/Core.h"
#include "Primitives/Primitive.h"
#include "Core/Random.h"
#include "Renderer/Camera.h"

namespace Elion
{
	
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity, VelocityVariation;
		glm::vec4 ColorBegin, ColorEnd;
		float SizeBegin, SizeEnd, SizeVariation;
		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;
		float Rotation = 0.0f;
		bool Active = false;
	};

		class ParticleSystem
		{
		private:

			std::vector<Particle> m_ParticlePool;
			uint32_t m_PoolIndex = 999;

			GLuint m_program;

			GLint m_ViewProjection , m_Transform , m_Color;


			GLuint m_QuadVA = 0;
		public:

			ParticleSystem()
			{
				this->m_ParticlePool.resize(1000);
			}

			void init(const Camera& camera);

			void Emit(const Particle& particle);
			
		};
	
}

