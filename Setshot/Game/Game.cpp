/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Game.h"

#include <State/PlayState.h>

long calculateFPS(const sf::Time& time) {
	return (1000000.0f / time.asMicroseconds());
}

Game::Game(LaunchOptions opts)
	: m_world(this) {
	m_options = opts;

	m_currentState = 0;
	m_debug = false;
	m_wireframe = false;
}

int Game::run() {
	if (!setup()) {
		gLogger.tag("Game") << "Initial setup failed.";
		return 1;
	}

	gLogger.tag("Game") << "Entering game loop...";

	sf::Event ev;
	sf::Clock frameClock;

	setState(0);

	while (m_render.getWindow().isOpen()) {
		while (m_render.getWindow().pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				m_render.getWindow().close();
				continue;
			}

			if (ev.type == sf::Event::KeyReleased) {
				if (ev.key.code == sf::Keyboard::F2) {
					m_debug = !m_debug;
				}

				if (ev.key.code == sf::Keyboard::F3) {
					m_wireframe = !m_wireframe;

					m_render.setWireframeMode(m_wireframe);
				}

				if (ev.key.code == sf::Keyboard::F10) {
					m_render.getWindow().close();
					continue;
				}
			}

			m_states[m_currentState]->handleEvent(ev);
		}

		m_camera.update();

		m_states[m_currentState]->update(m_frameDelta);

		m_render.clear();

		m_states[m_currentState]->render(m_render);

		if (m_debug) {
			updateDebugInfo();
			m_render.render(m_debugText);
		}

		m_render.renderAll();

		m_frameDelta = frameClock.restart();
		m_fps = calculateFPS(m_frameDelta);
	}

	shutdown();

	gLogger.tag("Game") << "Game loop exited.";

	return 0;
}

Renderer& Game::getRenderer() {
	return m_render;
}

ResourceManager& Game::getResources() {
	return m_resources;
}

sf::Time Game::getFrameDelta() {
	return m_frameDelta;
}

long Game::getFPS() {
	return m_fps;
}

World& Game::getWorld() {
	return m_world;
}

Camera& Game::getCamera() {
	return m_camera;
}

void Game::setState(int index) {
	m_currentState = index;

	m_states[m_currentState]->init();
}

bool Game::setup() {
	gLogger.tag("Game") << "Initializing Renderer...";
	if (!m_render.init(1280, 720, 120)) {
		gLogger.tag("Game") << "Renderer::init() failed.";
		return false;
	}
	m_render.setCamera(m_camera);

	gLogger.tag("Game") << "Initializing ResourceManager...";
	m_resources.init();

	m_debugText.setFont(m_resources.getFont("main"));
	m_debugText.setPosition(sf::Vector2f(15.0f, 15.0f));
	m_debugText.setCharacterSize(14);
	m_debugText.setFillColor(sf::Color::Yellow);
	m_debugText.setOutlineColor(sf::Color::Black);
	m_debugText.setOutlineThickness(1.5f);

	m_states.push_back(new PlayState(*this));

	return true;
}

void Game::shutdown() {
	m_render.shutdown();
	m_resources.destroy();

	for (auto i = 0; i < m_states.size(); i++) {
		delete m_states[i];
	}

	gLogger.tag("Game") << "All systems shutdown!";
}

void Game::updateDebugInfo() {
	m_debugStream.str("");

	m_debugStream << "FPS: " << m_fps << " (" << m_frameDelta.asMilliseconds() << " ms.)\n";
	m_debugStream << "State: " << m_currentState << "\n";
	m_debugStream << "world.update(): " << m_world.getUpdateDelta().asMilliseconds() << " ms.\n";
	m_debugStream << "Camera Position: " << m_camera.getPosition().x << ", " << m_camera.getPosition().y << ", " << m_camera.getPosition().z;

	m_debugText.setString(m_debugStream.str());
}
