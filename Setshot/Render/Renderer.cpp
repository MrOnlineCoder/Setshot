/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Renderer.h"

#include "Shader.h"
#include "Mesh.h"
#include "Model.h"

bool Renderer::init(int w, int h, int fps) {
	m_window.create(sf::VideoMode(w,h), "Setshot by MrOnlineCoder");
	m_window.setFramerateLimit(fps);
	m_window.setActive();

	if (!gladLoadGL()) {
		gLogger.tag("Renderer") << "gladLoadGL() error - cannot init OpenGL.";
		return false;
	}

	gLogger.tag("Renderer") << "Initialized OpenGL version " << GLVersion.major << "." << GLVersion.minor;

	Shader s;
	s.loadFromFiles("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
	s.bind();

	return true;
}

sf::RenderWindow& Renderer::getWindow() {
	return m_window;
}

void Renderer::shutdown() {
	
}
