#include "Bloc.hpp"
#include "Grid.hpp"

Bloc::Bloc(Grid* grid, sf::Texture *texture)
{
	m_grid = grid;
	sprite.setTexture(*texture);

	m_cell.x = 0;
	m_cell.y = 0;
}

void Bloc::Display(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Bloc::Update(sf::Clock &clock)
{
}

void Bloc::SetTexture(sf::Texture *texture) {
	sprite.setTexture(*texture);
}

sf::Sprite &Bloc::GetSprite() {
	return sprite;
}