/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

#include <SFML/System/Clock.hpp>

class Logger {
public:
	bool init();

	Logger& tag(const std::string& str);
	
	Logger& operator<<(std::string& arg);
	Logger& operator<<(const char* arg);
	Logger& operator<<(int arg);
	Logger& operator<<(float arg);
	Logger& operator<<(unsigned int arg);


	void destroy();
private:
	sf::Clock m_clock;
	std::ofstream m_file;
};

extern Logger gLogger;

#endif