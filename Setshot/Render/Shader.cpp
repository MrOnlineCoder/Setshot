/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <Logger/Logger.h>

#include <glm/gtc/type_ptr.hpp>

Shader::Shader() {
	m_canBind = false;
}

Shader::~Shader() {
	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);
	glDeleteProgram(m_program);
}

bool Shader::loadFromFiles(const char* vertexPath, const char* fragmentPath) {
	std::ifstream vertexFile(vertexPath);
	std::ifstream fragmentFile(fragmentPath);

	if (!vertexFile) {
		gLogger.tag("Shader") << "Failed to open vertex shader file (" << vertexPath << ")";
		return false;
	}

	if (!fragmentFile) {
		gLogger.tag("Shader") << "Failed to open fragment shader file (" << fragmentPath << ")";
		return false;
	}

	std::stringstream vertexStream;
	std::stringstream fragmentStream;

	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();

	std::string vertexCodeString = vertexStream.str();
	std::string fragmentCodeString = fragmentStream.str();

	const char* vertexCode = vertexCodeString.c_str();
	const char* fragmentCode = fragmentCodeString.c_str();

	return compile(vertexCode, fragmentCode);
}

void Shader::bind() {
	glUseProgram(m_program);
}

void Shader::setInteger(const char * name, int val) {
	glUniform1i(glGetUniformLocation(m_program, name), val);
}

void Shader::setFloat(const char * name, float val) {
	glUniform1f(glGetUniformLocation(m_program, name), val);
}

void Shader::setMat4(const char * name, glm::mat4 mat) {
	glUniformMatrix4fv(glGetUniformLocation(m_program, name), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat3(const char * name, glm::mat3 mat) {
	glUniformMatrix3fv(glGetUniformLocation(m_program, name), 1, GL_FALSE, glm::value_ptr(mat));
}

bool Shader::compile(const char * vertexCode, const char * fragmentCode) {
	int success = 0;
	char errorData[512];


	//Vertex
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(m_vertexShader, 1, &vertexCode, NULL);
	glCompileShader(m_vertexShader);

	glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(m_vertexShader, 512, NULL, errorData);
		gLogger.tag("Shader") << "Vertex shader compilation failed!";
		gLogger.tag("OpenGL Error") << errorData;
		return false;
	}

	//Fragment
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_fragmentShader, 1, &fragmentCode, NULL);
	glCompileShader(m_fragmentShader);

	glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(m_fragmentShader, 512, NULL, errorData);
		gLogger.tag("Shader") << "Fragment shader compilation failed!";
		gLogger.tag("OpenGL Error") << errorData;
		return false;
	}

	m_program = glCreateProgram();

	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	glLinkProgram(m_program);

	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_program, 512, NULL, errorData);
		gLogger.tag("Shader") << "Shader program linking failed!";
		gLogger.tag("OpenGL Error") << errorData;
	}

	m_canBind = true;

	gLogger.tag("Shader") << "Successfully compiled shader #" << m_program;

	return true;
}
