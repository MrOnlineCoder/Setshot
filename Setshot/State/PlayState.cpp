/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "PlayState.h"

#include <Logger/Logger.h>

PlayState::PlayState(Game & game)
	: State(game) {

	/*float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	std::vector<float> verts(vertices, vertices + sizeof vertices / sizeof vertices[0]);
	std::vector<unsigned int> inds(indices, indices + sizeof indices / sizeof indices[0]);

	Mesh mesh;
	mesh.indices = inds;
	mesh.vertices = verts;

	model = new Model(mesh);*/

}

PlayState::~PlayState() {

}

void PlayState::handleEvent(sf::Event& e) {
	
}

void PlayState::update(sf::Time deltaTime) {

}

void PlayState::render(Renderer& renderer) {
	
}
