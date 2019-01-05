/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "StaticObject.h"

#include <Resource/OBJLoader.h>

#include <Game/Game.h>

StaticObject::StaticObject(World & world)
	:GameObject(world){
	Mesh mesh;

	OBJModelLoader::loadFromFile("Resources/Models/sfml.obj", mesh);

	m_model.create(mesh);

	m_texture.loadFromFile("Resources/Textures/default.png");

	m_transform = Transform();
	m_transform.position = glm::vec3(0.0f, 10.0f, 0.0f);

	m_renderData = Renderable::make(m_model, m_texture, m_transform);

	m_physNode.makeSphere(&m_transform, 1.5f, 1.5f);

	world.getPhysics().registerNode(&m_physNode);
}

void StaticObject::render(Renderer & renderer) {
	m_physNode.syncTransform();
	renderer.render(m_renderData);
}
