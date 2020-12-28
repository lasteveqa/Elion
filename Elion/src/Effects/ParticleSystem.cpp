#include"Effects/ParticleSystem.h"

namespace Elion 
{
	namespace Effect
	{

		void ParticleSystem::init()
		{

            // Generate 10 new particule each millisecond,
        // but limit this to 16 ms (60 fps), or if you have 1 long frame (1sec),
        // newparticles will be huge and the next frame even longer.
            int newparticles = (int)(m_time->get_delta() * 10000.0);
            if (newparticles > (int)(0.016f * 10000.0))
                newparticles = (int)(0.016f * 10000.0);
		}


		void ParticleSystem::render()
		{
            int ParticlesCount = 0;
            for (int i = 0; i < MaxParticles; i++) {


                this->m_PraticlePrimitives[i] = std::make_shared<Quad>();

                if (m_Life > 0.0f) {

                    // Decrease life
                    m_Life -= m_time->get_delta();
                    if (m_Life > 0.0f) {


                        this->m_Speed += glm::vec3(0.0f, -9.81f, 0.0f) * m_time->get_delta() * 0.5f;
               
                        this->m_PraticlePrimitives[i]->set_position(Position(1.0f * this->m_Speed.x * m_time->get_delta(),
                                                                             1.0f * this->m_Speed.y * m_time->get_delta(),
                                                                             1.0f * this->m_Speed.z * m_time->get_delta()));
                        // Fill the GPU buffer
                      /*  g_particule_position_size_data[4 * ParticlesCount + 0] = p.pos.x;
                        g_particule_position_size_data[4 * ParticlesCount + 1] = p.pos.y;
                        g_particule_position_size_data[4 * ParticlesCount + 2] = p.pos.z;

                        g_particule_position_size_data[4 * ParticlesCount + 3] = p.size;

                        g_particule_color_data[4 * ParticlesCount + 0] = p.r;
                        g_particule_color_data[4 * ParticlesCount + 1] = p.g;
                        g_particule_color_data[4 * ParticlesCount + 2] = p.b;
                        g_particule_color_data[4 * ParticlesCount + 3] = p.a;*/

                        this->m_PraticlePrimitives[i]->set_color(Color(4 * ParticlesCount + 0,
                            4 * ParticlesCount + 1,
                            4 * ParticlesCount + 2,
                            4 * ParticlesCount + 3));

                    }
                    else {
                        // Particles that just died will be put at the end of the buffer in SortParticles();
                      //  p.cameradistance = -1.0f;
                    }

                    ParticlesCount++;

                }
            }
            sort_particles();
		}


        int ParticleSystem::find_unused_particle()
        {

            int LastUsedParticle = 0;

            for (int i = LastUsedParticle; i < MaxParticles; i++) {
                if (this->m_Life < 0) {
                    LastUsedParticle = i;
                    return i;
                }
            }

            for (int i = 0; i < LastUsedParticle; i++) {
                if (this->m_Life < 0) {
                    LastUsedParticle = i;
                    return i;
                }
            }

            return 0; // All particles are taken, override the first one
        }


        void ParticleSystem::sort_particles() {
            std::sort(&this->m_PraticlePrimitives[0], &this->m_PraticlePrimitives[MaxParticles]);
        }
	}
}