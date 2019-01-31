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
	Bloc *newBloc = new Bloc(*bloc);
	std::vector<Cell*> body = newBloc->getCells();
	for (int i = 0; i < body.size(); ++i)
	{
		body[i]->setBloc(newBloc);
	}

	updateGrid(newBloc);

	std::vector<int>lineCompleted(0);
	
	do
	{
		lineCompleted = searchLineWithFullCell();

		if (lineCompleted.size() != 0) {
			destroyLine(lineCompleted);
		}
	} while (lineCompleted.size() != 0);
}

bool Grid::checkHaveBloc(sf::Vector2i pos)
{
	if (pos.x > 9)
	{
		return true;
	}

	if (m_grid[pos.x][pos.y] != NULL)
	{
		return true;
	}

	return false;
}

bool Grid::CheckCollision(sf::Vector2i bodyCell)
{
	if (m_grid[bodyCell.x][bodyCell.y + 1] != NULL)
	{
		return true;
	}

	return false;
}

bool Grid::CheckCollisionLeft(sf::Vector2i bodyCell)
{
	if (m_grid[bodyCell.x - 1][bodyCell.y] != NULL)
	{
		return true;
	}

	return false;

}

bool Grid::CheckCollisionRight(sf::Vector2i bodyCell)
{
	if (m_grid[bodyCell.x + 1][bodyCell.y] != NULL)
	{
		return true;
	}

	return false;
}

void Grid::Update(sf::Clock& clock) {
	std::vector<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		it->Update(clock);
	}
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (m_grid[i][j] != NULL)
			{
				m_grid[i][j]->draw(window);
			}
		}
	}

	std::vector<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		it->Display(window);
	}
}

void Grid::updateGrid(Bloc* bloc)
{
	std::vector<Cell*> body = bloc->getCells();
	
	for (int i = 0; i < body.size(); ++i)
	{
		sf::Vector2i pos = body[i]->getPos();
		m_grid[pos.x][pos.y] = body[i];
	}
}

bool Grid::gridIsFullY()
{
	for (int i = 0; i < 9; ++i)
	{
		if (m_grid[i][0] != NULL)
		{
			return true;
		}
	}

	return false;
}

std::vector<int> Grid::searchLineWithFullCell()
{
	std::vector <int> lineCompleted;

	int numberCellInLine = 0;
	for (int i = 0; i < 19; ++i)
	{
		numberCellInLine = 0;

		for (int j = 0; j < 9; j++)
		{
			if (m_grid[j][i] != NULL)
			{
				numberCellInLine++;
			}
		}

		if (numberCellInLine == 9)
		{
			lineCompleted.push_back(i);
		}
	}

	return lineCompleted;
}

void Grid::destroyLine(std::vector<int> completedLine)
{
	int numberLineDeleted = completedLine.size();

	std::vector<int>::iterator it = completedLine.begin();
	int limitToDecrease = 19;

	while (it != completedLine.end())
	{
		for (int j = 0; j < 9; ++j)
		{
			if (m_grid[j][*it] != NULL)
			{
				m_grid[j][*it]->destroy();
				m_grid[j][*it] = NULL;

			}
		}

		if (*it < limitToDecrease)
		{
			limitToDecrease = *it;
		}

		completedLine.erase(it);
	}

	for (int i = 8; i >= 0; --i)
	{
		for (int j = limitToDecrease; j >= 0; --j)
		{
			if (m_grid[i][j] != NULL)
			{
				Cell *tmpCell = new Cell(*m_grid[i][j]);
				m_grid[i][j] = NULL;

				// Pas ceux qui sont déjà plus bas que les lignes supprimés
				tmpCell->increasePos(0, numberLineDeleted);
				tmpCell->update(this);
				m_grid[i][j + numberLineDeleted] = tmpCell;
			}
		}
	}
}