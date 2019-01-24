#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.hpp"

class Grid;

class Bloc
{
	public:
		
		Bloc(Grid* grid, sf::Texture *texture, Cell *cells);

		void Display(sf::RenderWindow &window);
		void Update(sf::Clock &clock);

		void SetTexture(sf::Texture *texture);
		sf::Sprite &GetSprite();
		Cell *getCells();

	protected:
		Grid* m_grid;

		sf::Sprite sprite;

		sf::Vector2i m_cell_pos;

		Cell* m_cells[4];
};