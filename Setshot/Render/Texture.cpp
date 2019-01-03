/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include <Logger/Logger.h>

#include "Texture.h"

Texture::Texture() {
	m_texture = 0;
}

Texture::~Texture() {
	if (m_texture != 0) {
		glDeleteTextures(1, &m_texture);
	}
}

void Texture::loadFromFile(const std::string & path) {
	sf::Image img;
	if (!img.loadFromFile(path)) {
		gLogger.tag("Texture") << "Failed to load texture: " << path;
		return;
	}

	loadFromImage(img);
}

void Texture::loadFromImage(sf::Image& img) {
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
	glGenerateMipmap(GL_TEXTURE_2D);

	setFiltering(TextureFilter::Nearest);
	setRepeat(TextureRepeat::Repeat);

	gLogger.tag("Texture") << "Loaded texture #" << m_texture;
}

void Texture::setFiltering(TextureFilter mode) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mode);
}

void Texture::setRepeat(TextureRepeat mode) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
