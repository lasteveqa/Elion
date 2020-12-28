#pragma once
#include <algorithm>
#include "Core/Core.h"
#include "Core/Time.h"
#include "Primitives/Primitive.h"
#include "Primitives/Quad.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/compatibility.hpp"
namespace Elion
{
	namespace Effect
	{
		//struct Particle
		//{
		//
		//	glm::vec3 pos, speed;
		//	unsigned char r, g, b, a; // Color
		//	float size, angle, weight;
		//	const int MaxParticles = 100000;
		//	
		//	float life; // Remaining life of the particle. if < 0 : dead and unused.

  //          float cameradistance;

  //          bool operator<(const Particle& that) const {
  //              // Sort in reverse order : far particles drawn first.
  //              return this->cameradistance > that.cameradistance;
  //          }

	 //   };

        class ParticleSystem
        {
        private:
            std::shared_ptr<Time> m_time;

            std::vector<std::shared_ptr<Primitive>> m_PraticlePrimitives;

            float m_Life = 0;

            glm::vec3 m_Speed;

            const int MaxParticles = 100000;

        public:
            void init();
            void render();

            int find_unused_particle();

            void sort_particles();
        };

      

       

        



	}
}