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

	Mesh mesh;
	OBJModelLoader::loadFromFile("Resources/Models/sfml.obj",mesh);

	//model = new Model(mesh);

	//tex.loadFromFile("Resources/Textures/default.png");

	cam.setFOV(90.0f);
	cam.setAspectRatio(game.getRenderer().getWindow().getSize().x, game.getRenderer().getWindow().getSize().y);

	//skybox.loadFromFolder("Resources/Skybox/", "tga");

	m_pWorld = &game.getWorld();

	m_pWorld->addObject(new PlayerObject(*m_pWorld));
	m_pWorld->addObject(new StaticObject(*m_pWorld));

	game.getRenderer().switch3D(true);
}

PlayState::~PlayState() {

}

void PlayState::handleEvent(sf::Event& e) {
	if (e.type == sf::Event::MouseMoved) {
		mctrl.process(e);
	}

	if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::F4) {
			if (mctrl.isGrabbingMouse()) {
				mctrl.ungrabMouse();
			} else {
				mctrl.grabMouse(m_game->getRenderer().getWindow());
			}
		}
	}
}

void PlayState::update(sf::Time deltaTime) {
	mctrl.update();

	m_pWorld->update(deltaTime);

	glm::mat4 test(1.0f);

	glm::vec3 vel(0.0f, 0.0f, 0.0f);
	const float cam_speed = 15.0f;
	const float speed = cam_speed * deltaTime.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		vel.z += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		vel.z += -speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x += -speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x += speed;
	}

	m_game->getCamera().setVelocity(vel);

	m_game->getCamera().setRotation(glm::vec3(mctrl.getPitch(), mctrl.getYaw(), 0.0f));
}

void PlayState::render(Renderer& renderer) {
	renderer.initScene();

	m_pWorld->render(renderer);
}

void PlayState::init() {
	mctrl.grabMouse(m_game->getRenderer().getWindow());
}
