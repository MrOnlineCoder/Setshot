/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "PlayState.h"

#include <Resource/OBJLoader.h>

#include <Logger/Logger.h>

#include <glm/gtc/matrix_transform.hpp>

PlayState::PlayState(Game & game)
	: State(game) {

	Mesh mesh;
	OBJModelLoader::loadFromFile("Resources/Models/house.obj",mesh);

	model = new Model(mesh);

	shader.loadFromFiles("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
	shader.bind();

	sfshader.loadFromFile("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");

	tex.loadFromFile("Resources/Textures/house.png");

	cam.setFOV(90.0f);

	skybox.loadFromFolder("Resources/Skybox/", "tga");

	game.getRenderer().switch3D(true);
}

PlayState::~PlayState() {

}

void PlayState::handleEvent(sf::Event& e) {
	if (e.type == sf::Event::MouseMoved) {
		mctrl.process(e);
	}

	if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::F10) {
			if (mctrl.isGrabbingMouse()) {
				mctrl.ungrabMouse();
			} else {
				mctrl.grabMouse(m_game->getRenderer().getWindow());
			}
		}
	}
}

void PlayState::update(sf::Time deltaTime) {
	cam.update();
	mctrl.update();

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

	cam.setVelocity(vel);

	cam.setRotation(glm::vec3(mctrl.getPitch(), mctrl.getYaw(), 0.0f));

	shader.bind();
	shader.setMat4("MVP", cam.getProjectionMatrix() * cam.getViewMatrix() * glm::mat4(1.0f));
}

void PlayState::render(Renderer& renderer) {
	skybox.render(cam.getProjectionMatrix(), cam.getViewMatrix());

	shader.bind();
	tex.bind();
	model->bind();
	

	glDrawArrays(GL_TRIANGLES, 0, model->getVerticesCount());
}

void PlayState::init() {
	mctrl.grabMouse(m_game->getRenderer().getWindow());
}
