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
	//m_window.create(sf::VideoMode(1440,900), "Setshot by MrOnlineCoder", sf::Style::Fullscreen, contextSettings);
	m_window.setFramerateLimit(fps);
	m_window.setActive();

	if (!gladLoadGL()) {
		gLogger.tag("Renderer") << "gladLoadGL() error - cannot init OpenGL.";
		return false;
	}

	gLogger.tag("Renderer") << "Initialized OpenGL version " << GLVersion.major << "." << GLVersion.minor;


	m_skybox.loadFromFolder("Resources/Skybox/", "tga");

	if (!m_modelShader.loadFromFiles("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag")) {
		return false;
	}

	m_modelQueue.reserve(100);
	m_sfmlQueue.reserve(100);

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

void Renderer::initScene() {
	if (is3D) m_skybox.render(m_cameraPtr->getProjectionMatrix(), m_cameraPtr->getViewMatrix());

	m_modelShader.bind();
	m_modelShader.setMat4(ShaderUniforms::ViewMatrix, m_cameraPtr->getViewMatrix());
	m_modelShader.setMat4(ShaderUniforms::ProjectionMatrix, m_cameraPtr->getProjectionMatrix());
}

void Renderer::setWireframeMode(bool enabled) {
	if (enabled) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	} else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Renderer::setLightPosition(glm::vec3 pos) {
	m_lightPos = pos;
}

void Renderer::shutdown() {
	
}

void Renderer::setCamera(Camera& cam) {
	m_cameraPtr = &cam;
}

void Renderer::render(sf::Text& txt) {
	m_sfmlQueue.push_back(&txt);
}

void Renderer::render(Renderable & obj) {
	m_modelQueue.push_back(&obj);
}

void Renderer::renderAll() {
	for (std::size_t mI = 0; mI < m_modelQueue.size(); mI++) {
		Renderable* obj = m_modelQueue[mI];

		glm::mat4 modelMatrix = glm::mat4(1.0f);

		modelMatrix = glm::translate(modelMatrix, obj->transform->position);

		m_modelShader.setMat4(ShaderUniforms::ModelMatrix, modelMatrix);

		if (obj->texture) m_modelQueue[mI]->texture->bind();

		m_modelQueue[mI]->model->bind();
		
		if (obj->model->hasIndices()) {
			glDrawElements(GL_TRIANGLES, obj->model->getIndeciesCount(), GL_UNSIGNED_BYTE, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, obj->model->getVerticesCount());
		}
	}

	m_modelQueue.clear();

	startSFML();

	for (std::size_t sI = 0; sI < m_sfmlQueue.size(); sI++) {
		m_window.draw(*m_sfmlQueue[sI]);
	}

	endSFML();

	m_sfmlQueue.clear();

	m_window.display();
}

void Renderer::resetGLObjects() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
