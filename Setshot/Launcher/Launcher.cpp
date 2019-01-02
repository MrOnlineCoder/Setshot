/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "Launcher.h"

#include <Game/Game.h>
#include <Logger/Logger.h>

#include <vector>

Launcher::Launcher(int argc, char * argv[]) {
	std::vector<std::string> args(argv + 1, argv + argc);

	m_options = LaunchOptions();
	m_options.debug = false;

	for (int i = 0; i < args.size(); i++) {
		std::string arg = args[i];

		if (arg == "--debug") {
			m_options.debug = true;
		}
	}
}

int Launcher::launch() {
	if (!gLogger.init()) {
		return 1;
	}

	sf::sleep(sf::milliseconds(20));

	gLogger.tag("Launcher") << "Starting game...";

	Game* game = new Game(m_options);

	int err = game->run();

	gLogger.tag("Launcher") << "Game::run() exited with " << err;
	gLogger.tag("Launcher") << "Shutdown!";

	gLogger.destroy();

	delete game;

	return err;
}
