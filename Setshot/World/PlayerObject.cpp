/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "PlayerObject.h"
#include <Game/Game.h>

PlayerObject::PlayerObject(World & world)
	: GameObject(world) {
	m_mouseController.grabMouse(m_world->getGame().getRenderer().getWindow());
}

void PlayerObject::update(sf::Time delta) {
	m_mouseController.update();

	m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);

	const float speed = PLAYER_SPEED * delta.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_velocity.z += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_velocity.z += -speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_velocity.x += -speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_velocity.x += speed;
	}

	m_world->getGame().getCamera().setVelocity(m_velocity);

	m_world->getGame().getCamera().setRotation(glm::vec3(m_mouseController.getPitch(), m_mouseController.getYaw(), 0.0f));
}

void PlayerObject::input(sf::Event & ev) {
	if (ev.type == sf::Event::MouseMoved) {
		m_mouseController.process(ev);
	}

	if (ev.type == sf::Event::KeyReleased) {
		if (ev.key.code == sf::Keyboard::F4) {
			if (m_mouseController.isGrabbingMouse()) {
				m_mouseController.ungrabMouse();
			} else {
				m_mouseController.grabMouse(m_world->getGame().getRenderer().getWindow());
			}
		}
	}
}

void PlayerObject::render(Renderer & renderer) {

}
