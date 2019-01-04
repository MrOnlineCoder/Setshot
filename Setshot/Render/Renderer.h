/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>

#include <Math/GLMath.h>

#include <SFML/Graphics.hpp>

#include <Logger/Logger.h>

#include "Skybox.h"
#include "Renderable.h"
#include "Camera.h"


class Renderer {
public:
	bool init(int w, int h, int fps);

	sf::RenderWindow& getWindow();

	void startSFML();
	void endSFML();
	void switch3D(bool mode);

	void clear();

	void initScene();

	void setWireframeMode(bool enabled);
	void setLightPosition(glm::vec3 pos);

	void shutdown();

	void setCamera(Camera& cam);

	//All possible rendering methods
	void render(sf::Text& txt);
	void render(Renderable& obj);

	void renderAll();
private:
	void resetGLObjects();

	//Thanks Hopson/Ruixel for this idea of queued rendering

	std::vector<sf::Drawable*> m_sfmlQueue;
	std::vector<Renderable*> m_modelQueue;

	Shader m_modelShader;
	Camera* m_cameraPtr;

	sf::RenderWindow m_window;

	Skybox m_skybox;

	bool is3D;

	glm::vec3 m_lightPos;
};

#endif