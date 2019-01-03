/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/

#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unordered_map>

typedef std::string ResourceID;

const ResourceID RESOURCES_ROOT = "Resources/";

class ResourceManager {
public:
	ResourceManager();

	void init();
	void destroy();

	sf::Font& getFont(ResourceID id);
	
	//void playSound(ResourceID id);
private:
	void loadFont(ResourceID id, ResourceID fsID);

	void loadAllResources();

	std::unordered_map<ResourceID, sf::Font*> m_fonts;
};

#endif
