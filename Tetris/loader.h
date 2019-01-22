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

	private:
		sf::Texture background;
};

#endif