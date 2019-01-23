#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Grid;

class Bloc
{
	public:
		
		Bloc(Grid* grid, sf::Texture *texture, sf::Vector2i *body);

		void Display(sf::RenderWindow &window);
		void Update(sf::Clock &clock);

		void SetTexture(sf::Texture *texture);
		sf::Sprite &GetSprite();
		sf::Vector2i *getBodies();

	protected:
		Grid* m_grid;

		sf::Sprite sprite;

		sf::Vector2i m_cell;

		sf::Vector2i m_body[4];
		sf::RectangleShape m_shape[4];
};