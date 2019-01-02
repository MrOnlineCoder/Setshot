/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "Camera.h"

#include <iostream>

Camera::Camera() {
	setAspectRatio(1280, 720);
	setFOV(45.0f);

	m_pos = glm::vec3(0.0f, 0.0f, 5.0f);
	m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Camera::setPosition(glm::vec3 pos) {
	m_pos = pos;
}

void Camera::setRotation(glm::vec3 rot) {
	m_rotation = rot;
}

void Camera::setVelocity(glm::vec3 velocity) {
	m_velocity = velocity;
}

glm::vec3 Camera::getPosition() {
	return m_pos;
}

glm::vec3 Camera::getRotation() {
	return m_rotation;
}

void Camera::update() {
	m_pos += m_rightVec * m_velocity.x;
	m_pos += m_directionVec * m_velocity.z;

	m_pos.y += m_velocity.y;

	if (m_velocity != glm::vec3(0.0f, 0.0f, 0.0f)) {
		//std::cout << "cam pos: x=" << m_pos.x << " y=" << m_pos.y << " z=" << m_pos.z << std::endl;
	}


	m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);

	makeViewMatrix();
}

void Camera::setFOV(float fov) {
	makeProjection(fov);
}

void Camera::setAspectRatio(int winWidth, int winHeight) {
	m_aspectRatio = winWidth / winHeight;
}

glm::mat4& Camera::getViewMatrix() {
	return m_view;
}

glm::mat4& Camera::getProjectionMatrix() {
	return m_proj;
}

void Camera::makeProjection(float fov) {
	m_proj = glm::perspective(glm::radians(fov), m_aspectRatio, 0.01f, 100.0f);
}

void Camera::makeViewMatrix() {
	m_directionVec.x = cos(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));
	m_directionVec.y = sin(glm::radians(m_rotation.x));
	m_directionVec.z = sin(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));

	m_directionVec = glm::normalize(m_directionVec);

	m_rightVec = glm::normalize(glm::cross(m_directionVec, glm::vec3(0.0f, 1.0f, 0.0f)));

	m_upVec = glm::normalize(glm::cross(m_rightVec, m_directionVec));

	m_view = glm::lookAt(m_pos, m_pos + m_directionVec, m_upVec);
}
