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
		std::cout << m_body[i].x << std::endl;

		m_shape[i].setSize(sf::Vector2f(44.f, 44.f));
		m_shape[i].setFillColor(sf::Color(0, 0, 0, 50));
	}
}

void Bloc::Display(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < 4; ++i)
	{
		window.draw(m_shape[i]);
	}

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