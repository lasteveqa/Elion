#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Renderer/Camera.h"
#include "Renderer/VertexBuffer.h"

namespace Elion
{


	struct Velocity
	{
		static float Xpos;
		static float Ypos;
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

	struct Size
	{
		float X, Y, Z;
		Size(float x = 1.0f, float y = 1.0f, float z = 0.0f) :
			X(x),
			Y(y),
			Z(z)
		{}
	};


	class ELION_API Primitive
	{


	protected:


		GLuint VBO, VAO, EBO;

		std::shared_ptr<Shader> shader;
		GLuint program;
		GLint location;

		uint32_t SizeIndices;

		Color color;
		Position position;
		Size size;

		bool changes = false;

		Primitive() = default;
		
		
	public:
		//Primitive(PrimitiveType type, std::size_t vertexCount = 0);

	
		

		
		~Primitive()
		{
		}

		virtual void set_color(const Color& color) = 0;
		virtual void set_position(const Position& position) = 0;
		virtual void set_size(const Size& size) = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

		virtual bool is_set() = 0;
	};

}

