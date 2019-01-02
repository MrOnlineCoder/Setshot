/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Game.h"

#include <State/PlayState.h>

Game::Game(LaunchOptions opts) {
	m_options = opts;

	m_currentState = 0;
}

int Game::run() {
	if (!setup()) {
		gLogger.tag("Game") << "Initial setup failed.";
		return 1;
	}

	gLogger.tag("Game") << "Entering game loop...";

	sf::Event ev;
	sf::Time delta;
	sf::Clock frameClock;

	while (m_render.getWindow().isOpen()) {
		while (m_render.getWindow().pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				m_render.getWindow().close();
				continue;
			}

			m_states[m_currentState]->handleEvent(ev);
		}

		m_states[m_currentState]->update(delta);

		m_render.getWindow().clear();

		m_states[m_currentState]->render(m_render);

		m_render.getWindow().display();

		delta = frameClock.restart();
	}

	shutdown();

	gLogger.tag("Game") << "Game loop exited.";

	return 0;
}

Renderer & Game::getRenderer() {
	return m_render;
}

bool Game::setup() {
	gLogger.tag("Game") << "Initializing Renderer...";
	if (!m_render.init(1280, 720, 60)) {
		gLogger.tag("Game") << "Renderer::init() failed.";
		return false;
	}

	m_states.push_back(new PlayState(*this));

	return true;
}

void Game::shutdown() {
	m_render.shutdown();

	for (int i = 0; i < m_states.size(); i++) {
		delete m_states[i];
	}

	gLogger.tag("Game") << "All systems shutdown!";
}
