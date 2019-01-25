#include "Grid.hpp"

Grid::Grid()
{
	m_offset.x = 20.f;
	m_offset.y = 96.f;
}

Grid::~Grid()
{
	std::cout << "Destructor Grid" << std::endl;
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

void Grid::AddBloc(Grid* grid, Bloc *bloc)
{
	Cell *tmp = bloc->getCells();

	/*Bloc newBloc = *bloc;
	m_blocs.push_back(newBloc);
	for (int i = 0; i < 4; ++i)
	{
		std::cout << newBloc.getCells()[i].getPos().y << std::endl;
	}
	destroyLine(18);*/
	//updateGrid(*newBloc);
	//checkLine(*newBloc);
}

bool Grid::CheckCollision(sf::Vector2i bodyCell)
{
	std::list<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		Cell *body = it->getCells();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].getPos().x == bodyCell.x && body[i].getPos().y - bodyCell.y == 1) {
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
		Cell *body = it->getCells();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].getPos().x - bodyCell.x == -1 && body[i].getPos().y == bodyCell.y ) {
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
		Cell *body = it->getCells();

		for (int i = 0; i < 4; ++i)
		{
			if (body[i].getPos().x - bodyCell.x == 1 && body[i].getPos().y == bodyCell.y) {
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

void Grid::updateGrid(Bloc &bloc)
{
	Cell *cells = bloc.getCells();
	
	for (int i = 0; i < 4; ++i)
	{
		//sf::Vector2i pos = cells[i]->getPos();
		//m_grid2D[pos.x][pos.y] = cells[i];
	}
}

void Grid::checkLine(Bloc &bloc)
{
	Cell *cells = bloc.getCells();

	for (int i = 3; i < 4; ++i)
	{
		//sf::Vector2i pos = cells[i].getPos();
		sf::String color = cells[i].getColor();

		//if (checkLineCellY(pos.y, color))
	//	{
	//		destroyLine(pos.y);
	//	}
	}
}

bool Grid::checkLineCellY(int cellY, std::string color)
{
	for (int i = 0; i < 9; i++) {
		Cell cell = m_grid2D[i][cellY];

		if (cell.getColor() != color)
		{
			return false;
		}
	}

	return true;
}

void Grid::destroyLine(int cellY)
{
	Cell cell = m_grid2D[0][cellY];

	cell.destroy();
	/*for (int i = 0; i < 9; i++) {
		
	}*/
}