#pragma once

#ifndef DEF_GRID
#define DEF_GRID

#include <list>
#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"
#include "Cell.hpp"

class Grid
{
public:
	Grid();
	~Grid() = default;

	sf::Vector2f GetPositionByCell(int cellX, int cellY);

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow& window);

	void AddBloc(Bloc bloc);
	bool CheckCollision(sf::Vector2i bodyCell);
	bool CheckCollisionLeft(sf::Vector2i bodyCell);
	bool CheckCollisionRight(sf::Vector2i bodyCell);
private:
	void updateGrid(Bloc &bloc);
	void checkLine(Bloc &bloc);
	bool checkLineCellY(int cellY, std::string color);
	void destroyLine(int cellY);

	Cell m_grid2D[9][19];
	std::list<Bloc*> m_blocs;

	sf::Vector2f m_offset;
};

#endif