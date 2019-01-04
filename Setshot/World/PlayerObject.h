/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <Input/MouseController.h>
#include <Math/GLMath.h>

#include "GameObject.h"

#include <World/World.h>

const float PLAYER_SPEED = 15.5f;

class PlayerObject : public GameObject {
public:
	PlayerObject(World& world);

	void update(sf::Time delta);
	void input(sf::Event& ev);
	void render(Renderer& renderer);
private:
	glm::vec3 m_velocity;
	MouseController m_mouseController;
};

#endif
