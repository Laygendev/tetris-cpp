#include "BlocMovable.hpp"
#include "Grid.hpp"

BlocMovable::BlocMovable(Grid* grid, sf::Texture *texture, sf::Vector2i *body) : Bloc(grid, texture, body)
{

}

BlocMovable::~BlocMovable()
{
}

void BlocMovable::translate(std::string direction)
{
	if (direction == "left")
	{
		bool canGoLeft = true;

		for (int i = 0; i < 4; ++i)
		{
			if (m_body[i].x - 1 < 0) {
				canGoLeft = false;
				break;
			}

			if (CheckColliderLeft(m_body[i])) {
				canGoLeft = false;
				break;
			}
		}

		if (canGoLeft) {
			m_cell.x -= 1;
			for (int i = 0; i < 4; ++i)
			{
				m_body[i].x -= 1;
			}
		}
	}
	else {
		bool canGoRight = true;

		for (int i = 0; i < 4; ++i)
		{
			if (m_body[i].x + 1 > 8) {
				canGoRight = false;
				break;
			}

			if (CheckColliderRight(m_body[i])) {
				canGoRight = false;
				break;
			}
		}
		if (canGoRight) {
			m_cell.x += 1;
			for (int i = 0; i < 4; ++i)
			{
				m_body[i].x += 1;
			}
		}
	}
}

void BlocMovable::Update(sf::Clock &clock)
{
	sf::Time elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() > 0.3f && !m_hasCollision) {
		clock.restart();

		if (CheckCollider()) {

		}
		else {
			m_cell.y += 1;

			for (int i = 0; i < 4; ++i)
			{
				m_body[i].y += 1;
			}
		}
	}

	sprite.setPosition(m_grid->GetPositionByCell(m_cell.x, m_cell.y));

	for (int i = 0; i < 4; ++i)
	{
		m_shape[i].setPosition(m_grid->GetPositionByCell(m_body[i].x, m_body[i].y));
	}

}

bool BlocMovable::CheckCollider()
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_grid->CheckCollision(m_body[i])) {
			m_hasCollision = true;
			return true;
		}

		if ((m_body[i].y + 1) > 18) {
			m_hasCollision = true;
			return true;
		}
	}

	return false;
}

bool BlocMovable::CheckColliderLeft(sf::Vector2i cell)
{
	if (m_grid->CheckCollisionLeft(cell)) {
		return true;
	}

	return false;
}

bool BlocMovable::CheckColliderRight(sf::Vector2i cell)
{
	if (m_grid->CheckCollisionRight(cell)) {
		return true;
	}

	return false;
}

bool BlocMovable::GetHasCollision()
{
	return m_hasCollision;
}
