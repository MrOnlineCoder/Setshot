/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef CUBEMAP_H
#define CUBEMAP_H

#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class CubemapTexture {
public:
	CubemapTexture();
	~CubemapTexture();

	void load(std::vector<std::string>& paths);
	void bind();
private:
	GLuint m_texture;
};

#endif