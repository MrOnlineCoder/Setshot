/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

#include <Render/Renderer.h>

class World;

class GameObject {
public:
	GameObject(World& world);
	
	virtual void update(sf::Time delta) {};
	virtual void input(sf::Event& ev) {};
	virtual void render(Renderer& renderer) {};

	void kill();
	bool isAlive();

private:
	bool m_alive;
	World* m_world;
};

#endif // !GAMEOBJECT_H
