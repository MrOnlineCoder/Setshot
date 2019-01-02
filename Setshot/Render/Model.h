/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef MODEL_H
#define MODEL_H

#include <array>
#include <glad/glad.h>

#include "Mesh.h"

class Model {
public:
	Model(Mesh& mesh);
	~Model();

	void bind();

	std::size_t getCount();
private:
	void create(Mesh& mesh);

	void setupBuffer(int idx, int size, const std::vector<GLfloat>& data);

	GLuint m_vao;
	std::array<GLuint, 5> m_buffers;

	std::size_t m_count;
};

#endif