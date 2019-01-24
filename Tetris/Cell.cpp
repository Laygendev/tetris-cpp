#include "Cell.hpp"
#include "Grid.hpp"
#include "Bloc.hpp"

Cell::Cell() {}

Cell::Cell(Bloc* bloc, sf::Vector2i pos, std::string color)
{
	m_bloc = bloc;
	m_pos = pos;
	m_color = color;
	m_shape.setSize(sf::Vector2f(44.f, 44.f));

	if ("yellow" == color) {
		m_shape.setFillColor(sf::Color(0, 255, 255, 50));
	}
	else {
		m_shape.setFillColor(sf::Color(0, 0, 0, 50));
	}
}

void Cell::update(Grid &grid) {
	m_shape.setPosition(grid.GetPositionByCell(m_pos.x, m_pos.y));
}

void Cell::draw(sf::RenderWindow &window)
{
	window.draw(m_shape);
}

void Cell::setPos(sf::Vector2i pos)
{
	m_pos = pos;
}

void Cell::increasePos(int x, int y)
{
	m_pos.x += x;
	m_pos.y += y;
}

void Cell::destroy()
{

}

sf::Vector2i Cell::getPos()
{
	return m_pos;
}

std::string Cell::getColor()
{
	return m_color;
}