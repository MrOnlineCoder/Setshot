/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>

#include <SFML/Graphics.hpp>

#include <Logger/Logger.h>

class Renderer {
public:
	bool init(int w, int h, int fps);

	sf::RenderWindow& getWindow();

	void shutdown();
private:
	sf::RenderWindow m_window;
};

#endif