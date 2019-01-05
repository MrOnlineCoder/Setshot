/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef PHYSICSNODE_H
#define PHYSICSNODE_H

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "Transform.h"

class PhysicsNode {
public:
	PhysicsNode();
	void makeSphere(Transform* transform, float mass, float radius);
	~PhysicsNode();

	void syncTransform();

	btRigidBody& getRigidBody();
private:
	void destroy();

	btRigidBody* m_rigidBody;
	btCollisionShape* m_shape;

	//This is used to automatically update transform position and rotation, so it can be used by Renderer
	Transform* m_transform;
};

#endif // !PHYSICSNODE_H
