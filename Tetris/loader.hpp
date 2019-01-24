#pragma once

#ifndef DEF_LOADER
#define DEF_LOADER

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.hpp"

class Loader
{
	public:
		Loader();

		sf::Texture* GetBackground();
		sf::Texture* GetBlocTexture(int index);
		Cell* GetCell(int index);

	private:
		sf::Texture background;
		sf::Texture m_blocsTexture[5];
		Cell m_cell[5][4];
};

#endif