#include "Bloc.hpp"
#include "Grid.hpp"

Bloc::Bloc(Grid* grid, sf::Texture *texture, sf::Vector2i *body)
{
	m_grid = grid;
	sprite.setTexture(*texture);

	m_cell.x = 0;
	m_cell.y = 0;

	for (int i = 0; i < 4; ++i)
	{
		m_body[i].x = body[i].x;
		m_body[i].y = body[i].y;
	}
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

sf::Vector2i *Bloc::getBodies() {
	return m_body;
}