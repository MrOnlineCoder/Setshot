/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include <Logger/Logger.h>

#include "CubemapTexture.h"

CubemapTexture::CubemapTexture() {
	m_texture = 0;
}

CubemapTexture::~CubemapTexture() {
	if (m_texture != 0) glDeleteTextures(1, &m_texture);
}

void CubemapTexture::load(std::vector<std::string>& paths) {
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_texture);

	for (auto i = 0; i < paths.size(); i++) {
		std::string path = paths[i];

		sf::Image img;
		if (!img.loadFromFile(path)) {
			gLogger.tag("CubemapTexture") << "Failed to load cubemap side " << path;
			continue;
		}

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0, GL_RGB, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr()
		);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	gLogger.tag("Cubemap") << "Loaded cubemap to texture #" << m_texture;
}

void CubemapTexture::bind() {
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_texture);
}
