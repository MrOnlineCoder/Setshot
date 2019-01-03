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
	VERTICES = 0,
	TEXCOORDS = 1,
	NORMALS = 2,
	
	INDICES
};

struct Mesh {
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> texCoords;
	std::vector<GLfloat> normals;
	std::vector<GLuint> indices;
};

#endif