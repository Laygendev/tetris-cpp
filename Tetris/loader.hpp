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
		sf::Texture* GetBlocSpriteTexture(int index);
		std::vector<Cell*> GetCell(int index);

	private:
		sf::Texture background;
		sf::Texture m_blocsTexture[5];
		sf::Texture m_blocsSpriteTexture[5];
		std::vector<std::vector<Cell*>> m_cells;
};

#endif