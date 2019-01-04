/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <Math/GLMath.h>

class Camera {
public:
	Camera();

	void setPosition(glm::vec3 pos);
	void setRotation(glm::vec3 rot);

	void setVelocity(glm::vec3& velocity);

	glm::vec3 getPosition();
	glm::vec3 getRotation();

	void update();

	void setFOV(float fov);
	void setAspectRatio(int winWidth, int winHeight);
	
	glm::mat4& getViewMatrix();
	glm::mat4& getProjectionMatrix();
private:
	void makeProjection(float fov);
	void makeViewMatrix();

	float m_aspectRatio;

	glm::mat4 m_view;
	glm::mat4 m_proj;

	glm::vec3 m_pos;
	glm::vec3 m_rotation;

	glm::vec3 m_upVec;
	glm::vec3 m_rightVec;
	glm::vec3 m_directionVec;

	glm::vec3 m_velocity;
};

#endif
