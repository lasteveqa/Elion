#pragma once
#include "Renderer/Model.h"
#include "Scene/SceneCamera.h"

namespace Elion
{
	class ModelLoader
	{
	private:

		Shader m_Shader;
		Model m_Model;
		GLuint m_Program;

	public:

		ModelLoader(){}
		ModelLoader(const std::string &path);
		void draw();


	
		~ModelLoader(){}
	};

}