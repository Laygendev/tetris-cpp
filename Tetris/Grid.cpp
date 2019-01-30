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
		destroyLine(lineCompleted);
	} while (lineCompleted.size() != 0);
}

bool Grid::CheckCollision(sf::Vector2i bodyCell)
{
	std::vector<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		std::vector<Cell*> body = it->getCells();

		for (int i = 0; i < body.size(); ++i)
		{
			if (body[i]->getPos().x == bodyCell.x && body[i]->getPos().y - bodyCell.y == 1) {
				return true;
			}
		}
	}

	return false;
}

bool Grid::CheckCollisionLeft(sf::Vector2i bodyCell)
{
	std::vector<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		std::vector<Cell*> body = it->getCells();

		for (int i = 0; i < body.size(); ++i)
		{
			if (body[i]->getPos().x - bodyCell.x == -1 && body[i]->getPos().y == bodyCell.y ) {
				return true;
			}
		}
	}

	return false;
}

bool Grid::CheckCollisionRight(sf::Vector2i bodyCell)
{
	std::vector<Bloc>::iterator it;

	for (it = m_blocs.begin(); it != m_blocs.end(); ++it)
	{
		std::vector<Cell*> body = it->getCells();

		for (int i = 0; i < body.size(); ++i)
		{
			if (body[i]->getPos().x - bodyCell.x == 1 && body[i]->getPos().y == bodyCell.y) {
				return true;
			}
		}
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
	for (int i = 0; i < completedLine.size(); ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (m_grid[j][completedLine[i]] != NULL)
			{
				m_grid[j][completedLine[i]]->destroy();
				m_grid[j][completedLine[i]] = NULL;
			}
		}

		completedLine.erase(completedLine.begin() + i);
	}

	/*std::vector<int> deletedCellX;
	std::vector<Bloc>::iterator it = m_blocs.begin();

	while(it != m_blocs.end())
	{
		deletedCellX.push_back(it->deleteCellInLine(cellY));
		++it;
	}

	std::vector<Bloc>::iterator it_bloc = m_blocs.begin();

	while (it_bloc != m_blocs.end())
	{
		std::vector<Cell*> body = it_bloc->getCells();
		std::vector<Cell*>::iterator it_cell;

		for (it_cell = body.begin(); it_cell != body.end(); ++it_cell)
		{
			for (int i = 0; i < deletedCellX.size(); ++i)
			{
				if ((*it_cell)->getPos().x == deletedCellX[i] && (*it_cell)->getPos().y < cellY)
				{
					(*it_cell)->increasePos(0, 1);
					break;
				}
			}
		}

		it_bloc->setCells(body);

		if (it_bloc->getCells().size() == 0)
		{
			m_blocs.erase(it_bloc);
		}
		else {
			if (it_bloc != m_blocs.end()) {
				++it_bloc;
			}
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (checkLineCellY(i, ""))
		{
			destroyLine(i);
		}
	}*/
}