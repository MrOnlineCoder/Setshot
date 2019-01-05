/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "Physics.h"

#include <Logger/Logger.h>

void Physics::init() {
	m_broadphase = new btDbvtBroadphase();

	m_collisionConfig = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_collisionConfig);
	m_solver = new btSequentialImpulseConstraintSolver();

	m_dWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collisionConfig);

	m_dWorld->setGravity(WORLD_GRAVITY);

	gLogger.tag("Physics") << "Initialized physics btDiscreteDynamicsWorld.";
}

void Physics::update(sf::Time delta) {

}

void Physics::destroy() {
	delete m_dWorld;
	delete m_solver;
	delete m_dispatcher;
	delete m_collisionConfig;
	delete m_broadphase;

	gLogger.tag("Physics") << "Destroyed physics system";
}
