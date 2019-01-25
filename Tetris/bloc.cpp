#include "Bloc.hpp"
#include "Grid.hpp"

Bloc::Bloc(Grid* grid, sf::Texture *texture, Cell *cells)
{
	m_grid = grid;
	m_texture = texture;

	m_cell_pos.x = 0;
	m_cell_pos.y = 0;

	m_cells[0] = new Cell(this, sf::Vector2i(0, 0), "yellow");
	m_cells[1] = new Cell(this, sf::Vector2i(0, 1), "yellow");
	m_cells[2] = new Cell(this, sf::Vector2i(0, 2), "yellow");
	m_cells[3] = new Cell(this, sf::Vector2i(0, 3), "yellow");

	/*for (int i = 0; i < 4; ++i)
	{
		m_cells[i] = new Cell(this, cells[i].getPos(), cells[i].getColor());
	}*/

	std::cout << "cell" << std::endl;
}
Bloc::Bloc(Bloc const& blocToCopy)
	: m_grid(blocToCopy.m_grid),
	m_texture(blocToCopy.m_texture),
	m_cell_pos(blocToCopy.m_cell_pos)
{
	for (int i = 0; i < 4; ++i)
	{
		m_cells[i] = new Cell(*(blocToCopy.m_cells[i]));
	}
}

Bloc::~Bloc()
{
}

void Bloc::Display(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; ++i)
	{
		m_cells[i]->draw(window);
	}
}

void Bloc::Update(sf::Clock &clock)
{
}

void Bloc::SetTexture(sf::Texture *texture) {
}

void Bloc::deleteCell(Cell *cell)
{
	//delete cell;
	// cell = 0;
}

sf::Texture *Bloc::getTexture()
{
	return m_texture;
}

Cell Bloc::getCells() {
	return m_cells;
}