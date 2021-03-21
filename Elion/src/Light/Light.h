#pragma once

#include "Core/Core.h"
#include "Renderer/Entity.h"

namespace Elion
{

	class Light
	{

	protected:

		glm::vec3 LightPosition;
		std::unique_ptr<Entity> u_Entity;

	public:

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

		//Light Position
		virtual void set_light_position(const glm::vec3& vec) { LightPosition = vec; }
		virtual glm::vec3 get_light_position() const { return this->LightPosition; }



		virtual ~Light(){}

    };
}