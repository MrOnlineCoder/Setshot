#include "World.h"

#include "GameObject.h"

World::World(Game* game) {
	m_game = game;
	m_objects.reserve(64);

	m_physics.init();
}

World::~World() {
	for (auto i = 0; i < m_objects.size(); i++) {
		delete m_objects[i];
	}

	m_physics.destroy();
}

void World::update(sf::Time delta) {
	m_physics.update(delta);

	for (auto i = 0; i < m_objects.size(); i++) {
		m_objects[i]->update(delta);
	}

	m_updateDelta = m_updateClock.restart();
}

void World::input(sf::Event & ev) {
	for (auto i = 0; i < m_objects.size(); i++) {
		m_objects[i]->input(ev);
	}
}

void World::render(Renderer & renderer) {
	for (auto i = 0; i < m_objects.size(); i++) {
		m_objects[i]->render(renderer);
	}
}

void World::addObject(GameObject * obj) {
	m_objects.push_back(obj);
}

sf::Time World::getUpdateDelta() {
	return m_updateDelta;
}

Game& World::getGame() {
	return *m_game;
}

Physics& World::getPhysics() {
	return m_physics;
}
