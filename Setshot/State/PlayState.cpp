/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "PlayState.h"

#include <Resource/OBJLoader.h>
#include <World/PlayerObject.h>
#include <World/StaticObject.h>

#include <Logger/Logger.h>

#include <glm/gtc/matrix_transform.hpp>

PlayState::PlayState(Game & game)
	: State(game) {
	m_pWorld = &game.getWorld();

	m_pWorld->addObject(new PlayerObject(*m_pWorld));
	m_pWorld->addObject(new StaticObject(*m_pWorld));

	game.getRenderer().switch3D(true);
}

PlayState::~PlayState() {

}

void PlayState::handleEvent(sf::Event& e) {
	m_pWorld->input(e);
}

void PlayState::update(sf::Time deltaTime) {
	m_pWorld->update(deltaTime);
}

void PlayState::render(Renderer& renderer) {
	renderer.initScene();

	m_pWorld->render(renderer);
}

void PlayState::init() {
	
}
