#pragma once
#include "Core/Core.h"

namespace Elion
{
	struct Color
	{
		float R, G, B, A;
		Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f) :
			R(r), G(g), B(b), A(a)
		{}
	};

	struct Position
	{
		float X, Y, Z;
		Position(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
			X(x), Y(y), Z(z)
		{}
	};

	struct Scale
	{
		float X, Y, Z;
		Scale(float x = 1.0f, float y = 1.0f, float z = 1.0f) :
			X(x), Y(y), Z(z)
		{}
	};

	struct Rotation
	{
		float Radians;
		float X, Y, Z;
		Rotation(float radians = 0.0f, float x = 1.0f, float y = 1.0f, float z = 1.0f) :
			Radians(radians),
			X(x), Y(y), Z(z)
		{}
	};

	struct Projection
	{

		float Radians;
		float Width, Height, Near, Far;
		Projection(float radians = 45.0f, float width = SCENE_WIDTH, float height = SCENE_HEIGHT, float _near = 0.1f, float _far = 1000.0f) :
			Radians(radians), Width(width), Height(height), Near(_near), Far(_far)
		{}
	};


	struct SetOfPropeties
	{
		Color color;
		Scale scale;
		Position position;
		Rotation rotation;
		Projection projection;
	};

}