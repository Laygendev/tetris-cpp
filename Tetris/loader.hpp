#pragma once

#ifndef DEF_LOADER
#define DEF_LOADER

#include <iostream>
#include <SFML/Graphics.hpp>

class Loader
{
	public:
		Loader();

		sf::Texture* GetBackground();
		sf::Texture* GetBlocTexture(int index);

	private:
		sf::Texture background;
		sf::Texture m_blocsTexture[5];
};

#endif