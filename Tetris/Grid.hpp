#pragma once

#ifndef DEF_GRID
#define DEF_GRID

#include <list>
#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"

class Grid
{
public:
	Grid();
	~Grid() = default;

	sf::Vector2f GetPositionByCell(int cellX, int cellY);

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow& window);

	void AddBloc(Bloc& bloc);
	bool CheckCollision(sf::Vector2i bodyCell);
private:
	int m_grid2D[8][18] = { 0 };
	std::list<Bloc> m_blocs;

	sf::Vector2f m_offset;
};

#endif