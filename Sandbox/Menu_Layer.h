#pragma once
#include "GL/glew.h"
#include "Elion.h"
#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__
class Menu_Layer : public Elion::Layer
{

private:



	Elion::OpenGL_API api;
	std::shared_ptr<Elion::VertexArray> _vao;
	std::shared_ptr<Elion::VertexBuffer> _vbo;
	std::shared_ptr<Elion::VertexIndices> _ebo;
	std::shared_ptr<Elion::Shader> shader;
	GLuint program;

public:

	Menu_Layer();


	void init() override;
	void update() override;
	void render() override;
	void clear() override;

};

#endif;

