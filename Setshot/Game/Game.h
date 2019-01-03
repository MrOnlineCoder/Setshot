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
#include <Resource/ResourceManager.h>

#include <vector>
#include <sstream>

class Game {
public:
	Game(LaunchOptions opts);
	int run();

	Renderer& getRenderer();
	ResourceManager& getResources();
	sf::Time getFrameDelta();
	long getFPS();

	void setState(int index);
private:
	bool setup();
	void shutdown();

	LaunchOptions m_options;
	Renderer m_render;
	ResourceManager m_resources;

	//Debug stuff
	bool m_debug;
	sf::Text m_debugText;
	std::stringstream m_debugStream;
	bool m_wireframe;

	void updateDebugInfo();

	sf::Time m_frameDelta;
	long m_fps;

	std::vector<State*> m_states;
	std::size_t m_currentState;
};

#endif