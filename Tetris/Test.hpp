#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

class Test
{
public:

	Test();
	void deleteVector();
	std::vector<sf::Vector2i> getPos();
private:
	std::vector<sf::Vector2i> pos;
};