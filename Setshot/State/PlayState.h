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
#include <Render/Shader.h>
#include <Render/Texture.h>
#include <Render/Skybox.h>

#include <Render/Camera.h>

#include <Input/MouseController.h>

#include <World/World.h>

class PlayState : public State
{
public:
	PlayState(Game& game);
	~PlayState();

	void handleEvent(sf::Event& e);
	void update(sf::Time deltaTime);
	void render(Renderer& renderer);

	void init();
private:
	World* m_pWorld;

	Camera cam;
	MouseController mctrl;

	sf::Clock clock;
};

#endif