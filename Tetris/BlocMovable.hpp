#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "bloc.hpp"

class BlocMovable : public Bloc
{
public:

	BlocMovable(Grid* grid, sf::Texture *texture, sf::Vector2i *body);
	void Update(sf::Clock &clock);

	void CheckCollider();
	bool GetHasCollision();

private:
	bool m_hasCollision = false;
	sf::Vector2i *m_body;
};