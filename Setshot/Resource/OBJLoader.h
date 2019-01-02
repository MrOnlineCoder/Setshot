/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <Render/Mesh.h>

#include <string>

class OBJModelLoader {
public:
	static bool loadFromFile(const char* path, Mesh& mesh);
};

#endif