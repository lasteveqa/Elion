#pragma once
#include "Core/Core.h"
#include "imgui.h"
#include <chrono>
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

		struct SetOfMatrices
		{

		};

		struct SetOfPropeties
		{
			Color color;
			Scale scale;
			Position position;
			Rotation rotation;
			Projection projection;
		};

		class UIComponent
		{
		protected:
			static std::vector<PrimitiveTypes> m_PrimitiveTypes;
			static std::vector<SetOfPropeties> m_SetOfProperties;


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