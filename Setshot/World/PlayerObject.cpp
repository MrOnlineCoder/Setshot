/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "PlayerObject.h"

PlayerObject::PlayerObject(World & world)
	: GameObject(world) {

}

void PlayerObject::update(sf::Time delta) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_velocity.z += PLAYER_SPEED;
		std::cout << "boom " << m_velocity.z << std::endl;
	}
}

void PlayerObject::input(sf::Event & ev) {

}

void PlayerObject::render(Renderer & renderer) {

}
