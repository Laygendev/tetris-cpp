#include "BlocMovable.hpp"
#include "Grid.hpp"

BlocMovable::BlocMovable(Grid* grid, sf::Texture *texture, sf::Vector2i *body) : Bloc(grid, texture, body)
{

}

BlocMovable::~BlocMovable()
{
}

void BlocMovable::Update(sf::Clock &clock)
{
	sf::Time elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() > 0.2f && !m_hasCollision) {
		clock.restart();

		m_cell.y += 1;

		for (int i = 0; i < 4; ++i)
		{
			m_body[i].y += 1;
		}

		CheckCollider();

		sprite.setPosition(m_grid->GetPositionByCell(m_cell.x, m_cell.y));
	}
}

void BlocMovable::CheckCollider()
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_grid->CheckCollision(m_body[i])) {
			m_hasCollision = true;
		}

		if (m_body[i].y > 17) {
			m_hasCollision = true;
		}
	}
}

bool BlocMovable::GetHasCollision()
{
	return m_hasCollision;
}
