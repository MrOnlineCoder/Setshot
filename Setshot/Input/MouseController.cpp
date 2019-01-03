/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "MouseController.h"

MouseController::MouseController() {
	isGrabbing = false;
	m_pitch = 0.0f;
	m_yaw = -90.0f;

	m_sensitivity = 0.1f;
}

void MouseController::grabMouse(sf::RenderWindow & target) {
	isGrabbing = true;

	target.setMouseCursorVisible(false);

	centerPos = sf::Vector2i(target.getSize().x / 2, target.getSize().y / 2);

	m_grabbedWindow = &target;
}

void MouseController::ungrabMouse() {
	isGrabbing = false;

	m_grabbedWindow->setMouseCursorVisible(true);
}

bool MouseController::isGrabbingMouse() {
	return isGrabbing;
}

void MouseController::setSensitivity(float arg) {
	m_sensitivity = arg;
}

void MouseController::process(sf::Event & moveEv) {
	if (!isGrabbing) return;

	float deltaX = moveEv.mouseMove.x - centerPos.x;
	float deltaY = centerPos.y - moveEv.mouseMove.y;

	deltaX *= m_sensitivity;
	deltaY *= m_sensitivity;

	m_yaw += deltaX;
	m_pitch += deltaY;

	if (m_pitch > 89.0f) {
		m_pitch = 89.0f;
	} else if (m_pitch < -89.0f) {
		m_pitch = -89.0f;
	}
}

void MouseController::update() {
	if (isGrabbing) {
		sf::Mouse::setPosition(centerPos, *m_grabbedWindow);
	}
}

float MouseController::getPitch() {
	return m_pitch;
}

float MouseController::getYaw() {
	return m_yaw;
}
