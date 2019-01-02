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

	/*float vertices[] = {
	 -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f, 
	};

	std::vector<float> verts(vertices, vertices + sizeof vertices / sizeof vertices[0]);
	//std::vector<unsigned int> inds(indices, indices + sizeof indices / sizeof indices[0]);

	Mesh mesh;
	//mesh.indices = inds;
	mesh.vertices = verts;

	model = new Model(mesh);*/

	Mesh mesh;
	OBJModelLoader::loadFromFile("Resources/cube.obj",mesh);

	model = new Model(mesh);

	shader.loadFromFiles("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
	shader.bind();
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
	const float speed = 0.2f;

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

	shader.setMat4("MVP", cam.getProjectionMatrix() * cam.getViewMatrix() * glm::mat4(1.0f));
}

void PlayState::render(Renderer& renderer) {
	shader.bind();
	model->bind();

	glDrawArrays(GL_TRIANGLES, 0, model->getVerticesCount());
}

void PlayState::init() {
	mctrl.grabMouse(m_game->getRenderer().getWindow());
}
