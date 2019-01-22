#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Grid;

class Bloc
{
	public:
		
		Bloc(Grid* grid, sf::Texture *texture);

		void Display(sf::RenderWindow &window);
		void Update(sf::Clock &clock);

		void SetTexture(sf::Texture *texture);
		sf::Sprite &GetSprite();

	protected:
		Grid* m_grid;

		sf::Sprite sprite;

		sf::Vector2i m_cell;
};