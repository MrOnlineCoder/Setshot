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

	void startSFML();
	void endSFML();
	void switch3D(bool mode);

	void clear();

	void setWireframeMode(bool enabled);

	void shutdown();


	//All possible rendering methods
	void render(sf::Text& txt);
private:
	void resetGLObjects();

	sf::RenderWindow m_window;

	bool is3D;
};

#endif