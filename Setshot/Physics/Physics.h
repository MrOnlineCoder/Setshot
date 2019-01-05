/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef PHYSICS_H
#define PHYSICS_H

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include <SFML/System/Clock.hpp>

#include "PhysicsNode.h"

const btVector3 WORLD_GRAVITY = btVector3(0.0, -9.8, 0.0);

class Physics {
public:
	void init();
	void update(sf::Time delta);
	void registerNode(PhysicsNode* node);
	void destroy();
private:
	btBroadphaseInterface* m_broadphase;
	btDefaultCollisionConfiguration* m_collisionConfig;
	btSequentialImpulseConstraintSolver* m_solver;
	btCollisionDispatcher* m_dispatcher;
	btDiscreteDynamicsWorld* m_dWorld;
};

#endif // !PHYSICS_H
