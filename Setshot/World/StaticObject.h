/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

#include <Math/GLMath.h>

#include <Render/Renderable.h>
#include <Physics/Transform.h>
#include <Physics/PhysicsNode.h>


class StaticObject : public GameObject {
public:
	StaticObject(World& world);

	void render(Renderer& renderer);
private:
	Model m_model;
	Texture m_texture;
	Transform m_transform;
	PhysicsNode m_physNode;

	Renderable m_renderData;
};

#endif
