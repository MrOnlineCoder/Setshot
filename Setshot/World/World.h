/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "GameObject.h"

class Game;

class World {
public:
	World(Game* game);
	~World();

	void update(sf::Time delta);
	void input(sf::Event& ev);
	void render(Renderer& renderer);

	void addObject(GameObject* obj);

	sf::Time getUpdateDelta();

	Game& getGame();
private:
	std::vector<GameObject*> m_objects;

	Game* m_game;
	
	sf::Time m_updateDelta;
	sf::Clock m_updateClock;
};

#endif // !WORLD_H
