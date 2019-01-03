/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <string>

enum TextureRepeat {
	Repeat = GL_REPEAT,
	Mirror = GL_MIRRORED_REPEAT,
	ToEdge = GL_CLAMP_TO_EDGE
};

enum TextureFilter {
	Nearest = GL_NEAREST,
	Linear = GL_LINEAR,
};

class Texture {
public:
	Texture();
	~Texture();

	void loadFromFile(const std::string& path);
	void loadFromImage(sf::Image& img);

	void setFiltering(TextureFilter mode);
	void setRepeat(TextureRepeat mode);

	void bind();
private:
	GLuint m_texture;
};

#endif