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

	if (m_onPlayFx)
	{
		updateFx();
		drawFx(window);
	}
}

void Cell::setPos(sf::Vector2i pos)
{
	m_pos[m_currentRotation] = pos;
}

void Cell::setPosSprite(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
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

sf::Sprite* Cell::getSprite()
{
	return &m_sprite;
}

sf::Texture* Cell::getTexture()
{
	return m_texture;
}

void Cell::updateFx()
{
	m_fx.setPosition(m_sprite.getPosition());
	m_fx.setFillColor(sf::Color(255, 255, 255, 30));

	float mSizeHeight = m_clockFX.getElapsedTime().asSeconds() * 420;

	if (mSizeHeight > 44.f)
	{
		m_onPlayFx = false;
		mSizeHeight = 44.f;
	}

	m_fx.setSize(sf::Vector2f(44.f, mSizeHeight));
}

void Cell::drawFx(sf::RenderWindow &window)
{
	window.draw(m_fx);
}

void Cell::playFx()
{
	m_onPlayFx = true;
	m_clockFX.restart();
}