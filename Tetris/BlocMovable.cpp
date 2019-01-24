#include "BlocMovable.hpp"
#include "Grid.hpp"

BlocMovable::BlocMovable(Grid* grid, sf::Texture *texture, Cell *cells) : Bloc(grid, texture, cells)
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
			if (m_cells[i]->getPos().x - 1 < 0) {
				canGoLeft = false;
				break;
			}

			if (CheckColliderLeft(m_cells[i]->getPos())) {
				canGoLeft = false;
				break;
			}
		}

		if (canGoLeft) {
			m_cell_pos.x -= 1;
			for (int i = 0; i < 4; ++i)
			{
				m_cells[i]->increasePos(-1, 0);
			}
		}
	}
	else {
		bool canGoRight = true;

		for (int i = 0; i < 4; ++i)
		{
			if (m_cells[i]->getPos().x + 1 > 8) {
				canGoRight = false;
				break;
			}

			if (CheckColliderRight(m_cells[i]->getPos())) {
				canGoRight = false;
				break;
			}
		}
		if (canGoRight) {
			m_cell_pos.x += 1;
			for (int i = 0; i < 4; ++i)
			{
				m_cells[i]->increasePos(1, 0);
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
			m_cell_pos.y += 1;

			for (int i = 0; i < 4; ++i)
			{
				m_cells[i]->increasePos(0, 1);
			}
		}
	}

	sprite.setPosition(m_grid->GetPositionByCell(m_cell_pos.x, m_cell_pos.y));

	for (int i = 0; i < 4; ++i)
	{
		m_cells[i]->update(*m_grid);
	}

}

bool BlocMovable::CheckCollider()
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_grid->CheckCollision(m_cells[i]->getPos())) {
			m_hasCollision = true;
			return true;
		}

		if ((m_cells[i]->getPos().y + 1) > 18) {
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
