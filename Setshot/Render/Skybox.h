/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef SKYBOX_H
#define SKYBOX_H

#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <string>

#include "CubemapTexture.h"
#include "Model.h"
#include "Shader.h"

class Skybox {
public:
	Skybox();
	void loadFromFolder(const std::string& path, const std::string& format);

	void render(glm::mat4& proj, glm::mat4& view);
private:
	CubemapTexture m_cubemap;
	Model m_model;
	Shader m_shader;
};

#endif