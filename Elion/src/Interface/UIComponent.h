#pragma once
#include "Core/Core.h"
#include "imgui.h"
#include "imgui/examples/imgui_impl_sdl.h"
#include "imgui/examples/imgui_impl_opengl3.h"
#include "Core/WindowProperties.h"
#include "Primitives/Primitive.h"
#include "Scene/Scene.h"

namespace Elion
{
	namespace Interface
	{
		class UIComponent
		{
		protected:
			//Primitive Types required for Scene Outliner window
			static std::vector<PrimitiveTypes> m_PrimitiveTypes;
			WindowProperties m_Wprops;

			Color m_Color;
			Size m_Size;
			Position m_Position;


		public:
			virtual void init(){}
			virtual void render(){}
			virtual void clear(){}
		};


	}
}