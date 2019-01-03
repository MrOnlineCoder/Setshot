/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#include "ResourceManager.h"

#include <Logger/Logger.h>

ResourceManager::ResourceManager() {
	m_fonts.clear();
}

void ResourceManager::init() {
	loadAllResources();
}

void ResourceManager::destroy() {
	gLogger.tag("ResourceManager") << "Destroying all loaded resources...";

	for (auto it = m_fonts.begin(); it != m_fonts.end(); it++) {
		delete it->second;
	}

	m_fonts.clear();

	gLogger.tag("ResourceManager") << "Resources memory was released successfully!";
}

sf::Font & ResourceManager::getFont(ResourceID id) {
	return *(m_fonts.at(id));
}

void ResourceManager::loadFont(ResourceID id, ResourceID fsID) {
	sf::Font* fnt = new sf::Font();

	if (!fnt->loadFromFile(RESOURCES_ROOT+fsID)) {
		gLogger.tag("ResourceManager") << "Failed to load font " << fsID;
		delete fnt;
		return;
	}

	gLogger.tag("ResourceManager") << "Loaded font `" << id << "`";

	m_fonts.insert(std::make_pair(id, fnt));
}

void ResourceManager::loadAllResources() {
	loadFont("main", "Fonts/comic.ttf");
}
