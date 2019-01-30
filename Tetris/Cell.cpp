#include "Cell.hpp"
#include "Grid.hpp"
#include "Bloc.hpp"

Cell::Cell() {}

Cell::Cell(Bloc *bloc, const std::vector<sf::Vector2i> pos, std::string color)
{
	m_bloc = bloc;
	m_pos = pos;
	m_color = color;
}

Cell::Cell(Cell const& cellToCopy)
	: m_bloc(cellToCopy.m_bloc),
	m_pos(cellToCopy.m_pos),
	m_color(cellToCopy.m_color),
	m_sprite(cellToCopy.m_sprite),
	m_currentRotation(cellToCopy.m_currentRotation)
{
}


void Cell::init(Grid &grid) {
	m_sprite.setPosition(grid.GetPositionByCell(m_pos[m_currentRotation].x, m_pos[m_currentRotation].y));
}


void Cell::update(Grid *grid) {
	m_sprite.setPosition(grid->GetPositionByCell(m_pos[m_currentRotation].x, m_pos[m_currentRotation].y));
}

void Cell::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

void Cell::setPos(sf::Vector2i pos)
{
	m_pos[m_currentRotation] = pos;
}

void Cell::increasePos(int x, int y)
{
	for (int i = 0; i < m_pos.size(); ++i)
	{
		m_pos[i].x += x;
		m_pos[i].y += y;
	}
}


void Cell::SetTexture(sf::Texture *texture) {
	m_texture = texture;
	m_sprite.setTexture(*m_texture);
}


void Cell::destroy()
{
	m_bloc->deleteCellInLine(m_pos[m_currentRotation].x, m_pos[m_currentRotation].y);
}

sf::Vector2i Cell::simulateNextRotation()
{
	int nextRotation = m_currentRotation + 1;

	if (m_pos.size() <= nextRotation)
	{
		nextRotation = 0;
	}

	return m_pos[nextRotation];
}

void Cell::nextRotation()
{
	m_currentRotation++;

	if (m_pos.size() <= m_currentRotation)
	{
		m_currentRotation = 0;
	}
}

void Cell::setBloc(Bloc *bloc)
{
	m_bloc = bloc;
}

Bloc Cell::getBloc()
{
	return *m_bloc;
}

sf::Vector2i Cell::getPos()
{
	return m_pos[m_currentRotation];
}

std::string Cell::getColor()
{
	return m_color;
}