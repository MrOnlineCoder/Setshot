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
	sf::ContextSettings contextSettings;
	contextSettings.antialiasingLevel = 4;
	contextSettings.depthBits = 24;
	contextSettings.stencilBits = 8;

	contextSettings.majorVersion = 3;
	contextSettings.minorVersion = 3;

	m_window.create(sf::VideoMode(w,h), "Setshot by MrOnlineCoder", sf::Style::Titlebar | sf::Style::Close, contextSettings);
	m_window.setFramerateLimit(fps);
	m_window.setActive();

	if (!gladLoadGL()) {
		gLogger.tag("Renderer") << "gladLoadGL() error - cannot init OpenGL.";
		return false;
	}

	gLogger.tag("Renderer") << "Initialized OpenGL version " << GLVersion.major << "." << GLVersion.minor;

	return true;
}

sf::RenderWindow& Renderer::getWindow() {
	return m_window;
}

void Renderer::switchSFML() {
	m_window.pushGLStates();
}

void Renderer::switch3D() {
	m_window.popGLStates();

	glEnable(GL_DEPTH_TEST);
}

void Renderer::setWireframeMode(bool enabled) {
	if (enabled) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	} else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Renderer::shutdown() {
	
}
