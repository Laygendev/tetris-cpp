#include "BlocMovable.hpp"
#include "Grid.hpp"

BlocMovable::BlocMovable(Grid* grid, sf::Texture *texture, sf::Vector2i *body) : Bloc(grid, texture)
{
	m_body = body;
}

void BlocMovable::Update(sf::Clock &clock)
{
	sf::Time elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() > 0.2f) {
		clock.restart();

		m_cell.y += 1;

		CheckCollider();

		sprite.setPosition(m_grid->GetPositionByCell(m_cell.x, m_cell.y));
	}
}

void BlocMovable::CheckCollider()
{

}

bool BlocMovable::GetHasCollision()
{
	return m_hasCollision;
}
