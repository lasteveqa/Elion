#pragma once
#include "GL/glew.h"
#include "Elion.h"
#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__
class Menu_Layer : public Elion::Layer
{

private:
	GLuint vbo, vao, program , positionAttribute, colorAttribute;
	Elion::LayerState state;

	std::shared_ptr<Elion::VertexArray> m_VertexArray;
	std::shared_ptr<Elion::VertexBuffer> m_VertexBuffer;
public:

	Menu_Layer();


	void init() override;
	void update() override;
	void render() override;
	void clear() override;

};

#endif;
