/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "PhysicsNode.h"

PhysicsNode::PhysicsNode() {
	m_rigidBody = NULL;
}

void PhysicsNode::makeSphere(Transform * transform, float mass, float radius) {
	destroy();

	m_shape = new btSphereShape(radius);

	btQuaternion rotation;
	rotation.setEulerZYX(transform->rotation.z, transform->rotation.y, transform->rotation.x);

	btVector3 position = btVector3(transform->position.x, transform->position.y, transform->position.z);
	
	btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(rotation, position));

	btScalar bodyMass = mass;
	btVector3 bodyInertia;
	m_shape->calculateLocalInertia(bodyMass, bodyInertia);

	btRigidBody::btRigidBodyConstructionInfo bodyCI = btRigidBody::btRigidBodyConstructionInfo(bodyMass, motionState, m_shape, bodyInertia);
    
    bodyCI.m_restitution = 1.0f;
    bodyCI.m_friction = 0.5f;
    
    m_rigidBody = new btRigidBody(bodyCI);
	m_rigidBody->setLinearFactor(btVector3(1,1,0));

	m_transform = transform;
}

PhysicsNode::~PhysicsNode() {
	destroy();
}

void PhysicsNode::syncTransform() {
	m_transform->position.x = m_rigidBody->getWorldTransform().getOrigin().x();
	m_transform->position.y = m_rigidBody->getWorldTransform().getOrigin().y();
	m_transform->position.z = m_rigidBody->getWorldTransform().getOrigin().z();
}

btRigidBody& PhysicsNode::getRigidBody() {
	return *m_rigidBody;
}

void PhysicsNode::destroy() {
	if (m_rigidBody) {
		delete m_rigidBody->getMotionState();
		delete m_rigidBody;
	}
	if (m_shape) delete m_shape;
}
