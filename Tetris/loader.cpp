#include "Loader.hpp"

Loader::Loader()
{
	background.loadFromFile("ressources/Mockup/background.jpg");

	m_blocsTexture[0].loadFromFile("ressources/yellow.png");
	m_blocsTexture[1].loadFromFile("ressources/white.png");
	m_blocsTexture[2].loadFromFile("ressources/marron.png");
	m_blocsTexture[3].loadFromFile("ressources/orange.png");
	m_blocsTexture[4].loadFromFile("ressources/green.png");
	m_blocsTexture[5].loadFromFile("ressources/rose.png");


	m_blocsSpriteTexture[0].loadFromFile("ressources/I/1.png");
	m_blocsSpriteTexture[1].loadFromFile("ressources/L/L.png");
	m_blocsSpriteTexture[2].loadFromFile("ressources/R/R.png");
	m_blocsSpriteTexture[3].loadFromFile("ressources/S/S.png");
	m_blocsSpriteTexture[4].loadFromFile("ressources/T/T_2.png");
	m_blocsSpriteTexture[5].loadFromFile("ressources/S/S_2.png");

	std::vector<Cell*> tmp;

	std::vector<sf::Vector2i> posCell;
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "yellow"));
	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "yellow"));
	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 2));
	posCell.push_back(sf::Vector2i(2, 0));

	tmp.push_back(new Cell(NULL, posCell, "yellow"));
	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 3));
	posCell.push_back(sf::Vector2i(3, 0));

	tmp.push_back(new Cell(NULL, posCell, "yellow"));
	posCell.erase(posCell.begin(), posCell.end());
	
	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "green"));
	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "green"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 1));
	posCell.push_back(sf::Vector2i(0, 2));
	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(1, 1));

	tmp.push_back(new Cell(NULL, posCell, "green"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 0));
	posCell.push_back(sf::Vector2i(1, 2));
	posCell.push_back(sf::Vector2i(2, 0));
	posCell.push_back(sf::Vector2i(1, 2));
	tmp.push_back(new Cell(NULL, posCell, "green"));

	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "marron"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 1));

	tmp.push_back(new Cell(NULL, posCell, "marron"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "marron"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));

	tmp.push_back(new Cell(NULL, posCell, "marron"));


	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "orange"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(0, 1));


	tmp.push_back(new Cell(NULL, posCell, "orange"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(1, 1));


	tmp.push_back(new Cell(NULL, posCell, "orange"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 0));
	posCell.push_back(sf::Vector2i(1, 2));


	tmp.push_back(new Cell(NULL, posCell, "orange"));

	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(1, 0));


	tmp.push_back(new Cell(NULL, posCell, "white"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(1, 1));


	tmp.push_back(new Cell(NULL, posCell, "white"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(0, 1));

	tmp.push_back(new Cell(NULL, posCell, "white"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 1));
	posCell.push_back(sf::Vector2i(0, 2));
	posCell.push_back(sf::Vector2i(2, 0));
	posCell.push_back(sf::Vector2i(1, 2));

	tmp.push_back(new Cell(NULL, posCell, "white"));

	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "rose"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(1, 1));

	tmp.push_back(new Cell(NULL, posCell, "rose"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(0, 1));

	tmp.push_back(new Cell(NULL, posCell, "rose"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 1));
	posCell.push_back(sf::Vector2i(0, 2));

	tmp.push_back(new Cell(NULL, posCell, "rose"));

	m_cells.push_back(tmp);
}

sf::Texture* Loader::GetBackground()
{
	return &background;
}

sf::Texture* Loader::GetBlocTexture(int index)
{
	return &m_blocsTexture[index];
}

sf::Texture* Loader::GetBlocSpriteTexture(int index)
{
	return &m_blocsSpriteTexture[index];
}

std::vector<Cell*> Loader::GetCell(int index)
{
	std::vector<Cell*>tmp_vector_cell(0);

	for (int i = 0; i < m_cells[index].size(); ++i)
	{
		Cell* tmp_cell = new Cell(*m_cells[index][i]);
		tmp_vector_cell.push_back(tmp_cell);
	}

	return tmp_vector_cell;
}
