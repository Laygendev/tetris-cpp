#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.hpp"

class Grid;

class Bloc
{
	public:
		
		Bloc(Grid* grid, sf::Texture *texture, Cell *cells);
		Bloc(Bloc const& blocToCopy);
		~Bloc();

		void Display(sf::RenderWindow &window);
		void Update(sf::Clock &clock);
		void deleteCell(Cell *cell);

		void SetTexture(sf::Texture *texture);
		Cell getCells();
		sf::Texture *getTexture();

	protected:
		Grid* m_grid;

		sf::Texture *m_texture;

		sf::Vector2i m_cell_pos;

		Cell* m_cells[4];
};