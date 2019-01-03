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

	contextSettings.attributeFlags = sf::ContextSettings::Default;

	m_window.create(sf::VideoMode(w,h), "Setshot by MrOnlineCoder", sf::Style::Titlebar | sf::Style::Close, contextSettings);
	m_window.setFramerateLimit(fps);
	m_window.setActive();

	if (!gladLoadGL()) {
		gLogger.tag("Renderer") << "gladLoadGL() error - cannot init OpenGL.";
		return false;
	}

	gLogger.tag("Renderer") << "Initialized OpenGL version " << GLVersion.major << "." << GLVersion.minor;


	is3D = false;
	return true;
}

sf::RenderWindow& Renderer::getWindow() {
	return m_window;
}

void Renderer::startSFML() {
	resetGLObjects();
	m_window.pushGLStates();
}

void Renderer::endSFML() {
	m_window.popGLStates();
}

void Renderer::switch3D(bool mode) {	
	is3D = mode;

	if (!is3D) {
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
	} else {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}

	
}

void Renderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

void Renderer::render(sf::Text& txt) {
	m_window.draw(txt);
}

void Renderer::resetGLObjects() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
