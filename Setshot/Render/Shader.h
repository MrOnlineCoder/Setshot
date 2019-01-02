/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>

class Shader {
public:
	Shader();
	~Shader();

	bool loadFromFiles(const char* vertexPath, const char* fragmentPath);
	void bind();

	void setInteger(const char* name, int val);
	void setFloat(const char* name, float val);
	
private:
	bool compile(const char* vertexCode, const char* fragmentCode);

	bool m_canBind;

	GLuint m_program;

	GLuint m_vertexShader;
	GLuint m_fragmentShader;
};

#endif