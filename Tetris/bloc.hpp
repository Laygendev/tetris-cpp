#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Cell.hpp"

class Grid;

class Bloc
{
	public:
		
		Bloc(Grid* grid, sf::Texture *texture, std::vector<Cell*> cells);
		Bloc(Bloc const& blocToCopy);
		~Bloc();

		void Display(sf::RenderWindow &window);
		void Update(sf::Clock &clock);
		void updateTexture();
		void updateCellPos();
		int deleteCellInLine(int y);

		
		void setCells(std::vector<Cell*> cells);
		std::vector<Cell*> getCells();
		sf::Texture *getTexture();

	protected:
		Grid* m_grid;

		sf::Texture *m_texture;

		sf::Vector2i m_cell_pos;

		int m_currentAngle = 0;

		std::vector<Cell*> m_cells;
};