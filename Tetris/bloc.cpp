#include "Bloc.hpp"
#include "Grid.hpp"

Bloc::Bloc(Grid* grid, sf::Texture *texture, std::vector<Cell*> cells)
{
	m_grid = grid;
	m_texture = texture;

	m_cell_pos.x = 3;
	m_cell_pos.y = 0;

	m_cells = cells;

	updateTexture();
	updateCellPos();
}
Bloc::Bloc(Bloc const& blocToCopy)
	: m_grid(blocToCopy.m_grid),
	m_texture(blocToCopy.m_texture),
	m_cell_pos(blocToCopy.m_cell_pos),
	m_cells(blocToCopy.m_cells)
{
	std::cout << "here" << m_cells.size() << std::endl;
	/*for (int i = 0; i < m_cells.size(); ++i)
	{
		m_cells[i].setBloc(this);
		m_cells[i].SetTexture(m_texture);
		//m_cells[i].update(*m_grid);
	}*/
}

Bloc::~Bloc()
{
}

void Bloc::Display(sf::RenderWindow &window)
{
	for (int i = 0; i < m_cells.size(); ++i)
	{
		m_cells[i]->draw(window);
	}
}

void Bloc::Update(sf::Clock &clock)
{
	int i = 0;
	for (i = 0; i < m_cells.size(); i++) {
		m_cells[i]->update(*m_grid);

	}
}

void Bloc::updateTexture()
{
	int i = 0;
	for (i = 0; i < m_cells.size(); i++) {
		m_cells[i]->SetTexture(m_texture);
	}
}

void Bloc::updateCellPos()
{
	int i = 0;
	for (i = 0; i < m_cells.size(); i++) {
		m_cells[i]->increasePos(m_cell_pos.x, m_cell_pos.y);
	}
}

int Bloc::deleteCellInLine(int y)
{
	int posX = 0;
	std::vector<Cell*>::iterator it_cell;

	for (it_cell = m_cells.begin(); it_cell != m_cells.end(); ++it_cell) {
		if ((*it_cell)->getPos().y == y) {
			posX = (*it_cell)->getPos().x;
			m_cells.erase(it_cell);
			break;
		}
	}
	return posX;
}

sf::Texture *Bloc::getTexture()
{
	return m_texture;
}

void Bloc::setCells(std::vector<Cell*> cells)
{
	m_cells = cells;
}

std::vector<Cell*> Bloc::getCells() {
	return m_cells;
}

