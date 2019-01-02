/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef MOUSECONTROLLER_H
#define MOUSECONTROLLER_H

#include <Math/GLMath.h>

#include <SFML/Graphics.hpp>

class MouseController {
public:
	MouseController();

	void grabMouse(sf::RenderWindow& target);
	void ungrabMouse();

	bool isGrabbingMouse();

	void setSensitivity(float arg);

	void process(sf::Event& moveEv);

	void update();

	float getPitch();
	float getYaw();
private:
	float m_pitch;
	float m_yaw;

	float m_sensitivity;

	sf::Vector2i centerPos;

	bool isGrabbing;

	sf::RenderWindow* m_grabbedWindow;
};

#endif
