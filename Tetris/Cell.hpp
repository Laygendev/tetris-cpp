#pragma once

#ifndef DEF_CELL
#define DEF_CELL

#include <iostream>
#include <SFML/Graphics.hpp>

class Grid;
class Bloc;

class Cell
{
public:
	Cell();
	Cell(Bloc* bloc, sf::Vector2i pos, std::string color);

	void update(Grid &grid);
	void draw(sf::RenderWindow &window);

	void setPos(sf::Vector2i pos);

	void increasePos(int x, int y);

	void destroy();

	sf::Vector2i getPos();
	std::string getColor();
private:
	Bloc *m_bloc;
	sf::Vector2i m_pos;
	std::string m_color;

	sf::RectangleShape m_shape;
};

#endif