#include "Grid.hpp"

Grid::Grid()
{
	m_offset.x = 20.f;
	m_offset.y = 96.f;
}

sf::Vector2f Grid::GetPositionByCell(int cellX, int cellY)
{
	sf::Vector2f position;
	position.x = (float)(cellX * 44);
	position.y = (float)(cellY * 44);

	// Offset
	position.x += m_offset.x;
	position.y += m_offset.y;

	return position;
}

void Grid::AddBloc(Bloc& bloc)
{
	m_blocs.push_back(bloc);
}

bool Grid::CheckCollision(sf::Vector2i bodyCell)
{
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		sf::Vector2i *body = it->getBodies();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].x == bodyCell.x && body[i].y - bodyCell.y == 1) {
				return true;
			}
		}
	}

	return false;
}

bool Grid::CheckCollisionLeft(sf::Vector2i bodyCell)
{
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		sf::Vector2i *body = it->getBodies();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].x - bodyCell.x == -1 && body[i].y == bodyCell.y ) {
				return true;
			}
		}
	}

	return false;
}

bool Grid::CheckCollisionRight(sf::Vector2i bodyCell)
{
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		sf::Vector2i *body = it->getBodies();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].x - bodyCell.x == 1 && body[i].y == bodyCell.y) {
				return true;
			}
		}
	}

	return false;
}

void Grid::Update(sf::Clock& clock) {
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		it->Update(clock);
	}
}

void Grid::Draw(sf::RenderWindow& window)
{
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		it->Display(window);
	}
}