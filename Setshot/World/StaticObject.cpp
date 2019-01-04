/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "StaticObject.h"

#include <Resource/OBJLoader.h>

StaticObject::StaticObject(World & world)
	:GameObject(world){
	Mesh mesh;

	OBJModelLoader::loadFromFile("Resources/Models/sfml.obj", mesh);

	m_model.create(mesh);

	m_texture.loadFromFile("Resources/Textures/default.png");

	m_renderData = Renderable::make(m_model, m_texture);
}

void StaticObject::render(Renderer & renderer) {
	renderer.render(m_renderData);
}