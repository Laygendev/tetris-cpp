#include "Bloc.hpp"
#include "Grid.hpp"

Bloc::Bloc(Grid* grid, sf::Texture *texture, Cell *cells)
{
	m_grid = grid;
	sprite.setTexture(*texture);

	m_cell_pos.x = 0;
	m_cell_pos.y = 0;

	for (int i = 0; i < 4; ++i)
	{
		m_cells[i] = new Cell(this, cells[i].getPos(), cells[i].getColor());
	}
}

void Bloc::Display(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < 4; ++i)
	{
		m_cells[i]->draw(window);
	}

}

void Bloc::Update(sf::Clock &clock)
{
}

void Bloc::SetTexture(sf::Texture *texture) {
	sprite.setTexture(*texture);
}

sf::Sprite &Bloc::GetSprite() {
	return sprite;
}

Cell *Bloc::getCells() {
	return *m_cells;
}