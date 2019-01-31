#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"

class BlocMovable : public Bloc
{
public:

	BlocMovable(App * app, Grid* grid, sf::Texture *texture, const std::vector<Cell*> cells);
	~BlocMovable();

	void translate(std::string direction);
	void Update(sf::Clock &clock);

	bool CheckCollider();
	bool CheckColliderLeft(sf::Vector2i cell);
	bool CheckColliderRight(sf::Vector2i cell);
	bool GetHasCollision();

private:
	bool m_hasCollision = false;
};