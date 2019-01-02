/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef GAME_H
#define GAME_H

#include <Launcher/Launcher.h>
#include <Render/Renderer.h>
#include <State/State.h>

#include <vector>

class Game {
public:
	Game(LaunchOptions opts);
	int run();

	Renderer& getRenderer();

	void setState(int index);
private:
	bool setup();
	void shutdown();

	LaunchOptions m_options;
	Renderer m_render;

	std::vector<State*> m_states;
	std::size_t m_currentState;
};

#endif