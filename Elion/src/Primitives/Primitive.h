#pragma once
#include "Core/Core.h"
#include "Core/WindowProperties.h"

#include "Renderer/Entity.h"
#include "Renderer/ModelLoader.h"
#include "Renderer/VertexBuffer.h" 

#include "Scene/SceneCamera.h"
#include "Light/Sun.h"
#include <math.h>


namespace Elion
{
	enum class PrimitiveTypes
	{
		TRIANGLE = 0,
		PLANE = 1,
		ROUND = 2,
		CUBE = 3,
		SPHERE = 4
	};


	



	



	class ELION_API Primitive
	{
	protected:

		Entity entity;

		glm::mat4 transform, mat_scale, mat_rotate, mat_view, mat_camera_view , mat_projection , mat_camera_rotate;

		uint32_t SizeIndices;

		SetOfPropeties m_Props;

		WindowProperties m_WProps;

		Model model;

	
		std::unique_ptr<Light> light;

		float m_Radius = 1.0f;
		const float m_DoublePI = 3.141592 * 2;
		

		Primitive() = default;
			
	public:		
		
		~Primitive()
		{
			free();
		}

		virtual void set_color(const Color& color) = 0;
		virtual void set_position(const Position& position) = 0;
		virtual void set_scale(const Scale& scale) = 0;
		virtual void set_rotation(const Rotation& rotation) = 0;
		virtual void set_projection(const Projection& projection) = 0;


		virtual void set_view(glm::mat4 view) { this->mat_camera_view = view; }

		virtual void update(){}
		virtual void draw(){}

		virtual void free(){}


		
	};

}

