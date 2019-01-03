/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Logger.h"

Logger gLogger;

bool Logger::init() {
	m_file.open("game.log");

	if (!m_file) return false;

	m_clock.restart();

	m_file << "Logger Initialized";

	m_file << std::fixed;
	m_file.precision(3);

	return true;
}

Logger& Logger::tag(const std::string& str) {
	m_file << "\n[" << m_clock.getElapsedTime().asSeconds() << "s.] <" << str << ">\t";
	return *this;
}

Logger& Logger::operator<<(const std::string & arg) {
	m_file << arg;
	return *this;
}

Logger& Logger::operator<<(std::string & arg) {
	m_file << arg;
	return *this;
}

Logger& Logger::operator<<(const char* arg) {
	m_file << arg;
	return *this;
}

Logger& Logger::operator<<(int arg) {
	m_file << arg;
	return *this;
}

Logger& Logger::operator<<(unsigned int arg) {
	m_file << arg;
	return *this;
}

Logger& Logger::operator<<(float arg) {
	m_file << arg;
	return *this;
}

void Logger::destroy() {
	m_file.close();
}
