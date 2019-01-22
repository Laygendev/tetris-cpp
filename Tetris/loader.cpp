#include "loader.h"

Loader::Loader()
{
	if (!background.loadFromFile("C:/Users/EOXIA/source/repos/Tetris/x64/Release/ressources/Mockup/background.jpg"))
	{
		std::cout << "No loadd" << std::endl;
	}
	else
	{
		std::cout << "Loaded" << std::endl;
	}
}

sf::Texture* Loader::GetBackground() {
	std::cout << "Send background" << std::endl;
	return &background;
}
