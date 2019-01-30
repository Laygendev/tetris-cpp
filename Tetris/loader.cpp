#include "Loader.hpp"

Loader::Loader()
{
	background.loadFromFile("ressources/Mockup/background.jpg");
	m_blocsTexture[0].loadFromFile("ressources/green.png");
	m_blocsTexture[1].loadFromFile("ressources/marron.png");
	m_blocsTexture[2].loadFromFile("ressources/orange.png");
	m_blocsTexture[3].loadFromFile("ressources/white.png");
	m_blocsTexture[4].loadFromFile("ressources/yellow.png");

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

	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(0, 0));
	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "green"));
	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));
	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(0, 1));
	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "green"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 0));
	posCell.push_back(sf::Vector2i(1, 2));
	posCell.push_back(sf::Vector2i(1, 1));
	posCell.push_back(sf::Vector2i(0, 1));

	tmp.push_back(new Cell(NULL, posCell, "green"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(2, 1));
	posCell.push_back(sf::Vector2i(0, 2));
	posCell.push_back(sf::Vector2i(2, 1));
	posCell.push_back(sf::Vector2i(0, 2));
	tmp.push_back(new Cell(NULL, posCell, "green"));

	m_cells.push_back(tmp);

	tmp.erase(tmp.begin(), tmp.end());

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 0));

	tmp.push_back(new Cell(NULL, posCell, "blue"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(0, 1));

	tmp.push_back(new Cell(NULL, posCell, "blue"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 0));

	tmp.push_back(new Cell(NULL, posCell, "blue"));

	posCell.erase(posCell.begin(), posCell.end());

	posCell.push_back(sf::Vector2i(1, 1));

	tmp.push_back(new Cell(NULL, posCell, "blue"));


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


	/*m_body[1][0].x = 0;
	m_body[1][0].y = 0;
	m_body[1][1].x = 0;
	m_body[1][1].y = 1;
	m_body[1][2].x = 0;
	m_body[1][2].y = 2;
	m_body[1][3].x = 1;
	m_body[1][3].y = 2;

	m_body[2][0].x = 0;
	m_body[2][0].y = 0;
	m_body[2][1].x = 0;
	m_body[2][1].y = 1;
	m_body[2][2].x = 1;
	m_body[2][2].y = 0;
	m_body[2][3].x = 1;
	m_body[2][3].y = 1;*/
}

sf::Texture* Loader::GetBackground()
{
	return &background;
}

sf::Texture* Loader::GetBlocTexture(int index)
{
	return &m_blocsTexture[index];
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
