#pragma once

#include "Core/Core.h"
#include "Renderer/Entity.h"
#include "Renderer/Model.h"
#include "Scene/SceneCamera.h"

namespace Elion
{

	class Light
	{

	protected:

		glm::vec3 LightPosition;
		//Entity entity;
		Model model;
		GLint program;
		Shader shader;


	public:

		virtual void init(){}
		virtual void update(const std::string& filename){}
		virtual void draw(){}
		virtual void free(){}

		//Light Position
		virtual void set_light_position(const glm::vec3& vec) { LightPosition = vec; }
		virtual glm::vec3 get_light_position() const { return this->LightPosition; }

		inline Model& get_model() { return model; }

		
		//~Light() { free(); }

    };
}