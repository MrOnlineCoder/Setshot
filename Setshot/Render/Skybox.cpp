/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "Skybox.h"

#include <Logger/Logger.h>

const float SKYBOX_VERTICES[] = {
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	-1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f
};

Skybox::Skybox() {

}

void Skybox::loadFromFolder(const std::string & path, const std::string& format) {
	std::vector<std::string> faces = {
		path + "right."+format,
		path + "left."+format,
		path + "top."+format,
		path + "bottom."+format,
		path + "back."+format,
		path + "front."+format
	};

	m_cubemap.load(faces);
	
	Mesh mesh;

	int n = sizeof(SKYBOX_VERTICES) / sizeof(SKYBOX_VERTICES[0]);

	std::vector<float> verticesVector(SKYBOX_VERTICES, SKYBOX_VERTICES + n);

	mesh.vertices = verticesVector;

	m_model.create(mesh);

	if (!m_shader.loadFromFiles("Resources/Shaders/skybox.vert", "Resources/Shaders/skybox.frag")) {
		gLogger.tag("Skybox") << "Failed to load skybox shader!";
	}

	gLogger.tag("Skybox") << "Loaded skybox from " << path;
}

void Skybox::render(glm::mat4& proj, glm::mat4& view) {

	glm::mat4 noTransView = glm::mat4(glm::mat3(view));

	m_shader.bind();
	m_shader.setMat4("projection", proj);
	m_shader.setMat4("view", noTransView);

	glDepthMask(GL_FALSE);
	
	m_cubemap.bind();
	m_model.bind();

	glDrawArrays(GL_TRIANGLES, 0, m_model.getVerticesCount());

	glDepthMask(GL_TRUE);
}
