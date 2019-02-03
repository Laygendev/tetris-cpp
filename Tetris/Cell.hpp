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
	Cell(Bloc *bloc, const std::vector<sf::Vector2i>, std::string color);
	Cell(Cell const& cellToCopy);
	void init(Grid &grid);
	void update(Grid *grid);
	void draw(sf::RenderWindow &window);

	void setPos(sf::Vector2i pos);
	void setPosSprite(sf::Vector2f pos);

	void increasePos(int x, int y);

	void destroy();
	sf::Vector2i simulateNextRotation();
	void nextRotation();

	void SetTexture(sf::Texture *texture);

	void setBloc(Bloc *bloc);
	Bloc getBloc();

	sf::Vector2i getPos();
	std::string getColor();
	sf::Sprite* getSprite();
	sf::Texture* getTexture();

	void playFx();
	void updateFx();
	void drawFx(sf::RenderWindow &window);
private:
	Bloc *m_bloc;
	std::vector<sf::Vector2i> m_pos;
	std::string m_color;

	sf::Sprite m_sprite;
	sf::Texture *m_texture;
	int m_currentRotation = 0;

	bool m_onPlayFx = false;
	sf::RectangleShape m_fx;

	sf::Clock m_clockFX;
};

#endif