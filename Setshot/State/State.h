/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

//Based on https://github.com/Ruixel/Multiverse/blob/master/src/States/StateBase.h
//Thanks!

#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class Renderer;
class Game;

class State {
public:
	State(Game& game)
		: m_game(&game) {

	}

	virtual ~State() = default;

	virtual void handleEvent(sf::Event& ev) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(Renderer& renderer) = 0;

protected:
	Game* m_game;
};

#endif