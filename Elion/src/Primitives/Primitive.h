#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Renderer/Camera.h"
#include "Renderer/VertexBuffer.h" 
#include "Core/WindowProperties.h"
#include "Scene/SceneCamera.h"
#include <math.h>


namespace Elion
{
	enum class PrimitiveTypes
	{
		TRIANGLE = 0,
		QUAD = 1,
		ROUND = 2,
		CUBE = 3
	};


	

	struct Color
	{
		float R;
		float G;
		float B;
		float A;
		Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f) :
			R(r),
			G(g),
			B(b),
			A(a)
		{}
	};

	struct Position
	{
		float X, Y, Z;
		Position(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
			X(x),
			Y(y),
			Z(z)
		{}
	};

	struct Scale
	{
		float X, Y, Z;
		Scale(float x = 1.0f, float y = 1.0f, float z = 1.0f) :
			X(x),
			Y(y),
			Z(z)
		{}
	};

	struct Rotation
	{
		float Radians;
		float X, Y, Z;
		Rotation(float radians = 0.0f , float x = 1.0f, float y = 1.0f, float z = 1.0f) :
			Radians(radians),
			X(x),
			Y(y),
			Z(z)
		{}
	};

	struct Projection
	{

		float Radians;
		float Width, Height, Near , Far;
		Projection(float radians = 45.0f, float width = SCENE_WIDTH, float height = SCENE_HEIGHT, float _near = 1.0f , float _far = 100.0f) :
			Radians(radians),
			Width(width),
			Height(height),
			Near(_near),
			Far(_far)
		{
			
		}
	};


	//Custom Primitive Object
	struct PObject
	{
		GLuint VBO, VAO, EBO, Texture, Program;
		std::shared_ptr<Shader> shader;
	};

	



	class ELION_API Primitive
	{





	protected:


		GLuint VBO, VAO, EBO, Texture;

		std::shared_ptr<Shader> shader;
		GLuint program;

		GLint location , RotateLocation , ScaleLocation , Translate , ViewLocation , ProjectionLocation;

		glm::mat4 transform, mat_scale, mat_rotate, mat_view, mat_camera_view , mat_projection , mat_camera_rotate;

		uint32_t SizeIndices;

		Color color;
		Position position;
		Scale scale;
		Rotation rotation;
		Projection projection;

		WindowProperties m_WProps;
		

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


		virtual Color& get_color() { return this->color; }
		virtual Position& get_position() { return this->position; }
		virtual Scale& get_scale() { return this->scale; }
		virtual Rotation& get_rotation() { return this->rotation; }
		virtual Projection& get_projection() { return this->projection; }


		virtual glm::mat4& get_transform() { return this->transform; }
		virtual glm::mat4& get_rotate_mat4() { return this->mat_rotate; }
		virtual glm::mat4& get_scale_mat4() { return this->mat_scale; }
		virtual glm::mat4& get_view_mat4() { return this->mat_camera_view; }
		virtual glm::mat4& get_projection_mat4() { return this->mat_projection; }
	};

}

