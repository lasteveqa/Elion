#pragma once
#include "Core/Core.h"
#include "imgui.h"
#include "imguizmo/ImGuizmo.h"
#include "imgui/examples/imgui_impl_sdl.h"
#include "imgui/examples/imgui_impl_opengl3.h"
#include "Core/WindowProperties.h"
#include "Primitives/Primitive.h"
#include "Scene/Scene.h"

namespace Elion
{
	namespace Interface
	{
		enum { SINGLEUPDATE, MULTIUPDATE };

		struct SetOfPropeties
		{
			Color color;
			Size size;
			Position position;
			Rotation rotation;
			Projection projection;
		};

		class UIComponent
		{
		protected:
			//Primitive Types required for Scene Outliner window

			static std::vector<PrimitiveTypes> m_PrimitiveTypes;
			static std::vector<SetOfPropeties> m_SetOfProperties;

			static Color m_Color;
			static Size m_Size;
			static Position m_Position;
			static Rotation m_Rotation;
			static Projection m_Projection;

			static Scene m_Scene;

			static int index;
			static int m_Update;

			WindowProperties m_Wprops;



		public:
			virtual void init() {}
			virtual void render() { }
			virtual void clear() {}
		};



	}
}