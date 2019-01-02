/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Model.h"

#include <Logger/Logger.h>

Model::Model(Mesh & mesh) {
	m_vao = 0;
	m_indeciesCount = 0;
	m_hasIndices = false;
	m_verticesCount = 0;

	create(mesh);
}

Model::~Model() {
	if (m_vao) {
		glDeleteVertexArrays(1, &m_vao);
		glDeleteBuffers(m_buffers.size(), m_buffers.data());
	}
}

void Model::bind() {
	glBindVertexArray(m_vao);
}


std::size_t Model::getIndeciesCount() {
	return m_indeciesCount;
}

std::size_t Model::getVerticesCount() {
	return m_verticesCount;
}

bool Model::hasIndices() {
	return m_hasIndices;
}

void Model::create(Mesh& mesh) {
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//VBOs
	setupBuffer(BufferType::VERTICES, 3, mesh.vertices);
	setupBuffer(BufferType::TEXCOORDS, 3, mesh.texCoords);
	setupBuffer(BufferType::NORMALS, 3, mesh.normals);

	if (!mesh.indices.empty()) {
		//EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffers[BufferType::INDICES]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * mesh.indices.size(), mesh.indices.data(), GL_STATIC_DRAW);
		m_indeciesCount = mesh.indices.size();
		m_hasIndices = true;
	} else {
		m_verticesCount = mesh.vertices.size() / 3;
	}
	
	gLogger.tag("Model") << "Loaded model with " << m_verticesCount << " vertices to VAO #" << m_vao;
}

void Model::setupBuffer(int idx, int size, const std::vector<GLfloat>& data) {
	glGenBuffers(1, &m_buffers[idx]);
	glBindBuffer(GL_ARRAY_BUFFER, m_buffers[idx]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(idx, size, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(idx);
}
