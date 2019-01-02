/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>

#include <vector>

enum BufferType {
	VERTICES,
	TEXCOORDS,
	NORMALS,
	
	INDICES
};

struct Mesh {
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> texCoords;
	std::vector<GLfloat> normals;
	std::vector<GLuint> indices;
};

#endif