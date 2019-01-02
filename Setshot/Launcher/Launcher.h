/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef LAUNCHER_H
#define LAUNCHER_H

struct LaunchOptions {
	bool debug;
};

class Launcher {
public:
	Launcher(int argc, char* argv[]);
	int launch();
private:
	LaunchOptions m_options;
};

#endif