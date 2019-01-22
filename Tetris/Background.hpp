#pragma once

#ifndef DEF_BACKGROUND
#define DEF_BACKGROUND

#include <iostream>
#include <SFML/Graphics.hpp>

class Background
{
public:

	Background(sf::Texture *texture);

	void draw(sf::RenderWindow &window);
	void SetTexture(sf::Texture *texture);

private:
	sf::Sprite sprite;
};

#endif