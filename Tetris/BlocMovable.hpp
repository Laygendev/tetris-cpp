#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"

class BlocMovable : public Bloc
{
public:

	BlocMovable(Grid* grid, sf::Texture *texture, sf::Vector2i *body);
	~BlocMovable();
	void Update(sf::Clock &clock);

	void CheckCollider();
	bool GetHasCollision();

private:
	bool m_hasCollision = false;
};