/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "GameObject.h"

#include <Math/GLMath.h>

const float PLAYER_SPEED = 0.3f;

class PlayerObject : public GameObject {
public:
	PlayerObject(World& world);

	void update(sf::Time delta);
	void input(sf::Event& ev);
	void render(Renderer& renderer);
private:
	glm::vec3 m_velocity;
};

#endif // !GAMEOBJECT_H
