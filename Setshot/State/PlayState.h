/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <Game/Game.h>

#include "State.h"

#include <Render/Model.h>

class PlayState : public State
{
public:
	PlayState(Game& game);
	~PlayState();

	void handleEvent(sf::Event& e);
	void update(sf::Time deltaTime);
	void render(Renderer& renderer);

	Model* model;
};

#endif