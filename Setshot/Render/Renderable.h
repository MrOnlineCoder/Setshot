/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Model.h"
#include "Texture.h"
#include <Physics/Transform.h>

class Renderable {
public:
	Model* model;
	Texture* texture;
	Transform* transform;

	static Renderable make(Model& model, Texture& tex, Transform& transform) {
		Renderable obj;
		obj.model = &model;
		obj.texture = &tex;
		obj.transform = &transform;
		
		return obj;
	}
};

#endif