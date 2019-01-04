/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "GameObject.h"

GameObject::GameObject(World & world)
	:m_world(&world) {

}

void GameObject::kill() {
	m_alive = false;
}

bool GameObject::isAlive() {
	return m_alive;
}
