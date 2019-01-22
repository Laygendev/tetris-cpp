#pragma once

#ifndef DEF_BLOC
#define DEF_BLOC

#include <iostream>
#include <SFML/Graphics.hpp>

class Bloc
{
	public:
		
		Bloc();

		void Display(sf::RenderWindow &window);
		void SetTexture(sf::Texture *texture);
		sf::Sprite GetSprite();

	private:
		sf::Sprite sprite;
};

#endif