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
	sf::Time elapsed = clock.getElapsedTime();
	std::cout << elapsed.asSeconds() << std::endl;
	
	if (elapsed.asSeconds() > 1) {
		clock.restart();

		m_cell.y += 1;
		
		sprite.setPosition(m_grid->GetPositionByCell(m_cell.x, m_cell.y));
	}
}

void Bloc::SetTexture(sf::Texture *texture) {
	sprite.setTexture(*texture);
}

sf::Sprite &Bloc::GetSprite() {
	return sprite;
}