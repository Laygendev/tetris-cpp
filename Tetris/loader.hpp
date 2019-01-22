#pragma once

#ifndef DEF_LOADER
#define DEF_LOADER

#include <iostream>
#include <SFML/Graphics.hpp>

class Loader
{
	public:
		Loader();

		sf::Texture* GetBackground();
		sf::Texture* GetBlocTexture(int index);
		sf::Vector2i* GetBody(int index);

	private:
		sf::Texture background;
		sf::Texture m_blocsTexture[5];
		sf::Vector2i m_body[5][4];
};

#endif